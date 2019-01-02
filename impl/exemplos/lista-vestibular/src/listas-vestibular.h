/*
 * listas-vestibular.h
 *
 *  Created on: 2 de jan de 2019
 *      Author: nicoli
 */

#ifndef LISTAS_VESTIBULAR_H_
#define LISTAS_VESTIBULAR_H_

typedef struct {
	int chave; //de 1 a 999
	float notaFinal; //de 0 a 10
	int opcao[3]; //de 1 a 7
} registro;

typedef struct celula_p {
	registro item;
	struct celula_p *prox;
} celula;

typedef struct tipoLista {
	celula *primeiro;
	celula *ultimo;
} tipoLista;


void flVazia(tipoLista *lista);
void imprime(tipoLista *lista);
void insere(registro* item, tipoLista *lista);
void retira(celula *p, tipoLista *lista);
int vazia(tipoLista lista);


#endif /* LISTAS_VESTIBULAR_H_ */
