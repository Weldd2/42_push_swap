#!/usr/bin/env bash

set -e

# Dossier courant = racine du projet
BASE_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
LIB_DIR="$BASE_DIR/lib"

# Fichier de dépendances principal
DEP_FILE="$BASE_DIR/dependencies.osi.json"

# Fichier temporaire pour stocker la liste de tous les modules rencontrés
TMP_MODULES_LIST=$(mktemp)

# Nettoyage en fin de script
cleanup() {
    rm -f "$TMP_MODULES_LIST"
}
trap cleanup EXIT

# Fonction pour cloner un module s'il n'existe pas déjà, puis installer ses dépendances
install_module() {
    local name="$1"
    local repo="$2"

    # Si le module est déjà marqué comme installé, on ne refait pas le travail
    if grep -q "^$name$" "$TMP_MODULES_LIST"; then
        return
    fi

    # Marquer le module comme installé
    echo "$name" >> "$TMP_MODULES_LIST"

    # Cloner le module s'il n'existe pas
    if [ ! -d "$LIB_DIR/$name" ]; then
        echo "Clonage du module $name depuis $repo..."
        mkdir -p "$LIB_DIR"
        git clone "$repo" "$LIB_DIR/$name"
    fi

    # Vérification de l'existence du module.osi.json
    local module_dep_file="$LIB_DIR/$name/module.osi.json"
    if [ -f "$module_dep_file" ]; then
        # Parcourir ses dépendances
        local dep_count=$(jq '.dependencies | length' "$module_dep_file")
        for (( i=0; i<$dep_count; i++ )); do
            local dep_name=$(jq -r ".dependencies[$i].name" "$module_dep_file")
            local dep_repo=$(jq -r ".dependencies[$i].repo" "$module_dep_file")
            install_module "$dep_name" "$dep_repo"
        done
    fi

    # Compiler le module pour générer la librairie
    # On suppose qu'un Makefile est présent dans le module et qu'un simple "make" génère lib<name>.a
    (cd "$LIB_DIR/$name" && make || true) # Le "|| true" évite de stopper si pas de makefile

    # On ne génère pas encore les flags ici, cela se fera plus tard
}

# Installer les dépendances à partir du fichier principal
main_dep_count=$(jq '.dependencies | length' "$DEP_FILE")
for (( i=0; i<$main_dep_count; i++ )); do
    dep_name=$(jq -r ".dependencies[$i].name" "$DEP_FILE")
    dep_repo=$(jq -r ".dependencies[$i].repo" "$DEP_FILE")
    install_module "$dep_name" "$dep_repo"
done
