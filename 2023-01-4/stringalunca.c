#include <stdio.h>
#include <string.h>


void stringalunga(char s[]){
	char temp;
	int len;
	int counter;
	int i;

	len = strlen(s);

	temp = s[len-1];

	for(i = len-1; i >= 0; i--){
		if (s[i] == temp){
			counter++;
		}
		else{
			printf("%c", temp);
			printf("%d", counter);
			temp = s[i];
			counter = 1;
		}
	}
	printf("%c", temp);
	printf("%d", counter);
}

int main(){
	char stringa[100];

	printf("Inserire la stringa: ");
	scanf("%s", stringa);

	stringalunga(stringa);


}