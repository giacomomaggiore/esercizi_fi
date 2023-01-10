#include<stdio.h>



int monotono(int numero, int* lunghezza){
	
	int i=0, rem=1, newnum, last;
	newnum = numero;
	while(newnum>0){
		newnum = newnum/10;
		(*lunghezza)++;
	}
	newnum = numero;
	last = -1;
	for(i=0; i<*lunghezza; i++){
		rem = newnum%10;
		newnum = newnum/10;
		if(last>rem){
			return 0;
		}
		last = rem;
	}
	
	return 1;
}


int main(){
	
	
	int numero, lunghezza=0, dec;
	printf("Inserire il numero: ");
	
	scanf("%d", &numero);
	
	dec = monotono(numero, &lunghezza);
	
	printf("\nIl numero è monotono decrecente?\n%d\nLUNGHEZZA: %d\n", dec, lunghezza);
	return 0;
}