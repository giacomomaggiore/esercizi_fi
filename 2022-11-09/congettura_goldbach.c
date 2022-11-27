#include <stdio.h>
/* CONGETTURA DI GOLDBCH AVVERMA CHE OGNI NUMERO PARI MAGGIORE DI 2 PUÒ
ESSERE SCRITTO COME SOMMA DI DUE NUMERI PRIMI (ANCHE UGUALI)
SCRIVERE SOTTOPROGRAMMA CHE RICEVE UN INTERO POSITIVO MAGGIORE DI 1 E RESTITUISCE
1 SE È PRIMO, SENNÒ 0.
SCRIVERE UN PROGRAMMA CHE CHIEDE ALL'UTENTE UN NUMERO MAGGIORE DI 2 E CALCOLA E VISUALIZZA TUTTE
LE POSSIBILI COPPIE DI PRIMI CHE SODDISFANO LA CONGETTUEA */

int is_primo(int);
n
int main(){
	int pari;
	int i;
	int j;
	do{ 
		printf("Inserire un numero maggiore di 2\n");
		scanf("%d", &pari);
		}while(pari < 2);

	printf("%d", is_primo(pari));
		if (pari % 2 == 0){ 
		for (i = 2; i < pari/2; i++){
			if(is_primo(i)==1){

				for (j = 2; j < pari; j++){
					if (is_primo(j) == 1){
						if (i+j == pari)
						{
							printf("%d + %d = %d  COPPIA DESIDERATA\n", i, j,pari);
						}
					}
				}
			}
		}
	}





}


int is_primo(int a){
	int i;
	int ris = 1;
	for (i = 2; i*i < a; i++){
		if (a % i == 0){
			ris = 0;
			return ris;
		}
	}
	return ris;
}