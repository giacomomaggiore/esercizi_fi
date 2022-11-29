/*
Scrivere un sottoprogramma che crea un array di interi dimensione N,
allocando la memoria dinamicamente.
Scrivere un sottoprogramma che in input un array di interi e la sua dimensione
N e trova il massimo elemento usando l’aritmetica dei pointer.
Scrivere un sottoprogramma che prende in input un array e libera la sua me-
moria.
Scrivere un programma che chiede all’utente di inserire un array di interi e
stampa a video il suo elemento massimo, usando i sottoprogrammi precedenti. */

#include <stdio.h>
#include <stdlib.h>
#define N 10

int chiedi_dimensione(){
	int dimensione;

	printf("Inserisci la dimensione dell'array \n");
	scanf("%d", &dimensione);

	return dimensione;
}
int acquisisci_array(int *p, int dimensione){
	int i;
	for(i = 0; i < dimensione; i++){
		printf("Inserisci l'elemento in posizione: %d \n", i+1);
		scanf("%d", (p+i));
	}
}
int visuallizza_array(int *p, int dimensione){
	int i;

	printf("\nArray da stampare");
	for(i =0; i < dimensione; i++){
		printf(" %d - ", *(p+i));

	}
	printf("\n");
}


int trova_massimo(int *p, int dimensione){
	int max = 0;
	int i;

	for (i = 0; i < dimensione; i++){
		if(*(p+i)>max){
			max = *(p+i);
		}
	}

	return max;

}
void libera_memoria(int *p){
	free(p);
	printf("Memoria eliminata!!! Complimenti!");
}



int main(){
	int n;
	int *p;
	int scelta;

	n = chiedi_dimensione();

	p = malloc(sizeof(int)*n);
	if (p){


		printf("Preparati a inserire i valori... \n\n");
		acquisisci_array(p, n);

		printf("Array acquisito, premi\n 1)per visualizzare l'array\n 2)Per trovare il massimo\n 3)Per liberare memoria\n");

		scanf("%d", &scelta);

		if(scelta == 1){
			visuallizza_array(p, n);

		}
		else if(scelta ==2){
			printf("Il massimo è: %d\n", trova_massimo(p,n));
		}
		else if(scelta == 3){
			libera_memoria(p);
		}
	}
	else{
		printf("Memoria esaurita! Compra più ram!");
	}
	



}