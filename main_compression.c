#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecriture.h"
#include "arbre.h"
#include "codage.h"
#include "lecture.h"
#include "huffman.h"
#define T_MAX 10000

arbre fakeTree(void)
{
    arbre a;
    a = creer_arbre();
    set_carac(ajoute_gauche(a), '\0');
    set_carac(ajoute_droit(a), 'd');
    //printf("Carac fils gauche : %c\n", carac(a->gauche)) ;
    //printf("Carac fils droit : %c\n", carac(a->droit)) ;
    set_carac(ajoute_droit(a->gauche), 'b');
    set_carac(ajoute_gauche(a->gauche), '\0');
    set_carac(ajoute_gauche(gauche(a)->gauche), 'e');
    set_carac(ajoute_droit(gauche(a->gauche)), 'p');
    return a;
}

void compress(char *file_in, char *file_out)
{
    arbre a;
    dico d;
    int n , len;
    int occ[256] = {0};
    unsigned char *serial;

    Bin_file *in = (Bin_file *)malloc(sizeof(Bin_file));
    open_file_read(in, file_in);
    // N=nb de char diff
    n = countCharInFile(occ, in->file);
    a = stringToHuffman(occ);
    print_arbre(a);
    serial = serialisation_plus(a , &len);

    printf("%s\n", serial);

    d = get_table(a , n);
    printf("ok\n");

    int i = 0;
    for (i = 0; i < n; i++) {
        printEntree(d[i]);
    }

    Bin_file *out = (Bin_file *)malloc(sizeof(Bin_file));
    open_file_write(out, "test.txt");

    fprintf(out->file, "%d\n", a->poids);

    fprintf(out->file, "%d\n", len);

    fprintf(out->file, "%s\n", serial);

    printf("Y\n");
    ecriture(in, out, d);

    //close_file(in);
    //close_file(out);
    printf("Compression effectuee\n");
}

void extract(char *file_in, char *file_out){
    arbre a;
    int n , i , j , len;
    unsigned char s[T_MAX];
    unsigned char c;

    Bin_file *in = (Bin_file *)malloc(sizeof(Bin_file));
    Bin_file *out = (Bin_file *)malloc(sizeof(Bin_file));
    in->fin = 0;
    in->i_record = 0;
    in->record_length = 0;

    open_file_read(in,file_in);
    open_file_write(out,file_out);

    fscanf(in->file , "%d\n" , &n);
    printf("n = %d\n" , n);

    fscanf(in->file, "%d\n", &len);

    j=0;
    while (j <= len){
        s[j++] = fgetc(in->file);
    }
    s[j] = 0;

    a = deserialisation_sup(s);
    print_arbre(a);

    for (i=0 ; i<n ; i++ ){
        fprintf(out->file , "%c", findChar(a,in));
    }
    //close_file(in);
    //close_file(out);
    printf("Extraction effectuee\n");
}

    int main(int argc, char *argv[])
{

    if (argc!=2){
        printf("erreur, Huffman n'admet qu'un seul parametre !\n");
        exit(1);
    }

    compress(argv[1], "test.txt");
    
    extract("test.txt" , "extrait.txt");

    return 0;
}