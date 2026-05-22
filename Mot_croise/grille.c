#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"
#include "header.h"

void placer_mot(char plateau[16][16], char* mot, int x_depart, int y_depart, int dx, int dy, int nb_lignes, int nb_colonnes) {

    int longeur = strlen(mot);

    for (int i = 0; i < longeur; ++i) {
        int pos_x = x_depart + (i*dx);
        int pos_y = y_depart + (i*dy);
        if (pos_x < 0 || pos_x >= nb_colonnes || pos_y < 0 || pos_y >= nb_lignes) {
            return 0;
        }
    }
}


