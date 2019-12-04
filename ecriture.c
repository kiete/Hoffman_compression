#include <stdio.h>
#include "caractere.h"
#include "ecriture.h"

void carToStr(char c, arbre a, char *tab, int* i){
    char miniBuffer[8];
    int bar , j;

    bar = 128;
    do{
        if (c>=bar) tab[*i] = 1;
        (*i)++;
        bar = bar/2 ;
    }while (bar > 0);
}

void decalle(char* tab , int i , int taille){
    int j ;
    for(j = i ; j < taille ; j++){
        tab[j-i] = tab[j] ;
    }
}

char bitToCar (char *tab){
    int i ;
    char sum ;

    sum = 0 ;
    for (i=0 ; i<8 ; i++){
        sum *= 2;
        sum += tab[i];
    }
    return sum;
}

void ecriture(FILE *in, FILE *out, arbre a)
{
    int i ;
    int bufferSize;
    char c ;
    char *buffer;

    bufferSize = profondeur(a) + 7 ;
    buffer = malloc(sizeoff(bufferSize));
    // a init à 0
    i=0;
    while (c = fgetc(in) != feof){
        carToStr(c,a,buffer,&i);
        while(i>=8){
            fprintf(out,"%c",bitToCar(buffer));
            decalle(buffer,8,bufferSize);
            i-=8;
        }
    }
    while ((i>0)&&(i<8)){
        buffer[i]=0 ;
        i++ ;
    }
}

