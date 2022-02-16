#include "biblioH.h"
#include "biblioLC.h"

int fonctionClef(char *auteur)
{
    int length = strlen(auteur);
    int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
    }
    //     hash_value = hash_value % TABLE_SIZE;
    return hash_value;
}

LivreH *creer livre(int num, char *titre, char *auteur)
{
    LivreH *livre;
    livre = (LivreH)malloc(sizeof(LivreH));
    livre->clef = fonctionClef(auteur);
    livre->num = strdup(num);
    livre->titre = strdup(titre);
    livre->auteur = strdup(auteur);
    livre->suivant = NULL;
}

void liberer livre(LivreH *l)
{
    if (l == NULL)
        return;
    free(l->titre);
    free(l->auteur);
    free(l);
}

BiblioH *creer biblio(int m)
{
    BiblioH *biblio;
    LivreH *hash_table = malloc(sizeof(LivreH) * m);

    biblio = (BiblioH)malloc(sizeof(BiblioH));

    biblio->nE = 0;
    biblio->m = m;
    biblio->(*T) = &hash_table;
}