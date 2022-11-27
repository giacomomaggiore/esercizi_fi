#include <stdio.h>
#define N 50
#define MAX_STR 31
#define nome_file "./localit.txt"
#define WRITE 9;

typedef struct{
	int x;
	int y;
	char nome[MAX_STR];
	}localita;

typedef struct{
	localita lista_l[N];
	int n;
}percorso;

void leggiTesto(percorso* l){
	FILE *fid;
	file_elenco = fopen(nome_file, "rb");
	int i = 0;
	if(fid){}
		while (!feof(fid)){
			fscanf(
		}


}
void scriviTesto(percorso* l){
	FILE *fid;
	int i;

	file_elenco = fopen(nome_file, "ab");
	if (file_elenco){
		for (i = 0; i < l->n; i++){ 
			fprintf(file_elenco, "%d %d %s", l -> lista_l[i].x, l -> lista_l[i].y, l->lista_l[i].nome);
	}
	fclose(file_elenco);

	}
	else{
		printf("File non aperto \n");
	}


int main(){
	percorso lista;
	lista.n = 0;
	int scelta;


	printf("Scegliere l'azione da eseguire\n");
	printf("1 - Inserire una nuova località.\n
			2 - Inserire una località in una posizione specifica\n
			3 - Visualizzare il percorso\n");

	while(True){
		scanf("%d", &scelta);	
	}
	
	if (scelta == WRITE){

	}

	}
