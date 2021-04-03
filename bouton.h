#ifndef BOUTON_H
#define BOUTON_H

void dessin_bouton(char *nom, float emplacement);
short int bouton_clique(char *nom, float emplacement);
void bouton_hover(char *nom, float emplacement);

void hover_bouton_lancer_partie(char nom);
void dessin_bouton_lancer_partie(char nom);
int cliquee_bouton_lancer_partie();


void hover_changement(int nom);
void dessin_changement(int nom);
char cliquee_changement();

void dessin_taille_grille(char *nom);


void intelligence_artificielle();

void dessiner_enable_ia(int enable_ia);
void hover_enable_ia(int enable_ia);

void difficulty(int hard_mod);
void hover_difficulty(int hard_mod);

void dessiner_bouton_reset();
void hover_bouton_reset();

void dessiner_bouton_enregistrer();
void hover_bouton_enregistrer();

void bouton_options(char *texte, int emplacement);
short int bouton_options_clique(int emplacement);
void bouton_options_hover(int emplacement);

#endif
