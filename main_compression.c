#include <stdio.h>
#include <stdlib.h>
#include "ecriture.h"
#include "arbre.h"
#include "codage.h"

arbre fakeTree(void)
{
    arbre a;
    a = creer_arbre();
    set_carac(ajoute_gauche(a), 'a');
    set_carac(ajoute_droit(a), 'd');
    //printf("Carac fils gauche : %c\n", carac(a->gauche)) ;
    //printf("Carac fils droit : %c\n", carac(a->droit)) ;
    set_carac(ajoute_droit(a->gauche), 'b');
    set_carac(ajoute_gauche(a->gauche), 'c');
    set_carac(ajoute_gauche(gauche(a)->gauche), 'e');
    set_carac(ajoute_droit(gauche(a->gauche)), 'p');
    return a;
}


int main(int argc, char *argv[])
{
    arbre a;
    dico d;
    FILE *in,*out ;

    if (argc!=2){
        printf("erreur, hoffman n'admet qu'un seul parametre !\n");
        exit(1);
    }

    a = fakeTree ();
    printf("ok\n");
    d = get_table(a);
    printf("ok\n");

    int i = 0;
    for (i=0 ; i<4 ; i++){
        printEntree(d[i]);
    }
    
    out = fopen("try.txt", "w");
    in = fopen(argv[1], "r");
    ecriture(in, out, d);

    




    return 0;
}