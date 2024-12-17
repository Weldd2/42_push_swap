# ============================================================================ #
#        Config variables                                                      #
# ============================================================================ #

# Nom de l'exécutable final
NAME = push_swap

# Compilateur
CC = gcc

# Répertoires
SRCDIR = src
INCDIR = include
OBJDIR = obj
LIB_DIR = lib

# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Détection automatique des répertoires d'inclusion
# Inclut le répertoire principal 'include' et tous les 'lib/*/include'
INCLUDE_DIRS = $(INCDIR) $(wildcard $(LIB_DIR)/*/include)
OSI_INCLUDE_FLAGS = $(addprefix -I, $(INCLUDE_DIRS))

# Détection automatique des fichiers sources du projet principal récursivement
SRCS = $(shell find $(SRCDIR) -type f -name '*.c')
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# Détection automatique des fichiers sources des modules récursivement
OSI_MODULE_SRCS = $(shell find $(LIB_DIR) -type f -name '*.c')
MOD_OBJS = $(patsubst $(LIB_DIR)/%.c,$(OBJDIR)/modules/%.o,$(OSI_MODULE_SRCS))

# Variables pour Valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all
TEST_ARGUMENTS = ""

# Règle par défaut
all: install_deps $(NAME)

# Règle de liaison pour créer l'exécutable
$(NAME): $(OBJS) $(MOD_OBJS)
	$(CC) $(CFLAGS) $(OSI_INCLUDE_FLAGS) $(OBJS) $(MOD_OBJS) -o $(NAME)

# Règle pour compiler les sources du projet principal récursivement
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(OSI_INCLUDE_FLAGS) -c $< -o $@

# Règle pour compiler les sources des modules récursivement
$(OBJDIR)/modules/%.o: $(LIB_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(OSI_INCLUDE_FLAGS) -c $< -o $@

# Règle pour installer les dépendances
install_deps:
	@echo "Installation des dépendances..."
	@./.install.osi.sh
	@echo "Dépendances installées."

# Règles de nettoyage
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME) osi_flags.mk

re: fclean all

# Règle Valgrind
valgrind: CFLAGS += -g
valgrind: re
	valgrind $(VALGRIND_FLAGS) ./$(NAME) $(TEST_ARGUMENTS)

# Déclaration des cibles phony
.PHONY: all clean fclean re install_deps valgrind
