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

# Répertoire de la bibliothèque
LIB_DIR := lib/str

# Compilateur et flags
CC := cc
CFLAGS := -Wall -Werror -Wextra -I$(INC_DIR) -g

# Sources principales
SRC := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC)) $(LIB_OBJ)

# Sources de la bibliothèque
LIB_SRC := $(wildcard $(LIB_DIR)/*.c)
LIB_OBJ := $(patsubst $(LIB_DIR)/%.c, $(OBJ_DIR)/lib/str/%.o, $(LIB_SRC))

# Objets principaux (incluant les objets de la bibliothèque)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC)) $(LIB_OBJ)

# Sources et objets de test
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ := $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/tests/%.o, $(TEST_SRC))

# Objets pour le binaire de test (excluant main.o et incluant les objets de la bibliothèque)
TEST_LINK_OBJ := $(filter-out $(OBJ_DIR)/main.o, $(OBJ)) $(TEST_OBJ)

# Flags additionnels
LDFLAGS :=
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all
LLDB_FLAGS := 

# Arguments pour l'exécution
TEST_ARGUMENTS := "2206 4 7129 923 3210"
MAIN_ARGUMENTS := "2206 4 82139 213"

# ============================================================================ #
#        Règles de compilation                                                 #
# ============================================================================ #

all: $(NAME)

$(NAME): $(OBJ) msg_comp
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@printf "$(GREEN)✔ $(NAME) créé.\n$(RESET)"

# Règle de compilation pour les objets principaux
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Règle de compilation pour les objets de la bibliothèque
$(OBJ_DIR)/lib/str/%.o: $(LIB_DIR)/%.c
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

# Règle de compilation pour les objets de test
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
	lldb $(LLDB_FLAGS) ./$(TEST_BIN) $(TEST_ARGUMENTS)

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
