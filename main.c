#include "fonctions.h"

int main(){
	char** grille = init_grille();
	jeu_humains();
	free_grille(grille);
	return 0;
}