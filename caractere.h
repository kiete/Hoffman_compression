#ifndef CARACTERE_H
#define CARACTERE_H

typedef struct t_noeud
{
    struct t_noeud* droit ;
    struct t_noeud *gauche;
    int poid ;
    char carac ;
}noeud;
typedef noeud* arbre ;

typedef struct t_element 
{
    arbre pArbre ;
    struct t_element *suiv;
    struct t_element *precedent;
}element;
typedef element* liste ;

#endif