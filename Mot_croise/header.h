#ifndef MOT_CROISE_HEADER_H
#define MOT_CROISE_HEADER_H

typedef enum {
    MENU,
    PARTIE,
    SCORE
} etat;

typedef struct {
    nb_lignes;
    nb_colonnes;
} size;

etat affichage_menu();
etat quitter_menu();
size ask_size();
void affichage_grille();

#endif //MOT_CROISE_HEADER_H
