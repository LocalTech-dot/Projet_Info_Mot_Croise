#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "header.h"
#include <string.h>

#include "grille.h"
#include "jeux.h"

int main() {
    srand(time(NULL));

    liste_mots mon_dictionnaire;//déclaration nécessaire pour le bon fonctionnement de la fonction recherche
    etat etat_jeux = MENU;

    do {
        etat_jeux = affichage_menu();

        if (etat_jeux == PARTIE) {
            printf("\n--- INITIALISATION DU MOTEUR MATRICIEL ---\n");

            jeux();
        }

    } while (etat_jeux == MENU);




    return 0;
}
