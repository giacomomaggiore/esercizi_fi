#include <stdio.h>
#include <string.h>
/* PROGRAMMA CHE RICHIEDE USERNAME CON AKLMENO N E L LETTERE MAIUSCOLE O MINUSCOLE
E NON CONTENGA CARATTERI SPECIALI, UN SOTTOPGORAMMA RICEVE LA STRINGA E RESTITUISCE 1 SE RISPECCHIA
LA CONDIZIONE, 0 ALTRIMENTI.
- N CARATTERI
- L LETTERE
NO STRINGHE DI CONTROLLO % : ; -+

*/
#define N 8
#define L 2
#define SYMB "%:;-+"

int checkInput(char username[], int n, int l, char symb[]){

	int i = 0;
	int flag = 1;
	int j = 0;
	int contatore = 0;

	
	while (username[i] != '\0' && flag == 1){
		for(j = 0; symb[j] != '\0'; j++){
			if(username[i] == symb[j]){
				flag = 0;
			}
			
		}
			
			if(username[i] >= 'a' && username[i] <= 'z'|| 
				username[i] >= 'A' && username[i] <= 'Z'){ 
				contatore++;
			}
			i++;
	}

	if (i <= L || contatore <= N ){
		flag = 0;
	}
	return flag;

}


int main(){
	char username[30];
	int flag;

	printf("Inserire l'username\n");
	fgets(username, 30, stdin);
	
	flag = checkInput(username, N, L, SYMB);
	printf("%d", flag);



}