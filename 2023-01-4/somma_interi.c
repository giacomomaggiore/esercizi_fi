#include <stdio.h>
#include <stdlib.h>

int ** coppie(int n){


	int i;
	int counter = 0;
	int **coppie;
	int k;

	for(i = 1; i <= n/2; i++){
		counter++;
	}

	coppie = malloc(sizeof(int*)*counter);
	printf("Vettore allocato\n");
	for(i = 0; i < counter; i++){
		*(coppie +i) = malloc(sizeof(int)*2);
	}


	for(i = 1; i <= n/2; i++){
		*( *(coppie+i-1)) = i;
		*(* (coppie+i-1)+1) = n-i;

	}
	for(i = 0; i < counter; i++){
		printf("%d - %d\n", *( *(coppie+i)), *( *(coppie+i)+1));
	}

	return coppie;

}

int main(){

	int **matrice;
	int i;
	int k;



	coppie(10);
}