
#include <stdio.h>
#include "arbre.h"
#include "dico.h"

int main() {
    arbre_t     arbre = arbre_initialiser();

    /* Chargement du dictionnaire */
    dico_charger(&arbre, "list.dat");
    dico_afficher(arbre);
    puts("");
    dico_recherche_mot(arbre, "ardu");
    arbre_liberer(arbre);

    return 0;
}
