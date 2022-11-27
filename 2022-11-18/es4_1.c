#include <stdio.h>
#define MAX 5

int main(){
	int vett[MAX];
	int i;
	int j;
	int k = 0;
	int min;
	int temp;


	vett[0] = 3;
	vett[1] = 2;
	vett[2] = 1;
	vett[3] = 3;
	vett[4] = 2;

	for (i = 0; i < MAX; i++){
		for (j = i + 1; j < MAX; j++){
			if (vett[j] < vett[i]){
				temp = vett[i];
				vett[i] = vett[j];
				vett[j] = temp;
			}
		}
	}
	


	for (i = 0; i < MAX; i++){
		printf("%d ", vett[i]);
	}





}
