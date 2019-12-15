#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codage.h"
#include "arbre.h"

int main()
{
    arbre a ;
    a = creer_arbre() ;
    set_carac(ajoute_gauche(a), 'a') ;
    set_carac(ajoute_droit(a), 'd') ;
    //printf("Carac fils gauche : %c\n", carac(a->gauche));
    //printf("Carac fils droit : %c\n", carac(a->droit));
    set_carac(ajoute_droit(a->gauche), 'b') ;
    set_carac(ajoute_gauche(a->gauche), 'c') ;
    set_carac(ajoute_gauche(gauche(a)->gauche), 'e') ;
    set_carac(ajoute_droit(gauche(a->gauche)), 'p') ;
    //printf("Hauteur de l'arbre : %d\n\n", hauteur(a));
    //char tab[5];
    entree table[100];
    dico d = &(table[0]);
    unsigned char *tab = malloc(sizeof(hauteur(a) + 1));
    parcours_profondeur(a, 0, table , tab);
    printf("essai\n");
    /*for(int i=0 ; i<5 ; i++){
        printf("%c  ", tab[i]);
    }
    printf("\n");
    for (int j=0 ; j<10 ; j++){
        printf("%c : ", table[j]->c);
        for(int k =0 ; k<table[j]->len ; k++){
            printf("%c  ", table[j]->seqBits[k]);
        }
        printf("\n\n");
    }*/
    for(int i=0 ; i<5 ; i++){
        printEntree(table[i]);
    }

    

    return 0 ;
}
