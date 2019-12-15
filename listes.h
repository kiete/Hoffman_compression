/* Algo - TP3 */
/* Module Listes */
/* Implementation du type abstrait Liste */

#ifndef LISTES_H
#define LISTES_H
#include "arbre.h"

typedef arbre elt ;
struct zMaillon {
    elt Elt ;
    struct zMaillon *suiv ;
} ;
typedef struct zMaillon Maillon ;
typedef Maillon * Liste ;

#endif
