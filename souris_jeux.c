#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"jeux.h"

void jeux_hover() {

}

/* _X LARGEUR et _Y HAUTEUR */

int placement_pion(int taille_grille, int num_sprite) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	int cliquee;
	int i, j;
	int coord_hauteur, coord_largeur;
	int x,y;
	short int sortir=0;


	float cote_grille = (hauteur_fenetre-(hauteur_fenetre*0.2));

	cliquee = SourisCliquee();
	
	if(cliquee == 1) {
		if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {

			for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {
				for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {
					if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {
						printf("%d %d\n", coord_largeur+1, coord_hauteur+1);
						
						
						AfficherSprite(num_sprite, largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille), hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille));
						
						return 1;
					}
				}
			}
		}


	}
}




void cliquer_grille(int taille_grille) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	int cliquee;
	int i, j;
	int coord_hauteur, coord_largeur;
	int x,y;

	float cote_grille = (hauteur_fenetre-(hauteur_fenetre*0.2));

	cliquee = SourisCliquee();
	if(cliquee == 1) {
		if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {
			
			for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {
				for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {
					if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {
						
					}
				}
			}
		}

	}
}

