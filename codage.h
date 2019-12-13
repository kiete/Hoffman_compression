#ifndef CODAGE_H
#define CODAGE_H
#include "arbre.h"

typedef struct dico_t
{
    char c;
    char* seqBits;
    int len;
} dico ;

// etablit la correspondance d'un char avec sa sequence de bits
void codage_dico(arbre a, dico table[], int MaxCar);

// 


#endif