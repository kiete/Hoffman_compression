#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "arbre.h"
#define max(a, b) (((a) < (b)) ? b : a)

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

unsigned char carac(arbre a){
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

void set_carac(arbre a, unsigned char c){
    a->carac = c ;
}

// calcule la hauteur d'un arbre
int hauteur(arbre a){
    if(est_arbre_vide(a)) return 0 ;
    else {
        return 1 + max(hauteur(a->gauche), hauteur(a->droit)) ;
    }
}

int est_feuille(arbre a){
    return(droit(a)==NULL && gauche(a)==NULL) ;
}

unsigned char* serialisation_plus(arbre a){
    unsigned char *str;
    int i;
    str = malloc(sizeof(unsigned char) * T_MAX);
    i = 0;
    int* p_i = &i;
    serialisation(a,str,p_i);
    str[i] = 0;
    return str;
}

void serialisation(arbre a, unsigned char*str, int*i){
    if (a==NULL){
        str[*i] = '0';
        (*i)++;
    }else{
        str[*i] = '1';
        (*i)++;
        if (a->carac == 0) str[*i] = 'O';
        else str[*i] = a->carac ;
        (*i)++;
        serialisation(a->gauche, str, i);
        serialisation(a->droit, str, i);
    }
}

arbre deserialisation_sup(unsigned char *chaine){
    int i;
    i=0;
    return deserialisation(chaine,&i);
}

arbre deserialisation (unsigned char* chaine, int*i){
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
