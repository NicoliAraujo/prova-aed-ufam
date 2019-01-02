/*
 * pilha-ponteiro.h
 *
 *  Created on: 26 de dez de 2018
 *      Author: nicoli
 */

#ifndef PILHA_PONTEIRO_H_
#define PILHA_PONTEIRO_H_


typedef struct {
	int chave;
} tipoItem;

typedef struct celula_p {
	tipoItem item;
	struct celula_p *prox;
} celula;

typedef struct tipoPilha {
	celula *fundo;
	celula *topo;
	int tamanho;
} tipoPilha;

void fpVazia(tipoPilha* pilha);
int tamanho(tipoPilha* tamanho);
void imprime(tipoPilha* pilha);
void empilha(tipoItem* item, tipoPilha* pilha);
tipoItem desempilha(tipoPilha* pilha);
int vazia(tipoPilha* pilha);


#endif /* PILHA_PONTEIRO_H_ */
