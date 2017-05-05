#include <stdlib.h>
#include "arbre.h"

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
