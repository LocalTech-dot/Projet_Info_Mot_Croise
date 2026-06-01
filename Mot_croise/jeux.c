#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"
#include "header.h"
#include "jeux.h"
#include <time.h>

int ask_time(){
    int resp
    do {
        printf("En combien de minutes souhaiter vous tenter votre chance ?\n");
        printf("----------------------------------------------------------\n");
        printf("----------1------------------2----------------3-----------\n");
        scanf("%d", &resp);
        if (resp != '1' && resp != '2' && resp != '3') {
            printf("Erreur de saisie. Veuillez repondre par 1 2 ou 3\n");
        }
    } while (resp != '1' && resp != '2' && resp != '3');
    return resp;
}

void jeux() {
    int score = 0;
    int masque[16][16];
    char resp;
    char grille[16][16];
    size dim;
    liste_mots mon_dictionnaire;

    do {
        dim = ask_size();
        do {
            printf("Vous avez choisi de jouer dans une grille de taille %d*%d. Voulez-vous continuer ? Y/N : ", dim.nb_lignes, dim.nb_colonnes);
            scanf(" %c", &resp);
            if (resp != 'Y' && resp != 'y' && resp != 'N' && resp != 'n') {
                printf("Erreur de saisie. Veuillez repondre par Y ou N.\n");
            }
        } while (resp != 'Y' && resp != 'y' && resp != 'N' && resp != 'n');
    } while (resp == 'N' || resp == 'n');

    initialiser_grille(dim.nb_lignes, dim.nb_colonnes, grille);

    for (int i = 0; i < dim.nb_lignes; i++) {
        for (int j = 0; j < dim.nb_colonnes; j++) {
            masque[i][j] = '0';
        }
    }

    config_grille(dim, &mon_dictionnaire, grille);
}