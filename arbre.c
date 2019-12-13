#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"
#include <math.h>
#define T_MAX 100

int est_arbre_vide(arbre a){
    return (a==NULL) ;
}

arbre gauche (arbre a){
    return a->gauche;
}

arbre droit (arbre a){
    return a->droit;
}

int poids(arbre a){
    return a->poids;
}

char carac(arbre a){
    return a->carac;
}

arbre creer_arbre(void){
    return malloc(sizeof(noeud));
}

arbre ajoute_gauche(arbre a){
    a->gauche = creer_arbre() ;
    return gauche(a);
}

arbre ajoute_droit(arbre a){
    a->droit = creer_arbre();
    return droit(a);
}

void set_poids (arbre a , int pds){
    a->poids = pds ;
}

void set_carac(arbre a, char c){
    a->carac = c ;
}

int hauteur(arbre a){
    if(est_arbre_vide(a)) return 0 ;
    else {
        return 1 + max(hauteur(a->gauche), hauteur(a->droit)) ;
    }
}

int est_feuille(arbre a){
    return(droit(a)==NULL && gauche(a)==NULL) ;
}

char* serialisation_plus(arbre a){
    char *str;
    int i;
    str = malloc(sizeof(char) * T_MAX);
    i = 0;
    int* p_i = &i;
    serialisation(a,str,p_i);
    str[i] = 0;
    return str;
}

void serialisation(arbre a, char*str, int*i){
    if (a==NULL){
        str[*i] = '0';
        (*i)++;
    }else{
        str[*i] = '1';
        (*i)++;
        str[*i] = a->carac;
        (*i)++;
        serialisation(a->gauche, str, i);
        serialisation(a->droit, str, i);
    }
}

arbre deserialisation_sup(char *chaine){
    int i;
    i=0;
    return deserialisation(chaine,&i);
}

arbre deserialisation (char* chaine, int*i){
    arbre pointeur ;
    if (chaine[*i]=='0'){
        (*i)++;
        pointeur = NULL;
    } else if (chaine[*i]=='1'){
        (*i)++;
        arbre pointeur = creer_arbre();
        set_poids(pointeur,chaine[*i]);
        (*i)++;
        pointeur->gauche = (deserialisation(chaine,i));
        pointeur->droit = (deserialisation(chaine,i));
        //return pointeur;
    }
    return pointeur;
}

// parcours en profondeur
void parcours_profondeur(arbre a){
    if(!est_arbre_vide(a)){
        printf("%d\n", racine(a)) ;
        parcours_profondeur(filsGauche(a)) ;
        parcours_profondeur(filsDroit(a)) ;
    }
}