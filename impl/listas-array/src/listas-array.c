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

typedef struct tipoItem {
	int chave;
	int valor;
};

struct tipoLista{
	int primeiro, ultimo, MAXTAM;
	tipoItem item[MAXTAM];
};

void flVazia(tipoLista *lista){
	lista.primeiro = 0;
	lista.ultimo = 0;
	lista.MAXTAM = 0;

};

void insere();

void retira();

void imprime();

int vazia();

int main(void) {
	puts("Hello World"); /* prints Hello World */
	tipoLista lista;
	lista.primeiro
	return EXIT_SUCCESS;
}
