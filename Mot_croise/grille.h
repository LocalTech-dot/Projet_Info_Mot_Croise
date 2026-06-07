#ifndef MOT_CROISE_GRILLE_H
#define MOT_CROISE_GRILLE_H

#ifndef PLATEAU_H
#define PLATEAU_H

#include <stdbool.h>

void initialiser_grille(int lignes, int colonnes, char grille[16][16]);
bool verifier_placement(char plateau[16][16], char* mot, int x_depart, int y_depart, int dx, int dy, int nb_lignes, int nb_colonnes);
void placer_mot(char plateau[16][16], char* mot, int x_depart, int y_depart, int dx, int dy);
void bruitage_grille(int lignes, int colonnes, char plateau[16][16]);
void affichage_grille(int lignes, int colonnes, char plateau[16][16], int masque[16][16]);

#endif

#endif 
