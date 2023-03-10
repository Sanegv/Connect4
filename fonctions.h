#ifndef DEF_FONCTIONS_CONNECT4
#define DEF_FONCTIONS_CONNECT4
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief initialise une grille de 6*7 et la remplit de 0
 * 
 * @return char** 
 */
char** init_grille();

/**
 * @brief libère la mémoire de la grille
 * 
 * @param grille 
 */
void free_grille(char** grille);

/**
 * @brief affiche la grille de jeu
 * 
 * @param grille 
 */
void print_grille(char** grille);

/**
 * @brief place le jeton en entrée dans la première case libre de la colonne, renvoie faux sinon
 * 
 * @param grille
 * @param jeton 
 * @param colonne 
 * @return bool 
 */
bool place_jeton(char** grille, char jeton, int colonne);

/**
 * @brief Demande au joueur la colonne dans laquelle il veut jouer jusqu'à trouver une colonne non pleine,
 * puis y place le jeton
 * 
 * @param grille 
 * @param joueur 
 */
void tour_humains(char** grille, char joueur);

/**
 * @brief Vérifie toutes les possibilités de victoire
 * 
 * @param grille 
 * @return true 
 * @return false 
 */
bool check_victoire(char** grille);

/**
 * @brief vérifie que la grille n'est pas pleine (ne regarde que la ligne en haut, le reste est inutile)
 * 
 * @param grille 
 * @return true 
 * @return false 
 */
bool check_plein(char** grille);

/**
 * @brief appelle toutes les fonctions nécessaires pour faire une partie entre deux humains
 * 
 */
void jeu_humains();

/**
 * @brief supprime le jeton en haut de la colonne indiquée en entrée et le renvoie, ou renvoie 0 si la colonne est vide
 * 
 * @param grille 
 * @param colonne 
 */
char pop(char** grille, int colonne);

#endif