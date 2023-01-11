#include <stdio.h>
#include <stdlib.h>

int *scomponi(int num){
	int *array;
	int i;
	int len;
	int buffer;
	int k;

	len = 0;
	buffer = num;
	k = 0;

	for(i = 2; i <= num;i++){
			if (num % i == 0){
				
				len = len + 1;
				num = num / i;
				i--;
			}
		
	}
		
	
	array = malloc(sizeof(int)*len);
	printf("Vettore allocato con dimensione %d\n", len);


	for (i = 2; i <= buffer; i++){
			if (buffer % i == 0){

				
				*(array+k) = i;
				k++;
				buffer = buffer / i;
				i--;
			}
		}
	
	
	printf("\nI divisori sono: ");
	for(k = 0; k < len; k++){
		printf("%d - ", *(array+k));
	}


	printf("\n\n");
	return array;

}


int main(){
	int num;

	printf("Inserire un intero di cui si vogliono trovare i divisori:  ");
	scanf("%d", &num);

	scomponi(num);



}