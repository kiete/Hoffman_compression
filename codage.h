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

// etablit la correspondance d'un char avec sa sequence de bits
void codage_dico(arbre a, dico, int MaxCar);

// Construit un tableau de dico
dico get_table(arbre a);

// Decode le caractere c par le dico d.
void decode(char c, dico d);

#endif