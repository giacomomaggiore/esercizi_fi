#include <stdio.h>
#define DOCUMENTO "lmin.txt"


int main(){
	char nome[80];
	FILE *f;
	int lmin;
	int lmax;
	int len;
	int temp;
	int min;
	int max;
	int somma;

	lmin = 0;
	lmax = 10;
	len = 0;

	min = lmax;
	max = lmin;


	f = fopen(DOCUMENTO, "r");
	
	if(f){
		while(!feof(f)){
			fscanf(f,"%d", &temp);
			if(temp > lmin && temp < lmax){
				len++;
				somma = somma + temp;
				if(temp < min){
					min = temp;
				}
				if (temp > max){
					max = temp;
				}
			}			
		}
	}
	fclose(f);

	printf("Minimo: %d\n", min);
	printf("Massimo: %d\n", max);
	printf("Media: %d\n", somma / len);

}