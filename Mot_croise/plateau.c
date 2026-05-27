#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plateau.h"
#include "header.h"
#include <stdbool.h>

void initialiser_plateau(int lignes, int colonnes, char grille[16][16]) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            grille[i][j] = ' ';
        }
    }
}

bool verifier_placement(char plateau[16][16], char* mot, int x_depart, int y_depart, int dx, int dy, int nb_lignes, int nb_colonnes) {
    int longueur = strlen(mot);

    for (int i = 0; i < longueur; ++i) {
        // Calcul coordonnée de la lettre actuelle
        int pos_x = x_depart + (i*dx);
        int pos_y = y_depart + (i*dy);
        //Est-ce que cette coordonnée sort du tableau
        if (pos_x < 0 || pos_x >= nb_colonnes || pos_y < 0 || pos_y >= nb_lignes) {
            return 0;
        }
        //verification de la collision avec un autre lettre
        char case_actuelle = plateau[pos_y][pos_x];
        if (case_actuelle != ' ' && case_actuelle != mot[i]) {
            return 0;
        }
    }
    return 1;
}

void placer_mot(char plateau[16][16], char* mot, int x_depart, int y_depart, int dx, int dy) {
    int longueur = strlen(mot);

    for (int i = 0; i < longueur; i++) {

        int pos_x = x_depart + (i * dx);
        int pos_y = y_depart + (i * dy);

        plateau[pos_y][pos_x] = mot[i];  // meme boucle sauf qu'on place la lettre a dans la case
    }
}
//remplie le tableau avec des lettres aléatoires
void bruitage_grille(int lignes, int colonnes, char plateau[16][16]) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            if (plateau[i][j] == ' ') {
                // Génération d'une lettre entre 'a' et 'z'
                plateau[i][j] = 'a' + (rand() % 26);
            }
        }
    }
}

void affichage_grille(int lignes, int colonnes, char plateau[16][16]) {
    printf("\n");

    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            // Affichage de la lettre
            printf("%c ", plateau[i][j]);
        }
        // Retour  à la fin de la ligne
        printf("\n");
    }
    printf("\n");
}