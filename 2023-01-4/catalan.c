#include <stdio.h>

int catalan(int n){
	int cat = 0;
	int i;
	if (n == 0){
		return 1;
	}
	else{
		for(i = 0; i < n; i++){
			cat = cat + catalan(i)*catalan(n-i-1);
		}
		
	}

	return cat;


}

int main(){
	printf("%d\n", catalan(4));
	printf("%d\n", catalan(2));
	printf("%d\n", catalan(3));




}