/*
 ============================================================================
 Name        : fila-array.c
 Author      : Nicoli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "fila-array.h"

#include <stdio.h>
#include <stdlib.h>


void ffVazia(struct tipoFila* fila){
	fila->frente = 1;
	fila->atras = fila->frente;
}

void enfileira(struct tipoItem* item, struct tipoFila* fila){
	if ((fila->atras % MaxTam + 1) == fila->frente) {
		printf("fila cheia");
	} else {
		fila->item[fila->atras] = *item;
		fila->atras = fila->atras % MaxTam + 1;
	}
}

struct tipoItem desenfileira(struct tipoFila* fila){
	struct tipoItem item;

	if (vazia(fila)==1) {
		printf("erro: fila vazia");
	} else {
		item = fila->item[fila->frente];
		fila->frente = fila->frente % MaxTam + 1;
	}
	return item;
}

void imprime(struct tipoFila *fila) {
	int aux;

	printf("====fila====\n");
	printf("tamanho %d vazia %d\n", tamanho(fila), vazia(fila));
	printf("frente %d atras %d\n", fila->frente, fila->atras);

	for (aux = fila->frente; aux <fila->atras ; aux++) {
		printf("%d \n", fila->item[aux].chave);
	}
}

int tamanho(struct tipoFila* fila){
	return fila->atras - fila->frente;
}

int vazia(struct tipoFila* fila) {
	return (fila->frente == fila->atras);
}

//int main(void) {
//
//	struct tipoFila* fila;
//	fila = malloc(sizeof(struct tipoFila));
//
//	ffVazia(fila);
//
//	imprime(fila);
//
//	struct tipoItem* item = NULL;
//	item = malloc(sizeof(struct tipoItem));
//
//	item->chave = 5;
//
//	enfileira(item, fila);
//
//	item->chave = 15;
//
//	enfileira(item, fila);
//
//	item->chave = 20;
//
//	enfileira(item, fila);
//
//	imprime(fila);
//
//	struct tipoItem item1;
//	item1 = desenfileira(fila);
//
//	imprime(fila);
//
//	printf("item desenfileirado %d \n", item1.chave);
//
//	free(fila);
//	free(item);
//
//	return EXIT_SUCCESS;
//}
