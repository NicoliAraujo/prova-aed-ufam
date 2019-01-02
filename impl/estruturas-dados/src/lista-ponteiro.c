/*
 * lista-ponteiro.c
 *
 *  Created on: 26 de dez de 2018
 *      Author: nicoli
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "lista-ponteiro.h"

void flVazia(tipoLista *lista){

	lista->primeiro = NULL;
	lista->primeiro = malloc(sizeof(celula));

	lista->ultimo = NULL;
	lista->ultimo = malloc(sizeof(celula));

	lista->primeiro->prox = NULL;

	lista->ultimo = lista->primeiro;
}

int vazia(struct tipoLista lista){
	return (lista.primeiro->item.chave == lista.ultimo->item.chave);
}

void insere(tipoItem* item, tipoLista *lista){

	lista->ultimo->prox = NULL;
	lista->ultimo->prox = malloc(sizeof(celula));

	lista->ultimo = lista->ultimo->prox;

	lista->ultimo->item = *item;

}

void retira(celula *p, tipoLista *lista){
	celula *q = NULL;
	q = malloc(sizeof(celula));

	if ((vazia(*lista) == 1) || (p == NULL) || (p->prox == NULL)) {
		printf("Erro: lista vazia ou posição não existe");
	}
	else {

		q = p->prox;

		p->prox = q->prox;

		if (p->prox == NULL) {
			lista->ultimo = p;
		}
		free(q);
	}
}

void imprime(tipoLista * lista){
	celula *aux;

	aux = lista->primeiro->prox;
	while (aux != NULL) {
		printf("%d %d\n", aux->item.chave, aux->item.valor);
		aux = aux->prox;
	}
}

int main(void) {

	tipoLista *lista;
	lista = malloc(sizeof(tipoLista));

	flVazia(lista);

	tipoItem *item1;
	item1 = malloc(sizeof(tipoItem));

	tipoItem *remove_item;

	item1->chave = 1;
	item1->valor = 15;

	insere(item1, lista);

	remove_item = item1;

	tipoItem *item2;
	item2 = malloc(sizeof(tipoItem));

	item2->chave = 2;
	item2->valor = 30;

	insere(item2, lista);

	item2->chave = 30;
	item2->valor = 22;

	insere(item2, lista);

	imprime(lista);

	celula *p;
	p = malloc(sizeof(celula));

	p->item = *remove_item;
	p->prox = lista->ultimo;
	retira(p, lista);

	imprime(lista);
	return EXIT_SUCCESS;
}
