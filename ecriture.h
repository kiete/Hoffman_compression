#ifndef ECRITURE_H
#define ECRITURE_H

// Transforme un caractere c en chaine de bits par a en partant de l'emplacement i de tab
void carToStr(char c, arbre a, char* tab, int i);

// Decalle tous les bits de tab de i positions vers la gauche
void decalle(char *tab, int i, int taille);

// Transforme une chaine de 8 car en char
char bitToCar(char *tab);

// Compresse in dans out par l'arbre a
void ecriture(FILE *in, FILE *out, arbre a);

#endif