#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int el;
	struct nodo *next;
};

typedef struct nodo *lista;

lista seleziona(lista l);
lista aggiungi_in_coda(lista l, int num);
void visualizza_lista(lista l);


int main() {
	lista head = NULL;
	lista nuova_lista;
	int num;
	do {
		printf("Inserire nuovo valore (0 per terminare inserimento): ");
		scanf("%d", &num);
		if (num != 0) {
			head = aggiungi_in_coda(head, num);
			visualizza_lista(head);
		}
	} while(num != 0);
	nuova_lista = seleziona(head);
	visualizza_lista(nuova_lista);
	return 0;
}

void visualizza_lista(lista l) {
	if (l == NULL) {
		printf("NULL\n");
		return;
	}
	printf(" %d ->", l->el);
	visualizza_lista(l->next);
}

lista seleziona(lista l) {
	int somma;
	lista tmp;
	lista nuova_lista = NULL;

	for(l = l; l != NULL; l = l->next) {
		tmp = l;
		somma = 0;
		while(tmp->next != NULL) {
			tmp = tmp->next;
			somma += tmp->el;
		}
		if (somma <= l->el)
			nuova_lista = aggiungi_in_coda(nuova_lista, l->el);
	}
	return nuova_lista;
}

lista aggiungi_in_coda(lista l, int num) {
	lista tmp, prec;
	tmp = malloc(sizeof(struct nodo));
	if(tmp != NULL) {
		tmp->el = num;
		tmp->next = NULL;
		if(l == NULL)
			l = tmp;
		else {
			for(prec = l; prec->next != NULL; prec = prec->next);
				prec->next = tmp;
		}
	} else printf("Errore allocazione memoria\n");
	return l;
}
