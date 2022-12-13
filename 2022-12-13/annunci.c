#include <stdio.h>
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
	printf("VISUALIZZAZIONE DELLA LISTA IN ORDINE CRONOLOGICO \n");
	while(l != NULL){
		printf("Id: %d\n", l->id);
		l = l->next;
	}
}
void visualizza_prezzi(annuncio *l){
	printf("VISUALIZZAZIONE DELLA LISTA IN ORDINE CRESCENTE DI PREZZO\n");

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
	file = fopen("annunci.bin", "rb");
	annuncio temporaneo;



	do{
		printf("sono nel do while1\n");
		fread(&temporaneo, sizeof(annuncio), 1, file);
		printf("%d %f\n", temporaneo.id, temporaneo.prezzo);

	}while(!feof(file));


	fclose(file);
}


FILE *scrivi_binario(FILE *file, annuncio *l){
	file = fopen("annunci.bin", "wb");



	while (l != NULL){
		fwrite(&l, sizeof(annuncio), 1, file);
		l = l->next;
	}

	fclose(file);
}


int main(){
	annuncio *l = NULL; //recente
	annuncio *p = NULL; //prezzo
	FILE *fid;
	




	l = inserisci_coda(l, 1, 1, 14.3);
	l = inserisci_coda(l, 2, 1, 11.3);
	l = inserisci_coda(l, 3, 1, 10.3);
	l = inserisci_dopo(l, 1, 54, 1, 0.2);
	//visualizza(l);
	//printf("\n\n\n");

	p = inserisci_prezzo_crescente(p, 1, 1, 32.0);

	p = inserisci_prezzo_crescente(p, 2, 1, 22.0);

	
	p = inserisci_prezzo_crescente(p, 3, 1, 2.0);

	
	p = inserisci_prezzo_crescente(p, 4, 1, 52.0);


	p = inserisci_prezzo_crescente(p, 4, 1, 5.0);

	visualizza_prezzi(p);
	scrivi_binario(fid, p);
	leggi_binario(fid);

}