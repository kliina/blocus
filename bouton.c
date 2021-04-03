#include<stdlib.h>
#include<stdio.h>
#include<graph.h>



void bouton_options(char *texte, int emplacement) {
	couleur grey = 7697781;
	couleur lite_black = 2039583;
	couleur white = 14803425;
	couleur pink = 14200534;	

	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;

	ChoisirCouleurDessin(pink);
	RemplirRectangle(largeur_fenetre*0.05, hauteur_fenetre*emplacement/10 - 30, 350, 40);
	ChoisirCouleurDessin(white);
	EcrireTexte(largeur_fenetre*0.05 + 5, hauteur_fenetre*emplacement/10, texte, 2);
	ChoisirCouleurDessin(lite_black);
	DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*emplacement/10 - 30, 350, 40);
}



short int bouton_options_clique(int emplacement) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	short int cliquee;

	cliquee = SourisCliquee();
	if(cliquee == 1) {
		if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 350 && _Y > hauteur_fenetre*emplacement/10 - 30 && _Y < hauteur_fenetre*emplacement/10 + 10);
		return 1;
	}
}

void bouton_options_hover(int emplacement) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	couleur lite_black = 2039583;
	couleur lite_white = 15592941;

	if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 350 && _Y > hauteur_fenetre*emplacement/10 - 30 && _Y < hauteur_fenetre*emplacement/10 + 10) {
		ChoisirCouleurDessin(lite_white);
		DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*emplacement/10 - 30, 350, 40);
	} else {
		ChoisirCouleurDessin(lite_black);
		DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*emplacement/10 - 30, 350, 40);
	}


}



void dessin_bouton_lancer_partie(char nom) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	couleur pink = 14200534;
	couleur black = 0;	

	if(nom=='y') {
		ChoisirCouleurDessin(pink);
		RemplirRectangle(340, 200, 50, 20);
		ChoisirCouleurDessin(black);
		DessinerRectangle(340, 200, 50, 20);
		EcrireTexte(345, 218, "YES", 1);
	}

	if(nom=='n') {
		ChoisirCouleurDessin(pink);
		RemplirRectangle(415, 200, 50, 20);
		ChoisirCouleurDessin(black);
		DessinerRectangle(415, 200, 50, 20);
		EcrireTexte(425, 218, "NO", 1);
	}

}

void hover_bouton_lancer_partie(char nom) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	couleur pink = 14200534;
	couleur purple = 16711935;
	couleur black = 0;
	couleur lite_white = 15592941;


	if(nom=='y') {
		if(_X > 340 && _X < 340+50 && _Y > 200 && _Y < 220) {

			ChoisirCouleurDessin(black);
			DessinerRectangle(340, 200, 50, 20);
			ChoisirCouleurDessin(lite_white);
			EcrireTexte(345, 218, "YES", 1);
		} else {

			ChoisirCouleurDessin(black);
			DessinerRectangle(340, 200, 50, 20);
			EcrireTexte(345, 218, "YES", 1);
		}
	}

	if(nom=='n') {
		if(_X > 415 && _X < 415+50 && _Y > 200 && _Y < 220) {

			ChoisirCouleurDessin(black);
			DessinerRectangle(415, 200, 50, 20);
			ChoisirCouleurDessin(lite_white);
			EcrireTexte(425, 218, "NO", 1);
		} else {
			ChoisirCouleurDessin(black);
			DessinerRectangle(415, 200, 50, 20);
			EcrireTexte(425, 218, "NO", 1);
		}
	}

}


void dessin_taille_grille(char *nom) {
	couleur pink = 14200534;
	couleur black = 0;

	ChoisirCouleurDessin(pink);
	RemplirRectangle(260, 390, 60, 30);
	ChoisirCouleurDessin(black);
	DessinerRectangle(260, 390, 60, 30);
	EcrireTexte(268, 416, nom, 2);
}

void dessin_changement(int nom) {
	couleur pink = 14200534;
	couleur black = 0;

	if(nom == 1) {
		ChoisirCouleurDessin(pink);
		RemplirRectangle(260+60+20, 390-5, 40, 40);
		ChoisirCouleurDessin(black);
		DessinerRectangle(260+60+20, 390-5, 40, 40);
		EcrireTexte(260+60+32, 390-5+28, "+", 2);
	}

	if(nom == 2) {
		ChoisirCouleurDessin(pink);
		RemplirRectangle(260-60, 390-5, 40, 40);
		ChoisirCouleurDessin(black);
		DessinerRectangle(260-60, 390-5, 40, 40);
		EcrireTexte(260-60+17, 390-5+30, "-", 2);
	}
}

void hover_changement(int nom) {
	couleur pink = 14200534;
	couleur black = 0;
	couleur lite_white = 15592941;

	if(nom == 1) {
		if(_X > 260+60+20 && _X < 260+60+20+40 && _Y > 385 && _Y < 385+40) {

			ChoisirCouleurDessin(lite_white);
			DessinerRectangle(260+60+20, 390-5, 40, 40);
			EcrireTexte(260+60+32, 390-5+28, "+", 2);
		} else {
			ChoisirCouleurDessin(black);
			DessinerRectangle(260+60+20, 390-5, 40, 40);
			EcrireTexte(260+60+32, 390-5+28, "+", 2);
		}
	}

	if(nom == 2) {
		if(_X > 260-60 && _X < 260-60+40 && _Y > 385 && _Y < 385+40) {
			ChoisirCouleurDessin(lite_white);
			DessinerRectangle(260-60, 390-5, 40, 40);
			EcrireTexte(260-60+17, 390-5+30, "-", 2);
		} else {
			ChoisirCouleurDessin(black);
			DessinerRectangle(260-60, 390-5, 40, 40);
			EcrireTexte(260-60+17, 390-5+30, "-", 2);
		}
	}
}

void intelligence_artificielle() {
	couleur pink = 14200534;
	couleur black = 0;

	ChoisirCouleurDessin(pink);
	RemplirRectangle(180, 275, 220, 30);
	ChoisirCouleurDessin(black);
	DessinerRectangle(180, 275, 220, 30);
	EcrireTexte(190, 297, "Intelligence Artificielle", 1);
}

void dessiner_enable_ia(int enable_ia) {
	couleur pink = 14200534;
	couleur black = 0;

	if (enable_ia==1) {
		ChoisirCouleurDessin(pink);
		RemplirRectangle(125, 323, 140, 30);
		ChoisirCouleurDessin(black);
		DessinerRectangle(125, 323, 140, 30);
		EcrireTexte(160, 345, "Enabled", 1);
	} else if (enable_ia==0) {
		ChoisirCouleurDessin(pink);
		RemplirRectangle(125, 323, 140, 30);
		ChoisirCouleurDessin(black);
		DessinerRectangle(125, 323, 140, 30);
		EcrireTexte(160, 345, "Disabled", 1);
	}
}

void hover_enable_ia(int enable_ia) {
	couleur black = 0;
	couleur lite_white = 15592941;
	couleur pink = 14200534;


	if (enable_ia==1) {

		if(_X > 125 && _X < 125+140 && _Y > 323 && _Y < 332+30) {
			ChoisirCouleurDessin(lite_white);
			DessinerRectangle(125, 323, 140, 30);


		} else {
			ChoisirCouleurDessin(black);
			DessinerRectangle(125, 323, 140, 30);

		}
	}

	if (enable_ia==0) {
		if(_X > 125 && _X < 125+140 && _Y > 323 && _Y < 332+30) {

			ChoisirCouleurDessin(lite_white);
			DessinerRectangle(125, 323, 140, 30);

		} else {

			ChoisirCouleurDessin(black);
			DessinerRectangle(125, 323, 140, 30);

		}
	}
}



void difficulty(int hard_mod) {
	couleur pink = 14200534;
	couleur black = 0;

	if(hard_mod==0) {
		ChoisirCouleurDessin(pink);
		RemplirRectangle(320, 323, 140, 30);
		ChoisirCouleurDessin(black);
		DessinerRectangle(320, 323, 140, 30);
		EcrireTexte(360, 345, "Normal", 1);
	} else if(hard_mod==1) {
		ChoisirCouleurDessin(pink);
		RemplirRectangle(320, 323, 140, 30);
		ChoisirCouleurDessin(black);
		DessinerRectangle(320, 323, 140, 30);
		EcrireTexte(363, 345, "Hard", 1);

	}
}  
void hover_difficulty(int hard_mod) {
	couleur black = 0;
	couleur lite_white = 15592941;
	couleur pink = 14200534;

	if(hard_mod==0) {
		if(_X > 320 && _X < 320+140 && _Y > 323 && _Y < 323+30) { 

			ChoisirCouleurDessin(lite_white);
			DessinerRectangle(320, 323, 140, 30);

		} else {

			ChoisirCouleurDessin(black);
			DessinerRectangle(320, 323, 140, 30);

		}
	}

	if(hard_mod==1) {
		if(_X > 320 && _X < 320+140 && _Y > 323 && _Y < 323+30) { 

			ChoisirCouleurDessin(lite_white);
			DessinerRectangle(320, 323, 140, 30);

		} else {

			ChoisirCouleurDessin(black);
			DessinerRectangle(320, 323, 140, 30);


		}
	}
}


void dessiner_bouton_reset() {
	couleur black = 0;
	ChoisirCouleurDessin(black);
	EcrireTexte(200, 490, "Reset", 1);
}

void hover_bouton_reset() {
	couleur black = 0;
	couleur lite_white = 3189942;


	if(_X > 200 && _X < 200+60 && _Y > 475 && _Y < 490) {
		ChoisirCouleurDessin(lite_white);
		EcrireTexte(200, 490, "Reset", 1);
	} else {
		ChoisirCouleurDessin(black);
		EcrireTexte(200, 490, "Reset", 1);
	}
}


void dessiner_bouton_enregistrer() {
	couleur black = 0;

	ChoisirCouleurDessin(black);
	EcrireTexte(340, 490, "Save", 1);
}
void hover_bouton_enregistrer() {
	couleur black = 0;
	couleur lite_white = 3189942;
	if(_X > 340 && _X < 385 && _Y > 475 && _Y < 490) {
		ChoisirCouleurDessin(lite_white);
		EcrireTexte(340, 490, "Save", 1);
	} else {
		ChoisirCouleurDessin(black);
		EcrireTexte(340, 490, "Save", 1);	
	}
}




int cliquee_bouton_lancer_partie() {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	couleur pink = 14200534;
	couleur purple = 16711935;
	couleur black = 0;
	couleur lite_white = 15592941;


	if(_X > 340 && _X < 340+50 && _Y > 200 && _Y < 220) {
		puts("Yes");
		return 1;
	}
	if(_X >= 590 && _X <= 605 && _Y >= 40 && _Y <= 55) {
		return 2;
	}
	if(_X > 415 && _X < 415+50 && _Y > 200 && _Y < 220) {
		puts("No");
		return 2;
	}
}





void dessin_bouton(char *nom, float emplacement) {
	couleur grey = 7697781;
	couleur lite_black = 2039583;
	couleur white = 14803425;
	couleur pink = 14200534;
	couleur black = 0;	

	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;


	ChoisirCouleurDessin(black);
	EcrireTexte(largeur_fenetre*emplacement/10 + 160, hauteur_fenetre*0.5, nom, 1);


}

short int bouton_clique(char *nom, float emplacement) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;

	if(_X > largeur_fenetre*(emplacement/10) + 160 && _X < largeur_fenetre*(emplacement/10) + 160 + 70 && _Y > 285 && _Y < 300) {
		return 1;
	}
}

void bouton_hover(char *nom, float emplacement) {

	couleur blue = 3093129;
	couleur orange = 16344064;
	couleur grey = 7697781;
	couleur lite_black = 2039583;
	couleur lite_white = 15592941;
	couleur black = 0;	
	couleur white = 14803425;
	couleur pink = 14200534;

	couleur dark_grey = 2697513;
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;



	if(_X > largeur_fenetre*(emplacement/10) + 160 && _X < largeur_fenetre*(emplacement/10) + 160 + 70 && _Y > 285 && _Y < 300) {

		ChoisirCouleurDessin(lite_white);
		EcrireTexte(largeur_fenetre*emplacement/10 + 160, hauteur_fenetre*0.5, nom, 1);
	} else {
		ChoisirCouleurDessin(black);
		EcrireTexte(largeur_fenetre*emplacement/10 + 160, hauteur_fenetre*0.5, nom, 1);
	}		



}
