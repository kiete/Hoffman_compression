#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "codage.h"

void printEntree(entree e){
    printf("char : %c - codage : %s - longueur : %d\n", e.c, e.seqBits, e.len);
}

// parcours en profondeur
void parcours_profondeur(arbre a, int indice, entree table[], char* tab)
{
    
    static int j = 0 ;
    if(!est_arbre_vide(a)){
        if(!est_feuille(a)){
            //printf("%c\n", carac(a)) ;
            tab[indice] = '0';
            parcours_profondeur(gauche(a), indice+1, table , tab) ;
            tab[indice] = '1';
            parcours_profondeur(droit(a), indice+1, table , tab) ;
        }else{
            entree e;
            e.len=indice;
            e.c=carac(a);
            tab[indice] = 0 ;
            char *tab2 = malloc(sizeof(indice + 1));
            memcpy(tab2 , tab , indice + 1);
            e.seqBits = tab2 ;
            memcpy(&(table[j]) , &e , sizeof(entree));

            //table[j]->len=indice ;
            //table[j]->c=carac(a);
            table[j]=e;
            j++;
        }
    }
    return;
}

entree code(unsigned char c, dico d)
{
    int j;
    while ((d)->c != c) d++;

    return *d;
}

dico get_table (arbre a){
    entree table[100];
    dico d = &(table[0]);
    char *tab = malloc(sizeof(hauteur(a) + 1));
    parcours_profondeur(a, 0, table, tab);
    return d;
}