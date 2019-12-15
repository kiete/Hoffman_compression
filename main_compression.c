#include <stdio.h>
#include <stdlib.h>
#include "ecriture.h"
#include "arbre.h"
#include "codage.h"
#include "lecture.h"

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


int main(int argc, char *argv[])
{
    arbre a;
    dico d;
    int n;
    unsigned char *serial;

    if (argc!=2){
        printf("erreur, hoffman n'admet qu'un seul parametre !\n");
        exit(1);
    }
    int occ[256] = {0};

    Bin_file *in = (Bin_file *)malloc(sizeof(Bin_file));
    open_file(in, argv[1]);
    // N=nb de char diff
    n = countCharInFile(occ, in->file);
    a = stringToHuffman(occ);

    printf("ok\n");
    d = get_table(a);
    printf("ok\n");

    int i = 0;
    for (i=0 ; i<n ; i++){
        printEntree(d[i]);
    }

    Bin_file *out = (Bin_file *)malloc(sizeof(Bin_file));
    open_file(out, "test.txt" );

    fprintf(out->file, "%c", '0');

    serial = serialisation_plus(a);
    printf("a=%s\n" , serial);
    fprintf(out , "%s" , serial);

    ecriture(in->file, out->file, d);

    return 0;
}