#include <stdio.h>
#include <stdlib.h>
#include "score.h"
#include "header.h"

void save(char name[], int lignes, int colonnes, int temps, int score, int diag) {
    FILE*score_file = fopen("score.txt", "a");

    if (score_file == NULL) {
        printf("La table des scores est introuvable.\n");
        return;
    }

    fprintf(score_file, "%s %d %d %d %d %d\n", name, lignes, colonnes, temps, score, diag);

    fclose(score_file);
}
etat affichage_score() {
    FILE *score_file = fopen("score.txt", "r");
    if (score_file == NULL) {
        printf("Aucun historique de score disponible.\n");
        return MENU;
    }
    printf("Joueur | Nb Lignes | Nb Colonnes | Minutes | Score | Diagonale autorisé |\n");

    char nom[50];
    int l, c, t, s, diag;

    while (fscanf(score_file, "%49s %d %d %d %d %d", nom, &l, &c, &t, &s, &diag) == 6) {
        printf("| %-10s | %2dx%-2d | %2dm  | %4d | %-5s |\n", nom, l, c, t, s, diag ? "Oui" : "Non");
    }
    fclose(score_file);
    return MENU;
}