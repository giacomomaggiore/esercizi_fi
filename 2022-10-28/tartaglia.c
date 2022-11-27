#include <stdio.h>
#define MAX 20


int main(){
	int n;

	int i;
	int k;



	int triangolo[MAX][MAX];

	do{
		printf("Inserire il nunero di righe del triangolo di Tartaglia");
		scanf("%d", &n);
	}while( n > MAX);


	/* 
	1 -- 1 - 1 -- 1 - 2 - 1 --

	*/
	for (i = 0; i < n; i ++){
		for (k = 0; i < k; k++){
			triangolo[i][k] = 0;
		}
	}
		triangolo[0][0] = 1;


	for (i = 1; i <= n; i++){
		for (k = 0; k<n; k++){
			triangolo[i][k] = triangolo[i-1][ik]+triangolo[i-1][k-1];
		}
	}


	for (i = 0; i < n; i ++){
		for (k = 0; k < n; k ++){
			printf("%d ", triangolo[i][k]);
		}
		printf("\n");
	}


}