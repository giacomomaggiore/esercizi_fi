#include <stdio.h>
/*FUNZIONE CE PRENDE UN VALORE INTERO E RESTITUISCE IL MODULO
FUNZIONE CHE RESTITUISCE IL MINORE TRA I DUE
PROGRAMMA CHE CHIEDE DUE VALORI E DA IL MINORE DEI VALORI ASSOLUTI */

int assoluto(int);

int minimo (int, int);


int main(){
	int a, b;
	printf("Inserire il primo valore\n");
	scanf("%d", &a);
	printf("Inserire il secondo valore\n");
	scanf("%d", &b);

	printf("%d",minimo(assoluto(a), assoluto(b)));
}

int assoluto(int a){
	int ris;
	if (a >= 0){
		ris = a;
	}
	else{
		ris = -a;
	}
	return ris;
}


int minimo(int a, int b){
	int ris;
	if (a < b){
		ris = a;
	}
	else{
 		ris = b;
 	}
 	return ris;
 } 
		




























		