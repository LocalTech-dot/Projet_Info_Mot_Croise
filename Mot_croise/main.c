#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "header.h"
#include "grille.h"

int main() {
    srand(time(NULL));
    etat etat_jeux = MENU;
    do {
        etat_jeux = affichage_menu();
    }while (etat_jeux == MENU);


     affichage_grille();


    return 0;
}
