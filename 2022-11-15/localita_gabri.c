#include <stdio.h>
#define NOME_FILE "testo.bin"
#define MAX_STR 31
#define MAX_LOCALITA 50
#define READ_TESTO 10
#define WRITE_TESTO 9
#define READ_BIN 11
#define WRITE_BIN 12
#define EXIT 0
#define APPENDI 1
#define INSERISCI 2
#define CANCELLA 3

typedef struct 
{
	int x, y;
    char nome [MAX_STR];
} localita_t;

typedef struct 
{
	localita_t lista[MAX_LOCALITA];
	int n;
} lista_localita_t;

void leggiTesto(lista_localita_t* l);{
FILE *fptr;
 char filename[MAX_STR];
 printf("inserisci il nome del file");
 fgets( filename, MAX_STR, stdin);
 fptr=fopen(filename, "r");
 int i;
 if(fptr){
 	while (!feof(fptr)){
 		fscanf(fptr, "%d %d %s", l->lista[i].x, l->lista[i].y, l->lista[i].nome);
 		i++;
 	

 	}
 	l->n = i;
 	fclose (fptr);
 }
 else {
 	printf("impossibile aprire file\n");
 }
}

void scriviTesto(lista_localita_t* l);{
 FILE *fptr;
 char filename[MAX_STR];
 fgets( filename, MAX_STR, stdin);
 fptr=fopen(filename, "w");
 int i;
 if(fptr){
 	for (i = 0; i < l->n; i++)
 	{
 		fprintf(fptr, "%d %d %s", l->lista[i].x, l->lista[i].y, l->lista[i].nome);
 	}
 	fclose (fptr);
 }
 else {
 	printf("impossibile aprire file\n");
 }
}

void leggiBinario(lista_localita_t* l);{
FILE *fptr;
 char filename[MAX_STR];
 printf("inserisci il nome del file");
 fgets( filename, MAX_STR, stdin);
 fptr=fopen(filename, "rb");
 int i;
 if(fptr){
 	fread (l, sizeof(l), 1, fptr);
 	fclose (fptr);
 }
 else {
 	printf("impossibile aprire file\n");
 }
}

void scribiBinario(lista_localita_t* l);{
FILE *fptr;
 char filename[MAX_STR];
 fgets( filename, MAX_STR, stdin);
 fptr=fopen(filename, "wb");
 int i;
 if(fptr){
 	fwrite (l, sizeof(l), 1, fptr);
 	fclose (fptr);
 }
 else {
 	printf("impossibile aprire file\n");
 }
}

void appendi (lista_localita_t* l){
	if (l-> == MAX_LOCALITA){
		printf ("la lista delle localita e piena\n");
	}
	else {
		printf ("inserisci i dati della nuova localita \n");
		scanf ("%d %d %s ", &l->lista[lista->n].x, &l->lista[lista->n].y, &l->lista[lista->n].nome);
		l->n++;
	}
}

void inserisci (lista_localita_t* l){
	if (l-> == MAX_LOCALITA){
		printf ("la lista delle localita e piena\n");
	}
	else {
		int nuovo_idx;
		printf ("inserisci nuovo indice;\n")
		scanf ("%d", &nuovo_idx);
		if (nuovo_idx < 0 || nuovo_idx > n){
			prinf ("indice non valido\n");
			return;
		}
		for (i=l->n-1; i>= nuovo_idx; i--){
			l->lista[i+1]=l->lista[i];
		}
		printf ("inserisci i dati della nuova localita \n");
		scanf ("%d %d %s ", &l->lista[nuovo_idx].x, &l->lista[nuovo_idx].y, &l->lista[nuovo_idx].nome);
		l->n++;
	}
}

void cancella (lista_localita_t* l){
	if (l-> == 0){
		printf ("la lista delle localita e vuota\n");
	}
	else {
		int indice;
		printf ("inserisci indice da cancellare:\n")
		scanf ("%d", &indice);
		if (nuovo_idx < 0 || nuovo_idx > n-1){
			prinf ("indice non valido\n");
			return;
		}
		for (i=indice; i<l->n-1; i++){
			l->lista[i]=l->lista[i+1];
		}
		l->n--;
	}
}

int main(int argc, char const *argv[])
{
	lista_localita_t lista;
    lista.n = 0;
    int s;
    s=-1;
    while (True && s!= EXIT){
    	scanf ("%d", &s);

    	if(s == WRITE_TESTO){
    		scriviTesto(&l);
    	}
    	else if(s == READ_TESTO){
    		leggiTesto(&l);
    	}
    	else if(s == WRITE_BIN){
    		scriviBinario(&l);
    	}
    	else if(s == READ_BIN){
    		leggiBinario(&l);
    	}
    	else if(s== APPENDI){
    		appendi(&l);
    	}
    	else if(s == INSERISCI){
    		inserisci(&l);
    	}
    	else if(s== CANCELLA){
    		cancella(&l);
    	}
    	
    }

	return 0;
}