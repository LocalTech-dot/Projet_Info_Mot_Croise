#ifndef MOT_CROISE_HEADER_H
#define MOT_CROISE_HEADER_H

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
    int lignes;
    int colns;
    char **cases;  //les deux pointeurs ça correspond a r c, soit lignes et collones, ya deux adresses a prendre en compte ducoup
}Grille;

etat affichage_menu();
etat quitter_menu();
size ask_size();
void affichage_grille();



#endif //MOT_CROISE_HEADER_H
