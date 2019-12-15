#ifndef ECRITURE_H
#define ECRITURE_H
#define BLOCK_SIZE 4096
#include "arbre.h"
#include "codage.h"

// Transforme un caractere c en chaine de bits par a en partant de l'emplacement i de tab
void compressChar(unsigned char c, arbre a, unsigned char *tab, int *i);


// Transforme une chaine de 8 car en char
unsigned char bitToCar(unsigned char *tab);

// Compresse in dans out par l'arbre a
void ecriture(FILE *in, FILE *out, dico d);


#endif