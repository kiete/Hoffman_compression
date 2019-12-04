#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc!=2){
        printf("erreur, hoffman n'admet qu'un seul parametre !");
        exit(1);
    }
    FILE* fichier ;
    fichier = fopen ("try.txt" , "w");
    fprintf(fichier , "Salut les mecs\n");
    return 0;
}