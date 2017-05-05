#ifndef TP3_ARBRE_H
#define TP3_ARBRE_H

#include "helpers.h"

typedef char arbre_content_t;

typedef struct arbre {
    arbre_content_t content;
    struct arbre * vertical;
    struct arbre * horizontal;
}noeud_t, *arbre_t;

void insererContent(arbre_t, arbre_content_t);
arbre_t lienVertical(arbre_t);
arbre_t lienHorizontal(arbre_t);
arbre_t initialiserArbre();
noeud_t * creerNoeud();

#endif
