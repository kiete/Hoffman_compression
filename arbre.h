#ifndef _ARBRE_H_
#define _ARBRE_H_
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct t_noeud
{
    struct t_noeud *droit ;
    struct t_noeud *gauche;
    int poids ;
    unsigned char carac ;
}noeud;
typedef noeud* arbre ;

typedef struct t_element 
{
    arbre pArbre ;
    struct t_element *suiv;
    struct t_element *precedent;
}element;

typedef element* liste ;

// Vérifie si un arbre est vide
int est_arbre_vide(arbre a);

// Verifie si a est une feuille
int est_feuille(arbre a);

arbre creer_feuille(unsigned char e, int poids);

// Retourne l'adresse de la branche a gauche
arbre gauche(arbre a);

arbre creer_arbre_complet(unsigned char e, int poids, arbre fg, arbre fd);

void print_arbre(arbre a);

// Retourne l'adresse de la branche a droite
arbre droit(arbre a);

// Retourne le poids du noeud de a
int poids(arbre a);

// Retourne le caractere du noeud de a
unsigned char carac(arbre a);

// Rencoie un pointeur sur un arbre vide
arbre creer_arbre(void);

// Ajoute un arbre a gauche du neoud a
arbre ajoute_gauche(arbre a);

// Ajoute un arbre a droite du neoud a
arbre ajoute_droit(arbre a);

// Fixe le poids du noeud
void set_poids(arbre a, int poids);

// Fixe le caractere d'un noeud
void set_carac(arbre a, unsigned char c);

// Transforme un arbre en chaine de caractere
void serialisation(arbre a, unsigned char *str, int *i);

// Transforme une str en arbre
arbre deserialisation(unsigned char *chaine, int *i);

// Calcule la hauteur d'un arbre
int hauteur(arbre a);

// Effectue la serialisation d'un arbre
unsigned char *serialisation_plus(arbre a , int* len);
void serialisation(arbre a, unsigned char *str, int *i);

// Effectue la deserialisation d'un arbre
arbre deserialisation_sup(unsigned char *chaine);
arbre deserialisation(unsigned char *chaine, int *i);

#endif