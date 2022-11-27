#include <stdio.h>
#define MAX 5


int acquisisci(int elenco[], int dimensione){
	int i; 
	for (i = 0; i < dimensione; i++){
		printf("Inserire l'elemento in posizione %d\n",  i+1);
		scanf("%d", &elenco[i]);
	}
}

void stampa_vettore(int vett[], int dim){
	int i;
	for (i = 0; i < dim; i ++){
		printf("%d ", vett[i]);
	}
	printf("\n");
}

int chiedi_k(int k){
	printf("Inserire (1) per ordinare l'array in senso crescente, (-1) per ordinare l'array in senso decrescente\n");
	scanf("%d", &k);
	return k;

}

void crescente(int vett[], int dimensione){
	int i; 
	int j;
	int temp;

	for (i = 0; i < dimensione; i++){
		for (j = i+1; j < dimensione; j++){
			if (vett[j] < vett[i]){
				temp = vett[i];
				vett[i] = vett[j];
				vett[j] = temp;
			}
		}
	}
}

void decrescente(int vett[], int dimensione){
	int i; 
	int j;
	int temp;
	for (i = 0; i < dimensione; i++){
		for (j = i +1; j < dimensione; j++){
			if(vett[j] > vett[i]){
				temp = vett[i];
				vett[i] = vett[j];
				vett[j] = temp;

			}
		}
	}
}



int main(){
	int a[MAX];
	int b[MAX];
	int k;


	acquisisci(a, MAX);
	stampa_vettore(a, MAX);

	k = chiedi_k(k);

	if (k == 1){
		crescente(a, MAX);
		stampa_vettore(a, MAX);
	}
	if (k == -1){
		decrescente(a, MAX);
		stampa_vettore(a, MAX);
	}



}
