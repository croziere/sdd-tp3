
#include "arbre.h"
#include "dico.h"

int main() {
    arbre_t arbre = initialiserArbre();
    chargerDico(&arbre, "../list.dat");
    afficherArbre(arbre);
    libererArbre(arbre);
    return 0;
}
