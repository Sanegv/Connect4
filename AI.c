#include "AI.h"

void menu(){
    int choix;
    do{
        printf("Voulez-vous jouer contre un humain (1) ou contre l'ordinateur (2) ?\n>");
        scanf("%d", &choix);
    } while(choix < 1 || choix > 2);

    if(choix == 1) jeu_humains();
    else jeu_ia_simple(choix_tour());
}

void jeu_ia_simple(int ia){
    char** grille = init_grille();
    print_grille(grille);
    int tour = 0;

    do{
        printf("\n");
        if(tour+1 == ia) tour_ia_simple(grille, ia); //l'IA joue seulement quand c'est son tour (ça marche, fais une table de vérité)
        else tour_humains(grille, (ia%2)+1); //si c'est au tour du joueur, on lui fait jouer avec le char INVERSE de celui de l'IA
        print_grille(grille);
        tour = !tour;
        printf("\n");
    } while(!check_victoire(grille) && !check_plein(grille)); //On joue tant que personne n'a gagné et tant qu'il y a de la place

    if(check_plein(grille)) printf("Match nul...\n"); //si la grille est pleine, pat
    else if(tour+1 == ia) printf("Félicitations !\n"); //si l'ia a perdu, victoire
    else printf("Perdu...\n"); //sinon, défaite
}

void tour_ia_simple(char** grille, int ia){
    bool coup = false;
    int colonne;
    while(!coup) {
        colonne = rand()%6;
        coup = place_jeton(grille, (char)ia, colonne);
    }

    printf("L'ordinateur a joué à la colonne n°%d\n", colonne);
}

int choix_tour(){
    int choix;
    do {
        printf("Voulez-vous jouer en premier (1), en deuxième (2), ou au hasard (3) ?\n>");
        scanf("%d", &choix);
    } while(choix < 1 || choix > 3);

    if(choix == 3) return rand()%2;
    return (choix%2)+1; //si le joueur veut être j1, renvoie 2 (pour l'ia), et inversement
}