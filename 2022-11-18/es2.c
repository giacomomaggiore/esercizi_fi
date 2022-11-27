#include <stdio.h>
#define MAX 20

int acquisisci(int elenco[]){
	int dim;
	int i;
	int temp;
	int len;

	do{
		printf("Quanti valori vuoi inserire: (massimo %d) \n", MAX);
		scanf("%d", &dim);
	}while(dim > MAX);
	for (i = 0; i < dim; i++){
		printf("Inserire l'intero in posizione %d\n", i+1);
		scanf("%d", &temp);

		if (i == 0){
			elenco[0] = temp;
			len = len + 1;}
		if(i > 0){
			if (temp > elenco[i-1]){
				elenco[i] = temp;
				len = len + 1;

			}
		}
	}
	return len;

}

void stampa(int elenco[], int dimensione){
	int i; 
	printf("La dimensione è: %d\n", dimensione);
	for (i = 0; i < dimensione; i ++){
		printf("%d", elenco[i]);
	}
}



int main(){
	int elenco[MAX];
	int len = acquisisci(elenco);
	


	stampa(elenco, len);


}