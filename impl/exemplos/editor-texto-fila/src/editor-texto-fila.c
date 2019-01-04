/*
 ============================================================================
 Name        : editor-texto-fila.c
 Author      : Nicoli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "pilha-array.h"

const int MaxTam = 70;
const char CancelaCaractere = '#';
const char CancelaLinha = '\\';
const char SaltaLinha = '@';
const char MarcaEof = '-';

void imprime_ET(struct tipoPilha* pilha){
	struct tipoPilha* pilhaux;
	struct tipoItem item;

	pilhaux = NULL;
	pilhaux = malloc(sizeof(struct tipoPilha));

//	item = NULL;
//	item = malloc(sizeof(struct tipoItem));

	fpVazia(pilhaux);
	while (vazia(pilha)!=1) {
		item = desempilha(pilha);
		empilha(pilhaux, &item);
	}
	while (vazia(pilhaux)!=1) {
		item = desempilha(pilhaux);
		printf("%c", item.chave);
	}
	printf("\n");
}

int main(void) {
	char filename[] = {"src/input.txt"};
	FILE *file;

	struct tipoPilha* pilha;
	struct tipoItem item;

//	item = NULL;
//	item = malloc(sizeof(struct tipoItem));

	pilha = NULL;
	pilha = malloc(sizeof(struct tipoPilha));

	fpVazia(pilha);

	file = fopen(filename, "r");
	if (file == NULL) {
		printf("Cannot open file '%s' : %s\n", filename, strerror(errno));
		exit(EXIT_FAILURE);
	}

	while ((item.chave = fgetc(file))!= MarcaEof) {

		if (item.chave == CancelaCaractere) {
			if (vazia(pilha)!=1)
				item = desempilha(pilha);
		}
		else {
			if (item.chave == CancelaLinha)
				fpVazia(pilha);
			else {
				if (item.chave == SaltaLinha)
					imprime_ET(pilha);
				else {
					if (tamanho(pilha) == MAX_TAM)
						imprime_ET(pilha);
					empilha(pilha, &item);
				}
			}
		}
	}
	if (vazia(pilha)!=1) imprime_ET(pilha);
	return EXIT_SUCCESS;
}
