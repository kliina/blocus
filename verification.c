#include<stdlib.h>
#include<stdio.h>
#include<graph.h>




int verification_victoire(int taille_grille, int case_prise[taille_grille][taille_grille], int coord_largeur_couleur, int coord_hauteur_couleur, int num_sprite_orange, int num_sprite_bleu) {

	if(case_prise[coord_largeur_couleur+1][coord_hauteur_couleur-1] == 1 && case_prise[coord_largeur_couleur-1][coord_hauteur_couleur] == 1 && case_prise[coord_largeur_couleur-1][coord_hauteur_couleur+1] == 1 && case_prise[coord_largeur_couleur+1][coord_hauteur_couleur-1] == 1 && case_prise[coord_largeur_couleur][coord_hauteur_couleur+1] == 1 && case_prise[coord_largeur_couleur+1][coord_hauteur_couleur-1] == 1 && case_prise[coord_largeur_couleur+1][coord_hauteur_couleur] == 1 && case_prise[coord_largeur_couleur+1][coord_hauteur_couleur+1] == 1) {
		LibererSprite(num_sprite_orange);
		LibererSprite(num_sprite_bleu);
		return 1;
	}

	/* Coin supérieur gauche */
	if(coord_largeur_couleur == 0 && coord_hauteur_couleur == 0) {
		if(case_prise[coord_largeur_couleur+1][coord_hauteur_couleur] == 1 && case_prise[coord_largeur_couleur+1][coord_hauteur_couleur+1] == 1 && case_prise[coord_largeur_couleur][coord_hauteur_couleur+1] == 1) {
			LibererSprite(num_sprite_orange);
			LibererSprite(num_sprite_bleu);
			return 1;
		}
	}

	/* Coin supérieur droit */
	if(coord_largeur_couleur == taille_grille-1 && coord_hauteur_couleur == 0) {
		if(case_prise[coord_largeur_couleur-1][coord_hauteur_couleur] && case_prise[coord_largeur_couleur-1][coord_hauteur_couleur+1] && case_prise[coord_largeur_couleur][coord_hauteur_couleur+1]) {
			LibererSprite(num_sprite_orange);
			LibererSprite(num_sprite_bleu);
			return 1;
		}
	}
	/* Coin inferieur gauche */

	if(coord_largeur_couleur == 0 && coord_hauteur_couleur == taille_grille-1) {
		if(case_prise[coord_largeur_couleur][coord_hauteur_couleur-1] && case_prise[coord_largeur_couleur+1][coord_hauteur_couleur-1] && case_prise[coord_largeur_couleur+1][coord_hauteur_couleur]) {
			LibererSprite(num_sprite_orange);
			LibererSprite(num_sprite_bleu);
			return 1;
		}
	}

	/* Coin inferieur droit */

	if(coord_largeur_couleur == taille_grille-1 && coord_hauteur_couleur == taille_grille-1) {
		if(case_prise[coord_largeur_couleur-1][coord_hauteur_couleur] && case_prise[coord_largeur_couleur-1][coord_hauteur_couleur-1] && case_prise[coord_largeur_couleur][coord_hauteur_couleur-1]) {
			LibererSprite(num_sprite_orange);
			LibererSprite(num_sprite_bleu);
			return 1;
		}
	}

	/*Bordure haute */
	if(coord_hauteur_couleur == 0) {
		if(case_prise[coord_largeur_couleur-1][coord_hauteur_couleur] && case_prise[coord_largeur_couleur-1][coord_hauteur_couleur+1] && case_prise[coord_largeur_couleur][coord_hauteur_couleur+1] && case_prise[coord_largeur_couleur+1][coord_hauteur_couleur+1] && case_prise[coord_largeur_couleur+1][coord_hauteur_couleur]) {
			LibererSprite(num_sprite_orange);
			LibererSprite(num_sprite_bleu);
			return 1;
		}
	}

	/*Bordure basse */
	if(coord_hauteur_couleur == taille_grille-1) {
		if(case_prise[coord_largeur_couleur-1][coord_hauteur_couleur] && case_prise[coord_largeur_couleur-1][coord_hauteur_couleur-1] && case_prise[coord_largeur_couleur][coord_hauteur_couleur-1] && case_prise[coord_largeur_couleur+1][coord_hauteur_couleur-1] && case_prise[coord_largeur_couleur+1][coord_hauteur_couleur]) {
			LibererSprite(num_sprite_orange);
			LibererSprite(num_sprite_bleu);
			return 1;
		}
	}

	/*Bordure gauche */
	if(coord_largeur_couleur == 0) {
		if(case_prise[coord_largeur_couleur][coord_hauteur_couleur-1] && case_prise[coord_largeur_couleur+1][coord_hauteur_couleur-1] && case_prise[coord_largeur_couleur+1][coord_hauteur_couleur] && case_prise[coord_largeur_couleur+1][coord_hauteur_couleur+1] && case_prise[coord_largeur_couleur][coord_hauteur_couleur+1]) {
			LibererSprite(num_sprite_orange);
			LibererSprite(num_sprite_bleu);
			return 1;	
		}
	}

	/*Bordure droite */

	if(coord_largeur_couleur == taille_grille-1) {
		if(case_prise[coord_largeur_couleur][coord_hauteur_couleur-1] && case_prise[coord_largeur_couleur-1][coord_hauteur_couleur-1] && case_prise[coord_largeur_couleur-1][coord_hauteur_couleur] && case_prise[coord_largeur_couleur-1][coord_hauteur_couleur+1] && case_prise[coord_largeur_couleur][coord_hauteur_couleur+1]) {
			LibererSprite(num_sprite_orange);
			LibererSprite(num_sprite_bleu);
			return 1;	
		}
	}

}

