#ifndef CODAGE_H
#define CODAGE_H
#include "arbre.h"

typedef struct entree_t
{
    char c;
    char* seqBits;
    int len;
} entree ;

typedef entree* dico;

void printEntree(entree e);

// etablit la correspondance d'un char avec sa sequence de bits
void codage_dico(arbre a, entree[], int MaxCar);

// Construit un tableau d'entrees
dico get_table(arbre a);

// Place c code par d dans
entree code(unsigned char c, dico d);

// parcours en profondeur qui etablit la correspondance d'un char avec sa sequence de bits
void parcours_profondeur(arbre a, int indice, entree table[], char *tab);

#endif