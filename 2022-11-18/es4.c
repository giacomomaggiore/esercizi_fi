#include <stdio.h>
#define MAX 3

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

void ordina_vettore(int vett[], int dimensione){
	int i; 
	int j;
	int temp;

	for (i = 0; i < dimensione; i++){
		for (j = i + 1; j < dimensione; j++){
			if (vett[j] < vett[i]){
				temp = vett[i];
				vett[i] = vett[j];
				vett[j] = temp;
			}
		}
	}
}

int elimina_dublicati(int vett[], int dimensione, int vettore_finale[]){
	int i;
	int k = 0;

	for (i = 0; i < dimensione; i++){
		if (vett[i] != vett[i+1]){
			vettore_finale[k] = vett[i];
			k = k + 1;
		}
	}


	return k;
}

int mixarr(int a1[], int a2[], int a3[], int dim1, int dim2){
	int elenco_provvorio[dim1+dim2];
	int min = 0;
	int i;
	int j;
	int k = 0;


	for (i = 0; i < dim1; i++){
		elenco_provvorio[i] = a1[i];
	}
	for (i = 0; i < dim2; i++){
		elenco_provvorio[dim1+i] = a2[i];
	}

	printf("\n\nL'elenco provvisorio è: \n");
	stampa_vettore(elenco_provvorio, dim1+dim2);
	ordina_vettore(elenco_provvorio, dim1+dim2);
	stampa_vettore(elenco_provvorio, dim1+dim2);
	elimina_dublicati(elenco_provvorio, dim1+dim2, a3);
	
	printf("La dimensione dell'array finale è: %d", elimina_dublicati(elenco_provvorio, dim1+dim2, a3));
	printf("L'array finale è: \n");
	stampa_vettore(a3, elimina_dublicati(elenco_provvorio, dim1+dim2, a3));

	
}


int main(){
	int a[MAX];
	int b[MAX];
	int c[MAX+MAX];
	


	acquisisci(a, MAX);
	acquisisci(b, MAX);

	
	mixarr(a, b, c, MAX, MAX);


}