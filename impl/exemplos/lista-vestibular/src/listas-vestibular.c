/*
 ============================================================================
 Name        : listas-vestibular.c
 Author      : Nicoli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "listas-vestibular.h"

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

void insere(registro* item, tipoLista *lista){

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
		printf("%d %d %f\n", aux->item.chave, aux->item.notaFinal, aux->item.opcao[0]);
		aux = aux->prox;
	}
}

//void vestibular(tipoLista *lista){
//	//@todo ordenar itens da lista
//	for (int nota = 10; nota>0; nota++) {
//		while
//	}
//}


int main(void) {

	tipoLista *lista;
	lista = malloc(sizeof(tipoLista));

	flVazia(lista);

	registro *item1;
	item1 = malloc(sizeof(registro));

	registro *remove_item;

	item1->chave = 1;
	item1->notaFinal = 10;
	item1->opcao[0] = 1;
	item1->opcao[1] = 2;
	item1->opcao[2] = 3;

	insere(item1, lista);

	remove_item = item1;

	registro *item2;
	item2 = malloc(sizeof(registro));

	item2->chave = 2;
	item2->notaFinal = 9.9;
	item2->opcao[0] = 1;
	item2->opcao[1] = 4;
	item2->opcao[2] = 6;

	insere(item2, lista);

	item2->chave = 3;
	item2->notaFinal = 9.7;
	item2->opcao[0] = 1;
	item2->opcao[1] = 2;
	item2->opcao[2] = 3;

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
