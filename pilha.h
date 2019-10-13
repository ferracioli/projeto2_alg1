#ifndef PILHA_H
	#define PILHA_H
	//TAD feito com implementacao estatica,para pilhas de tamanho conhecido
	
	#include "carro.h"//TAD com as caracteristicas de um carro em estacionamento
	#include <stdlib.h>
	#include <stdio.h>
	
	#define TAM 5	
	typedef struct pilha PILHA;
	
	PILHA* pilha_criar(void);
	void pilha_apagar(PILHA** pilha);
	int pilha_vazia(PILHA* pilha);
	int pilha_tamanho(PILHA* pilha);
	ITEM* pilha_topo(PILHA* pilha);
	int pilha_empilhar(PILHA* pilha, CARRO* vrum);
	ITEM* pilha_desempilhar(PILHA* pilha);
	void pilha_print(PILHA* p);
	
	#endif
