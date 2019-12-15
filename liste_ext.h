/* Algo - TP3 */
/* Header - Module Listes Ext */
/* Fonctions supplementaires sur les listes */

#ifndef LISTES_EXT_H
#define LISTES_EXT_H

#include <stdio.h>
#include "listes.h"

Liste creer_liste_vide() ;
int est_liste_vide (Liste l) ;
Liste ajouter (elt e, Liste l) ;
elt tete (Liste l) ;
Liste queue (Liste l) ;
void liberer_liste (Liste l) ;
elt liberer_maillon (Liste l) ;
int recherche (elt x, Liste l) ;
Liste copier (Liste l) ;
Liste InverseRec (Liste l, Liste tmp) ;
Liste inverser (Liste l) ;
Liste inserer (Liste l, int i, elt e) ;
Liste insertNode (Liste l, elt a) ;
Liste removeNode (Liste l, arbre *a);
Liste ajouter_fin (elt e, Liste l) ;
void afficherListe (Liste l) ;


#endif
