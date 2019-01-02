/*
 * listas-array.h
 *
 *  Created on: 26 de dez de 2018
 *      Author: nicoli
 */

#ifndef LISTAS_ARRAY_H_
#define LISTAS_ARRAY_H_


#define MaxTam 10
#define InicioArranjo 0

typedef int ponteiro_array;

struct tipoItem;
struct tipoLista;

struct tipoLista flVazia(struct tipoLista lista);
void imprime(struct tipoLista lista);
struct tipoLista insere(struct tipoItem item, struct tipoLista lista);
struct tipoLista retira(ponteiro_array p, struct tipoLista lista);
int vazia(struct tipoLista lista);

#endif /* LISTAS_ARRAY_H_ */
