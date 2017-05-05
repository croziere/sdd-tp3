#include "tests.h"
#include "cutest.h"

TEST_LIST = {
        { "Fonction d'arbres", test_ArbreFonctions },
        { "Recherche prec", test_recherchePrec },
        { "Insertion des mots", test_InsererMot },
        { "Affichage de l'arbre", test_AfficherArbre },
        { "Chargement fichier", test_ChargerDico },
        { "Recherche mot", test_RechercheMot },
        { 0 }
};

void test_ArbreFonctions() {
    arbre_t arbre = initialiserArbre();
    TEST_CHECK(arbre == NULL);

    arbre = creerNoeud();
    TEST_CHECK(arbre != NULL);
    TEST_CHECK(arbre->vertical == NULL);
    TEST_CHECK(arbre->horizontal == NULL);

    insererContent(arbre, 'a');
    TEST_CHECK(arbre->content == 'a');

    arbre->vertical = creerNoeud();
    TEST_CHECK(arbre->vertical != NULL);

    arbre->horizontal = creerNoeud();
    TEST_CHECK(arbre->horizontal != NULL);

    insererContent(lienVertical(arbre), 'c');
    TEST_CHECK(lienVertical(arbre)->content == 'c');

    insererContent(lienHorizontal(arbre), 'u');
    TEST_CHECK(lienHorizontal(arbre)->content == 'u');
}

void test_recherchePrec()
{
    arbre_t arbre = creerNoeud();
    arbre_t arbreNull = NULL;
    arbre_t * result = NULL;
    bool found;

    insererContent(arbre, 'a');

    arbre->horizontal = creerNoeud();
    arbre->horizontal->horizontal = creerNoeud();

    insererContent(lienHorizontal(arbre), 'c');
    insererContent(lienHorizontal(lienHorizontal(arbre)), 'd');

    result = recherchePrec(&arbre, 'b', &found);
    TEST_CHECK(found == false);
    TEST_CHECK(result == &(arbre->horizontal));

    result = recherchePrec(&arbre, 'B', &found);
    TEST_CHECK(found == false);
    TEST_CHECK(result == &(arbre->horizontal));

    result = recherchePrec(&arbre, 'a', &found);
    TEST_CHECK(found == true);
    TEST_CHECK(result == &arbre);

    result = recherchePrec(&arbre, 'A', &found);
    TEST_CHECK(found == true);
    TEST_CHECK(result == &arbre);

    result = recherchePrec(&arbre, 'd', &found);
    TEST_CHECK(found == true);
    TEST_CHECK(result == &(arbre->horizontal->horizontal));

    result = recherchePrec(&arbre, 'f', &found);
    TEST_CHECK(found == false);
    TEST_CHECK(result == &(arbre->horizontal->horizontal->horizontal));

    result = recherchePrec(&arbreNull, 'k', &found);
    TEST_CHECK(found == false);
    TEST_CHECK(result == &arbreNull);

}

void test_InsererMot()
{
    arbre_t arbre = initialiserArbre();

   // insererMot(&arbre, "abat");
    //insererMot(&arbre, "bite");
    //insererMot(&arbre, "balle");

    char * mot = "abaz";
    char * mot2 = "abef";
    char * mot3 = "aba";
    char * mot4 = "eftg";

    insererMot(&arbre, mot);
    TEST_CHECK(arbre->content == 'a');
    TEST_CHECK(arbre->vertical->content == 'b');
    TEST_CHECK(arbre->vertical->vertical->content == 'a');
    TEST_CHECK(arbre->vertical->vertical->vertical->content == 'Z');

    insererMot(&arbre, mot2);
    TEST_CHECK(arbre->content == 'a');
    TEST_CHECK(arbre->vertical->content == 'b');
    TEST_CHECK(arbre->vertical->vertical->content == 'a');
    TEST_CHECK(arbre->vertical->vertical->horizontal->content == 'e');
    TEST_CHECK(arbre->vertical->vertical->horizontal->vertical->content == 'F');

    insererMot(&arbre, mot3);
    TEST_CHECK(arbre->vertical->vertical->content == 'A');

    insererMot(&arbre, mot4);
    TEST_CHECK(arbre->horizontal->content == 'e');
    TEST_CHECK(arbre->horizontal->vertical->content == 'f');
    TEST_CHECK(arbre->horizontal->vertical->vertical->content == 't');
    TEST_CHECK(arbre->horizontal->vertical->vertical->vertical->content == 'G');
}

void test_AfficherArbre()
{
    arbre_t arbre = initialiserArbre();

    insererMot(&arbre, "abat");
    insererMot(&arbre, "art");
    insererMot(&arbre, "arts");
    insererMot(&arbre, "abim");
    insererMot(&arbre, "abime");
    insererMot(&arbre, "bisous");

    afficher(arbre, "");
}

void test_ChargerDico()
{
    char * path = "../list.dat";
    arbre_t arbre = initialiserArbre();

    chargerDico(&arbre, path);
    afficher(arbre, "");
}

void test_RechercheMot()
{
    arbre_t arbre = initialiserArbre();
    chargerDico(&arbre, "../list.dat");

    puts("Recherche de a :");
    rechercheMot(arbre, "a");

    puts("Recherche de bi :");
    rechercheMot(arbre, "bi");

    puts("Recherche de c :");
    rechercheMot(arbre, "c");
}
