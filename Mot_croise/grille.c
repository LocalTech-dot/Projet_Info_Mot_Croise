//
// Created by Max Vaillant on 22/05/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"
#include "header.h"

void initialiser_grille(int lignes, int colonnes, char plateau[16][16]) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            plateau[i][j] = ' ';
        }
    }
}