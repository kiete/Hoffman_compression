#include <stdio.h>
#include <stdlib.h>
#include "caractere.h"
#include "arbre.h"
#include "codage.h"
#include "ecriture.h"

// Buffersize est globale
int bufferSize;

void compressChar(unsigned char c, arbre a, unsigned char *tab, int* i){
    unsigned char* miniBuffer;
    int j,tabLen;
    
    miniBuffer = malloc(sizeof(miniBuffer));

    // Ici minibuffer -> son tableau de bits codés
    // Et tabLen -> longeur du tableau

    // On append mimibuffer à la fin du tableau
    for ( j=0 ; j<tabLen ; j++ , i++ ){
        tab[*i] = miniBuffer[j];
    }
    return ;
}

unsigned char bitToCar(unsigned char *tab)
{
    int i ;
    unsigned char sum;

    sum = 0 ;
    for (i=0 ; i<8 ; i++){
        sum *= 2;
        sum += tab[i]-'0';
        //printf("who: %c\n" , tab[i]);
    }
    return sum;
}

void ecriture(FILE *in, FILE *out, dico d)
{
    int i , j;
    unsigned char c,  len, carac;
    int ci;
    unsigned char buffer[8];
    entree e;

    j=0;
    while ((ci = fgetc(in)) != EOF){ // Faut s'arreter
        //printf("on lit un carac \n");
        //printf("%c\n" , c);
        //printf("ok - %d\n",c);
        c = (unsigned char) ci ;
        printf("OK1\n");
        e = code(c,d);
        printf("OK2\n");
        printEntree(e);
        for (i=0 ; i<e.len ; i++){
            buffer[j] = e.seqBits[i] ;
            j++ ;
            if(j==8){
                j=0 ;
                carac = bitToCar(buffer) ;
                printf("On print : %d\n" , carac);
                fprintf(out , "%c" , carac) ;
            }
        }
    }
    // Remplir de 0
}

