
#include <stdlib.h>
#include <stdio.h>
#include "pile.h"
#include "helpers.h"

Pile pile_initialiser(int taille)
{
    Pile p = NULL;
    p = (Pile)malloc(sizeof(pile_t));

    p->max = taille;
    p->size = 0;

    p->data = (pile_data_t *)malloc(sizeof(pile_data_t) * taille);

    return p;
}

void pile_liberer(Pile p)
{
    free(p->data);
    free(p);
}

void pile_empiler(Pile p, pile_data_t val){
    p->data[p->size] = val;
    p->size++;
}
pile_data_t pile_depiler(Pile p)
{
    p->size--;
    return p->data[p->size];
}

pile_data_t pile_sommet(Pile p)
{
    return p->data[p->size - 1];
}

int pile_est_vide(Pile p)
{
    return (p->size <= 0);
}

int pile_est_pleine(Pile p)
{
    return (p->size >= p->max);
}

void pile_afficher_pile(Pile p)
{
    puts("-- Debug Pile --");
    printf("\tSize %d - Max : %d\n", p->size, p->max);
    printf("\tData : ");
    int i;
    for(i=0;i < p->size; i++)
    {
        printf("%p ", p->data[i]);
    }
    printf("<= Head\n");
}
