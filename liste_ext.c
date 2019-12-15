/* Algo - TP3 */
/* Module Listes Ext */
/* Fonctions supplementaires sur les listes */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "liste_ext.h"

Liste creer_liste_vide() {
    return NULL ;
}

int est_liste_vide (Liste l) {
    return l == NULL ;
}

Liste ajouter (elt e, Liste l) {
    Maillon *tmp ;
    tmp = (Maillon *)malloc (sizeof (Maillon)) ;
    tmp->Elt = e ;
    tmp->suiv = l ;
    return tmp ;
}

elt tete (Liste l) {
    assert (!est_liste_vide (l)) ;
    return (l->Elt) ;
}

Liste queue (Liste l) {
    assert (!est_liste_vide (l)) ;
    return (l->suiv) ;
}

void liberer_liste (Liste l) {
    if (est_liste_vide (l)) return;
    else {
        liberer_liste (queue (l)) ;
        free (l) ;
    }
}

elt liberer_maillon (Liste l) {
    elt tmp ;

    assert (!est_liste_vide (l));
    tmp = l->Elt ;
    free (l) ;
    return tmp ;
}

int recherche (elt x, Liste l) {
    if (est_liste_vide (l)) {
        return 0 ;
    } else if (x == tete (l)) {
        return 1 ;
    } else {
        return recherche (x, queue (l)) ;
    }
}

Liste copier (Liste l) {
    Maillon *tmp ;
    if (est_liste_vide (l)) {
        return creer_liste_vide () ;
    } else {
        tmp = copier (queue (l)) ;
        return ajouter (tete (l), tmp) ;
    }
}

Liste InverseRec (Liste l, Liste tmp) {
    if (est_liste_vide (l)) {
        return tmp ;
    } else {
        return InverseRec (queue (l), ajouter (tete (l), tmp)) ;
    }
}

Liste inverser (Liste l) {
    return InverseRec (l, creer_liste_vide ()) ;
}


Liste inserer (Liste l, int i, elt e) {
    Maillon *tmp, *new ;
    int j ;

    tmp = l ;
    if (est_liste_vide (l)) {
        assert (i == 0) ;
        return ajouter (e, creer_liste_vide ()) ;
    } else {
        j = 0 ;
        while (j < i - 1) {
            tmp = tmp->suiv ;
            j++;
        }
        new = ajouter (e, queue (tmp)) ;
        tmp->suiv = new ;
    }
    
    return l ;
}

Liste insertNode (Liste l, elt a) {
   /* Maillon *new;
    Maillon *tmp;
    Maillon *prev;

    tmp = l;
    if (est_liste_vide(tmp)) return ajouter (a, creer_liste_vide());
    else if (est_liste_vide(queue(tmp))) {
        if (poids(a) < poids(tete(l))) {
            new = ajouter (a, tmp) ;
            return new ;
        } else {
            new = ajouter (a, queue(tmp)) ;
            tmp->suiv = new ;
        }
    }
    else {
            while (!est_liste_vide(queue(tmp)) && poids(a) > poids(tete(queue(tmp)))) {
                tmp = tmp->suiv ; 
            }
            prev = tmp ;
            tmp = queue (tmp) ;
            while (!est_liste_vide(tmp) && poids(a) < poids(tete(tmp))) {
                prev = tmp ;
                tmp = queue (tmp) ;
            }
            new = ajouter (a, tmp);
            prev->suiv = new;
    }*/
    Maillon *tmp = NULL ;
    Maillon *csl = l ;
    Maillon *elem = malloc(sizeof(Liste));
    if (!elem) exit(EXIT_FAILURE);
    elem->Elt = a;
    while (csl && poids(csl->Elt) < poids(a)) {
        tmp = csl;
        csl=csl->suiv ;
    }
    elem->suiv = csl ;
    if (tmp) tmp->suiv = elem ;
    else l = elem ;

    return l ;
}

Liste removeNode (Liste l, arbre *a) {
    *a = l->Elt ;
    return queue(l) ;
}

Liste ajouter_fin (elt e, Liste l) {
    Maillon *m, *tmp ;

    tmp = l ;
    if (est_liste_vide(l)) {
        m = ajouter (e, creer_liste_vide ()) ;
        return m;
    } else {
        while (!est_liste_vide(queue(tmp))) {
            tmp = queue (tmp) ;
        }
        m = ajouter (e, creer_liste_vide ()) ;
        tmp -> suiv = m ;
    }
    return l ;
}

void afficherListe (Liste l) {
    printf("Liste : \n");
    while (!est_liste_vide (l)) {
     //   printf ("%d -> ", l->Elt) ;
        print_arbre(l->Elt);
        printf ("\n") ;
        l = l->suiv ;
    }
    printf ("-----------------");
    printf ("\n") ;
}