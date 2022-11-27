#include <stdio.h>
#include <string.h>
#define NOME_FILE "testo.txt"

#define MAX_STR 31
#define MAX_LOCALITA 50



#define APPENDI 1
#define INSERISCI 2
#define WRITE_TESTO 9
#define READ_TESTO 10
#define WRITE_BIN 11
#define READ_BIN 12
#define EXIT 0


typedef struct{
		int x,y;
		char nome[MAX_STR];
}localita_t;

typedef struct{
	localita_t lista[MAX_LOCALITA];
	int n;
}lista_localita_t;


void leggiTesto(lista_localita_t* l){
	FILE *fptr;
	fptr = fopen(NOME_FILE,"r");
	int i;
	int x;
	int y;
	char nome[MAX_STR];
	if (fptr){
		while(!feof(fptr))
		{
			fscanf(fptr,"%d %d %s", &x,&y, nome);
			printf("%d %d %s", x, y, nome);
		i++;
		}

		l->n=i;
		
	}
	fclose(fptr);
}
void scriviTesto(lista_localita_t* l){
	FILE *fptr;
	fptr = fopen(NOME_FILE,"w");
	printf("%d\n", feof(fptr));
	int i;
	if (fptr){
		for(i=0;i<l->n;i++){
			fprintf(fptr,"%d %d %s", l->lista[i].x,l->lista[i].y, l->lista[i].nome);
		}
	}
	printf("%d\n", feof(fptr));
	fclose(fptr);
}
void scriviBinario(lista_localita_t* l){
	FILE *fptr;
	fptr = fopen(NOME_FILE,"wb");
	int i;
	if (fptr){
		fwrite(l,sizeof(l),1,fptr);
		fclose(fptr);
	}
	else
		printf("errore\n");
	fclose(fptr);
}

void leggiBinario(lista_localita_t* l){
	FILE *fptr;
	fptr = fopen(NOME_FILE,"rb");
	int i;
	if (fptr){
		fwrite(l,sizeof(l),1,fptr);
		fclose(fptr);
	}
	else
		printf("errore\n");
	fclose(fptr);
}

void appendi(lista_localita_t* l){
	if(l->n==MAX_LOCALITA){
		printf("la lista e' piena\n");
	}
	else{
		printf("inserire i dati della nuova localita'\n");
		scanf("%d %d %s", &l->lista[l->n].x, &l->lista[l->n].y, l->lista[l->n].nome);
		*(l->n) ++;
	}
}
int main(int argc, char *argv[])
{
	lista_localita_t lista;
	lista.n = 0;
	int s;
	s=-1;
	

	while(s!= EXIT)
	{
		printf("Scegliere l'azione da eseguire\n1  - Aggiungere una nuova localita \n2  - Inserire una località in una posizione speficia (NON DISPONIBILE)\n9  - Scrivere su un file di testo\n10 - Leggere da un file di testo\n11 - Scrivere su un file binario\n12 - Leggere da un file binario \n");


		scanf("%d",&s);
		if(s== WRITE_TESTO)
		{
			scriviTesto(&lista);
		}
		if(s== READ_TESTO)
		{
			leggiTesto(&lista);
		}

		else if( s== WRITE_BIN){
			scriviBinario(&lista);
		}
		else if( s== READ_BIN){
			leggiBinario(&lista);
		}
		else if (s == APPENDI)
		{
			appendi(&lista);
		}

		
	}
}