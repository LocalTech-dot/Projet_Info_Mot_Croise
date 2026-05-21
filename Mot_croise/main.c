#include <stdlib.h>
#include <stdio.h>

#include "header.h"

int main() {

    etat etat_jeux = MENU;
    do {
        etat_jeux = affichage_menu();
    }while (etat_jeux == MENU);



    return 0;
}
