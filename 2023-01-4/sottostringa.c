#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *quesito(char s[]){
	int i;
	int j;
	int max = 0;
	int indice;
	int counter;
	int indice_provv;

	for(i = 0; i < strlen(s); i++){
		counter = 0;
		indice_provv = i;
		j = i;

		while(s[j] != 32){
			counter++;
			j++;
		}
		if(counter > max){
			max = counter;
			indice = indice_provv;
		}
	}


	return s + indice;

}

int main(){
	char stringa[30];
	char seq[30];

	scanf("%[^\n]s", stringa);

	strcpy(seq, quesito(stringa));
	printf("\n");
	printf("%s", seq);
}