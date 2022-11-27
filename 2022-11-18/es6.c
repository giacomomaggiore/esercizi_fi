#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 1000



/*
0 se NON È strettamente positivo
1 se è PERFETTO (se corrisponde alla somma dei suoi divisori eccetto se stesso)
2 se è ABBONDANTE (minore della somma dei suoi divisori)
3 se è DIFETTIVO (altri casi)

*/


int acquisisci_array(int vett[], int d){
	int i;
	for (i = 0; i < d; i++){
		printf("Inserisci l'elemento in posizione %d\n", i+1);
		scanf("%d", &vett[i]);
	}

}


//ritorna l'indirizzo di memoria del vettore dei divisori
int * cerca_divisori(int n, int *divisori){ 
	int i;
	int j = 0; //contatore per le posizioni nel vettore dei divisori
	

	for (i = 1; i <= n/2; i++){
		if (n % i == 0){
			*(divisori+j) = i;
			j++;
			printf("\n%d", i);
		}
	}


	return divisori;
}


int visualizza_array(int *vett, int d){
	int i;
	for (i = 0; i < d; i++){
		printf("%d-", *(vett+i));

	}
}





int positivo(int n){
	if (n < 0){
		printf("NEGATIVO");

		return 1;
	}
	else{
		return 0;
	}
}

//input n e i suoi divisori
int perfetto(int n, int *vettore){
	int i;
	int somma = 0;
	for (i = 0; i < n; i++){
		somma = somma + *(vettore+i);
	}
	if (somma == n){
		printf("PERFETTO");
		return 1;	
	}
	else{
		return 0;
	}
	
}

int abbondante(int n, int *vettore){
	int i;
	int somma = 0;
	for (i = 0; i < n; i++){
		somma = somma + *(vettore+i);
	}
	if (n > somma){
		printf("ABBONDANTE");
		return 1;	
	}
	else{
		return 0;
	}
}

int return_definitivo(int n, int *vettore){
	if (positivo(n)){
		return 0;
	}
	else if (perfetto(n, vettore)){
		return 1;
	}
	else if (abbondante(n, vettore)){
		return 2;
	}
	else{
		printf("DIFETTIVO");
		return 3;
	}
}


int main(){
	int vettore_finale[N];


	int i;
	int *puntatore;

	int vett[N];
	int divisori[M];

	int *puntatore_divisori;
	int valore;

	puntatore_divisori = divisori;

	acquisisci_array(vett, N);

	printf("Array di partenza:\n");
	visualizza_array(vett, N);


	for (i = 0; i < N; i++){
		puntatore = malloc(sizeof(int)*i);
		valore = *(vett+i);


		printf("\nSto cercando i divisori di %d\n", valore);
		cerca_divisori(valore, puntatore);


		vettore_finale[i] =	return_definitivo(valore, puntatore);

		
	}

	printf("\n\nOutput finale:\n\n");

	visualizza_array(vett, N);
	printf("\n");

	visualizza_array(vettore_finale, N);




}