#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"
#include "header.h"
#include "dictionnaire.h"

int max_mots_partie(int lignes, int colonnes) {
    int max_mots = (lignes * colonnes) / 12;

    if (max_mots > MAX_MOTS) {
        max_mots = MAX_MOTS;
    }
    return max_mots;
}


