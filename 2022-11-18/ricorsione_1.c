#include <stdio.h>
void ricorsione(int n){
	if (n > 0){
		printf("%d", n%2);
		ricorsione((n-n%2)/2);
	}

}

int main(){

	ricorsione(135);

}