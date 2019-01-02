/*
 * pilha-ponteiro.c
 *
 *  Created on: 26 de dez de 2018
 *      Author: nicoli
 */

#include "pilha-ponteiro.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void fpVazia(tipoPilha *pilha){

	pilha->topo = NULL;
	pilha->topo = malloc(sizeof(celula));

	pilha->fundo = NULL;
	pilha->fundo = malloc(sizeof(celula));

	pilha->fundo = pilha->topo;
	pilha->topo->prox = NULL;

	pilha->tamanho = 0;
}

int vazia(tipoPilha *pilha){
	return (pilha->topo == pilha->fundo);
}

void empilha(tipoItem* item, tipoPilha* pilha){
	celula* aux = NULL;
	aux = malloc(sizeof(celula));

	pilha->topo->item = *item;
	aux->prox = pilha->topo;

	pilha->topo = aux;

	pilha->tamanho ++;
}

tipoItem desempilha(tipoPilha* pilha) {
	celula *q = NULL;
	q = malloc(sizeof(celula));

	tipoItem item;

	if (vazia(pilha) == 1) {
		printf("Erro: pilha vazia");
	}
	else {

		q = pilha->topo;

		pilha->topo = q->prox;

		item = q->prox->item;

		free(q);

		pilha->tamanho--;

		return item;
	}
}

void imprime(tipoPilha * pilha){
	celula *aux;

	aux = pilha->topo->prox;
	printf("===PILHA===\n");
	while (aux != NULL) {
		printf("%d\n", aux->item.chave);
		aux = aux->prox;
	}
}

int tamanho(tipoPilha* pilha) {
	return pilha->tamanho;
}

int main(void) {

	tipoPilha *pilha;
	pilha = malloc(sizeof(tipoPilha));

	fpVazia(pilha);

	tipoItem *item1;
	item1 = malloc(sizeof(tipoItem));

	item1->chave = 1;

	empilha(item1, pilha);

	tipoItem *item2;
	item2 = malloc(sizeof(tipoItem));

	item2->chave = 2;

	empilha(item2, pilha);

	item2->chave = 30;

	empilha(item2, pilha);

	imprime(pilha);

	tipoItem item_removido;
	item_removido = desempilha(pilha);

	imprime(pilha);

	item_removido = desempilha(pilha);

	imprime(pilha);
	return EXIT_SUCCESS;
}
