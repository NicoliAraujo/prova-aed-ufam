/*
 * listas-array.h
 *
 *  Created on: 26 de dez de 2018
 *      Author: nicoli
 */

#ifndef PILHA_ARRAY_H_
#define PILHA_ARRAY_H_


#define MaxTam 10

typedef int ponteiro_array;

struct tipoItem{
	int chave;
} ;

struct tipoPilha{
	ponteiro_array topo;
	struct tipoItem item[MaxTam];
};

void fpVazia(struct tipoPilha* pilha);
void imprime(struct tipoPilha* pilha);
void empilha(struct tipoItem* item, struct tipoPilha* pilha);
struct tipoItem desempilha(struct tipoPilha* pilha);
int vazia(struct tipoPilha* pilha);

#endif /* PILHA_ARRAY_H_ */
