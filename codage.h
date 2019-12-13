#ifndef CODAGE_H
#define CODAGE_H
#include "arbre.h"

struct {
    char c;
    char* seqBits;
    int len;
} dico_t;

typedef struct dico_t dico;

// etablit la correspondance d'un char avec sa sequence de bits
void codage_dico(arbre a, dico table[], int MaxCar);

// 


#endif