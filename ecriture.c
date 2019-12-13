#include <stdio.h>
#include "ecriture.h"
#include "arbre.h"
#include "codage.h"

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
    int i , j , size;
    char c, len , carac ;
    char *buffer [8] ;
    arbre a = fileToHuffman(in);
    size = laFonctionDeTheo(a);
    dico d = get_table(a,size);
    entree e;

    int j=0;
    while (c = fgetc(in) != feof){
        e = decode(c,d);
        // Need to fprintf serialisation
        for (i=0 ; i< e.len ; i++){
            buffer[j++] = e.seqBits[i];
            if(j==8){
                j=0 ;
                carac = bitToCar(buffer) ;
                fprintf(out , "%c" , carac) ;
            }
        }
    }
    while ((i>0)&&(i<8)){
        buffer[i]=0 ;
        i++ ;
    }
    if (i==8 )decalle(buffer,8,bufferSize);
}

