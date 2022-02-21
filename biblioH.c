#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "biblioH.h"

int fonctionClef(char *auteur)
{
    int length = strlen(auteur);
    int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += auteur[i];
    }
    return hash_value;
}

<<<<<<< HEAD
LivreH *creer_livre(int num, char *titre, char *auteur)
{
    LivreH *livre = (LivreH *)malloc(sizeof(LivreH));
    assert(livre);
=======
// Create new node
LivreH *creer_livre(int num, char *titre, char *auteur)
{
    LivreH *livre;
    livre = (LivreH *)malloc(sizeof(LivreH));
>>>>>>> f3980f87c1646cb3c643da43eba52a141f289d2e
    livre->clef = fonctionClef(auteur);
    livre->num = num;
    livre->titre = strdup(titre);
    livre->auteur = strdup(auteur);
    livre->suivant = NULL;
    return livre;
}

void liberer_livre(LivreH *l)
{
    if (l == NULL)
    {
        return;
    }
    free(l->titre);
    free(l->auteur);
    free(l);
    l = NULL;
}

<<<<<<< HEAD
// a checker
BiblioH *creer_biblio(int m)
{
    BiblioH *biblio = (BiblioH *)malloc(sizeof(BiblioH));
    LivreH **hash_table = malloc(sizeof(LivreH *) * m);

=======
BiblioH *creer_biblio(int m)
{
    BiblioH *biblio;
    LivreH **hash_table;

    biblio = (BiblioH *)malloc(sizeof(BiblioH));
    hash_table = malloc(sizeof(LivreH *) * m);
>>>>>>> f3980f87c1646cb3c643da43eba52a141f289d2e
    for (int i = 0; i < m; i++)
    {
        hash_table[i] = malloc(sizeof(LivreH));
        hash_table[i] = NULL;
    }
    biblio->nE = 0;
    biblio->m = m;
    biblio->T = hash_table;
    return biblio;
}

<<<<<<< HEAD
// fuite de memoire
void liberer_biblio(BiblioH *b)
{
    if (b == NULL)
    {
        return;
    }
    if (b->T == NULL)
    {
        free(b);
        return;
    }

    LivreH **hash_table = b->T;
    LivreH *tmp;

    for (int i = 0; i < b->m; i++)
    {
        if (hash_table[i] != NULL)
        {
            while (hash_table[i] != NULL)
            {
                tmp = hash_table[i];
                hash_table[i] = hash_table[i]->suivant;
                liberer_livre(tmp);
            }
        }
    }
    // free(b);
=======
void liberer_biblio(BiblioH *b)
{
    LivreH **hash_table;
    LivreH *tmp;

    hash_table = b->T;

    if (b->T == NULL)
        free(b);
    else
    {
        for (int i = 0; i < b->m; i++)
        {
            if (*(hash_table + i) != NULL)
            {
                while (*(hash_table + i) != NULL)
                {
                    tmp = (*(hash_table + i));
                    *(hash_table + i) = (*(hash_table + i))->suivant;
                    liberer_livre(tmp);
                }
            }
        }
    }
>>>>>>> f3980f87c1646cb3c643da43eba52a141f289d2e
}

int fonctionHachage(int cle, int m)
{
<<<<<<< HEAD
    return (int)(m * (cle * NOMBRE_OR - (int)(cle * NOMBRE_OR)));
=======
    return (m * (cle * NOMBRE_OR - (int)(cle * NOMBRE_OR)));
>>>>>>> f3980f87c1646cb3c643da43eba52a141f289d2e
}

void inserer(BiblioH *b, int num, char *titre, char *auteur)
{
<<<<<<< HEAD
    LivreH *l = creer_livre(num, titre, auteur);
    int i = fonctionHachage(fonctionClef(auteur), b->m);

    if ((b->T)[i] == NULL)
    {
        (b->T)[i] = l;
    }
    else
    {
        l->suivant = (b->T)[i];
        (b->T)[i] = l;
    }
    b->nE = (b->nE) + 1;
=======
    LivreH *livre_to_insert;
    int location;

    livre_to_insert = creer_livre(num, titre, auteur);
    location = fonctionHachage(livre_to_insert->clef, b->m);
    // printf("insert at %d\n", location);
    // printf("taille hashtable %d\n", b->m);

    if ((b->T)[location] == NULL)
    {
        (b->T)[location] = livre_to_insert;
    }
    else
    {
        // else already something in this case add next
        livre_to_insert->suivant = (b->T)[location];
        (b->T)[location] = livre_to_insert;
    }
    b->nE = b->nE + 1;
>>>>>>> f3980f87c1646cb3c643da43eba52a141f289d2e
}

void affichage_livre_hashtable(LivreH *l)
{
<<<<<<< HEAD
    if (l == NULL)
    {
        return;
    }
    printf("%d %d %s %s\n", l->clef, l->num, l->titre, l->auteur);
}

// a checker mais OK
void affichage_biblio_hashtable(BiblioH *b)
{
    if (b == NULL)
    {
        return;
    }

    LivreH *l;
    for (int i = 0; i < b->m; i++)
    {
        if ((b->T)[i] != NULL) //???
        {
            l = (b->T)[i];
            while (l != NULL)
            {
                printf("Pos %d ", i);
                affichage_livre_hashtable(l);
                l = l->suivant;
=======
    // Check if need to print clef
    if (l == NULL)
        return;
    printf("%d %d %s %s\n", l->clef, l->num, l->titre, l->auteur);
}

void affichage_biblio_hashtable(BiblioH *b)
{
    // Ask question about the efficiency of hashtable
    LivreH *crawler;

    if (b == NULL)
        return;

    for (int i = 0; i < b->m; i++)
    {
        if ((b->T)[i] != NULL)
        {
            crawler = (b->T)[i];
            while (crawler != NULL)
            {
                printf("Pos %d ", i);
                affichage_livre_hashtable(crawler);
                crawler = crawler->suivant;
>>>>>>> f3980f87c1646cb3c643da43eba52a141f289d2e
            }
        }
        else
        {
<<<<<<< HEAD
            // case contenant NULL
=======
>>>>>>> f3980f87c1646cb3c643da43eba52a141f289d2e
            printf("Pos %d\t--------------\n", i);
        }
    }
}

LivreH *recherche_ouvrage_num_hashtable(BiblioH *b, int num)
{
    LivreH *tmp;

    if ((b == NULL) || (b->T == NULL))
    {
        return NULL;
    }

    for (int i = 0; i < b->m; i++)
    {
        if ((b->T)[i] != NULL)
        {
            tmp = b->T[i];
            while (tmp != NULL)
            {
                if (tmp->num == num)
                {
                    return tmp;
                }
                tmp = tmp->suivant;
            }
        }
    }
    return NULL;
}

LivreH *recherche_ouvrage_titre_hashtable(BiblioH *b, char *titre)
{
    LivreH *tmp;

    if ((b == NULL) || (b->T == NULL))
    {
        return NULL;
    }
    for (int i = 0; i < b->m; i++)
    {
        if ((b->T)[i] != NULL)
        {
            tmp = b->T[i];
            while (tmp != NULL)
            {
                if (strcmp(titre, tmp->titre) == 0)
                {
                    return tmp;
                }
                tmp = tmp->suivant;
            }
        }
    }
    return NULL;
}

BiblioH *recherche_livres_auteur_hashtable(BiblioH *b, char *auteur)
{
    BiblioH *biblio = creer_biblio(1);
    int clef = fonctionClef(auteur);
    int hash_value = fonctionHachage(clef, b->m);
<<<<<<< HEAD
    LivreH *l = (b->T)[hash_value];
=======
    LivreH *crawler = (b->T)[hash_value];
>>>>>>> f3980f87c1646cb3c643da43eba52a141f289d2e
    if (b == NULL)
    {
        return NULL;
    }
<<<<<<< HEAD
    l = (b->T)[hash_value];
    while (l)
    {
        if (clef == l->clef)
        {
            inserer(biblio, l->num, l->titre, l->auteur);
        }
        l = l->suivant;
=======
    crawler = (b->T)[hash_value];
    while (crawler)
    {
        if (clef == crawler->clef)
        {
            inserer(biblio, crawler->num, crawler->titre, crawler->auteur);
        }
        crawler = crawler->suivant;
>>>>>>> f3980f87c1646cb3c643da43eba52a141f289d2e
    }

    return biblio;
}

void supprimer_ouvrage_hashtable(BiblioH *b, int num, char *titre, char *auteur)
{
<<<<<<< HEAD
    if (b == NULL)
    {
        return;
    }
    LivreH *tmp = NULL;
    LivreH *pred = NULL;

    int position = fonctionHachage(fonctionClef(auteur), b->m);
    tmp = b->T[position];
    while (tmp && (tmp->num != num) && (strcmp(tmp->titre, titre) != 0) && (strcmp(tmp->auteur, auteur) != 0))
    {
        pred = tmp;
        tmp = tmp->suivant;
    }
    if (!pred)
    {
        b->T[position] = (b->T[position])->suivant;
        return;
    }
    else
        pred->suivant = tmp->suivant;

    liberer_livre(tmp);
=======
    int hash_value = fonctionHachage(fonctionClef(auteur), b->m);
    LivreH *n;
    LivreH *prec;
    LivreH **hash_table = (b->T);

    if (*hash_table != NULL)
    {
        prec = *(hash_table + hash_value);
        if ((prec->num == num) && (strcmp(prec->titre, titre) == 0) && (strcmp(prec->auteur, auteur) == 0))
        { // si premier
            n = prec;
            *hash_table = prec->suivant;
            liberer_livre(n);
        }
        else
        { // les autres
            n = prec->suivant;
            while (n != NULL)
            {
                if ((n->num == num) && (strcmp(n->titre, titre) == 0) && (strcmp(n->auteur, auteur) == 0))
                {
                    prec->suivant = n->suivant;
                    liberer_livre(n);
                    break;
                }
                prec = n;
                n = n->suivant;
            }
        }
    }
>>>>>>> f3980f87c1646cb3c643da43eba52a141f289d2e
}

void fusion_hashtable(BiblioH *b1, BiblioH *b2)
{
<<<<<<< HEAD
    if ((b1 == NULL) && (b2 == NULL))
    {
        return;
    }

    LivreH *tmp = NULL;
    int i;
    for (i = 0; i < b2->m; i++)
    {
        tmp = b2->T[i];
        while (tmp)
        {
            inserer(b1, tmp->num, tmp->titre, tmp->auteur);
            tmp = tmp->suivant;
        }
    }
    liberer_biblio(b2);
=======
    LivreH *livreListe;
    if ((b1 == NULL) || (b2 == NULL) || (b1->T == NULL) || (b2->T == NULL))
    {
        return;
    }
    printf("Nombre element biblio 1 %d\n", b1->nE);
    printf("Nombre element biblio 2 %d\n", b2->nE);
    printf("Nombre element biblio 1+2 theorique %d\n", b1->nE + b2->nE);

    for (int i = 0; i < b2->m; i++)
    {
        livreListe = *(b2->T + i);
        while (livreListe)
        {
            inserer(b1, livreListe->num, livreListe->titre, livreListe->auteur);
            livreListe = livreListe->suivant;
        }
    }
    liberer_biblio(b2);

    printf("Nombre element reel 1 %d\n", b1->nE);
>>>>>>> f3980f87c1646cb3c643da43eba52a141f289d2e
}

BiblioH *recherche_exemplaires_hashtable(BiblioH *b)
{
    if ((b->T == NULL) || (b->T == NULL))
    {
        return NULL;
    }
    BiblioH *biblio = creer_biblio(1);
    LivreH *livreListe;
    LivreH *precedent;
    LivreH *suivant;

    for (int i = 0; i < b->m; i++)
    {
        livreListe = *(b->T + i);
        if (livreListe)
        {
            while (livreListe->suivant)
            {
                precedent = livreListe;
                suivant = livreListe->suivant;
                if (strcmp(precedent->auteur, suivant->auteur) == 0)
                {
                    if (strcmp(precedent->titre, suivant->titre) == 0)
                    {
                        inserer(biblio, precedent->num, precedent->titre, precedent->auteur);
                    }
                }
                livreListe = livreListe->suivant;
            }
            if (strcmp(precedent->auteur, livreListe->auteur) == 0)
                if (strcmp(precedent->titre, livreListe->titre) == 0)
                    inserer(biblio, livreListe->num, livreListe->titre, livreListe->auteur);
        }
    }
    return biblio;
}