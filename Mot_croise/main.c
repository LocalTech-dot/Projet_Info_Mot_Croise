#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "header.h"
#include "score.h"
#include "jeux.h"

int main() {
    srand(time(NULL));
    liste_mots mon_dictionnaire;//déclaration nécessaire pour le bon fonctionnement de la fonction recherche
    etat etat_jeux = MENU;

    while (1) {
        etat_jeux = affichage_menu(); // On redemande le menu à chaque tour

        if (etat_jeux == PARTIE) {
            printf("\n--- INITIALISATION DU MOTEUR MATRICIEL ---\n");
            jeux();
        }
        else if (etat_jeux == SCORE) {
            printf("\n--- AFFICHAGE DU TABLEAU DE SCORE ---\n");
            affichage_score();
        }
        else if (etat_jeux == 3) {
            printf("\nFermeture du programme...\n");
            break;
        }
    }
    return 0;
}
