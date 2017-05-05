#include <stdlib.h>
#include "arbre.h"
#include "pile.h"

void insererContent(arbre_t arbre, arbre_content_t content)
{
    arbre->content = content;
}

arbre_t lienVertical(arbre_t arbre)
{
    return arbre->vertical;
}

arbre_t lienHorizontal(arbre_t arbre)
{
    return arbre->horizontal;
}

arbre_t initialiserArbre()
{
    return NULL;
}

noeud_t * creerNoeud()
{
    noeud_t * arbre;
    arbre = (arbre_t)malloc(sizeof(noeud_t));

    if (arbre != NULL)
    {
        arbre->horizontal = NULL;
        arbre->vertical = NULL;
    }

    return arbre;
}

void libererArbre(arbre_t arbre)
{
    arbre_t cur = arbre;
    arbre_t temp = NULL;

    Pile p = pile_initialiser(100);

    while (cur != NULL || !pile_est_vide(p))
    {
        if (!cur)
        {
            cur = pile_depiler(p);
        }

        if (cur->horizontal)
        {
            pile_empiler(p, cur->horizontal);
        }

        temp = cur;
        cur = cur->vertical;

        free(temp);
    }

    pile_liberer(p);
}


