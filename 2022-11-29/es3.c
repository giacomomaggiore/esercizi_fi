/*
11.4 Scrivere un sottoprogramma che riceve come parametro un intero posi-
tivo N, alloca dinamicamente e restituisce una matrice quadrata NxN di valori
float. 
2Scrivere un sottoprogramma che riceve come parametro una matrice bidimen-
sionale di valori float allocata dinamicamente ed il suo numero di righe, e ne
libera la memoria.
Si consideri un file di testo serie.txt che contiene una sequenza di numeri. Il
primo valore, un intero n, indica quanti numeri float sono di seguito contenuti
nel file; si assuma che il file sia ben formato (cioè il numero di valori contenuti
è n+1, il primo valore è un intero ed i successivi numeri float). Per esempio il
file potrebbe contenere i valori: 4 3.5 4.3 5.4 3.4
Scrivere un programma che legge la sequenza di float dal file serie.txt salvan-
doli in un array dichiarato dinamicamente V. In seguito il programma calcola
il prodotto matriciale tra V (vettore colonna) e V trasposto (vettore riga) e vi-
sualizza la matrice risultante. Si utilizzino i due sottoprogrammi definiti sopra
per l’allocazione e la deallocazione di matrici dinamiche di float.
*/

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>




int chiedi_intero(){
	int n;
	printf("Inserisci un numero interno\n");

	scanf("%d", &n);
	return n;
}


double **allora_matrice(int N){
	double **p;
	int i;

	p = malloc(sizeof(double*)*N);
	if(p){
		//controlla che l'allocazione sia andata a buon fine
		for (i = 0; i < N; i++){

			*(p+i) = malloc(sizeof(double)*N);
		}
		return p;
	}
	else{
		printf("Memoria esaurita\n");
		free(p);

		return NULL;
	}

}
double *alloca_array(int N){
	//alloca dinamicamente un array di dimensione N

	double *v;
	v = malloc(sizeof(double)*N);
	if(v){
		return v;
	}
	else{
		printf("Memoria esaurita\n");
		return NULL;
	}
}

void popola_array(double *vett, int dimensione, FILE *file){

}

void visualizza_array(double *vett, int dimensione){
	int i;
	for (i = 0; i < dimensione; i++){
		printf("%lf\n", *(vett+i));
	}
}

double ** alloca_matrice(int righe, int colonne){
	double **p;
	int i;

	p = malloc(sizeof(double *)*righe);
	if(p){ 
		for (i = 0; i < righe; i++){
			*(p+i) = malloc(sizeof(double)*colonne);
		}
		printf("Matrice allocata con %d righe e %d colonne!\n", righe, colonne);
		return p;
	}
	else{
		printf("Memoria esaurita\n");
		return NULL;
	}
}

double **prodotto(double *vett1, double *vett2, int righe, int colonne, double **matrice){
	int i;
	int j;
	double somma;

	printf("Sto calcolando i prodotti... \n");
	sleep(1.5);
	printf("...\n");
	sleep(1.5);
	printf("...\n");
	sleep(1.5);
	printf("...\n");
	sleep(1.5);
	printf("...\n");


	for(i = 0; i < righe; i++){
		for (j = 0; j < colonne; j++){
			somma = *(vett1+i) *  (*(vett2+j));

			*(*(matrice+i)+j) = somma;
		}
	}
	 
}
void stampa_matrice(double **matrice, int righe, int colonne){
	int i;
	int j;
	for (i = 0; i < righe; i++){

		for(j = 0; j < colonne; j++){ 
			printf("%.2lf ", *(*(matrice+i)+j));
		}
			printf("\n");

	}

}


int main(){
	FILE *file1;
	FILE *file2;
	int dimensione1;
	int dimensione2;
	double *vett1;
	double *vett2;

	double **matrice;


	int i;

	file1 = fopen("1.txt", "r");
	file2 = fopen("2.txt", "r");

	fscanf(file1, "%d", &dimensione1);
	fscanf(file2, "%d", &dimensione2);

	vett1 = alloca_array(dimensione1);
	vett2 = alloca_array(dimensione2);

	printf("Dimensione 1: %d\n", dimensione1);

	printf("Dimensione 2: %d\n", dimensione2);

	for (i = 0; i < dimensione1; i++){ 
		fscanf(file1, "%lf ", vett1+i);
	
	}
	for (i = 0; i < dimensione1; i++){ 
		fscanf(file2, "%lf ", vett2+i);
	
	}
	printf("Vettore 1:\n");
	visualizza_array(vett1, dimensione1);

	printf("Vettore 2:\n");
	visualizza_array(vett2, dimensione2);

	matrice = alloca_matrice(dimensione1, dimensione2);

	prodotto(vett1, vett2, dimensione1, dimensione2, matrice);

	printf("MATRICE PRODOTTO:\n");
	stampa_matrice(matrice, dimensione1, dimensione2);
}