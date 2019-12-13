#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    if (argc!=2){
        printf("erreur, hoffman n'admet qu'un seul parametre !\n");
        exit(1);
    }
    FILE* fichier ;
    fichier = fopen ("try.txt" , "w");
    fprintf(fichier , "Essai\n");
    return 0;
}