// Projet C
// KERNEVES Théo, DELOLME Antonin, SANTOS Aurelien, LAVEDRINE Aymeric
// Module Uffman - Header

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"
#include "listes.h"
#include "liste_ext.h"
#include "lecture.h"

// Compte le nombre d'occurence de chaque caractere à partir d'un fichier ouvert. Renvoie le nombre de caractères différents
int countCharInFile (int T[], FILE *f) ;

// renvoie un arbre à partir d'un char et d'un poids
arbre charToLeaf (char c, int poids) ;

// Construit l'arbre de Huffman à partir de la table d'occurences
arbre stringToHuffman (int T[]) ;

// Avance dans l'arbre de huffman en fonction d'un flux de bits
char findChar (arbre huffman, Bin_file * input);

arbre fileToHuffman (FILE *f) ;


#endif