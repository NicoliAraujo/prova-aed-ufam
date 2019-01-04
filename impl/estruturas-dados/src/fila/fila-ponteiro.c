/*
 * fila-ponteiro.c
 *
 *  Created on: 26 de dez de 2018
 *      Author: nicoli
 */

#include "fila-ponteiro.h"

#include <stdlib.h>
#include <malloc.h>

void ffVazia(tipoFila *fila){

	fila->atras = NULL;
	fila->atras = malloc(sizeof(celula));

	fila->frente = NULL;
	fila->frente = malloc(sizeof(celula));

	fila->atras = fila->frente;
	fila->frente->prox = NULL;
}

int vazia(tipoFila *fila){
	return (fila->frente == fila->atras);
}

void enfileira(tipoItem* item, tipoFila* fila){
	fila->atras->prox = NULL;
	fila->atras->prox = malloc(sizeof(celula));

	fila->atras = fila->atras->prox;
	fila->atras->item = *item;
	fila->atras->prox = NULL;
}

tipoItem desenfileira(tipoFila* fila) {
	celula *q = NULL;
	q = malloc(sizeof(celula));

	tipoItem item;

	if (vazia(fila) == 1) {
		printf("Erro: fila vazia");
	}
	else {

		q = fila->frente;

		fila->frente = fila->frente->prox;

		item = fila->frente->item;

		free(q);

		return item;
	}
}

void imprime(tipoFila * fila){
	celula *aux;

	aux = fila->frente->prox;
	printf("===FILA===\n");
	while (aux != NULL) {
		printf("%d\n", aux->item.chave);
		aux = aux->prox;
	}
}

int tamanho(tipoFila* fila) {
	return fila->tamanho;
}

int main(void) {

	tipoFila *fila;
	fila = malloc(sizeof(tipoFila));

	ffVazia(fila);

	tipoItem *item1;
	item1 = malloc(sizeof(tipoItem));

	item1->chave = 1;

	enfileira(item1, fila);

	tipoItem *item2;
	item2 = malloc(sizeof(tipoItem));

	item2->chave = 2;

	enfileira(item2, fila);

	item2->chave = 30;

	enfileira(item2, fila);

	imprime(fila);

	tipoItem item_removido;
	item_removido = desenfileira(fila);

	imprime(fila);

	item_removido = desenfileira(fila);

	imprime(fila);
	return EXIT_SUCCESS;
}
