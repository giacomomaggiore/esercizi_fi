#include <stdio.h>
#include <stdlib.h>

int quesito(FILE *f){
	int num;
	int digits[10];
	int i;
	int provv;
	int max;
	int risultato;


	max = 0;

	if(fscanf(f, "%d", &num) == 1){
		for (i = 0; i < 10; i++){
			digits[i] = 0;
		}
		while (num > 0){
			provv = num % 10;
			digits[provv]++;
			num = (num - provv)/ 10;
		}
		for(i = 0; i < 10; i++){
			if (digits[i] > max){
				max = digits[i];
				risultato = i;
			}
		}


	}
	return risultato;
}


int main(){
	FILE *f;

	f = fopen("file.txt", "r");

	printf("%d", quesito(f));

}