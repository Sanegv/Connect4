#ifndef DEF_AI_CONNECT4
#define DEF_AI_CONNECT4

#include "fonctions.h"
#include <time.h>

/**
 * @brief le menu du jeu, qui appelle les autres fonctions
 * 
 */
void menu();

/**
 * @brief la fonction du jeu contre une ia aléatoire, qui jouera j1 ou j2 selon le paramètre en entrée, qui apelle tour humains et tour ia simple
 * 
 * @param joueur
 */
void jeu_ia_simple(int ia);

/**
 * @brief tire une colonne non pleine au hasard, et y place un jeton
 * 
 * @param grille 
 * @param ia 
 */
void tour_ia_simple(char** grille, int ia);

/**
 * @brief Demande au joueur s'il veut joueur en premier ou en deuxième, et renvoie le résultat INVERSE pour l'attribuer à l'IA
 * 
 * @return int 
 */
int choix_tour();

/**
 * @brief Prend en entrée la profondeur à laquelle l'ordinateur doit chercher pour joueur le coup optimal, et appelle les fonctions nécessaires pour jouer une partie
 * 
 * @param depth 
 */
void jeu_ia_minmax(int depth);

/**
 * @brief joue un tour en plaçant le char de l'ia à la meilleure position pour la profondeur donnée
 * 
 * @param grille 
 * @param ia 
 * @param depth 
 */
void tour_ia_minmax(char** grille, int ia, int depth);

/**
 * @brief S'appelle récursivement pour trouver le meilleur coup, jusqu'à la profondeur désirée.
 * Calcule le score total de la branche en jouant le coup "colonne", et en essayant ensuite toutes les possibilités ouvertes par ce coup
 * 
 * @param grille 
 * @param ia 
 * @param depth 
 * @param colonne
 * @return int 
 */
int minmax(char** grille, int ia, int depth, int colonne);

/**
 * @brief renvoie l'indice de la valeur maximale de la table (de 7 colonnes) en entrée
 * 
 * @param table 
 * @return int 
 */
int find_max(int* table);

/**
 * @brief renvoie l'indice de la valeur minimale de la table (de 7 colonnes) en entrée
 * 
 * @param table 
 * @return int 
 */
int find_min(int* table);

/**
 * @brief renvoie vrai si toutes les valeurs de la table (de 7 colonnes en entrée) sont égales
 * 
 * @param table 
 * @return true 
 * @return false 
 */
bool check_equal(int* table);

/**
 * @brief renvoie la sommme des 7 valeurs de la table en entrée
 * 
 * @param table 
 * @return int 
 */
int sum(int* table);

#endif