/*
 * pilha-ponteiro.h
 *
 *  Created on: 26 de dez de 2018
 *      Author: nicoli
 */

#ifndef FILA_PONTEIRO_H_
#define FILA_PONTEIRO_H_


typedef struct {
	int chave;
} tipoItem;

typedef struct celula_p {
	tipoItem item;
	struct celula_p *prox;
} celula;

typedef struct tipoFila {
	celula *frente;
	celula *atras;
	int tamanho;
} tipoFila;

void ffVazia(tipoFila* fila);
int tamanho(tipoFila* tamanho);
void imprime(tipoFila* fila);
void empilha(tipoItem* item, tipoFila* fila);
tipoItem desempilha(tipoFila* fila);
int vazia(tipoFila* fila);


#endif /* FILA_PONTEIRO_H_ */
