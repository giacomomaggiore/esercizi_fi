#include <stdio.h>
#define BASE 10


int main(){
	int num;
	int i;
	int flag = 1;

	do{
		printf("Inserire il numero: \n");
		scanf("%d", &num);
	}while(num < 0);

	while( num > 0){

		for (i = num/2; i >= 2 && flag; i--){
			if (num % i == 0){
				flag = 0;
			}
			
				
		}
		num = num / BASE;
}

	printf("%d", flag);
}