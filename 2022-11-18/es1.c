/*ACQUISISCE 100 VALORI E UN INTERO K
QUANDO NUMERO NEGFATIVO O NULLO TERMINA O PIÙ DI 100

SE COPPIA SOMMA = K RETURN 1 (ALTRIMENTI 0)

FUNZIONE CHE RICEVE K E L'ARRAY*/

#include <stdio.h>
#define MAX 100

int array(int array[]){
	int i;
	int len = 0;
	int temp;
	for(i = 0; i < MAX; i++){

		printf("Inserire l'intero positivo in posizione %d\n", i +1);
		
		scanf("%d", &temp);
		if (temp >= 0){
			array[i] = temp;
			len = len + 1;

		}else{
			i = MAX;
		}

	}
	return len;
}

int visualizza(int array[], int dimensione){
	int i;
	printf("L'array ricercato è: \n");
	for (i = 0; i < dimensione; i++){
		printf("%d \n", array[i]);
	}
	printf("\n");
}

int chiedi_k(){
	int k;

	printf("Inserisci un valore k: ");
	scanf("%d", &k);
	return k;
}



int cercasomma(int k, int dimensione, int elenco[]){
	int i;
	int j;
	for (i = 0; i < dimensione; i++){
		for (j = i; j < dimensione; j++){
			if (j != i && elenco[i] + elenco[j] == k){
				return 1;
			}
		}
	}
	return 0;

}

int main(){
	int elenco[MAX];


	printf("%d", cercasomma(chiedi_k(), array(elenco), elenco));
	
}