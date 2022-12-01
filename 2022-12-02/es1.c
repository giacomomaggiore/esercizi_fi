#include <stdio.h>
#include "funzioni.h"

int main(){
	int *vettore;
	int **matrice;
	printf("Hello world");

	matrice = alloca_matrice(2,2);
	acquisisci_matrice(matrice, 2,2);
	visualizza_matrice(matrice, 2,2);
}