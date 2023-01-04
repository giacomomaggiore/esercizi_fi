#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

#define ANNO 2021
#define MESE 9
#define GIORNO 1

#define N 4

typedef struct{
	int anno;
	int mese;
	int giorno;

	char lotto[11];
}vaccino;

typedef struct{
	char cf[17];
	int eta;

	int numero_vaccinazioni;
	vaccino informazioni[5];

}contatto;

int controllo_data(vaccino informazioni[], int len){
	int numero_vaccinazioni = len;
	int r_anno = 0;
	int r_mese = 0;
	int r_giorno = 0;

	int i;


	if (numero_vaccinazioni < 2){
		return 0;
	}
	else{
		for(i = 0; i < numero_vaccinazioni; i++){
			if(informazioni[i].anno > r_anno){
				r_anno = informazioni[i].anno;
			}
			else if(informazioni[i].mese > r_mese){
				r_mese = informazioni[i].mese;
			}
			else if (informazioni[i].giorno > r_giorno){
				r_giorno = informazioni[i].giorno;
			}
		}
		if(r_anno > ANNO){
			return 1;
		}
		else if (r_anno == ANNO){
			if(r_mese > MESE){
				return 1;
			}
			else if(r_mese == MESE && r_giorno >= GIORNO){
				return 1;
		}
	}
}
	return 0;
}

int selezione(contatto lista[], contatto selezione[], int len){
// INT ANNI
// 3 VACCINAZIONI
// 2 VACCINAZIONI PRIMA DEL 1/9/21
	int i;
	int j = 0;
	int selezionati[len];
	int numero_vaccinazioni;


	int eta;
	for (i = 0; i < len; i ++){
		eta = lista[i].eta;
		numero_vaccinazioni = lista[i].numero_vaccinazioni;


		if (eta < 5 || numero_vaccinazioni >= 3 || controllo_data(lista[i].informazioni, numero_vaccinazioni)){
			selezione[j] = lista[i];
			j = j + 1;
	}
	

	}
	return j;
}

void popola(contatto lista[], int len){
	int i;
	int j;
	int numero_vaccinazioni;


	int eta;
	int anno;
	int giorno;
	int mese;
	for (i = 0; i < len; i++){
		printf("Persona N %d: \n", i+1);
		printf("Inserisci età: "); 
		scanf("%d", &eta);
		printf("Inserisci il numero di vaccini: ");
		scanf("%d", &numero_vaccinazioni);
		lista[i].eta = eta;
		lista[i].numero_vaccinazioni = numero_vaccinazioni;

		for (j = 0; j < numero_vaccinazioni; j++){
			printf("%d, Inserire anno, giorno e mese: ", j + 1);
			scanf("%d %d %d", &anno, &mese, &giorno);

			lista[i].informazioni[j].anno = anno;
			lista[i].informazioni[j].mese = mese;
			lista[i].informazioni[j].giorno = giorno;
		}
	}
}

void visualizza(contatto lista[], int len){
	int i;
	int j;
	for (i = 0; i < len; i ++){
		printf("\nEtà: %d Vax: %d ", lista[i].eta, lista[i].numero_vaccinazioni);
		if (lista[i].numero_vaccinazioni > 0){ 
			for (j = 0; j < lista[i].numero_vaccinazioni; j++){
				printf("%d ", lista[i].informazioni[j].anno);
			}
		}
	}
}


int main(){
	contatto lista[N];
	contatto sel[N];
	int dimensione;

	lista[0].eta = 1;
	lista[1].eta = 5;
	lista[2].eta = 32;
	lista[3].eta = 14;

	lista[0].numero_vaccinazioni = 3;
	lista[1].numero_vaccinazioni = 2;
	lista[2].numero_vaccinazioni = 0;
	lista[3].numero_vaccinazioni = 3;
	
	lista[0].informazioni[0].anno = 2009;
	lista[0].informazioni[1].anno = 2012; 
	lista[0].informazioni[2].anno = 2010;

	lista[1].informazioni[0].anno = 2023;
	lista[1].informazioni[1].anno = 2023;

	lista[3].informazioni[0].anno = 2002;
	lista[3].informazioni[1].anno = 1009;
	lista[3].informazioni[2].anno = 1990;



	dimensione = selezione(lista, sel, N);
	
	visualizza(lista, N);
	printf("\nSto effettuando la selezione naturale");
	sleep(1);
	printf("...\n");
	sleep(1);
	printf("...\n");
	sleep(1);
	printf("...\n");
	sleep(1);
	printf("...\n");
	sleep(1);
	printf("...\n");



	visualizza(sel, dimensione);
}
