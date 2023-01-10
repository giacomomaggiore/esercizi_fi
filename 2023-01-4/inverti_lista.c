#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num;
    struct nodo *next;
}lista;

int conta_elementi(lista *l){
    int i = 0;
    while(l != NULL){
        l = l->next;
        i = i + 1;
    }
    return i;
}

lista *inverti(lista* l){
    int len;
    int *vettore;
    lista *nuova;
    lista *temp;
    lista *prec;
    int i = 0;
    
    len = conta_elementi(l);
    printf("len: %d\n", len);
    
    vettore = (int*) malloc (len * sizeof(int));
    if(vettore){
            prec = l;
            printf("Primo :%d\n", prec->next->num);

            for(prec = l; prec!= NULL; prec = prec->next){
                printf("--%d ", prec->num);
            }
            
            
            printf("ciao");
            
            temp = malloc(sizeof(lista));
            if(temp){
                temp->num = *(vettore+i);
                temp->next = NULL;
                i--;
                l = temp;
            }
            
            
            
            for(i = len-1 ;i >= 0; i--){
                temp = malloc(sizeof(lista));
                if(temp){
                    temp->num = *(vettore+i);
                    temp->next = NULL;
                }
                for(prec = nuova; prec->next !=NULL; prec = prec->next);
                prec->next = temp;
            }
        }
                
                
        return nuova;
    
}

lista* inserisci_testa(lista *l, int num){
    lista *temp;
    temp = malloc(sizeof(lista));
    if(temp){
        temp->num = num;
        temp->next = l;
        l = temp;
        
    }
    printf("Aggiunto elemento %d\n", temp->num);
    
    return l;
}

void visualizza(lista *l){
    lista *prec;
    prec = l;
    printf("Visualizzazione Lista:\n");
    while(prec != NULL){
        printf("%d\n", prec->num);
        prec = prec->next;
    }
}


int main(){
    lista *l = NULL;;
    lista *nuova = NULL;
    l = inserisci_testa(l, 1);
    l = inserisci_testa(l, 2);
    l = inserisci_testa(l, 3);
    
    visualizza(l);
    nuova = inverti(l);
    //visualizza(new);

    
    
}