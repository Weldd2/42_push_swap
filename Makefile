# ============================================================================ #
#        ANSI color codes                                                      #
# ============================================================================ #

GREEN := \033[0;32m
YELLOW := \033[0;33m
BOLD_GREEN := \033[1;32m
BOLD_YELLOW := \033[1;33m
RESET := \033[0m
CLEAR_LINE := \033[K

# ============================================================================ #
#        Config variables                                                      #
# ============================================================================ #

NAME := push_swap
TEST_BIN := test_bin

# Répertoires
SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj
TEST_DIR := tests

CC := cc
CFLAGS := -Wall -Werror -Wextra -I$(INC_DIR) -g

# Sources
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ := $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/tests/%.o, $(TEST_SRC))

# Exclure main.o des objets principaux lors de la création de test_bin
TEST_LINK_OBJ := $(filter-out $(OBJ_DIR)/main.o, $(OBJ)) $(TEST_OBJ)

# Flags additionnels
LDFLAGS :=
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all
LLDB_FLAGS := --

# Arguments pour l'exécution
TEST_ARGUMENTS := 1 2 3 4
MAIN_ARGUMENTS := 5 6 7 8

# ============================================================================ #
#        Règles de compilation                                                 #
# ============================================================================ #

all: $(NAME)

$(NAME): $(OBJ) msg_comp
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@printf "$(GREEN)✔ $(NAME) créé.\n$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cible pour recompiler complètement
re: fclean all

# ============================================================================ #
#        Règles de nettoyage                                                   #
# ============================================================================ #

clean: msg_clean
	@rm -rf $(OBJ_DIR)

fclean: clean msg_fclean
	@rm -f $(NAME) $(TEST_BIN)

# ============================================================================ #
#        Règles de test                                                        #
# ============================================================================ #

# Construction du binaire de test
$(TEST_BIN): $(TEST_LINK_OBJ)
	@$(CC) $(CFLAGS) -o $@ $(TEST_LINK_OBJ) $(LDFLAGS)
	@printf "$(GREEN)✔ Binaire de test $(TEST_BIN) créé.\n$(RESET)"

$(OBJ_DIR)/tests/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Pour lancer les tests
test: $(TEST_BIN)
	@printf "$(YELLOW)Lancement des tests...\n$(RESET)"
	@./$(TEST_BIN) $(TEST_ARGUMENTS)

# Tests avec Valgrind
test_valgrind: $(TEST_BIN)
	@printf "$(YELLOW)Lancement des tests avec Valgrind...\n$(RESET)"
	valgrind $(VALGRIND_FLAGS) ./$(TEST_BIN) $(TEST_ARGUMENTS)

# Tests avec LLDB
test_lldb: $(TEST_BIN)
	@printf "$(YELLOW)Lancement des tests avec LLDB...\n$(RESET)"
	lldb $(LLDB_FLAGS) ./$(TEST_BIN) -- $(TEST_ARGUMENTS)

# ============================================================================ #
#        Règles pour le programme principal                                      #
# ============================================================================ #

# Exécuter le programme principal
run: $(NAME)
	@printf "$(YELLOW)Lancement de $(NAME)...\n$(RESET)"
	@./$(NAME) $(MAIN_ARGUMENTS)

# Exécuter le programme principal avec Valgrind
main_valgrind: $(NAME)
	@printf "$(YELLOW)Lancement de $(NAME) avec Valgrind...\n$(RESET)"
	valgrind $(VALGRIND_FLAGS) ./$(NAME) $(MAIN_ARGUMENTS)

# Exécuter le programme principal avec LLDB
main_lldb: $(NAME)
	@printf "$(YELLOW)Lancement de $(NAME) avec LLDB...\n$(RESET)"
	lldb $(LLDB_FLAGS) ./$(NAME) -- $(MAIN_ARGUMENTS)

# ============================================================================ #
#        Messages                                                              #
# ============================================================================ #

msg_comp:
	@printf "$(YELLOW)Compilation de $(NAME)... [$(CFLAGS)]\n$(RESET)"

msg_clean:
	@printf "$(YELLOW)Suppression des fichiers objets...\n$(RESET)"

msg_fclean:
	@printf "$(YELLOW)Suppression de $(NAME) et des tests...\n$(RESET)"

# ============================================================================ #
#        Cibles phony                                                          #
# ============================================================================ #

.PHONY: all clean fclean re test test_valgrind test_lldb run main_valgrind main_lldb msg_comp msg_clean msg_fclean
