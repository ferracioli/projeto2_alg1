#ifndef CARRO_H
	#define CARRO_H

	#include <stdio.h>
	#include <stdlib.h>

	typedef struct carro CARRO;

	void libera_carro(CARRO *carro);
	CARRO *aloca_carro(int placa, int entrada, int total);
	void imprime_carro(CARRO* carro);

	int carro_placa(CARRO *carro);
	int carro_entrada(CARRO *carro);
	int carro_saida(CARRO *carro);

	void atualiza_carro(CARRO *carro);

	#endif