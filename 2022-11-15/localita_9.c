#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 50
#define M 30
#define PROMPT "1. Inserire in coda una nuova localita’\n2. Inserire in una specificata posizione una nuova localita’\n3. Cancellare una localita’ nella lista\n4. Visualizzare l’intero percorso\n5. Visualizzare la lunghezza complessiva dell’itinerario\n6. Visualizzare la coppia di localita’ (anche non consecutive nel percorso) la cui distanza e’ maggiore di qualsiasi altra coppia\n7. Ricerca localita’ per nome\n8. Calcola la cornice intorno al percorso\n9. Salvare percorso su file di testo.\n10. Caricare percorso da file di testo.\n11. Salvare percorso su file binario.\n12. Caricare percorso da file binario.\n13. Uscita\n"


/*ATTENZIONE: NELLA COMPILAZIONE INCLUDERE LA LIBRERIA MATH.H. AGGIUNGI ARGOMENTO -lm ALLA FINE DELLA RIGA DI GCC:*/


typedef struct{
	
	
	
	int x;
	int y;
	char name[M];
	
} locs;


void clearView(){
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


void viewLoc(int len, locs percorso[]){
	clearView();
	printf("\n---FUNZIONE viewLoc---\n");
	for(int i=0; i<len; i++){
		printf("\n%d. %s | X: %d, Y: %d", i+1, percorso[i].name, percorso[i].x, percorso[i].y);
	}
	printf("\n---TOTALE LOCS: %d---\n", len);
}

void appendLoc(int *len, locs *percorso){
	clearView();
	printf("\n---FUNZIONE appendLoc---\n");
	if(*len>=50){
		printf("->ERRORE: Lista di località piena.\n");
	}
	else{
		(*len)++;
		printf("->INSERIRE NOME: ");
		scanf(" %[^\n]", percorso[(*len)-1].name);
		printf("->INSERIRE COORDINATE: \n-->X: ");
		scanf("%d", &percorso[(*len)-1].x);
		printf("-->Y: ");
		scanf("%d", &percorso[(*len)-1].y);
		printf("LOCALITA' %s INSERITA. RICORDA DI SALVARE!\n", percorso[*len].name);
		printf("------\n");
	}

}




void setLoc(int *len, locs percorso[]){
	
	clearView();
	viewLoc(*len, percorso);
	printf("---FUNZIONE setLoc---\n");
	
	int id;
	locs temp;
	
	do{
		printf("-> Inserire la posizione in cui aggiungere: ");
		scanf("%d", &id);
		id--;
	}while(id<0 || id>=*len);
	
	if(*len<=50){
		
		(*len)++;
		printf("->INSERIRE NOME: ");
		scanf(" %[^\n]", temp.name);
		printf("->INSERIRE COORDINATE: \n-->X: ");
		scanf("%d", &temp.x);
		printf("-->Y: ");
		scanf("%d", &temp.y);		
		
		for(int i=*len; i>=id; i--){
			percorso[i+1]=percorso[i];
		}
		percorso[id] = temp;
		printf("------");
	}
	else{
		printf("ERRORE: Percorso PIENO.");
	}

}





void remLoc(int *len, locs percorso[]){
	
	clearView();
	int id;
	printf("\n---FUNZIONE remLoc---\n");
	viewLoc(*len, percorso);
	do{
		printf("LOCALITA' DA RIMUOVERE: ");
		scanf("%d", &id);
		id--;
		
		
	}while(id<0 || id>=*len);
	
	for(int i=id; i<*len; i++){
	
		percorso[i]=percorso[i+1];
		
	}
	(*len)--;
	printf("------\n");
}


void getLen(int len, locs percorso[]){
	
	clearView();
	float total, dist;
	int deltax, deltay;
	printf("---FUNZIONE getLen---");
	
	
	for(int i=0; i<len-1; i++){
		deltax = percorso[i].x-percorso[i+1].x;
		deltay = percorso[i].y-percorso[i+1].y;
		dist = sqrt(1.0*deltax*deltax + 1.0*deltay*deltay);
		total += dist;
	}
	
	printf("LUNGHEZZA TOTALE: %f\n", total);
	printf("------\n");
	
}

void getMaxLen(int len, locs percorso[]){
	int deltax;
	int deltay;
	float dist = 0, max = 0;
	int id1, id2;
	clearView();
	printf("---FUNZIONE getMaxLen---\n");
	for(int i=0; i<len; i++){
		dist = 0;
		for(int j=0; j<len; j++){
			deltax = percorso[i].x-percorso[j].x;
			deltay = percorso[i].y-percorso[j].y;
			dist = sqrt(1.0*deltax*deltax+1.0*deltay*deltay);
			if(dist >= max){
				max = dist;
				id1 = i;
				id2 = j;
			}
		}
	}
	printf("COPPIA DI LOCALITA' PIU' DISTANTI:\n");
	printf("%s - %s\n", percorso[id1].name, percorso[id2].name);
	printf("DIST. %f\n", max);
	printf("------\n");
}


void searchLoc(int len, locs percorso[]){
	char input[M];
	int flag = 0, found;
	clearView();
	printf("---FUNZIONE searchLoc---\n");
	printf("Inserire il nome della localita: ");
	scanf(" %[^\n]", input);
	for(int i=0; i<len && !flag; i++){
		if(strcmp(input, percorso[i].name)==0){
			flag = 1;
			found = i;
		}
		
	}
	if(flag){
		printf("\nLocalità trovata: \n");
		printf("Nome: %s\n", percorso[found].name);
		printf("COORDINATE: X. %d, Y. %d\n", percorso[found].x, percorso[found].y);
	}else{
		
		printf("Localita non trovata.\n");
	}
	
	printf("------\n");
}


void getCornice(int len, locs percorso[]){
	clearView();
	printf("---FUNZIONE getCornice---\n");
	int minloc = 0, maxloc = 0;
	
	if(len>0){
		for(int i=0; i<len; i++){
			if((percorso[i].x>=percorso[maxloc].x)&&(percorso[i].y>=percorso[maxloc].y)){
				maxloc = i;
			}
			if((percorso[i].x<=percorso[minloc].x)&&(percorso[i].y<=percorso[minloc].y)){
				minloc = i;
			}

		}

		printf("---CORNICE TROVATA---\n");
		printf("->VERTICE ALTO SINISTRA: \n--> NOME:%s\n", percorso[maxloc].name);
		printf("--> COORDINATE:\n---> X: %d\n---> Y: %d\n", percorso[maxloc].x, percorso[maxloc].y);
		
		printf("->VERTICE BASSO DESTRA: \n--> NOME:%s\n", percorso[minloc].name);
		printf("--> COORDINATE:\n---> X: %d\n---> Y: %d\n", percorso[minloc].x, percorso[minloc].y);
	}
	else{
		
		printf("ERRORE: Il percorso è vuoto.\n");
	}
	printf("------\n");
	
}


void saveFileB(int len, locs percorso[]){
	clearView();
	char filename[M];
	printf("---FUNZIONE saveFileB---\n");
	printf("Inserire il nome del file di testo CON ESTENSIONE: ");
	scanf(" %s", filename);
	FILE *fid;
	


	fid = fopen(filename, "wb");		

	
	if(fid){
		
		fwrite(percorso, sizeof(locs), len, fid);
		fclose(fid);
		printf("\nFile percorso salvato con successo\n");
		
	}else{
		printf("\nERRORE NELL'APERTURA DEL FILE.\n");
	}
	
}


void loadFileTXT(int *len, locs percorso[]){
	clearView();
	char filename[M];
	printf("---FUNZIONE loadFileTXT---\n");
	printf("Inserire il nome del file di testo CON ESTENSIONE: ");
	scanf(" %s", filename);
	(*len)=0;
	FILE *fid;
	


	fid = fopen(filename, "r");		

	
	if(fid){
		while(!feof(fid) && (*len)<50){

			fscanf(fid, " %[^|]", percorso[*len].name);
			fscanf(fid, "|%d", &percorso[*len].x);
			fscanf(fid, "|%d\n", &percorso[*len].y);
/*ATTENZIONE: QUANDO LEGGI I FILE FORMATTATI IN TESTO INCLUDI I SEPARATORI NELLA STRINGA DI CONTROLLO. QUANDO FAI UN READ
DA UNA STRINGA DI TESTO CON ESPRESSIONE REGOLARE IL VALORE FINALE NON VIENE RAGGIUNTO (righe 269 & 270)*/
			(*len)++;
		}
		fclose(fid);
		printf("\nFile percorso salvato con successo\n");
		
	}else{
		printf("\nERRORE NELL'APERTURA DEL FILE.\n");
	}
	
}

void saveFileTXT(int len, locs percorso[]){
	clearView();
	char filename[M];
	printf("---FUNZIONE saveFileTXT---\n");
	printf("Inserire il nome del file di testo CON ESTENSIONE: ");
	scanf(" %s", filename);
	FILE *fid;
	


	fid = fopen(filename, "w");		

	
	if(fid){
		for(int i=0; i<len; i++){
			fprintf(fid, "%s", percorso[i].name);
			fprintf(fid, "|%d|%d\n", percorso[i].x, percorso[i].y);
		}
		fclose(fid);
		printf("\nFile percorso salvato con successo\n");
		
	}else{
		printf("\nERRORE NELL'APERTURA DEL FILE.\n");
	}
	
}





void loadFileB(int *len, locs percorso[]){
	clearView();
	char filename[M];
	printf("---FUNZIONE loadFileB---\n");
	printf("Inserire il nome del file di testo CON ESTENSIONE: ");
	scanf(" %s", filename);
	
	FILE *fid;;
	
	fid = fopen(filename, "rb");
	
	if(fid){
		*len = fread(percorso, sizeof(locs), 50, fid);
		fclose(fid);
		printf("Percorso caricato con successo.");
		viewLoc(*len, percorso);
	}
	else{
		printf("ERRORE NELL'APERTURA DEL FILE.\n");
	}
	
	
	
}


int main(){
	
	FILE *fid;
	int input, len = 0;
	locs percorso[N];
	
	printf("---LOCATION MANAGER---\n");
	printf("---AZIONI POSSIBILI---\n");
	printf("%s", PROMPT);
	
	do{
		
		do{
			printf("%s", PROMPT);
			printf("\nSCEGLIERE AZIONE: ");
			scanf("%d", &input);
		}while(input<0 || input > 13);
		
		
		if(input==1){
			appendLoc(&len, percorso);
		}else if(input==2){
			setLoc(&len, percorso);
		}else if (input==3){
			remLoc(&len, percorso);
		}
		else if(input==4){
			viewLoc(len, percorso);
		}
		else if(input==5){
			getLen(len, percorso);		
		}else if(input==6){
			getMaxLen(len, percorso);
		}else if(input == 7){
			searchLoc(len, percorso);
			
		}else if(input==8){
			getCornice(len, percorso);
		}else if (input==9){
			saveFileTXT(len, percorso);
		}else if(input==10){
			loadFileTXT(&len, percorso);
		}else if (input==11){
			saveFileB(len, percorso);
		}else if(input==12){
			loadFileB(&len, percorso);
		}
		
		
	}while(input!=13);
	
	
	return 0;
	
}