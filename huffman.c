// Projet C
// KERNEVES Théo, DELOLME Antonin, SANTOS Aurelien, LAVEDRINE Aymeric
// Module Huffman

#include "huffman.h"
#include "arbre.h"

int countCharInFile (int T[], FILE *f) {
    unsigned char c;
    int n , ic;

    n = 0 ;
    while (fscanf(f, "%c", &c) != EOF) {
        ic = (int)c;
        if (T[ic] == 0) n++ ;
        T[ic] = T[ic] + 1 ;
    }

    rewind(f);
    return n ;
}

arbre charToLeaf (unsigned char c, int poids) {
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

        tmp = creer_arbre_complet ('.', poids(a1) + poids(a2), a1, a2) ;
        l = insertNode (l, tmp) ;   
    }

    return tete(l) ;
}

unsigned char findChar(arbre huffman, Bin_file *input)
{
    arbre tmp;
    unsigned char bit;

    tmp = huffman;
    while (!est_feuille(tmp))
    {
        bit = lecture(input);
        //printf("bit : %d\n", bit);

        if (bit == 1)
        {
            tmp = tmp->droit;
        }
        else if (bit == 0)
        {
            tmp = tmp->gauche;
        }
    }
    return carac(tmp);
}