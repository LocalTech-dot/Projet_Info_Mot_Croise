#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "dictionnaire.h"

int max_mots_partie(int lignes, int colonnes) {
    int max_mots = (lignes * colonnes) / 12;

    if (max_mots > MAX_MOTS) {
        max_mots = MAX_MOTS;
    }
    return max_mots;
}
int calc_taille_mots_max(int lignes, int colonnes) {
    if (lignes > colonnes) {
        return lignes;
    } else {
        return colonnes;
    }
}
void recherche(int lignes, int colonnes, liste_mots *ma_liste) {
    int max_mots = max_mots_partie(lignes, colonnes);// ici on calcule le nombres de mots maximum que l'on pourra stocker dans la grille
    int taille_mots_max = calc_taille_mots_max(lignes, colonnes);// pareil mais avec la taille des mots pou ne pas tirer au hasard un mots trop grand pour la grille
    char buffer[256]; // tableau "tampon" destiné à stocker la valeur lue par le curseur fgets
    int nombres = 0;
    int num_lignes;
    FILE*fichier = fopen ("dico.txt","r");//ouverture du dictionnaire en mode lecture

    if (fichier == NULL) {
        printf("Le dictionnaire est introuvable, veuillez le telecharger sur Moodle.");
        return;
    }
    while (fgets(buffer, 256, fichier) != NULL) { //petite boucle pour compter le nombre de mots dans le dictionnaire
        nombres++;
    }

    ma_liste->nb_mots = rand()%max_mots;//définition d'un seuil de nombres de mots : on va chercher un nombre de mots compris entre 5 et max_mots
    if (ma_liste->nb_mots < 5) {
        ma_liste->nb_mots = 5;
    }


    for (int i = 0; i < ma_liste->nb_mots; i++) { //boucle principale de la fonction
        num_lignes = rand()%nombres; //on prend un nombre aléatoire inférieur aux nombres de mots dans le dictionnaire
        rewind(fichier);//on remonte le curseur au début du fichier
        for (int j = 0; j < num_lignes; j++) { //petite boucle rapide pour aller jusqu'a la ligne tirer au sort
            fgets(buffer, 256, fichier);
        }
        fgets(buffer, 256, fichier);//on prend le contenue de cette ligne
        buffer[strcspn(buffer, " \r\n")] = '\0';//nettoyage du mots, la fonction strcspn cherche dans buffer les caractère interdit et renvoie leur position, on à donc buffer[position caractère interdit] = \0
        if (strlen(buffer) > taille_mots_max) {//condition pour que le mots ne soit pas trop long, si c'est le cas on décrémente l'indice pour qu'au tour d'après on écrive toujours au même niveau dans la structure, sinon ca ferait un trou et on perdrais un mots
            i--;
            continue;//si on arrive ici, le programme repart au début de la boucle for, on relance l'itération en quelques sortes vu qu'avant on a i--
        }
        strcpy(ma_liste->mots_choisie[i], buffer);//en arrivant ici on a passé le test de longueur on peut donc stocker le mots qui est a la ligne tiré au hasard dans le tableau de la structure list_mots déclar dans le header
    }

    fclose(fichier);

}