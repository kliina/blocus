#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"bouton.h"


struct parametres{
	int grille;
	int ia;
	int hard;
};


struct parametres menu_options(int i, struct parametres o) {
	couleur orange = 16344064;
	couleur dark_grey = 2697513;
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	short int options = 1;
	int changement;
	int enable_IA;
	int taille_grille;
	int hard_mod;

	short int cliquee;

	couleur lite_black = 2039583;
	couleur lite_white = 15592941;


	while(options == 1) { 

		if(i==0) {
			enable_IA = 1;
			taille_grille = 6;
			hard_mod = 1;
		} else {
			taille_grille = o.grille;
			enable_IA = o.ia;
			hard_mod = o.hard;
		}



		ChargerImageFond("image/menu_option.png");

		intelligence_artificielle();
		dessiner_enable_ia(enable_IA);
		difficulty(hard_mod);
		dessiner_bouton_reset();

		dessiner_bouton_enregistrer();


		dessin_changement(2);
		dessin_changement(1);


		if(taille_grille == 9) {
			dessin_taille_grille("9x9");
		} else if (taille_grille == 8) {
			dessin_taille_grille("8x8");
		} else if (taille_grille == 7) {
			dessin_taille_grille("7x7");
		} else if (taille_grille == 6) {
			dessin_taille_grille("6x6");
		} else if (taille_grille == 5) {
			dessin_taille_grille("5x5");
		} else if (taille_grille == 4) {
			dessin_taille_grille("4x4");
		} else if (taille_grille == 3) {
			dessin_taille_grille("3x3");
		}
		



		do{
			SourisPosition();
			hover_enable_ia(enable_IA);
			hover_difficulty(hard_mod);
			hover_bouton_reset();
			hover_bouton_enregistrer();
			hover_changement(1);
			hover_changement(2);

			cliquee = SourisCliquee();
			if(cliquee == 1) {

				if(_X > 320 && _X < 320+140 && _Y > 323 && _Y < 323+30) {
					if(hard_mod == 1) {
						hard_mod = 0;
						difficulty(hard_mod);

					} else {
						hard_mod = 1;
						difficulty(hard_mod);

					}
				}

				if(_X > 125 && _X < 125+140 && _Y > 323 && _Y < 332+30) {
					if(enable_IA == 1) {
						enable_IA = 0;
						dessiner_enable_ia(enable_IA);

					} else {
						enable_IA = 1;
						dessiner_enable_ia(enable_IA);

					}
				}

				if(_X > 260+60+20 && _X < 260+60+20+40 && _Y > 385 && _Y < 385+40) {
					if(taille_grille == 3) {
						dessin_taille_grille("4x4");
						taille_grille = 4;
					} else if(taille_grille == 4) {
						dessin_taille_grille("5x5");
						taille_grille = 5;
					} else if(taille_grille == 5) {
						dessin_taille_grille("6x6");
						taille_grille = 6;
					} else if(taille_grille == 6) {
						dessin_taille_grille("7x7");
						taille_grille = 7;
					} else if(taille_grille == 7) {
						dessin_taille_grille("8x8");
						taille_grille = 8;
					} else if(taille_grille == 8) {
						dessin_taille_grille("9x9");
						taille_grille = 9;
					} else if(taille_grille == 9) {
						dessin_taille_grille("3x3");
						taille_grille = 3;
					}
				}

				if(_X > 260-60 && _X < 260-60+40 && _Y > 385 && _Y < 385+40) {
					if(taille_grille == 3) {
						dessin_taille_grille("9x9");
						taille_grille = 9;
					} else if(taille_grille == 9) {
						dessin_taille_grille("8x8");
						taille_grille = 8;
					} else if(taille_grille == 8) {
						dessin_taille_grille("7x7");
						taille_grille = 7;
					} else if(taille_grille == 7) {
						dessin_taille_grille("6x6");
						taille_grille = 6;
					} else if(taille_grille == 6) {
						dessin_taille_grille("5x5");
						taille_grille = 5;
					} else if(taille_grille == 5) {
						dessin_taille_grille("4x4");
						taille_grille = 4;
					} else if(taille_grille == 4) {
						dessin_taille_grille("3x3");
						taille_grille = 3;
					}
				}

				printf("%d %d\n", _X, _Y);

				if(_X > 490 && _X < 515 && _Y > 234 && _Y < 255) {
					return o;
				}


				if(_X > 200 && _X < 200+60 && _Y > 475 && _Y < 490) {
					i=0;
					puts("Reset");
					break;
				}


				if(_X > 340 && _X < 385 && _Y > 475 && _Y < 490) {
					options = 0;
					puts("Enregistrer");
					o.grille = taille_grille;
					o.ia = enable_IA;
					o.hard = hard_mod;

					return o;
				}
			}



		} while (options == 1);
		
	}



	

}
