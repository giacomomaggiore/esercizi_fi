/* Quesito 3 [6 pti]
Scrivere un sottoprogramma che ricevuto in ingresso un valore intero restituisce al chiamante 
il numero di cifre che compaiono più di una volta. Per esempio, se il sottoprogramma riceve 
in ingresso il valore 3282821 il sottoprogramma restituisce il valore 2, perché la cifra 8 e 
2 compaiono entrambe più di una volta. */

#include <stdio.h>
#include <string.h>
#define N 50

int count_digits();
int controllo();
int controllo2();

int main(){

	int n;

	printf("\nnumero: ");
	
	do
		scanf("%d", &n);
	while (n<0);
	
	printf("\nmetodo conversione in stringa\nle cifre che compaiono più di una volta in %d sono %d\n\n", n, controllo(n));
	printf("\nmetodo divisioni\nle cifre che compaiono più di una volta in %d sono %d\n\n", n, controllo2(n));

	return 0;
}


//metodo con la conversione in stringa

int controllo(int n){

	int len, i, count;
	char numero[N];
	int doppi[10];

	for(i=0; i<10; i++)
		doppi[i]= 0;

	sprintf(numero, "%d", n);

	len = strlen(numero);

	count = 0;

	for(i=0; i<len ; i++){

		doppi[numero[i]-48]++;	

	}

	for(i=0; i<10; i++){

		if (doppi[i]>1){
			count++;
		}
	}

	
	return count;

}


//metodo con le divisioni

int controllo2(int n){

	int count = 0;
	int doppi[10];
	int i;
	int digit;

	//creo un array 'doppi' con 10 elementi inizializzato a zero 
	for(i=0; i<10; i++)
		doppi[i] = 0;


	while (n != 0) {
		
		digit = n % 10;
        doppi[digit]++;

        if (doppi[digit] == 2) {
            count++;
        }

        n /= 10;
    }

    return count;
}


/* come funziona quel ciclo while alla riga 82

esempio: numero 343542

Iterazione 1: 
	n è uguale a 343542. 
	Il resto della divisione di n per 10 è 2, quindi digit viene assegnato il valore 2. 
	Il valore di doppi[2] viene incrementato di 1. 
	Poiché doppi[2] è uguale a 1, il contatore count non viene incrementato. 
	n viene quindi diviso per 10 e il nuovo valore di n è 34354.

Iterazione 2: 
	n è uguale a 34354. 
	Il resto della divisione di n per 10 è 4, quindi digit viene assegnato il valore 4. 
	Il valore di doppi[4] viene incrementato di 1. 
	Poiché doppi[4] è uguale a 1, il contatore count non viene incrementato. 
	n viene quindi diviso per 10 e il nuovo valore di n è 3435.

Iterazione 3: 
	n è uguale a 3435. 
	Il resto della divisione di n per 10 è 5, quindi digit viene assegnato il valore 5. 
	Il valore di doppi[5] viene incrementato di 1. 
	Poiché doppi[5] è uguale a 1, il contatore count non viene incrementato. 
	n viene quindi diviso per 10 e il nuovo valore di n è 343.

Iterazione 4: 
	n è uguale a 343. 
	Il resto della divisione di n per 10 è 3, quindi digit viene assegnato il valore 3. 
	Il valore di doppi[3] viene incrementato di 1. 
	Poiché doppi[3] è uguale a 1, il contatore count non viene incrementato. 
	n viene quindi diviso per 10 e il nuovo valore di n è 34.

Iterazione 5: 
	n è uguale a 34. 
	Il resto della divisione di n per 10 è 4, quindi digit viene assegnato il valore 4. 
	Il valore di doppi[4] viene incrementato di 1. 
	Poiché doppi[4] è uguale a 2, il contatore count viene incrementato di 1. 
	n viene quindi diviso per 10 e il nuovo valore di n è 3.

Iterazione 6: 
	n è uguale a 3. 
	Il resto della divisione di n per 10 è 3, quindi digit viene assegnato il valore 3. 
	Il valore di doppi[3] viene incrementato di 1. 
	Poiché doppi[3] è uguale a 2, il contatore count viene incrementato di 1. 
	n viene quindi diviso per 10 e il nuovo valore di n è 0.

Poiché n è diventato zero, il ciclo while termina e la funzione controllo2 restituisce il valore di count, 
che in questo caso è uguale a 2. */


















