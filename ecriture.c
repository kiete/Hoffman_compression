#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "codage.h"
#include "ecriture.h"
#include "huffman.h"
#include "lecture.h"

// Buffersize est globale
int bufferSize;

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

void ecrire_2 (Bin_file * output, char bit) {
    unsigned char octet, b ;
    int i ;
    output->octet[output->i_octet++] = bit ;
    if (output->i_octet == 8){
        octet = 0 ;
        b = 0x80 ;
        for (i=0 ; i<8 ; i++){
            if (output->octet[i] == '1'){
                octet = octet|b ;
            }
            b = b>>1 ;
        }
        output->i_octet = 0 ;
        output->record[output->i_record] = octet ;
        output->i_record = output->i_record+1 ;
        output->nb_octets = output->nb_octets+1 ;
        fprintf(output->file, "%c", output->record[0]);
        output->i_record = 0;
        /*
        if (output->i_record == BLOCK_SIZE){
            //Ecriture de output->record dans output->file
            fprintf(output->file , "%s" , output->record );
            output->i_record = 0 ;
        }
        */
    }
}

void ecriture(Bin_file* in, Bin_file* out, dico d)
{
    int i , j;
    unsigned char c,  len, carac;
    int ci;
    unsigned char buffer[8];
    entree e;

    j=0;

    if ((ci = fgetc(in->file)) == EOF){
        exit (1);
    }

    do {
        c = (unsigned char) ci ;
        e = code(c,d);
        //printf("%c\n" , c);
        for (i=0 ; i<e.len ; i++){
            j++;
            j %= 8;
            //printf("j=%d e=%c\n", j, e.seqBits[i]);
            ecrire_2(out, e.seqBits[i]);

            /*
            buffer[j] = e.seqBits[i] ;
            j++ ;
            if(j==8){
                j=0 ;
                carac = bitToCar(buffer) ;
                fprintf(out , "%c" , carac) ;
                printf("On print %d \n" , carac);
            }
            */
        }
    } while((ci = fgetc(in->file)) != EOF);
    printf("ti\n");
    // Remplir de 0
    while ((j > 0) && (j < 8))
    {
        ecrire_2(out, '0');
        j++;
        //printf("Boucle infinie\n");
    }
    printf("ti\n");
}

