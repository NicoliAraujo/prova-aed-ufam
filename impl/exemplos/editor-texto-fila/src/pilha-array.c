/*
 ============================================================================
 Name        : pilha-array.c
 Author      : Nicoli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "pilha-array.h"

void fpVazia(struct tipoPilha* pilha){
	pilha = NULL;
	pilha = malloc(sizeof(struct tipoPilha));
	pilha->topo = 0;
}

void empilha(struct tipoPilha* pilha, struct tipoItem* item){
	if (pilha->topo == MAX_TAM) {
		printf("pilha cheia");
	} else {
		pilha->topo++;
		pilha->item[pilha->topo] = *item;
	}
}

struct tipoItem desempilha(struct tipoPilha* pilha){
	struct tipoItem item;

	if (vazia(pilha)==1) {
		printf("erro: pilha vazia");
	} else {
		item = pilha->item[pilha->topo];
		pilha->topo --;
	}
	return item;
}

void imprime(struct tipoPilha *pilha) {
	int aux;

	printf("====pilha====\n");
	printf("%d %d\n", pilha->topo, vazia(pilha));

	for (aux = pilha->topo; aux >0 ; aux--) {
		printf("%c \n", pilha->item[aux].chave);
	}
}

int tamanho(struct tipoPilha* pilha){
	return pilha->topo;
}

int vazia(struct tipoPilha* pilha) {
	return (pilha->topo == 0);
}

//int main(void) {
//
//	struct tipoPilha* pilha;
//	pilha = malloc(sizeof(struct tipoPilha));
//
//	fpVazia(pilha);
//
//	imprime(pilha);
//
//	struct tipoItem* item = NULL;
//	item = malloc(sizeof(struct tipoItem));
//	item->chave = malloc(sizeof(int));
//	item->chave = 5;
//
//	empilha(item, pilha);
//
//	item->chave = 15;
//
//	empilha(item, pilha);
//
//	item->chave = 20;
//
//	empilha(item, pilha);
//
//	imprime(pilha);
//
//	struct tipoItem item1;
//	item1 = desempilha(pilha);
//
//	imprime(pilha);
//
//	free(pilha);
//	free(item);
//
//	return EXIT_SUCCESS;
//}
