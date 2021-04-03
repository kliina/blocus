#include<stdlib.h>
#include<stdio.h>
#include<graph.h>

void dessiner_case(int taille_grille) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;

	int i, j;

	float placement_largeur = 0.2;
	float placement_hauteur = 0.1;

	float cote_grille;
	couleur lite_black = 2039583;

	cote_grille = (hauteur_fenetre-(hauteur_fenetre*0.2));


	ChoisirCouleurDessin(lite_black);
	for(i = 0; i < taille_grille; i++) {
		for(j = 0; j < taille_grille; j++) { 
			DessinerRectangle(largeur_fenetre*0.2 + (i*(cote_grille/taille_grille)), hauteur_fenetre*0.1 +(j*(cote_grille/taille_grille)), cote_grille/taille_grille, cote_grille/taille_grille);
		}
	}

}


void dessiner_contour_grille(int taille_grille) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;

	couleur lite_black = 14474460;
	couleur lite_white = 15592941;


	ChoisirCouleurDessin(lite_white);
	RemplirRectangle(largeur_fenetre*0.2, hauteur_fenetre*0.1, hauteur_fenetre - (hauteur_fenetre*0.2), hauteur_fenetre - (hauteur_fenetre*0.2));

	ChoisirCouleurDessin(lite_black); 
	DessinerRectangle(largeur_fenetre*0.2, hauteur_fenetre*0.1, hauteur_fenetre - (hauteur_fenetre*0.2), hauteur_fenetre - (hauteur_fenetre*0.2) );

	dessiner_case(taille_grille);
}


void dessiner_grille(int taille_grille) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;

	dessiner_contour_grille(taille_grille);

}
