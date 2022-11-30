#include <stdio.h>
#include <stdlib.h>

#define N 10

int cosa_sei(int);
void istogramma(int*);
int max(int, int);

int main(){

	int vet[N];
	int i;
	int vet2[N];

	for(i=0; i<N; i++){

		printf("\nvalore n.%d: ",i+1);
		scanf("%d", &vet[i]);
		vet2[i] = cosa_sei(vet[i]);
	}

	printf("\n\n");

	for(i=0; i<N; i++){

		printf("%3d ", vet[i]);
	}

	printf("\n");

	for(i=0; i<N; i++){

		printf("%3d ", vet2[i]);
	}

	printf("\n\n");

	istogramma(vet2);


	return 0;
}

int cosa_sei(int num){

	int i;
	int sum=0;

	if(num<=0)
		return 0;

	for(i=2; i<=num/2; i++){

		if(num%i==0)
			sum = sum+i;
	}

	sum++;

	if(sum==num)
		return 1;

	else if(sum>num)
		return 2;

	else
		return 3;

}

void istogramma(int v[]){

	int perfetti=0, difettivi=0, abbondanti=0;
	int i,maxv, buff;

	//conto quanti ce ne sono

	for(i=0; i<N; i++){

		if(v[i]==1)
			perfetti++;

		else if(v[i]==2)
			difettivi++;

		else if(v[i]==1)
			abbondanti++;

	}

	//trovo il max dei 3

	buff = max(difettivi, abbondanti);

	maxv = max(perfetti, buff);

	//stampo istogramma

	for(i=maxv;i>=0;i--){

		if(difettivi==i){
			printf("*");
			difettivi--;
		}else{
			printf(" ");
		}

		if(abbondanti==i){
			printf("*");
			abbondanti--;
		}else{
			printf(" ");
		}

		if(perfetti==i){
			printf("*");
			perfetti--;
		}else{
			printf(" ");
		}

		printf("\n");

	}

}

int max(int a, int b){

	if(a>=b)
		return a;

	else
		return b;
}