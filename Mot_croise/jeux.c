#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"
#include "header.h"
#include "jeux.h"
#include <time.h>

int ask_time(){
    int resp;
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
    int trouve;
    int masque[16][16];
    char resp;
    char mot_saisi[50];
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
            masque[i][j] = 0;
        }
    }
    int minutes = ask_time();
    time_t temps_debut = time(NULL);
    time_t temps_fin = temps_debut + (minutes * 60);
    config_grille(dim, &mon_dictionnaire, grille);

    while (time(NULL) < temps_fin) {
        trouve = 0;
        affichage_grille(dim.nb_lignes, dim.nb_colonnes, grille, masque);
        printf("\n");
        printf("Veuillez saisir le mot trouvé :...\n");
        scanf("%s", mot_saisi);
        if (verifier_mots(dim.nb_lignes, dim.nb_colonnes, grille, masque, mot_saisi)) {
            for (int i = 0; i < mon_dictionnaire.nb_mots; i++) {
                if (strcmp(mon_dictionnaire.mots_choisie[i],mot_saisi) == 0){
                    trouve = 1;
                    mon_dictionnaire.mots_choisie[i][0] = '\0';
                    break;
                }

            }
            if (trouve) {
                score++;
            }else {
                score += 5;
            }
        }
    }
}