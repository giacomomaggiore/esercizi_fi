#include <stdio.h>

typedef struct{
	int codice;
	char nome[100];
	float prezzo;
	int quantita;
}prodotto;

typedef struct {
	int cliente;
	char indirizzo[200];
	prodotto carrello[500];

}ordine;

float calcolaConto(ordine o){

	float totale = 0;
	float temp;
	int unit;
	int i;
	int len;

	len = sizeof(o.carrello) / sizeof(prodotto);

	for(i = 0; i < len; i ++){
		temp = o.carrello[i].prezzo;
		unit = o.carrello[i].quantita;
		totale = totale + temp*unit;
	}

	return totale;



}

int main() {

}