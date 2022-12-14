#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char indirizzo[10];
	int dimensione;
	int numero_stanze;
	char classe_energetica;
	int posizione;
}casa;


typedef struct annuncio_t{
	int id;
	char data[20];
	int tipo;
	double prezzo;
	struct annuncio_t *next;

}annuncio;

annuncio * inserisci_coda(annuncio *l, int id, int tipo, double prezzo){
	annuncio *temp;
	annuncio *prec;
	int flag = 1;

	temp = malloc(sizeof(annuncio));
	temp->id = id;
	temp->tipo = tipo;
	temp->prezzo = prezzo;
	temp->next = NULL;

	if (l == NULL){
		l = temp;
	}
	else{
		for(prec = l; flag == 1; prec = prec->next){
			if (prec->next == NULL){
				prec->next = temp;
				flag = 0;
			}
			
		}
	}
	return l;
}


void visualizza(annuncio *l){
	while(l != NULL){
		printf("Id: %d\n", l->id);
		l = l->next;
	}
}
void visualizza_prezzi(annuncio *l){

	while(l != NULL){
		printf("Id: %d Prezzo: %f\n",l->id, l->prezzo);
		l = l->next;
	}
}


int cerca_massimo_prezzo(annuncio *l){
	double massimo = 0;
	int id_massimo = 0;
	while(l != NULL){
			if (l->prezzo>=massimo){
				massimo = l->prezzo;
				id_massimo = l->id;
			}

			l = l->next;
			
	}

	//printf("Prezzo massimo: %f\n", massimo);
	return id_massimo;
}


annuncio *inserisci_dopo(annuncio *l, int cerc, int id, int tipo, double prezzo){
	annuncio *temp;
	annuncio *temp_2;
	annuncio *prec;
	int flag = 1;

	temp = malloc(sizeof(annuncio));
	temp->id = id;
	temp->tipo = tipo;
	temp->prezzo = prezzo;

	if (l == NULL){
		l = temp;
	}
	else{
		for(prec = l; flag == 1; prec=prec->next){

			if(prec->id == cerc){
				temp_2 = prec->next;
				prec->next = temp;
				temp->next = temp_2;
				flag = 0;
			}
	}
	}
	return l;
}

annuncio *inserisci_prezzo_crescente(annuncio *l, int id, int tipo, double prezzo){
	annuncio *temp;
	annuncio *prec1;
	annuncio *prec2;
	annuncio *current;
	int posizione = 0;



	temp = malloc(sizeof(annuncio));
	temp->id = id;
	temp->tipo = tipo;
	temp->prezzo = prezzo;
	temp->next = NULL;


	//CASO IN CUI LA LISTA È VUOTA
	if (l == NULL){
		l = temp;
		temp->next = NULL;
	}

	//CASO IN CUI L'ELEMENTO DA INSERIRE È MINORE DEL PRIMO
	else if (prezzo < l->prezzo){
		temp->next = l;
		l = temp;

	}
	//CASO GENERALE
	else{
		prec1 = l;
		while(prec1->next != NULL && prec1->next->prezzo < temp->prezzo){
				prec1 = prec1->next;
			}
				
			
		//posizione è l'elememto dopo cui inserire l'elemento

		temp->next = prec1->next;
		prec1->next = temp;
	
}
	return l;




	
}

void leggi_binario(FILE *file){
	struct myStruct{ 
	int id;
	char data[20];
	int tipo;
	double prezzo; 
	};

	struct myStruct annuncio_scrivere;

	file = fopen("annunci.bin", "rb");



	do{
		fread(&annuncio_scrivere, sizeof(annuncio_scrivere), 1, file);
		printf("%d %f\n", annuncio_scrivere.id, annuncio_scrivere.prezzo);

	}while(!feof(file));


	fclose(file);
}

annuncio *rimuovi(annuncio *l, int id){
	annuncio *prec1;
	annuncio *prec2;
	annuncio *temp;
	if(l == NULL){
		printf("Lista vuota!\n");
	}

	else if(l->id == id){
			temp = l;
			l = l->next;
			free(temp);
	}
	else{
		prec1 = l;
		prec2 = l->next;
		while (prec2 != NULL){
			if (prec2->id == id){
				printf("Trovato\n");
				prec1->next = prec2->next;
				free(prec2);
			}
			prec1 = prec1->next;
			prec2 = prec2->next;
		}
	}

	return l;
}


FILE *scrivi_binario(FILE *file, annuncio *l){

	
	struct myStruct{ 
	int id;
	char data[20];
	int tipo;
	double prezzo; };

	struct myStruct annuncio_scrivere;

	file = fopen("annunci.bin", "wb");



	while (l != NULL){
		annuncio_scrivere.id = (l->id);
		annuncio_scrivere.tipo = l->tipo;
		annuncio_scrivere.prezzo = l->prezzo;
		strcpy(annuncio_scrivere.data, l->data);



		fwrite(&annuncio_scrivere, sizeof(annuncio_scrivere), 1, file);
		l = l->next;
	}

	fclose(file);
}

int main(){
	int id;
	int tipo;
	double prezzo;
	char data[20];
	annuncio *l = NULL; //recente
	annuncio *p = NULL; //prezzo
	FILE *fid;
	int scelta;


	l = inserisci_coda(l, 1, 23, 30.0);
	l = inserisci_coda(l, 3, 23, 31.0);
	l = inserisci_coda(l, 2, 23, 34.0);

	p = inserisci_coda(p, 1, 23, 30.0);
	p = inserisci_coda(p, 3, 23, 31.0);
	p = inserisci_coda(p, 2, 23, 34.0);

	printf("Benvenuto!\n\n\n");

	do{ 
	printf("1 - VISUALIZZA ELENCO\n2 - VISUALIZZA ELENCO IN ORDINE DI PREZZO\n3 - AGGIUNGI ANNUNCIO\n4 - RIMUOVI ANNUNCIO\n0 - ESCI\n");
	scanf("%d", &scelta);

	if(scelta == 1){
		printf("Ecco la lista in ordine cronologico:\n");
		visualizza(l);
	}
	else if (scelta == 2){
		printf("Ecco la lista in ordine di prezzo:\n");
		visualizza(p);
	}
	else if(scelta == 3){

		printf("\nInserire Id annuncio: ");
		scanf("%d", &id);
		printf("\nInserire il tipo di annuncio: ");
		scanf("%d", &tipo);
		printf("\nInserire il prezzo: ");
		scanf("%lf", &prezzo);
		printf("\nInserire la data: ");
		scanf("%s", data);	

	l = inserisci_coda(l, id, tipo, prezzo);
	p = inserisci_prezzo_crescente(p, id, tipo, prezzo);
	}
	else if(scelta == 4){
		printf("Inserisci l'Id dell'elemento da rimuovere: ");
		scanf("%d", &id);

		l = rimuovi(l, id);
		p = rimuovi(p, id);
	}



	}while(scelta != 0);




	
}