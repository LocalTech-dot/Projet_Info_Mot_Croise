//
// Created by Max Vaillant on 22/05/2026.
//

#ifndef MOT_CROISE_GRILLE_H
#define MOT_CROISE_GRILLE_H

// A savoir: g...grille    r....lignes  c....collones   car....caractere

grille *grille_crée(int lignes, int colns);

void grille_liberer(Grille *g);

void grille_afficher(const Grille *g);

//remplit  cases vides avec lettres aléatoires.
void grille_remplir_aleatoire(Grille *g);

//retourne le caractere a la position (r,c) r:lignes c: colonnes
char grille_get(const Grille *g, int r, int c);

//écrit un caractère à la position r,c     || car: "caractere"
void grille_set(Grille *g, int r, int c, char car);

int grille_position_valide(const Grille *g, int r, int c);

#endif //MOT_CROISE_GRILLE_H
