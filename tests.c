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
    arbre_t arbre = arbre_initialiser();
    TEST_CHECK(arbre == NULL);

    arbre = arbre_creer_noeud();
    TEST_CHECK(arbre != NULL);
    TEST_CHECK(arbre->vertical == NULL);
    TEST_CHECK(arbre->horizontal == NULL);

    arbre_inserer_content_noeud(arbre, 'a');
    TEST_CHECK(arbre->content == 'a');

    arbre->vertical = arbre_creer_noeud();
    TEST_CHECK(arbre->vertical != NULL);

    arbre->horizontal = arbre_creer_noeud();
    TEST_CHECK(arbre->horizontal != NULL);

    arbre_inserer_content_noeud(arbre_lien_vertical(arbre), 'c');
    TEST_CHECK(arbre_lien_vertical(arbre)->content == 'c');

    arbre_inserer_content_noeud(arbre_lien_horizontal(arbre), 'u');
    TEST_CHECK(arbre_lien_horizontal(arbre)->content == 'u');
}

void test_recherchePrec()
{
    arbre_t arbre = arbre_creer_noeud();
    arbre_t arbreNull = NULL;
    arbre_t * result = NULL;
    bool found;

    arbre_inserer_content_noeud(arbre, 'a');

    arbre->horizontal = arbre_creer_noeud();
    arbre->horizontal->horizontal = arbre_creer_noeud();

    arbre_inserer_content_noeud(arbre_lien_horizontal(arbre), 'c');
    arbre_inserer_content_noeud(arbre_lien_horizontal(arbre_lien_horizontal(arbre)), 'd');

    result = dico_recherche_prec(&arbre, 'b', &found);
    TEST_CHECK(found == false);
    TEST_CHECK(result == &(arbre->horizontal));

    result = dico_recherche_prec(&arbre, 'B', &found);
    TEST_CHECK(found == false);
    TEST_CHECK(result == &(arbre->horizontal));

    result = dico_recherche_prec(&arbre, 'a', &found);
    TEST_CHECK(found == true);
    TEST_CHECK(result == &arbre);

    result = dico_recherche_prec(&arbre, 'A', &found);
    TEST_CHECK(found == true);
    TEST_CHECK(result == &arbre);

    result = dico_recherche_prec(&arbre, 'd', &found);
    TEST_CHECK(found == true);
    TEST_CHECK(result == &(arbre->horizontal->horizontal));

    result = dico_recherche_prec(&arbre, 'f', &found);
    TEST_CHECK(found == false);
    TEST_CHECK(result == &(arbre->horizontal->horizontal->horizontal));

    result = dico_recherche_prec(&arbreNull, 'k', &found);
    TEST_CHECK(found == false);
    TEST_CHECK(result == &arbreNull);

}

void test_InsererMot()
{
    arbre_t arbre = arbre_initialiser();

   // dico_inserer_mot(&arbre, "abat");
    //dico_inserer_mot(&arbre, "bite");
    //dico_inserer_mot(&arbre, "balle");

    char * mot = "abaz";
    char * mot2 = "abef";
    char * mot3 = "aba";
    char * mot4 = "eftg";

    dico_inserer_mot(&arbre, mot);
    TEST_CHECK(arbre->content == 'a');
    TEST_CHECK(arbre->vertical->content == 'b');
    TEST_CHECK(arbre->vertical->vertical->content == 'a');
    TEST_CHECK(arbre->vertical->vertical->vertical->content == 'Z');

    dico_inserer_mot(&arbre, mot2);
    TEST_CHECK(arbre->content == 'a');
    TEST_CHECK(arbre->vertical->content == 'b');
    TEST_CHECK(arbre->vertical->vertical->content == 'a');
    TEST_CHECK(arbre->vertical->vertical->horizontal->content == 'e');
    TEST_CHECK(arbre->vertical->vertical->horizontal->vertical->content == 'F');

    dico_inserer_mot(&arbre, mot3);
    TEST_CHECK(arbre->vertical->vertical->content == 'A');

    dico_inserer_mot(&arbre, mot4);
    TEST_CHECK(arbre->horizontal->content == 'e');
    TEST_CHECK(arbre->horizontal->vertical->content == 'f');
    TEST_CHECK(arbre->horizontal->vertical->vertical->content == 't');
    TEST_CHECK(arbre->horizontal->vertical->vertical->vertical->content == 'G');
}

void test_AfficherArbre()
{
    arbre_t arbre = arbre_initialiser();

    dico_inserer_mot(&arbre, "abat");
    dico_inserer_mot(&arbre, "art");
    dico_inserer_mot(&arbre, "arts");
    dico_inserer_mot(&arbre, "abim");
    dico_inserer_mot(&arbre, "abime");
    dico_inserer_mot(&arbre, "bisous");

    dico_afficher_prefix(arbre, "");
}

void test_ChargerDico()
{
    char * path = "../list.dat";
    arbre_t arbre = arbre_initialiser();

    dico_charger(&arbre, path);
    dico_afficher_prefix(arbre, "");
}

void test_RechercheMot()
{
    arbre_t arbre = arbre_initialiser();
    dico_charger(&arbre, "../list.dat");

    puts("Recherche de a :");
    dico_recherche_mot(arbre, "a");

    puts("Recherche de bi :");
    dico_recherche_mot(arbre, "bi");

    puts("Recherche de c :");
    dico_recherche_mot(arbre, "c");
}
