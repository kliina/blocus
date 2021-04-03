#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"menu.h"
#include"options.h"

int main(void) {
	short int initialisation_graphique;
	int largeur, hauteur;
	short int action = 0;

	int i = 0;
	int j = 0;

	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	int cliquee;

	short int start_menu = 0;


	initialisation_graphique = InitialiserGraphique();
	if(initialisation_graphique = 0) {
		puts("Mode graphique non initialisé");
		return EXIT_FAILURE;
	}

	CreerFenetre(0, 0, largeur_fenetre, hauteur_fenetre);
	ChoisirTitreFenetre("BLOCUS");

	ChargerImageFond("image/init1.png");



	do {
		SourisPosition();
		if(_X > 0 && _X < 60 && _Y > 0 && _Y < 80) {
			ChargerImageFond("image/init2.png");
		} else {
			ChargerImageFond("image/init1.png");
		}	


		cliquee = SourisCliquee();	
		if(cliquee == 1) {
			if(_X > 0 && _X < 60 && _Y > 0 && _Y < 80) {
				while(action == 0) {

					action = menu(i, j);
					if(action == 3) {
						action = 0;
						break;
					}
					i=1;
					j=1;


					if(action == 2) {
						CacherFenetre();
						Touche();
						FermerGraphique();
						return EXIT_SUCCESS;
					}
				}
			}
		}
	} while(start_menu != 1);
}
