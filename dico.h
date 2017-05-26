#ifndef TP3_DICO_H
#define TP3_DICO_H

#include "arbre.h"

arbre_t   * dico_recherche_prec(arbre_t* , arbre_content_t, bool*);
void        dico_inserer_mot(arbre_t *, char *);
void        dico_inserer_mot_direct(arbre_t *, char *);
void        dico_afficher(arbre_t);
void        dico_afficher_prefix(arbre_t, const char *);
void        dico_recherche_mot(arbre_t, char *);
void        dico_charger(arbre_t *, const char *);

#endif
