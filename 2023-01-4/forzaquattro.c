#include <stdio.h>
// 0 VUOTO
// 1 ROSSO
// 2 GIALLO


int esito(int griglia[][7]){

	int i;
	int j;
	int counter = 0;
	int current;

	//ELEMENTI IN RIGA
	for(i = 0; i < 6; i++){
		counter = 0;
		temp = 1;

		for(j = 0; j < 7; j++){
			if(temp == griglia[i][j] && temp != 0){
				counter++;
				if(counter == 4)
			}
			else{
					temp = griglia[i][j];
					counter = 1;
			}
		}
	}


	//ELEMENTI IN COLONNA
	for(i = 0; i < 7; i++){
		counter = 0;
		temp = 1;

		for(j = 0; j < 6; j++){
			if(temp == griglia[j][i] && temp != 0){
				counter++;
				if(counter == 4){
					return temp;
				}
			}
			else{
					temp = griglia[j][i];
					counter = 1;
			}
		}
	}


	//ELEMENTI DIAGONAlE
	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++){
			temp = 1;
			counter = 0;
			for(k = 0; k  < 4; k++){
				if(temp == griglia[i+k][j+k] && temp != 0){
					counter++;
					if(counter == 4){
						return temp;
					}
				}
				else{
					temp = griglia[i+k][j+k];
					counter = 1;
				}
	}
		}
	}

}


int main(){
	int mat[6][7];




}