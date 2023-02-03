#include "fonctions.h"

char** init_grille(){
	char** grille = malloc(6*sizeof(char*));
	if(!grille) exit(1);
	for(int i = 0; i < 6; i++){
		grille[i] = calloc(7,sizeof(char));
		if(!grille[i]) exit(1);
	}

	return grille;
}

void free_grille(char** grille){
	for(int i = 0; i < 6; i++) free(grille[i]);
	free(grille);
}

void print_grille(char** grille){
	for(int i = 5; i >= 0; i--){
		for(int j = 0; j < 7; j++){
			if(!grille[i][j]) printf("□ ");
			else if(grille[i][j] == 1) printf("● ");
			else printf("○ ");
		}
		printf("\n");
	}
}

bool place_jeton(char** grille, char jeton, int colonne){
	for(int i = 0; i < 6; i++){
		if(!grille[i][colonne]){
			grille[i][colonne] = jeton;
			return true;
		}
	}
	return false;
}

void tour_humains(char** grille, char joueur){
	bool test = false;
	int colonne;
	while(!test){
		do{
			printf("Sur quelle colonne voulez-vous jouer ?\n>");
			scanf("%d", &colonne);
		} while(colonne < 0 || colonne > 6);
		test = place_jeton(grille, joueur, colonne);
	}
}

void jeu_humains(){
	char** grille = init_grille();
	int joueur = 0;
	print_grille(grille);

	do{
		printf("Au tour du joueur %d :\n", joueur+1);
		tour_humains(grille, joueur+1);
		joueur = !joueur;
		print_grille(grille);
		printf("\n");
	} while(!check_victoire(grille) && !check_plein(grille));

	if(check_plein(grille)) printf("Match nul...\n");
	else printf("Félicitations, joueur %d !\n", (!joueur)+1);
	free_grille(grille);
}

bool check_victoire(char** grille){
	//vérification des lignes
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 4; j++){
			if(!grille[i][j]) continue; //si la case est vide, on passe à la case suivante
			if(grille[i][j] == grille[i][j+1] 
			&& grille[i][j] == grille[i][j+2] 
			&& grille[i][j] == grille[i][j+3])
				return true;
		}
	}

	//vérification des colonnes
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 3; j++){
			if(!grille[j][i]) continue; //si la case est vide, on passe à la case suivante
			if(grille[j][i] == grille[j+1][i]
			&& grille[j][i] == grille[j+2][i]
			&& grille[j][i] == grille[j+3][i])
				return true;
		}
	}

	//vérification des diagonales vers le haut
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			if(!grille[i][j]) continue;//si la case est vide, on passe à la case suivante
			if(grille[i][j] == grille[i+1][j+1]
			&& grille[i][j] == grille[i+2][j+2]
			&& grille[i][j] == grille[i+3][j+3])
				return true;
		}
	}

	//vérification des diagonales vers le bas
	for(int i = 5; i > 2; i--){
		for(int j = 0; j < 4; j++){
			if(!grille[i][j]) continue;//si la case est vide, on passe à la case suivante
			if(grille[i][j] == grille[i-1][j+1]
			&& grille[i][j] == grille[i-2][j+2]
			&& grille[i][j] == grille[i-3][j+3])
				return true;
		}
	}
	return false;
}

bool check_plein(char** grille){
	for(int i = 0; i < 7; i++){
		if(!grille[5][i]) return false;
	}
	return true;
}