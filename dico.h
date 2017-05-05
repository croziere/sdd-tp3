#ifndef TP3_DICO_H
#define TP3_DICO_H

#include "arbre.h"

arbre_t * recherchePrec(arbre_t * arbre, arbre_content_t value, bool * found);
void insererMot(arbre_t * arbre, char * mot);
void insererMotDirect(arbre_t *prec, char *value);
void afficherArbre(arbre_t);
void afficher(arbre_t arbre, const char *);
void rechercheMot(arbre_t arbre, char * mot);
void chargerDico(arbre_t*, const char *);

#endif
