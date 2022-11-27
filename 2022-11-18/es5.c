#include <stdio.h>
#include <string.h>


#define MAX 30
 
int acquisisci(char stringa[]){

	do{ 
	printf("Inserire la stringa in cui ricercare le sottostringhe: \n");
	scanf("%[^\n]", stringa);
	
	}while(strlen(stringa) > MAX);
}

int cerca_sottostringa(char stringa[]){
	int len = strlen(stringa);
	int i;
	int j;
	int k = 0;
	int max = 0;

	for (i = 0; i< len; i++){
			for (j = 1; j+i< len; j++){
				if (stringa[i] != stringa[i+j]){
					k = k + 1;
				}

				if (k > max){
					max = k;
					k = 0;
				}
				if (k <= max){
					k = 0;
				}

			}
		
		}

	
	printf("\nLa dimensione della sottostringa è: %d\n", max);
	return max;
}


int main(){
	char stringa[MAX];
	acquisisci(stringa);

	cerca_sottostringa(stringa);



}