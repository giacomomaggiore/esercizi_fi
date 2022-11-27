/* 8.6 Scrivere un sottoprogramma che riceve come parametri un array di interi e
la sua dimensione. Il sottoprogramma popola l’array con valori chiesti all’utente.

Scrivere un secondo sottoprogramma che riceve come parametri un array di
interi e la sua dimensione, quest’ultima passata per indirizzo. Il sottoprogramma
rimuove dall’array i valori duplicati ed aggiorna la dimensione ricevuta come
parametro con il numero effettivo di valori validi contenuti nell’array. 

Scrivere un terzo sottoprogramma che riceve come parametri due array con le relative
dimensioni. Assumendo che ciascuno dei due array in ingresso non contenga
valori duplicati, il sottoprogramma calcola l’intersezione del contenuto dei due
array salvando il risultato in un terzo array ricevuto anch’esso come parametro;
inoltre il sottoprogramma restituisce al chiamate tramite un ultimo parametro
passato per indirizzo il numero effettivo di valori contenuti nell’intersezione.


Scrivere un sottoprogramma che riceve come parametri un array di interi e la
sua dimensione e visualizza il contenuto dell’array. Scrivere un programma che
mediante l’ausilio dei sottoprogrammi sopra definiti 1) chiede all’utente i dati di
tre array contenenti 20 valori interi ciascuno, 2) rimuove i duplicati in ciascuno di
essi, 3) visualizza i tre insiemi risultanti, 4) calcola l’intersezione dei tre insiemi,
5) visualizza il risultato finale
*/

#include <stdio.h>
#define N 3

void array1(int array[], int dimensione){
	int i = 0;
	for (i = 0; i < dimensione; i++){
		printf("Inserire il valore in posizione %d:\n", i +1);
		scanf("%d", &array[i]);
	}
}

void array2(int array[], int *dimensione){
	int i, j;
	for (i = 0; i < *dimensione; i++){
		if (array[i] == array[i+1]){
				array[i+1] = array[i+2];
				*dimensione = *dimensione - 1;
			
			
		}
		
	}
	printf("Dimensione finale dell'array: %d\n", *dimensione);
}


void visualizza_array(int array[], int dimensione){
	int i = 0;
	printf("L'array desiderato è: \n");
	for (i = 0; i < dimensione; i++){
		printf("%d -", array[i]);
	}
	printf("\n");
}

int comparison_array(int array1[], int array2[], int dimensione1, int dimensione2){
	int intersezione[(dimensione1+dimensione2)/2];
	int i, j, k;
	k = 0;
	for (i = 0; i < dimensione1; i++){
		for(j = 0; j < dimensione2; j++){
			if (array1[i] == array2[j])
			{
				intersezione[k] = array1[i];
				k = k+1;
			}
		}
	}
	visualizza_array(intersezione, k);
	return k;
}


int main(){
	int elenco[N];
	int dimensione = N;
	int *puntatore;
	puntatore = &dimensione;
	
	int elenco1[N];
	int elenco2[N];

	array1(elenco1, N);
	array1(elenco2, N);

	comparison_array(elenco1, elenco2, N, N);

}