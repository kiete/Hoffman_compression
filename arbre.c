#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"
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

void set_carac(arbre a, unsigned char c){
    a->carac = c ;
}

arbre creer_arbre_complet(unsigned char e, int poids, arbre fg, arbre fd) {
    arbre a ;
    a = creer_arbre();
    set_poids(a, poids) ;
    set_carac(a, e) ;
    a->gauche = fg ;
    a->droit = fd ;

    return a;
}

arbre creer_feuille(unsigned char e, int poids) {
    return creer_arbre_complet(e, poids, creer_arbre(), creer_arbre());
}

int est_feuille (arbre a) {
    if (est_arbre_vide(a))
        return 0 ;
    return (est_arbre_vide(a->gauche) && est_arbre_vide(a->droit)) ;
}

int max (int a, int b){
    if (a>b) return a ;
    else return b ;
}

// calcule la hauteur d'un arbre
int hauteur(arbre a){
    if(est_arbre_vide(a)) return 0 ;
    else {
        return 1 + max(hauteur(a->gauche), hauteur(a->droit)) ;
    }
}

void print_arbre_aux(arbre a)
{
  if (est_arbre_vide(a))
    printf(".") ;
  else
  {
    printf("%c (", a->carac) ;
    print_arbre_aux(a->gauche) ;
    printf(") (");
    print_arbre_aux(a->droit) ;
    printf(")") ;
  }
}

void print_arbre(arbre a) // Notation préfixe
{
  print_arbre_aux(a) ;
  printf("\n") ;
  printf ("%d\n", poids(a));
  printf("\n");
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
