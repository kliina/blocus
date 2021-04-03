#ifndef JEUX_H
#define JEUX_H



int jeux(struct parametres o);
int charger_pion(int taille_grille, char *couleur_pion);
void bouton_notification(char *texte, int decalage, char *color);
int ecran_fin(char gagnant);

#endif
