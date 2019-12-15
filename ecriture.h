#ifndef ECRITURE_H
#define ECRITURE_H
#define BLOCK_SIZE 4096
#include "arbre.h"
#include "codage.h"
#include "lecture.h"

// Transforme une chaine de 8 car en char
unsigned char bitToCar(unsigned char *tab);

// Compresse in dans out par l'arbre a
void ecriture(Bin_file *in, Bin_file *out, dico d);

// Compresse inshallah in dans out par l'arbre a
void ecrire_2(Bin_file *output, char bit);

#endif