#include "carro.h"

struct carro{
	int placa;
	int horario_chegada;
	int horario_saida;
	float desconto;
};

void libera_carro(CARRO *c){
	free(c);
	return;
}

CARRO *aloca_carro(int placa, int entrada, int total){

	CARRO *c = (CARRO*)malloc(sizeof(CARRO));
	if(c==NULL)
		exit(1);

	c->placa = placa;
	c->horario_chegada = entrada;
	c->horario_saida = entrada+total;
	c->desconto = 0;

	return c;	

}

void imprime_carro(CARRO *c){

	printf("Placa: %04d, Valor: R$%02d.00", c->placa, (c->horario_saida-c->horario_chegada)*3);
	
}

int carro_placa(CARRO *carro){

	return carro->placa;

}

int carro_entrada(CARRO *carro){

	return carro->horario_chegada;

}

int carro_saida(CARRO *carro){

	return carro->horario_saida;

}