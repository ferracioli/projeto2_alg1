#ifndef FILA_H
	#define FILA_H
	
	#include "carro.h"//TAD com as caracteristicas de um carro em estacionamento
	#include <stdlib.h>
	#include <stdio.h>
	
	#define TAM_FILA 10	
	typedef struct fila FILA;
	
	FILA* fila_criar(void);
	void fila_apagar(FILA** fila);

	int fila_vazia(FILA* fila);
	int fila_cheia(FILA* fila);
	int fila_tamanho(FILA* fila);
    int fila_buscar(FILA* fila, int chave);

	int fila_inserir(FILA* fila, CARRO* carro);
	CARRO* fila_remover(FILA* fila);

	CARRO* fila_inicio(FILA* fila);
    void fila_imprime(FILA* fila);
	
	#endif
