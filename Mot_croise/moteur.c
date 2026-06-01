#include <stdlib.h>
#include <string.h>
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

diagonale ask_diag() {
    char rep_diag;
    do {
        printf("Voulez-vous prendre en compte les diagonales ? (Y/N) : ");
        scanf(" %c", &rep_diag);

        if (rep_diag == 'Y' || rep_diag == 'y') {
            return TRUE;
        }
        else if (rep_diag == 'N' || rep_diag == 'n') {
            return FALSE;
        }
        else {
            printf("Erreur de saisie. Veuillez répondre par Y ou N.\n");
        }
    } while (rep_diag != 'Y' && rep_diag != 'y' && rep_diag != 'N' && rep_diag != 'n');

    return FALSE;
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

void config_grille(liste_mots *dico) {
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

    recherche(dim.nb_lignes, dim.nb_colonnes, dico);//on tire la liste de mots au hasard
    initialiser_grille(dim.nb_lignes, dim.nb_colonnes, plateau_de_jeu);

    /*printf("il y a %d mots \n", dico->nb_mots);*/

    int N;
    if (dim.nb_colonnes > dim.nb_lignes) {
        N = dim.nb_lignes;
        } else {
        N = dim.nb_colonnes;
    }//cette boucle calcule la taille minimale de la grille

    int taille_actuelle = N;

    bool diagonale = ask_diag();


    while (taille_actuelle >= 3) {//la consigne précise de ne pas placer des mots plus petits que 3

        char* mot_possible = NULL;
        int indices_candidats[MAX_MOTS];
        int nb_candidats = 0;

            for (int j = 0; j < dico->nb_mots; j++) {//on liste tous les mots de la taille actuelle et on range leurs positons dans indice_candidats
            if (strlen(dico->mots_choisie[j]) == taille_actuelle) {
                indices_candidats[nb_candidats] = j;
                nb_candidats++;
                }
            }
                if (nb_candidats > 0) {//parmis les mots d'une même taille on en choisis un au hasard
                int tirage = rand() % nb_candidats;
                int index_gagnant = indices_candidats[tirage];
                mot_possible = dico->mots_choisie[index_gagnant];
                }
            if (mot_possible == NULL) {//si pas de mots de la taille_actuelle on passe à l'itération suivante
            taille_actuelle--;
            continue;
            }

        int x_depart = rand() % dim.nb_colonnes;
        int y_depart = rand() % dim.nb_lignes;
        int dx, dy;
        do {
            dx = (rand() % 3) -1;
            dy = (rand() % 3) -1;
            if (!diagonale) {
                if (rand()%2 == 0) {
                    dx = 0;
                }else {
                    dy = 0;
                }
            }
        }while (dx == 0 && dy == 0);



        int est_valide = verifier_placement(plateau_de_jeu, mot_possible, x_depart, y_depart, dx, dy, dim.nb_lignes, dim.nb_colonnes);//test de placement

        printf("Tentative de placement : %s | Valide : %d\n", mot_possible, est_valide);


            if (est_valide) {
                placer_mot(plateau_de_jeu, mot_possible, x_depart, y_depart, dx, dy);

                    for (int j = 0; j < dico->nb_mots; j++) {//si le mot choisi est placé, on rajoute le caractère de fin de ligne pour ne plus avoir à le retirer
                        if (dico->mots_choisie[j] == mot_possible) {
                            dico->mots_choisie[j][0] = '\0';
                        break;
                        }
                    }
            }
        else{//deuxième test : voir consigne
            do {
                dx = (rand() % 3) -1;
                dy = (rand() % 3) -1;
                if (!diagonale) {
                    if (rand()%2 == 0) {
                        dx = 0;
                    }else {
                        dy = 0;
                    }
                }
            }while (dx == 0 && dy == 0);
                    int est_valide_2 = verifier_placement(plateau_de_jeu, mot_possible, x_depart, y_depart, dx, dy, dim.nb_lignes, dim.nb_colonnes);
                            if (est_valide_2) {
                                placer_mot(plateau_de_jeu, mot_possible, x_depart, y_depart, dx, dy);
                                    for (int j = 0; j < dico->nb_mots; j++) {
                                        if (dico->mots_choisie[j] == mot_possible) {
                                            dico->mots_choisie[j][0] = '\0';
                                        break;
                                        }
                                    }
                            }
                            else {
                                taille_actuelle--;
                            }
        }
    }
    //tant que le jeux n'est pas fini on met en pause le bruitage sinon c'est la street pour voir si il y a bien des mots dans le tableau
    /*bruitage_grille( dim.nb_lignes, dim.nb_colonnes, plateau_de_jeu);*/


    affichage_grille(dim.nb_lignes, dim.nb_colonnes, plateau_de_jeu);

}


