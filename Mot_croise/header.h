#ifndef MOT_CROISE_HEADER_H
#define MOT_CROISE_HEADER_H
#define MAX_MOTS 15
#define MAX_LONGUEUR 17

typedef enum {
    MENU,
    PARTIE,
    SCORE
} etat;

typedef struct {
    int nb_lignes;
    int nb_colonnes;
} size;

typedef struct {
    char liste_mots[MAX_MOTS][MAX_LONGUEUR];
    int nb_mots;
}liste_mots;

etat affichage_menu();
etat quitter_menu();
size ask_size();
void affichage_grille();



#endif //MOT_CROISE_HEADER_H
