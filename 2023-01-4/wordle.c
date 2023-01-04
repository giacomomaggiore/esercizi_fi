#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//soluzione tentativo
// casto porta 01021
// casto costa 21221



void wordle(char tentativo[], char soluzione[], int *risultato){
	int len = strlen(tentativo);
	int i;
	int j;

	risultato = malloc(sizeof(int)*len);
	for(i = 0; i < len; i ++){
		if (tentativo[i] == soluzione[i]){
			*(risultato+i) = 2;
			tentativo[i] = '.';
		}
		else{
			for(j = 0; j < len; j++){
				if (tentativo[i]==soluzione[j]){
					*(risultato+i) = 1;
					tentativo[i] = '.';

				}
				
			}
		}
	}
	for(i = 0; i < len; i ++){
		if(tentativo[i] != '.'){
			*(soluzione+i) = 0;
		}
	}

	printf("\n");
	for(i = 0; i < len; i++){
		printf("%d", *(risultato+i));
	}

}


int main(){
	char tentativo[100];
	char soluzione[100];
	int *risultato;

	printf("Tentativo: ");
	scanf("%s", tentativo);
	printf("\nSoluzione: ");
	scanf("%s", soluzione);

	wordle(tentativo, soluzione, risultato);

}