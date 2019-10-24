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

	printf("Placa: %04d, Valor: R$%.2f.00", c->placa, (c->horario_saida - c->horario_chegada)*(float)3 - c->desconto);
	
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

void atualiza_carro(CARRO *carro){
	//Adiciona o desconto para um carro

	carro->desconto = (0.1)*(carro->horario_saida - carro->horario_chegada)*3;

	printf(" Ocorreu um sorteio, e o carro vencedor foi :\n");
	imprime_carro(carro);
	return;
}