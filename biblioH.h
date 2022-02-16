#ifndef _BIBLIO_H_
#define _BIBLIO_H_
#define TABLE_SIZE 10

typedef struct livreh
{
    int clef;
    int num;
    char *titre;
    char *auteur;
    struct livreh *suivant;
} LivreH;

typedef struct table
{
    int nE;     /*nombre d’elements contenus dans la table de hachage */
    int m;      /*taille de la table de hachage */
    LivreH **T; /*table de hachage avec resolution des collisions par chainage */
} BiblioH;

int fonctionClef(char *auteur);
LivreH *creer livre(int num, char *titre, char *auteur);
void liberer livre(LivreH *l);
BiblioH *creer biblio(int m);
#endif