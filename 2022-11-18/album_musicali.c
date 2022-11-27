#include <stdio.h>
#include <string.h>
#define MAX 100
#define MAX_STRINGA 30

typedef struct{
	int ore;
	int minuti;
	int secondi;
}durata;

typedef struct{
	char titolo[MAX_STRINGA];
	char autore[MAX_STRINGA];
	int anno;
	int numero_tracce;
	durata durata;
	double prezzo;
}album;



int main(){
	album archivio[MAX];
	char autore_ricercato[MAX_STRINGA];
	int dimensione;
	int i;
	int max = 0;
	int indice_massimo;

	printf("Quanti album vuoi inserire nell'archivio?\n");
	scanf("%d", &dimensione);

	for (i = 0; i < dimensione; i++){
		printf("Inserisci il titolo dell'album n %d\n", i +1);
		scanf("%s", archivio[i].titolo);
		printf("Inserisci l'autore dell'album n %d\n", i +1);
		scanf("%s", archivio[i].autore);
		printf("Inserisci l'anno di pubblicazione dell'album n %d\n", i +1);
		scanf("%d", &archivio[i].anno);
		printf("Inserisci il numero di tracce dell'album n %d\n", i +1);
		scanf("%d", &archivio[i].numero_tracce);
		printf("Inserisci la durata dell'album n %d\n", i +1);
		printf("Inserire il numero di ore\n");
		scanf("%d", &archivio[i].durata.ore);
		printf("Inserire il numero di minuti\n");
		scanf("%d", &archivio[i].durata.minuti);
		printf("Inserire il numero di secondi\n");
		scanf("%d", &archivio[i].durata.secondi);
		printf("Inserisci il prezzo dell'album n %d\n", i +1);
		scanf("%lf", &archivio[i].prezzo);
	}

	for (i = 0; i < dimensione; i++){
		if (archivio[i].durata.ore * 3600 + archivio[i].durata.minuti*60 + archivio[i].durata.secondi > max){
			max = archivio[i].durata.ore * 3600 + archivio[i].durata.minuti*60 + archivio[i].durata.secondi;
			indice_massimo = i;
		}

	}
	printf("L'album con la durata massima è:\n");
	printf("%s\n", archivio[indice_massimo].titolo);

	printf("Inserire il nome di un autore: \n");
	scanf("%s", autore_ricercato);
	for (i = 0; i < dimensione; i++){
		if (!strcmp(autore_ricercato, archivio[i].autore)){
			printf("%s", archivio[i].titolo);
		}
	}

}