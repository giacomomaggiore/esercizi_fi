#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

char * carino(char s[], int n){
	//printf("Funzione chiamata con %s\n", s);

	int len;
	len = strlen(s);
	int i = 0;
	int j = 0;

	char *temp1;
	char *temp2;
	

	temp1 = malloc(sizeof(char)*len);
	temp2 = malloc(sizeof(char)*len);

	if(n > 1){
		//printf("N MAGGIORE DI 1\n");
		strcpy(temp1, s);
		strcpy(temp2, s);

		while(s[i] != 'x'){
			i++;
		}
		temp1[i] = '1';
		temp2[i] = '0';
		
		carino(temp1, n-1);
		carino(temp2, n-1);
		}
	else{
		//printf("CASO BASE\n");
		while(s[j] != 'x'){
			j++;
		}
		strcpy(temp1, s);
		strcpy(temp2, s);


		temp1[j] = '1';
		temp2[j] = '0';

		printf("%s\n", temp1);
		printf("%s\n", temp2);

	}

}

int main(){
	char s[6];
	s[0] = '1';
	s[1] = 'x';
	s[2] = 'x';
	s[3] = 'x';
	s[4] = 'x';
	s[5] = '0';

	carino(s, 4);
}