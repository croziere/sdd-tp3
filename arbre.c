#include <stdlib.h>
#include "arbre.h"
#include "pile.h"

void arbre_inserer_content_noeud(arbre_t arbre, arbre_content_t content)
{
    arbre->content = content;
}

arbre_t arbre_lien_vertical(arbre_t arbre)
{
    return arbre->vertical;
}

arbre_t arbre_lien_horizontal(arbre_t arbre)
{
    return arbre->horizontal;
}

arbre_t arbre_initialiser()
{
    return NULL;
}

noeud_t * arbre_creer_noeud()
{
    noeud_t    * arbre;
    arbre = (arbre_t)malloc(sizeof(noeud_t));

    if (arbre != NULL)
    {
        arbre->horizontal = NULL;
        arbre->vertical = NULL;
    }

    return arbre;
}

void arbre_liberer(arbre_t arbre)
{
    arbre_t     cur = arbre;
    arbre_t     temp = NULL;
    Pile    p = pile_initialiser(100);

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


