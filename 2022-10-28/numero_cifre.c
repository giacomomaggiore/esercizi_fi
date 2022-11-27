#include <stdio.h>
int main(){
	int num;
	int k;
	int ordine = 1;
	int i;



	do{
		printf("Inserire numero \n");
		scanf("%d", &num);
	}while( num <= 0);

	do{
		printf("Inserire il numero di cifre\n");
		scanf("%d", &k);
	}while(k <= 0);

	for(i = 0; i < k-1; i++){
		ordine = ordine*10;

	}
	printf("%d\n\n", ordine);

	while (num < ordine){
		printf("0");
		ordine = ordine / 10;
	}
		printf("%d", num);


}

