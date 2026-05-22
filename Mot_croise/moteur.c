#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#include "grille.h"
#include "dictionnaire.h"

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
            printf("Erreur, Veuillez lire la consigne, vai tomar no cu lucien do caralho\n");
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

        if (rep_quit == 'Y' || rep_quit == 'y') {
            exit(0);
        }
        if (rep_quit == 'N' || rep_quit == 'n') {
            return MENU;
        }
    } while (rep_quit != 'Y' && rep_quit != 'y' && rep_quit != 'n' && rep_quit != 'N');
    return MENU;
}

size ask_size() {
    size dim;

    do {
        printf("Veuillez entrer le nombres de lignes de votre grilles\n");
        printf("-------------Nombre attendu entre 8 et 16------------\n");
        scanf("%d", &dim.nb_lignes);
        printf("Veuillez entrer le nombres de colonnes de votre grilles\n");
        printf("-------------Nombre attendu entre 8 et 16------------\n");
        scanf("%d", &dim.nb_colonnes);

        if (dim.nb_lignes < 8 || dim.nb_colonnes < 8  || dim.nb_colonnes > 16 || dim.nb_lignes > 16) {
            printf("Erreur, veuillez bien lire la consigne");
        }

    }while (dim.nb_lignes < 8 || dim.nb_colonnes < 8  || dim.nb_colonnes > 16 || dim.nb_lignes > 16);

    return dim;
}

void affichage_grille() {
    char resp;
    char plateau_de_jeu[16][16];

    size dim;

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

    size dim_plateau = ask_size();

    initialiser_grille(dim_plateau.nb_lignes, dim_plateau.nb_colonnes, plateau_de_jeu);


}