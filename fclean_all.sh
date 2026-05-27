#!/bin/bash
# Lance "make fclean" dans tous les dossiers contenant un Makefile.
# Usage : ./fclean_all.sh [cible]   (cible = fclean par défaut, ex: clean, re)

TARGET="${1:-fclean}"
ROOT="$(cd "$(dirname "$0")" && pwd)"

GREEN='\033[0;32m'
CYAN='\033[0;36m'
YELLOW='\033[0;33m'
RESET='\033[0m'

count=0
# -not -path "$ROOT/Makefile" pour ignorer le Makefile racine (sandbox)
find "$ROOT" -name Makefile -not -path "$ROOT/Makefile" | sort | while read -r mk; do
	dir="$(dirname "$mk")"
	printf "${YELLOW}➜ make %s${RESET} dans ${CYAN}%s${RESET}\n" "$TARGET" "${dir#$ROOT/}"
	make -C "$dir" "$TARGET" 2>/dev/null
	rm -rf "$dir/.claude"
done

printf "${GREEN}✓ Terminé : '%s' exécuté partout.${RESET}\n" "$TARGET"
