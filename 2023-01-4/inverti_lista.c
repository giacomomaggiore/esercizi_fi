#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num;
    struct nodo *next;
}lista;

int conta_elementi(lista *l){
    int i = 0;

    while(l != NULL){
        i++;
        l = l->next;
        
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
    
    len = 3;
    printf("len: %d\n", len);
    
    vettore = malloc(sizeof(int)*len);

    
    if(vettore){
            prec = l;
            for(prec = l; prec != NULL; prec = prec->next){
                *(vettore+i) = prec->num;
                i++;
            }
            
            printf("\n");
            
            temp = malloc(sizeof(lista));
            
            printf("Mumeri interi:");
            for(i = 0; i < len; i++){
                printf("%d ", *(vettore+i));
            }

            //INSERIMENTO ULTIMO ELEMENTO DEL VETTORE
            if(temp){
                temp->num = *(vettore+len-1);
                printf("Aggiunto elemento %d \n", temp->num);
                temp->next = NULL;
                i--;
                nuova = temp;
            }
            
            
            
            for(i = len-2;i >= 0; i--){
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
    printf("Visualizzazione Lista:\n");
    while(l != NULL){
        printf("%d\n", l->num);
        l = l->next;
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
    visualizza(nuova);

    
    
}