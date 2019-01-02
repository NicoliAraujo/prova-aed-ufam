/*
 ============================================================================
 Name        : listas-array.c
 Author      : Nicoli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "listas-array.h"

struct tipoItem{
	int chave;
	int valor;
} ;

struct tipoLista{
	int primeiro, ultimo;
	struct tipoItem item[MaxTam];
};

struct tipoLista flVazia(struct tipoLista lista){
	lista.primeiro = InicioArranjo;
	lista.ultimo = lista.primeiro;
	return lista;
}

struct tipoLista insere(struct tipoItem item, struct tipoLista lista){
	if (lista.ultimo > MaxTam) {
		printf("Lista cheia");
	} else {
		lista.item[lista.ultimo] = item;
		lista.ultimo = lista.ultimo + 1;
	}
	return lista;
}

struct tipoLista retira(ponteiro_array p, struct tipoLista lista){
	int aux;
	struct tipoItem item;

	if ((vazia(lista)==1) || (p>= lista.ultimo)) {
		printf("erro: posição não existe");
	} else {
		item = lista.item[p];
		lista.ultimo = lista.ultimo - 1;

		/* deslocando os itens da lista em uma posição pra que os itens continuem
		 * organizados de maneira contínua no vetor
		*/
		for (aux = p; aux < lista.ultimo; aux++) {
			lista.item[aux] = lista.item[aux+1];
		}
	}
	return lista;
}

void imprime(struct tipoLista lista) {
	int aux;

	printf("====LISTA====\n");
	printf("%d %d %d\n", lista.primeiro, lista.ultimo, vazia(lista));

	for (aux = lista.primeiro; aux < lista.ultimo; aux++) {
		printf("%d %d\n", lista.item[aux].chave, lista.item[aux].valor);
	}
}

int vazia(struct tipoLista lista) {
	return (lista.primeiro == lista.ultimo);
}

//int main(void) {
//
//	struct tipoLista lista;
//
//	lista = flVazia(lista);
//
//	imprime(lista);
//
//	struct tipoItem item;
//	item = (struct tipoItem) {0, 10};
//
//	lista = insere(item, lista);
//
//	item = (struct tipoItem) {1, 15};
//
//	lista = insere(item, lista);
//
//	item = (struct tipoItem) {2, 20};
//
//	lista = insere(item, lista);
//
//	imprime(lista);
//
//	lista = retira(1, lista);
//
//	imprime(lista);
//
//	return EXIT_SUCCESS;
//}
