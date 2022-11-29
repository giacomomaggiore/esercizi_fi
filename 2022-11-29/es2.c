#include <stdio.h>
#include <stdlib.h> 
/*
Scrivere un sottoprogramma che riceve come parametro un intero posi-
tivo N, alloca dinamicamente e restituisce una matrice quadrata NxN di valori
interi. 

Scrivere un sottoprogramma che riceve come parametro una matrice bidimen-
sionale di valori interi allocata dinamicamente ed il suo numero di righe, e ne
libera la memoria.

Scrivere un programma che chiede all’utente la dimensione di una matrice qua-
drata m e poi i dati per popolarla

Il programma cerca nella matrice m la sottomatrice di dimensione
massima che parte da m[0][0] e la cui somma dei valori è pari a zero e, se esiste,
la salva in una seconda matrice allocata anch’essa dinamicamente. In seguito,
il programma stampa a video la nuova matrice calcolata (se esiste), libera la
memoria e termina. 

Esempio: se l’utente inserisce la matrice 3x3:
123
-1 -2 3
333
La sottomatrice a somma nulla di dimensione massima che parte da m[0][0] è:
12
-1 -2

*/

int chiedi_dimensione(){
	int dimensione;
	printf("Inserisci la dimensione della matrice\n");
	scanf("%d", &dimensione);

	return dimensione;
}
void acquisci_matrice(int **p, int dimensione){
	int i; 
	int j;


	for (i = 0; i < dimensione; i++){
		for (j = 0; j < dimensione; j++){
			printf("Inserire l'elemento su riga %d e colonna %d \n", i+1, j+1);
			scanf("%d", (*(p + i)+j));

			
		}
	}
}

void visualizza_matrice(int **p, int dimensione){
	int i; 
	int j;

	for (i = 0; i < dimensione; i++){
		for (j = 0; j < dimensione; j++){
			printf("%d ", *(*(p + i)+j));

			
		}
		printf("\n");
	}
	printf("\n");
}


int** alloca_matrice(int dimensione){
	int **p;
	int i;
	p = malloc(sizeof(int *)*dimensione);
	for (i = 0; i < dimensione; i++){

		*(p+i) = malloc(sizeof(int)*dimensione);
	}


	printf("Matrice allocata di dimensione %d x %d!!\n", dimensione, dimensione);
	return p;

}
int somma_matrice(int **p, int dimensione){
	int i;
	int j;

	int somma = 0;
	for (i = 0; i < dimensione; i ++){
		for (j = 0; j < dimensione ; j++){
			somma = somma + *(*(p+i)+j);
		}
	}
	return somma;
}


int cerca_sottomatrice(int **temp, int **p, int dimensione){
	int max = 0;
	int somma;
	int i;
	int j;

	
	visualizza_matrice(p, dimensione);

	for(i = 0; i < dimensione; i++){
		printf("\n\n");
		printf("Somma della matrice %d x %d\n", dimensione-i, dimensione-i);
		somma = somma_matrice(p, dimensione-i);
		printf("%d\n", somma);

		if (somma == 0 && dimensione-i > max){
			max = dimensione-i;
			printf("Massima dimensione trovata: %d\n", max);
		}


	}

	temp = alloca_matrice(max);
	for (i = 0; i < max; i ++){
		for(j = 0; j < max; j++){
			*(*(temp + i)+j) = *(*(p + i)+j);
		}
	}


	printf("Ciao!!!\nHo trovato una sottomatrice di dimensione %dx%d,\nla cui somma dei valori è 0\n", max, max);
	visualizza_matrice(temp, max);

	return max;

}



int main(){
	int dimensione;
	int **matrice;
	int **sotto_matrice;
	int dimensione_sottomatrice;

	dimensione = chiedi_dimensione();

	matrice = alloca_matrice(dimensione);
	acquisci_matrice(matrice, dimensione);

	printf("\nSto cercando la sottomatrice... Attendere \n");
	dimensione_sottomatrice = cerca_sottomatrice(sotto_matrice, matrice, dimensione);
	
	//printf("\nho trovato una sottomatrice...\n")
	//visualizza_matrice(sotto_matrice, dimensione_sottomatrice);
}