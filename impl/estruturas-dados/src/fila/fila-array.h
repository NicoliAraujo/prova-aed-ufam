/*
 * fila-array.h
 *
 *  Created on: 26 de dez de 2018
 *      Author: nicoli
 */

#ifndef FILA_ARRAY_H_
#define FILA_ARRAY_H_


#define MaxTam 10

typedef int ponteiro_array;

struct tipoItem{
	int chave;
} ;

struct tipoFila{
	ponteiro_array frente, atras;
	struct tipoItem item[MaxTam];
};

void ffVazia(struct tipoFila* fila);
void imprime(struct tipoFila *fila);
void enfileira(struct tipoItem* item, struct tipoFila* fila);
struct tipoItem desenfileira(struct tipoFila* fila);
int vazia(struct tipoFila* fila);
int tamanho(struct tipoFila* fila);

#endif /* FILA_ARRAY_H_ */
