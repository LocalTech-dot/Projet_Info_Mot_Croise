#ifndef MOT_CROISE_HEADER_H
#define MOT_CROISE_HEADER_H
#define MAX_MOTS 15
#define MAX_LONGUEUR 17

typedef enum {
    MENU,
    PARTIE,
    SCORE
} etat;

typedef enum {
    FALSE,
    TRUE
} diagonale;

typedef struct {
    int nb_lignes;
    int nb_colonnes;
} size;

typedef struct {
    char mots_choisie[MAX_MOTS][MAX_LONGUEUR];
    int nb_mots;
}liste_mots;

etat affichage_menu();
etat quitter_menu();
size ask_size();
void config_grille(size dim, liste_mots *dico, char plateau_de_jeu[16][16]);
diagonale ask_diag();
int verifier_mots(int lignes, int colonnes, char plateau_de_jeu[16][16], int masque[16][16], char mot_saisi[50]);



#endif //MOT_CROISE_HEADER_H
