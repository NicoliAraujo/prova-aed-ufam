/*
 * listas-array.h
 *
 *  Created on: 26 de dez de 2018
 *      Author: nicoli
 */

#ifndef PILHA_ARRAY_H_
#define PILHA_ARRAY_H_


#define MAX_TAM 100

typedef int ponteiro_array;

struct tipoItem{
	char chave;
} ;

struct tipoPilha{
	ponteiro_array topo;
	struct tipoItem item[MAX_TAM];
};

void fpVazia(struct tipoPilha* pilha);
void imprime(struct tipoPilha* pilha);
void empilha(struct tipoPilha* pilha, struct tipoItem* item);
struct tipoItem desempilha(struct tipoPilha* pilha);
int vazia(struct tipoPilha* pilha);
int tamanho(struct tipoPilha* pilha);

#endif /* PILHA_ARRAY_H_ */
