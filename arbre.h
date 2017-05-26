#ifndef TP3_ARBRE_H
#define TP3_ARBRE_H

#include "helpers.h"

typedef char arbre_content_t;

typedef struct arbre {
    arbre_content_t     content;
    struct arbre      * vertical;
    struct arbre      * horizontal;
}noeud_t, *arbre_t;

void        arbre_inserer_content_noeud(arbre_t, arbre_content_t);
arbre_t     arbre_lien_vertical(arbre_t);
arbre_t     arbre_lien_horizontal(arbre_t);
arbre_t     arbre_initialiser();
noeud_t   * arbre_creer_noeud();
void        arbre_liberer(arbre_t);

#endif
