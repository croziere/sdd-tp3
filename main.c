
#include <stdio.h>
#include "arbre.h"
#include "dico.h"

int main() {

    puts("=== TESTS ===");

    puts("-- Fichier vide :");
    arbre_t arbre1 = arbre_initialiser();
    dico_charger(&arbre1, "vide.dat");
    dico_afficher(arbre1);
    arbre_liberer(arbre1);

    puts("-- Insertion dans un arbre vide :");
    arbre1 = arbre_initialiser();
    dico_inserer_mot(&arbre1, "belle");
    dico_afficher(arbre1);

    puts("-- Insertion au début :");
    dico_inserer_mot(&arbre1, "abat");
    dico_afficher(arbre1);

    puts("-- Insertion au millier :");
    dico_inserer_mot(&arbre1, "balle");
    dico_afficher(arbre1);

    puts("-- Insertion à la fin :");
    dico_inserer_mot(&arbre1, "wagon");
    dico_afficher(arbre1);

    puts("-- Insertion d'un doublon :");
    dico_inserer_mot(&arbre1, "balle");
    dico_afficher(arbre1);

    puts("-- Insertion d'un mot plus grand :");
    dico_inserer_mot(&arbre1, "wagonnet");
    dico_afficher(arbre1);

    puts("-- Insertion d'un mot plus petit :");
    dico_inserer_mot(&arbre1, "bal");
    dico_afficher(arbre1);

    puts("-- Affichage d'arbre vide :");
    arbre_t arbre2 = arbre_initialiser();
    dico_afficher(arbre2);

    puts("-- Recherche motif existant :");
    dico_recherche_mot(arbre1, "ba");

    puts("-- Recherche motif inexistant :");
    dico_recherche_mot(arbre1, "za");

    puts("-- Recherche d'un motif egal à un mot :");
    dico_recherche_mot(arbre1, "balle");

    arbre_liberer(arbre1);
    arbre_liberer(arbre2);

    puts("=== FIN DES TESTS ===");

    return 0;
}
