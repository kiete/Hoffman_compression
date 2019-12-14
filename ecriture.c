#include <stdio.h>
#include <stdlib.h>
#include "caractere.h"
#include "arbre.h"
#include "codage.h"
#include "ecriture.h"

// Buffersize est globale
int bufferSize;

void compressChar(char c, arbre a, char *tab, int* i){
    char* miniBuffer;
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

void decalle(char* tab , int i , int taille){
    int j ;
    for(j = i ; j < taille ; j++){
        tab[j-i] = tab[j] ;
    }
}

unsigned char bitToCar (char *tab){
    int i ;
    char sum ;

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
    char c, len , carac ;
    char buffer[8] ;
    entree e;

    j=0;
    while ((c = fgetc(in))!=-1) { // Faut s'arreter
        //c = fgetc(in);
        printf("ok - %d\n",c);
        e = code(c,d);
        printEntree(e);
        // Need to print serialisation
        for (i=0 ; i<e.len ; i++){
            buffer[j] = e.seqBits[i] ;
            j++ ;
            if(j==8){
                j=0 ;
                carac = bitToCar(buffer) ;
                printf("On print : %c\n" , carac);
                fprintf(out , "%c" , carac) ;
            }
        }
    }
    if (i==8 )decalle(buffer,8,bufferSize);
}

