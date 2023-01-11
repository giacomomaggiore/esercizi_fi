#include <stdio.h>


void lessico(char s[], int n, int m){
	int i;
	int j;
	int k;
	char max;
	char temp;


	for(i = n; i < m+1; i++){
		max = 0;

		for(j = i; j < m+1; j++){
			if(s[j] >max){
				max = s[j];
				k = j;
			}
		}
		temp = s[i];
		s[i] = max;
		s[k] = temp;
	}
}


int main(){
	char s[100];


	printf("Inserisci la stringa:\n");
	scanf("%s", s);

	lessico(s, 2, 5);
	printf("%s", s);
}