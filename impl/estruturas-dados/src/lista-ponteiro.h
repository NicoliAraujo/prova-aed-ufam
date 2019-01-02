/*
 * lista-ponteiro.h
 *
 *  Created on: 26 de dez de 2018
 *      Author: nicoli
 */

#ifndef LISTA_PONTEIRO_H_
#define LISTA_PONTEIRO_H_


typedef struct {
	int chave;
	int valor;
} tipoItem;

typedef struct celula_p {
	tipoItem item;
	struct celula_p *prox;
} celula;

typedef struct tipoLista {
	celula *primeiro;
	celula *ultimo;
} tipoLista;


void flVazia(tipoLista *lista);
void imprime(tipoLista *lista);
void insere(tipoItem* item, tipoLista *lista);
void retira(celula *p, tipoLista *lista);
int vazia(tipoLista lista);

#endif /* LISTA_PONTEIRO_H_ */
