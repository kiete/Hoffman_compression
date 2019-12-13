#ifndef CODAGE_H
#define CODAGE_H
#include "arbre.h"

typedef struct entree_t
{
    char c;
    char* seqBits;
    int len;
} entree ;

typedef entree *dico;

// etablit la correspondance d'un char avec sa sequence de bits
void codage_dico(arbre a, dico, int MaxCar);

// Construit un dico
dico get_table(arbre a , int size);

// Decode le caractere c par le dico d.
entree decode(char c, dico d);

#endif