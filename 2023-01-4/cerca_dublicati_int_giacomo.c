#include <stdio.h>
#include <stdlib.h>

int quesito(int num){
    int len = 0;
    int buffer = num;
    int *vett;
    int i;
    int j;
    int counter = 0;
    
    while(num > 0){
        num = num / 10;
        len = len + 1;
    }
    
    printf("Buffer: %d, Len: %d\n", buffer, len);
    
    
    vett = malloc(sizeof(int)*len);
    if(vett){
        while(buffer > 0){
            printf("%d\n", buffer % 10);
            *(vett+i) = buffer % 10;
            i = i + 1;
            buffer = (buffer - (buffer % 10))/10;
        }
        
        printf("\n\n");

        for(i = 0; i < len; i ++){
            printf("%d", *(vett+i));
        }
        for(i = 0; i < len; i++){
            for(j = i+1; j < len; j++){
                if( *(vett+i) == *(vett+j)){
                    counter = counter + 1;
                    //printf("%d", *(vett+i));
                }
            }
        }
        
        
    }
    
    
    return counter;
}

int funzione(int num){
    int vett[10];
    int counter = 0;
    int i;
    int resto;
    
    for(i = 0; i < 10; i++){
        vett[i] = 0;
    }
    
    
    while(num > 0){
        resto = num % 10;
        vett[resto]++;
        num = num / 10;
    }
    for(i = 0; i < 10; i++){
        if(vett[i]>1){
            counter++;
        }
    }
    return counter;
    
    
    
    
}


int main()
{
    printf("%d\n", funzione(1232));
    printf("%d\n", funzione(23632));
    printf("%d\n", funzione(2232));
}