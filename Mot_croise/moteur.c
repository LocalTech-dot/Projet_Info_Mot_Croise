#include <stdlib.h>
#include <stdio.h>
#include "header.h"

etat affichage_menu() {
    int selection_menu;

    do {
        printf("---------------------------------------------\n");
        printf("Muito Prazer, Bienvenue dans les Mots Melees de Max et Lucien\n");
        printf("---------------------------------------------\n");
        printf("1 -- Lancer une partie\n");
        printf("2 -- Afficher le tableau des scores\n");
        printf("3 -- Quitter\n");
        printf("---------------------------------------------\n");
        printf("Presser le numero correspondant a votre action :\n");

        scanf("%d", &selection_menu);

        if (selection_menu < 1 || selection_menu > 3) {
            printf("\n---------------------------------------------\n");
            printf("Erreur, Veuillez lire la consigne\n");
            printf("---------------------------------------------\n\n");
        }

    } while (selection_menu < 1 || selection_menu > 3);

    if (selection_menu == 1) {
        return PARTIE;
    }
    if (selection_menu == 2) {
        return SCORE;
    }

    return quitter_menu();
}

etat quitter_menu() {
    char rep_quit;
    do {
        printf("Etes vous sur de vouloir quitter notre super Jeux ? Y/N : ");
        scanf(" %c", &rep_quit);

        if (rep_quit == 'Y') {
            exit(0);
        }
        if (rep_quit == 'N') {
            return MENU;
        }
    } while (rep_quit != 'Y' && rep_quit != 'N');
    return MENU;
}