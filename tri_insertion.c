//Algo de tri par insertion

#include <stdio.h>
#include <stdlib.h>
#define N 10

void tri_insertion(int tab[], int taille) ;
void afficher(int tab[], int taille) ;


int main()
{
	int T[N] = {5,4,8,6,3,1,5,7,9,2} ;
	tri_insertion(T, N) ;
	afficher(T, N) ;

	return 0 ;
}

void tri_insertion(int tab[], int taille)
{
	int x, j ;

	for (int i = 0; i < taille; i++){
		x = tab[i] ;
		j = i - 1 ;
		while (j >= 0 && x < tab[j]){
			tab[j + 1] = tab[j] ;
			j = j - 1 ;
		}
		tab[j + 1] = x ;
	}
	return ;
}


void afficher(int tab[], int taille)
{
	printf("[ ");
	for (int i = 0; i < taille; i++) printf("%d ", tab[i]) ;
	printf("]\n") ;
	return ; 
}