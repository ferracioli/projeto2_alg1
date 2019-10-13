#include "carro.h"

struct vrum{
	int placa;
	int horario_chegada;
	int horario_saida;
	float desconto;
};

void libera_carro(CARRO *vrum){
	free(vrum);
	return;
}

CARRO *aloca_carro(int placa, int entrada, int total){
	CARRO *vrum = (CARRO*)malloc(sizeof(CARRO));
	if(vrum==NULL)
		exit(1);
	vrum->placa = placa;
	vrum->horario_chegada = entrada;
	vrum->horario_saida = entrada+total;
	vrum->desconto = 0;
	return vrum;	
}
