// Projet C
// KERNEVES Théo, DELOLME Antonin, SANTOS Aurelien, LAVEDRINE Aymeric
// Module Huffman

#include "huffman.h"

int countCharInFile (int T[], FILE *f) {
    char c ;
    int n ;

    n = 0 ;
    while (fscanf(f, "%c", &c) != EOF) {
        if (T[c] == 0) n++ ;
        T[c] = T[c] + 1 ;
    }

    rewind(f);
    return n ;
}

arbre charToLeaf (char c, int poids) {
    return creer_feuille (c, poids) ;
}

arbre stringToHuffman (int T[]) {
    int i ;
    arbre tmp, a1, a2 ;
    Liste l ;

    l = creer_liste_vide();
    for (i = 0 ; i < 256; i++) {
        if (T[i] != 0) {
            tmp = charToLeaf (i, T[i]) ;
            l = insertNode (l, tmp) ;
        }
    }

    while (!est_liste_vide(queue((l)))) {
        l = removeNode (l, &a1) ;
        l = removeNode (l, &a2) ;

        tmp = creer_arbre_complet ('0', poids(a1) + poids(a2), a1, a2) ;
        l = insertNode (l, tmp) ;   
    }

    return tete(l) ;
}

char findChar (arbre huffman, Bin_file * input) {
    arbre tmp ;
    arbre prev ;
    char bit ;

    tmp = huffman ;
    prev = tmp ;
   // bit = lecture(input) ; 
    while (carac(tmp) == '0') {
        prev = tmp ;
        bit = lecture(input) ;
        printf("bit : %d\n", bit); 

        if (bit == 1) {
            tmp = tmp->droit ;
        } else if (bit == 0) {
            tmp = tmp->gauche ;
        }
    }
    return carac(tmp) ;
}