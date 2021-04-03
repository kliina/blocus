#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"grille.h"
#include"souris_jeux.h"
#include"verification.h"
#include"ia_jeux.h"
#include<unistd.h>
#include"options.h"



int charger_pion(int taille_grille, char *couleur_pion) {
	char caractere_taille_grille;
	char sprite_num;
	char sprite_bleu[19] = "sprite/blue3.png";
	char sprite_orange[19] = "sprite/yellow3.png";

	int i;

	if(couleur_pion == "bleu") {

		caractere_taille_grille = '3';

		for(i = 3; i < taille_grille; i++) {
			caractere_taille_grille	= caractere_taille_grille + 1;
		}

		sprite_bleu[11] = caractere_taille_grille;
		printf("%s chargé\n", sprite_bleu);
		sprite_num = ChargerSprite(sprite_bleu);
		return sprite_num;


	} else if (couleur_pion == "orange") {

		caractere_taille_grille = '3';

		for(i = 3; i < taille_grille; i++) {
			caractere_taille_grille	= caractere_taille_grille + 1;
		}

		sprite_orange[13] = caractere_taille_grille;
		printf("%s chargé\n", sprite_orange);
		sprite_num = ChargerSprite(sprite_orange);

		return sprite_num;

	} else {

		puts("Pion non chargé");
		return EXIT_FAILURE;
	}
}

void bouton_notification(char *texte, int decalage, char *color) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;

	couleur dark_blue = 4733;
	couleur bleu = 28647;
	couleur orange = 15182181;
	couleur red = 850606;
	couleur lite_black = 2039583;
	couleur grey = 7697781;


	ChoisirCouleurDessin(dark_blue);
	RemplirRectangle(largeur_fenetre*0.20, hauteur_fenetre*0.92+3, 480, 20);



	if(color == "bleu") {
		ChoisirCouleurDessin(bleu);
	} else if (color == "orange") {
		ChoisirCouleurDessin(orange);
	}

	ChoisirCouleurDessin(orange);
	EcrireTexte(largeur_fenetre*0.25 + decalage, hauteur_fenetre*0.950, texte, 1);

}



int ecran_fin(char gagnant) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	couleur blue = 4363775;
	couleur orange = 16501922;
	couleur red = 850606;
	couleur grey = 7697781;
	couleur lite_black = 2039583;
	couleur lite_white = 15592941;
	couleur white = 14803425;
	couleur dark_grey = 2697513;
	couleur black = 0;
	couleur pink = 14200534;	

	int num_sprite_orange, num_sprite_bleu;

	int num_fin;
	int cliquee;

	short int quitter_ecran_fin;




			/*
			ChoisirCouleurDessin(grey);
			RemplirRectangle(largeur_fenetre*0.25, hauteur_fenetre*0.15, 400, 420);
			ChoisirCouleurDessin(lite_black);
			DessinerRectangle(largeur_fenetre*0.25, hauteur_fenetre*0.15, 400, 420);
			DessinerRectangle(largeur_fenetre*0.25+1, hauteur_fenetre*0.15+1, 400-2, 420-2);
			DessinerRectangle(largeur_fenetre*0.25+2, hauteur_fenetre*0.15+2, 400-4, 420-4);
			DessinerRectangle(largeur_fenetre*0.25+3, hauteur_fenetre*0.15	+3, 400-6, 420-6);
			*/

	if(gagnant == 'o') {
		ChoisirCouleurDessin(orange);

		num_fin = ChargerSprite("image/fin.png");
		AfficherSprite(num_fin, 200, 170);

		num_sprite_orange = ChargerSprite("sprite/yellow3.png");
		AfficherSprite(num_sprite_orange, 600, 50);


		EcrireTexte(largeur_fenetre*0.20+5+90, hauteur_fenetre*0.60-100, "Le Soleil se leve sur l'horizon", 1);

		LibererSprite(num_fin);
		LibererSprite(num_sprite_orange);


	} else if(gagnant == 'b') {
		ChoisirCouleurDessin(blue);

		num_fin = ChargerSprite("image/fin.png");
		AfficherSprite(num_fin, 200, 170);

		num_sprite_bleu = ChargerSprite("sprite/blue3.png");
		AfficherSprite(num_sprite_bleu, 600, 50);

		ChoisirCouleurDessin(black);
		EcrireTexte(largeur_fenetre*0.20+5+90, hauteur_fenetre*0.60-100, "La Lune se leve sur l'horizon", 1);


		LibererSprite(num_fin);
		LibererSprite(num_sprite_bleu);

	}


	ChoisirCouleurDessin(black);
	EcrireTexte(largeur_fenetre*0.20+5+90, hauteur_fenetre*0.60-20, "Menu", 2);

	ChoisirCouleurDessin(black);
	EcrireTexte(largeur_fenetre*0.20+240+35, hauteur_fenetre*0.60-20, "Restart", 2);



	


	while(quitter_ecran_fin != 1) {
		SourisPosition();
		if(_X > 210 && _X < 390 && _Y > 308 && _Y < 350) {
			ChoisirCouleurDessin(lite_white);
			EcrireTexte(largeur_fenetre*0.20+5+90, hauteur_fenetre*0.60-20, "Menu", 2);
		} else {
			ChoisirCouleurDessin(black);
			EcrireTexte(largeur_fenetre*0.20+5+90, hauteur_fenetre*0.60-20, "Menu", 2);
		}


		if(_X > 400 && _X < 580 && _Y > 308 && _Y < 350) {
			ChoisirCouleurDessin(lite_white);
			EcrireTexte(largeur_fenetre*0.20+240+35, hauteur_fenetre*0.60-20, "Restart", 2);

		} else {
			ChoisirCouleurDessin(black);
			EcrireTexte(largeur_fenetre*0.20+240+35, hauteur_fenetre*0.60-20, "Restart", 2);

		}

		cliquee = SourisCliquee();
		if(cliquee == 1) {
			if(_X > 210 && _X < 390 && _Y > 308 && _Y < 350) {
				puts("Quitter");
				return 1;
			}
			if(_X > 400 && _X < 580 && _Y > 308 && _Y < 350) {
				puts("Relancer");
				return 0;
			}

		} 

	}
} 





char debut_jeux(int taille_grille) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	int coord_hauteur, coord_largeur;
	int cliquee;

	float position_x_orange, position_y_orange;
	float position_x_bleu, position_y_bleu;
	float ancienne_pos_x_orange, ancienne_pos_y_orange;
	float ancienne_pos_y_bleu, ancienne_pos_x_bleu;

	int ancienne_coord_largeur_orange, ancienne_coord_hauteur_orange;
	int ancienne_coord_largeur_bleu, ancienne_coord_hauteur_bleu;
	int coord_largeur_orange, coord_hauteur_orange;
	int coord_largeur_bleu, coord_hauteur_bleu;

	int placer_orange = 0;
	int placer_bleu = 0;
	int i, j;

	int orange_defaite = 0;
	int bleu_defaite = 0;
	int gagnant = 0;

	couleur bleu = 28647;
	couleur orange = 15182181;

	short int fin_partie = 0;

	int num_sprite_bleu, num_sprite_orange;
	couleur lite_white = 15592941;

	int placer_mur_orange, placer_mur_bleu;
	int position_x_orange_mur, position_x_bleu_mur;
	int position_y_orange_mur, position_y_bleu_mur;
	int case_prise[taille_grille][taille_grille];

	float cote_grille = (hauteur_fenetre-(hauteur_fenetre*0.2));
	float cote_case = cote_grille/taille_grille;

	printf("Taille grille : %dx%d\n", taille_grille, taille_grille);

	dessiner_grille(taille_grille);
	num_sprite_bleu = charger_pion(taille_grille, "bleu");
	printf("%d\n", num_sprite_bleu);
	num_sprite_orange = charger_pion(taille_grille, "orange");
	printf("%d\n", num_sprite_orange);





	for(i = 0; i < taille_grille; i++) {
		printf("\n");
		for(j = 0; j < taille_grille; j++) {
			case_prise[j][i] = 0;
			printf("%d ", case_prise[j][i]);
		}
	}

	printf("\n");


	fflush(0);


	bouton_notification("Soleil : doit se placer", 5, "orange");
	while(placer_orange == 0) {
		cliquee = SourisCliquee();
		if(cliquee == 1) {
			if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {

				for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {
					for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {

						if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {
							printf("Pion placé : %d %d\n", coord_largeur+1, coord_hauteur+1);
							position_x_orange = largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille);
							position_y_orange = hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille);

							AfficherSprite(num_sprite_orange,position_x_orange, position_y_orange);

							case_prise[coord_largeur][coord_hauteur] = 1;

							coord_largeur_orange = coord_largeur;
							coord_hauteur_orange = coord_hauteur;

							placer_orange = 1;

						}
					}
				}
			}
		}
	}


	bouton_notification("Lune : doit se placer", 5, "bleu");

	while(placer_bleu == 0) {
		cliquee = SourisCliquee();
		if(cliquee == 1) {
			if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {

				for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {
					for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {
						if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {
							printf("Pion placé : %d %d\n", coord_largeur+1, coord_hauteur+1);
							position_x_bleu = largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille);
							position_y_bleu = hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille);

							if(position_y_bleu == position_y_orange && position_x_bleu == position_x_orange) {
								bouton_notification("Lune : La case est prise, placez-vous ailleurs", 20, "bleu");
								break;
							}

							case_prise[coord_largeur][coord_hauteur] = 1;

							AfficherSprite(num_sprite_bleu,position_x_bleu, position_y_bleu);
							coord_largeur_bleu = coord_largeur;
							coord_hauteur_bleu = coord_hauteur;

							placer_bleu = 1;
						}
					}
				}
			}
		}
	}



	fin_partie = 0;
	while(fin_partie == 0) {

			/* Deplacement */
		bouton_notification("Soleil : deplacez-vous...", 5, "orange");
		placer_orange = 0;
		i = 0;
		while(placer_orange == 0) {

			cliquee = SourisCliquee();
			if(cliquee == 1) {
				if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {

					for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {
						for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {

							if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {


								if(i == 0) {
									ancienne_pos_x_orange = position_x_orange;
									ancienne_pos_y_orange = position_y_orange;
									ancienne_coord_largeur_orange = coord_largeur;
									ancienne_coord_hauteur_orange = coord_hauteur;
								}

								i = 1;
								position_x_orange = largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille);
								position_y_orange = hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille);



								if(position_x_orange == position_x_bleu && position_y_orange == position_y_bleu) {
									bouton_notification("Soleil : la case est prise", 5, "orange");
									break;
								}
								if(position_x_orange == ancienne_pos_x_orange && position_y_orange == ancienne_pos_y_orange) {
									bouton_notification("Soleil : Vous devez vous deplacer autour de vous", 5, "orange");
									break;
								}
								if(case_prise[coord_largeur][coord_hauteur] == 1) {
									bouton_notification("Soleil : Deplacez-vous en dehors d'un mur", 5, "orange");
									break;									
								}


								printf("Position orange : %d %d\n", coord_largeur_orange, coord_hauteur_orange);

								printf("Position clique : %d %d\n\n", coord_largeur, coord_hauteur);




								if(coord_largeur_orange == coord_largeur-1 && coord_hauteur_orange == coord_hauteur+1 || coord_largeur_orange == coord_largeur && coord_hauteur_orange == coord_hauteur-1 || coord_largeur_orange == coord_largeur && coord_hauteur_orange == coord_hauteur+1 || coord_largeur_orange == coord_largeur-1 && coord_hauteur_orange == coord_hauteur-1 || coord_largeur_orange == coord_largeur+1 && coord_hauteur_orange == coord_hauteur || coord_largeur_orange == coord_largeur+1 && coord_hauteur_orange == coord_hauteur+1 || coord_largeur_orange == coord_largeur+1 && coord_hauteur_orange == coord_hauteur-1 || coord_largeur_orange == coord_largeur-1 && coord_hauteur_orange == coord_hauteur || coord_largeur_orange == coord_largeur-1 && coord_hauteur_orange == coord_hauteur-1) {
									ChoisirCouleurDessin(lite_white);
									RemplirRectangle(ancienne_pos_x_orange+1,ancienne_pos_y_orange+1,cote_grille/taille_grille-1,cote_grille/taille_grille-1);
									AfficherSprite(num_sprite_orange,position_x_orange, position_y_orange);
									placer_orange = 1;
									case_prise[coord_largeur_orange][coord_hauteur_orange] = 0;
									coord_largeur_orange = coord_largeur;
									coord_hauteur_orange = coord_hauteur;
									case_prise[coord_largeur_orange][coord_hauteur_orange] = 1;
									break;
								}


								bouton_notification("Soleil : Deplacez-vous d'une case maximum", 5, "orange");
								break;


							}
						}
						if(placer_orange == 1) {
							break;
						}
					}
				}
			}
		}




		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_orange, coord_hauteur_orange, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'b';
		}

		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_bleu, coord_hauteur_bleu, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'o';
		}


		bouton_notification("Soleil : placez un mur", 5, "orange");
		placer_mur_orange = 0;
		i = 0;
		while(placer_mur_orange == 0) {	

			cliquee = SourisCliquee();
			if(cliquee == 1) {
				if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {
					for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {

						for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {

							if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {


								position_x_orange_mur = largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille);
								position_y_orange_mur = hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille);

								if(position_x_orange_mur == position_x_orange && position_y_orange_mur == position_y_orange) {
									bouton_notification("Soleil : choisissez une case vide", 5, "orange");
									puts("Choisissez une autre case");
									break;
								}

								if(position_x_orange_mur == position_x_bleu && position_y_orange_mur == position_y_bleu) {
									bouton_notification("Soleil : choisissez une case vide", 5, "orange");
									break;
								}

								if(case_prise[coord_largeur][coord_hauteur] == 1) {
									bouton_notification("Soleil : choisissez une case vide", 5, "orange");
									puts("Choisissez une autre case");
									break;
								}

								ChoisirCouleurDessin(orange);
								RemplirRectangle(position_x_orange_mur+1,position_y_orange_mur+1,cote_grille/taille_grille-1,cote_grille/taille_grille-1);
								placer_mur_orange = 1;
								case_prise[coord_largeur][coord_hauteur] = 1;	


								for(i = 0; i < taille_grille; i++) {
									printf("\n");
									for(j = 0; j < taille_grille; j++) {
										printf("%d ", case_prise[j][i]);

									}
								}
								printf("\n");


							}
						}
					}
					if(placer_mur_orange == 1 ) {
						break;
					}
				}
			}
		}



		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_orange, coord_hauteur_orange, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'b';
		}

		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_bleu, coord_hauteur_bleu, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'o';
		}



		bouton_notification("Lune : deplacez-vous", 5, "bleu");
		placer_bleu = 0;
		i = 0;

		while(placer_bleu == 0) {

			cliquee = SourisCliquee();
			if(cliquee == 1) {
				if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {

					for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {

						for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {

							if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {


								if(i == 0) {
									ancienne_pos_x_bleu = position_x_bleu;
									ancienne_pos_y_bleu = position_y_bleu;
									ancienne_coord_hauteur_bleu = coord_hauteur; 
									ancienne_coord_largeur_bleu = coord_largeur;
								}

								i = 1;
								position_x_bleu = largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille);
								position_y_bleu = hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille);



								if(position_x_bleu == position_x_orange && position_y_bleu == position_y_orange) {
									bouton_notification("Lune : la case est prise", 5, "bleu");
									break;
								}
								if(position_x_bleu == ancienne_pos_x_bleu && position_y_bleu == ancienne_pos_y_bleu) {
									bouton_notification("Lune : vous devez vous deplacer", 5, "bleu");
									break;
								}

								if(case_prise[coord_largeur][coord_hauteur] == 1) {
									bouton_notification("Lune : deplacez-vous sur une case vide", 5, "bleu");
									break;									
								}

								printf("Position bleu : %d %d\n", coord_largeur_bleu, coord_hauteur_bleu);

								printf("Position clique : %d %d\n\n", coord_largeur, coord_hauteur);


										/* */
								if(coord_largeur_bleu == coord_largeur-1 && coord_hauteur_bleu == coord_hauteur+1 || coord_largeur_bleu == coord_largeur && coord_hauteur_bleu == coord_hauteur-1 || coord_largeur_bleu == coord_largeur && coord_hauteur_bleu == coord_hauteur+1 || coord_largeur_bleu == coord_largeur-1 && coord_hauteur_bleu == coord_hauteur-1 || coord_largeur_bleu == coord_largeur+1 && coord_hauteur_bleu == coord_hauteur || coord_largeur_bleu == coord_largeur+1 && coord_hauteur_bleu == coord_hauteur+1 || coord_largeur_bleu == coord_largeur+1 && coord_hauteur_bleu == coord_hauteur-1 || coord_largeur_bleu == coord_largeur-1 && coord_hauteur_bleu == coord_hauteur || coord_largeur_bleu == coord_largeur-1 && coord_hauteur_bleu == coord_hauteur-1) {
									ChoisirCouleurDessin(lite_white);
									RemplirRectangle(ancienne_pos_x_bleu+1,ancienne_pos_y_bleu+1,cote_grille/taille_grille-1,cote_grille/taille_grille-1);
									AfficherSprite(num_sprite_bleu,position_x_bleu, position_y_bleu);
									placer_bleu = 1;
									case_prise[coord_largeur_bleu][coord_hauteur_bleu] = 0;
									coord_largeur_bleu = coord_largeur;
									coord_hauteur_bleu = coord_hauteur;
									case_prise[coord_largeur_bleu][coord_hauteur_bleu] = 1;
									break;
								}

								bouton_notification("Lune : deplacez-vous d'une case au maximum", 5, "bleu");

							}
						}

						if(placer_bleu == 1 ) {
							break;
						}
					}
				}
			}
		}


			/*Verif defaite  orange */

		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_orange, coord_hauteur_orange, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'b';
		}

		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_bleu, coord_hauteur_bleu, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'o';
		}




		bouton_notification("Lune : placez un mur", 5, "bleu");
		placer_mur_bleu = 0;
		i = 0;
		while(placer_mur_bleu == 0) {	

			cliquee = SourisCliquee();
			if(cliquee == 1) {
				if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {
					for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {

						for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {
							if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {


								position_x_bleu_mur = largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille);
								position_y_bleu_mur = hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille);


								if(position_x_bleu_mur == position_x_orange && position_y_bleu_mur == position_y_orange) {
									bouton_notification("Lune : choisissez une case sans le soleil", 5, "bleu");
									puts("Choisissez une autre case");
									break;
								}

								if(position_x_bleu_mur == position_x_bleu && position_y_bleu_mur == position_y_bleu) {
									bouton_notification("Lune : choisissez une case vide", 5, "bleu");
									break;
								}

								if(case_prise[coord_largeur][coord_hauteur] == 1) {
									bouton_notification("Lune : choisissez une case vide", 5, "bleu");
									puts("Choisissez une autre case");
									break;
								}

								ChoisirCouleurDessin(bleu);
								RemplirRectangle(position_x_bleu_mur+1,position_y_bleu_mur+1,cote_grille/taille_grille-1,cote_grille/taille_grille-1);
								placer_mur_bleu = 1;
								case_prise[coord_largeur][coord_hauteur] = 1;	

								for(i = 0; i < taille_grille; i++) {
									printf("\n");
									for(j = 0; j < taille_grille; j++) {
										printf("%d ", case_prise[j][i]);
									}
								}
								printf("\n");

							}
						}

					}
					if(placer_mur_bleu == 1 ) {
						break;
					}
				}
			}
		}


		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_orange, coord_hauteur_orange, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'b';
		}

		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_bleu, coord_hauteur_bleu, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'o';
		}
	}
}




int jeux(struct parametres o) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	couleur blue = 3093129;
	couleur orange = 16344064;
	couleur grey = 7697781;
	couleur lite_black = 2039583;
	couleur lite_white = 15592941;
	couleur white = 14803425;
	couleur dark_grey = 2697513;

	int enable_IA;
	int taille_grille;
	int hard_mod;

	short int quitter_partie = 0;

	char gagnant;

	printf("Taille : %d | IA : %d | HardMod: %d\n", o.grille, o.ia, o.hard);

	taille_grille = o.grille;
	enable_IA = o.ia;
	hard_mod = o.hard;


	do {

		ChargerImageFond("image/fond_jeu.png");


		if(enable_IA == 0) {
			gagnant = debut_jeux(taille_grille);
		} else if(enable_IA == 1) {
			gagnant = ia_jeux(taille_grille, hard_mod);
		}

		quitter_partie = ecran_fin(gagnant);
		if(quitter_partie == 1) {
			return 1;
		}
	} while(1);


}
