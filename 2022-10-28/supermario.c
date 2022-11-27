#include <stdio.h>
int main(){
	int n;
	int k;
	int i = 0;
	

	do{
		printf("Inserire l'altezza delle tue piramidi: \n");
		scanf("%d", &n);

	}while(n <= 0);

	/*

 	  * *
	 ** **
	*** ***
	
	*/

	for(k = 0; k <= n; k++){
		for (i = 0; i<n-k; i++){
			printf(" ");
		}
		
		for (i = 0; i < k; i++){
			printf("*");
		}

		printf(" ");


		for (i = 0; i < k; i++){
			printf("*");
		}
		for (i = 0; i < n-k; i++){
			printf(" ");
		}

		printf("\n");
}
	}

	
