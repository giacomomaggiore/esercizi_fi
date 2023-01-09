#include <stdio.h>
#define N 10


int trova(char s1[], char s2[]){
    if(*s1 == '\0'){
        return 1;
    }
    else if(*s2 == '\0'){
        return -1;
    }
    else{
        if(*s1 == *s2){
            return trova(s1+1,s2+1);
        }
        else{
            return trova(s1, s2+1);
        }
    }
    
    
}


int main(){
    
    printf("%d", trova("abcd", "acbd"));
    
}
