#ifndef PROJECT_PILE_H
#define PROJECT_PILE_H

/// Représente le type contenu dans la pile
typedef void* pile_data_t;

/// Représente une pile
typedef struct pile
{
    int             max;
    int             size;
    pile_data_t   * data;
}pile_t, * Pile;

/// pile_initialiser
/// @brief Retourne une pile vide
///
Pile            pile_initialiser(int);

/// pile_liberer
/// @brief Libére la mémoire de la pile
///
void            pile_liberer(Pile);

/// pile_empiler
/// @brief Empile un élément
///
void            pile_empiler(Pile, pile_data_t);

/// pile_depiler
/// @brief Dépile un élément et le retourne
///
pile_data_t     pile_depiler(Pile);

/// pile_sommet
/// @brief Retourne le sommet de la pile sans le dépiler
///
pile_data_t     pile_sommet(Pile);

/// pile_est_vide
/// @brief Retourne 1 si la pile est vide
///
int             pile_est_vide(Pile);

/// pile_est_pleine
/// @brief Retourne 1 si la pile est pleine
///
int             pile_est_pleine(Pile);

/// pile_affiche_pile
/// @brief Affiche du contenu de la pile
///
void            pile_afficher_pile(Pile p);

#endif
