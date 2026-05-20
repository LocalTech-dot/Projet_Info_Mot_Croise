#include <stdlib.h>
#include <stdio.h>
#include "header.h"

void affichage_menu (etat etat_jeux) {
    int selection_menu;
    do {
        debut_menu :
        printf("---------------------------------------------\n");
        printf("Muito Prazer, Bienvenue dans le Mot Melees de Max et Lucien\n");
        printf("---------------------------------------------\n");
        printf("1 -- Lancer une partie\n");
        printf("2 -- Afficher le tableau des scores\n");
        printf("3 -- Quitter\n");
        printf("---------------------------------------------\n");
        printf("Presser le numero correspondant a votre action :\n");
        scanf("%d", &selection_menu);

        if (selection_menu < 1 || selection_menu > 3) {
            printf("\n");
            printf("---------------------------------------------\n");
            printf("Erreur, Veuillez lire la consigne\n");
            printf("---------------------------------------------\n");
            printf("\n");

        }
        if (selection_menu == 1) {
            etat_jeux = PARTIE;
        }
        if (selection_menu == 2) {
            etat_jeux = SCORE;
        }
        if (selection_menu == 3) {
            char rep_quit;

            do {
                printf("etes vous sur de vouloir quitter notre super Jeux ? Y/N");
                scanf("%c", &rep_quit);
                if (rep_quit == 'Y') {
                    return 0;
                }
                if (rep_quit == 'N') {
                    goto debut_menu;
                }
            }while ((rep_quit != 'Y')&&(rep_quit != 'N'));
        }
    }while (selection_menu < 1 || selection_menu > 3);

}