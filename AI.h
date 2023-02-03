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

#endif