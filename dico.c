#include "dico.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include "pile.h"

arbre_t *recherchePrec(arbre_t *arbre, arbre_content_t value, bool *found) {
    *found = false;
    arbre_t cur = *arbre;
    arbre_t * prec = arbre;

    while (cur != NULL && tolower(cur->content) < tolower(value))
    {
        prec = &(cur->horizontal);
        cur = cur->horizontal;
    }

    if (cur != NULL && tolower(cur->content) == tolower(value))
    {
        *found = true;
    }

    return prec;
}

void insererMot(arbre_t *arbre, char *mot) {
    char * car = mot;
    arbre_t cur = *arbre;
    arbre_t *prec = arbre;
    bool found = true;

    while (*car && found)
    {
        prec = recherchePrec(prec, *car, &found);
        cur = (*prec);
        if (found)
        {
            prec = &(cur->vertical);
            car++;
        }
    }

    if (!*car)
    {

        insererContent(cur, (arbre_content_t) toupper(cur->content));
    }
    else
    {
        insererMotDirect(prec, car);
    }
}

void insererMotDirect(arbre_t *prec, char *value) {
    noeud_t * noeud = NULL;

    noeud = creerNoeud();
    insererContent(noeud, *value);
    noeud->horizontal = *prec;
    *prec = noeud;
    prec = &(noeud->vertical);
    value++;

    while (*value)
    {
        noeud = creerNoeud();
        insererContent(noeud, *value);
        noeud->vertical = *prec;
        *prec = noeud;
        prec = &(noeud->vertical);
        value++;
    }

    insererContent(noeud, (arbre_content_t)toupper(noeud->content));
}

void afficherArbre(arbre_t arbre)
{
    afficher(arbre, "");
}

void afficher(arbre_t arbre, const char * motif) {
    Pile prefixe = pile_initialiser(200);
    Pile chemin = pile_initialiser(200);

    arbre_t cour = arbre;

    char * cour_prefix;
    char * buf;

    cour_prefix = (char *)malloc(sizeof(char)*30);

    while (cour != NULL || !pile_est_vide(chemin))
    {
        *cour_prefix = '\0';

        if (cour == NULL)
        {
            cour = pile_depiler(chemin);
        }

        if (cour->horizontal == NULL)
        {
            if (!pile_est_vide(prefixe))
            {
                buf = pile_depiler(prefixe);
                strcpy(cour_prefix, buf);
                free(buf);
            }
        }
        else
        {
            if (!pile_est_vide(prefixe))
            {
                buf = pile_sommet(prefixe);
                strcpy(cour_prefix, buf);
            }
            pile_empiler(chemin, cour->horizontal);
        }

        if (cour->vertical != NULL)
        {
            asprintf(&buf, "%s%c", cour_prefix, tolower(cour->content));
            pile_empiler(prefixe, buf);
        }

        if (isupper(cour->content))
        {
            printf("%s%s%c\n", motif, cour_prefix, tolower(cour->content));
        }

        cour = cour->vertical;
    }

    pile_liberer(prefixe);
    pile_liberer(chemin);
    free(cour_prefix);
}

void rechercheMot(arbre_t arbre, char *mot)
{
    arbre_t * prec = &arbre;
    char * car = mot;
    bool found = true;

    while (*car && found)
    {
        prec = recherchePrec(prec, *car, &found);
        if (found)
        {
            prec = &((*prec)->vertical);
            car++;
        }
    }

    if (*car)
    {
        puts("Aucun mot avec ce motif");
    }
    else
    {
        afficher(*prec, mot);
    }
}

void chargerDico(arbre_t * arbre, const char * path)
{
    FILE *stream;
    char buf[100];

    stream = fopen(path, "r");

    while (fgets(buf, 100, stream))
    {
        buf[strlen(buf) - 1] = '\0';
        insererMot(arbre, buf);
    }

    fclose(stream);
}

