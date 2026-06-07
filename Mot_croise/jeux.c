#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "grille.h"
#include "header.h"
#include "jeux.h"
#include "score.h"
#include <math.h>


int ask_time(){
    int resp;
    do {
        printf("En combien de minutes souhaiter vous tenter votre chance ?\n");
        printf("----------------------------------------------------------\n");
        printf("----------1------------------2----------------3-----------\n");
        scanf("%d", &resp);
        if (resp != 1 && resp != 2 && resp != 3) {
            printf("Erreur de saisie. Veuillez repondre par 1 2 ou 3\n");
        }
    } while (resp != 1 && resp != 2 && resp != 3);
    return resp;
}
etat jeux() {
    int score = 0;
    int trouve;
    int masque[16][16];
    char resp;
    char mot_saisi[50];
    char grille[16][16];
    char name [50];
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
    bool diagonale = config_grille(dim, &mon_dictionnaire, grille);

    while (time(NULL) < temps_fin) {
        affichage_grille(dim.nb_lignes, dim.nb_colonnes, grille, masque);
        printf("\nTemps restant : %ld secondes ", temps_fin - time(NULL));
        printf("Veuillez saisir le mot trouve : ");
        scanf("%s", mot_saisi);
        if (time(NULL) >= temps_fin) {
            printf("\nLe temps est ecoule, saisie invalidee !\n");
            break;
        }
        for (int k = 0; mot_saisi[k] != '\0'; k++) {
            mot_saisi[k] = toupper(mot_saisi[k]);
        }
        int mot_valide = 0;
        int points_a_gagner = 0;
        for (int i = 0; i < mon_dictionnaire.nb_mots; i++) {

            // On crée une copie du mot généré pour le comparer
            char mot_propre[50];
            int idx = 0;
            for (int k = 0; mon_dictionnaire.mots_choisie[i][k] != '\0'; k++) {
                // On ignore les retours à la ligne invisibles (\n et \r)
                if (mon_dictionnaire.mots_choisie[i][k] != '\n' && mon_dictionnaire.mots_choisie[i][k] != '\r') {
                    // On force en majuscule
                    mot_propre[idx] = toupper(mon_dictionnaire.mots_choisie[i][k]);
                    idx++;
                }
            }
            mot_propre[idx] = '\0';

            if (strcmp(mot_propre, mot_saisi) == 0) {
                mot_valide = 1;
                mon_dictionnaire.mots_choisie[i][0] = '\0';
                break;
            }
        }
        if (mot_valide == 0) {
            FILE *fichier_dico = fopen("dico.txt", "r");
            if (fichier_dico != NULL) {
                char mot_lu[50];
                while (fscanf(fichier_dico, "%49s", mot_lu) == 1) {
                    // On met en majuscule  pour comparer
                    for (int k = 0; mot_lu[k] != '\0'; k++) {
                        mot_lu[k] = toupper(mot_lu[k]);
                    }
                    if (strcmp(mot_lu, mot_saisi) == 0) {
                        mot_valide = 1;

                        break;
                    }
                }
                fclose(fichier_dico);
            } else {
                printf("\nErreur systeme : Impossible d'ouvrir dico.txt\n");
            }
        }
        if (mot_valide == 1) {
            if (verifier_mots(dim.nb_lignes, dim.nb_colonnes, grille, masque, mot_saisi)) {
                int longueur = strlen(mot_saisi);
                float points_gagnes = pow((float)longueur, 4.0/3.0);
                score += (int)points_gagnes;

                printf("\nMot valide et trouve ! \n");
            } else {
                printf("\nCe mot existe, mais il n'est pas dans la grille !\n");
            }
        } else {
            printf("\nCe mot n'existe pas ou a deja ete trouve.\n");
        }
    }

    printf("\n--- FIN DE LA PARTIE ---\n");
    printf("Le temps est ecoule\n");

    printf("Veuillez saisir votre nom pour sauvegarder la partie");
    scanf(" %s", name);

    save(name, dim.nb_lignes,dim.nb_colonnes,minutes, score, diagonale);
    return MENU;
}