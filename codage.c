#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "codage.h"

// parcours en profondeur
void parcours_profondeur(arbre a, int indice, dico table){
    char tab[hauteur(a)];
    static int j = 0 ;
    if(!est_arbre_vide(a)){
        if(!est_feuille(a)){
            //printf("%c\n", carac(a)) ;
            tab[indice] = '0';
            printf("0\n");
            parcours_profondeur(gauche(a), indice+1, table) ;
            tab[indice] = '1';
            printf("1\n");
            parcours_profondeur(droit(a), indice+1, table) ;
        }else{
            printf("indice : %d\n", indice);
            entree e;
            e.len=indice;
            e.c=carac(a);
            printf("char de la feuille : %c\n", e.c);
            memcpy(e.seqBits, tab, indice);
            //printf("ok3\n");
            /*for(int i=0 ; i<indice ; i++){
                printf("ok77\n");
                table[j]->seqBits[i]=tab[i] ;
                printf("ok2\n");
            }*/
            //table[j]->len=indice ;
            //table[j]->c=carac(a);
            printf("test\n");
            table[j]=e;
            printf("test 2\n");
            j++;
            printf("j vaut : %d\n",j);
        }
    }
    return;
}