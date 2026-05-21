#ifndef MOT_CROISE_HEADER_H
#define MOT_CROISE_HEADER_H

typedef enum {
    MENU,
    PARTIE,
    SCORE
} etat;

etat affichage_menu(void);
etat quitter_menu(void);

#endif //MOT_CROISE_HEADER_H
