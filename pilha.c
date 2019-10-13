#include "pilha.h"

struct pilha{
	CARRO* vaga[tam];//Vetor de carros no estacionamento
	int topo;
};

PILHA* pilha_criar(void){
	//Alocacao simples da estrutura pilha
	PILHA* pilha;
	pilha = (PILHA*)malloc(sizeof(PILHA));
	if (pilha != NULL)
 		pilha->topo = 0;
	return (pilha); 
}

void pilha_apagar(PILHA** pilha){
	free(*pilha);
	*pilha = NULL;
}

int pilha_vazia(PILHA* pilha){
	return ((pilha != NULL) ? pilha->topo == 0 : -25);
}

int pilha_tamanho(PILHA* pilha){
	//Retorna o tamanho da pilha
	return ((pilha != NULL) ? pilha->topo : -25);
}

CARRO* pilha_topo(PILHA* pilha){
	return ((pilha != NULL) ? pilha->vaga : NULL);
}

int pilha_empilhar(PILHA* pilha, CARRO* vrum){
	if ((pilha!=NULL) && (pilha_tamanho(pilha) < TAM) {
		pilha->vaga[pilha->topo] = vrum;
		pilha->topo++;
		return (1);
	}
	return (-25);
}

CARRO* pilha_desempilhar(PILHA* pilha){
	ITEM* i;
	if ((pilha != NULL) && (!pilha_vazia(pilha))) {
		i = pilha_topo(pilha);
		pilha->topo--;
		return (i);
	}
	return (NULL);
}

void pilha_print(PILHA* p){
	int i;
	for(i = pilha->topo;i > 0;i--){
		//Imprime em ordem decrescente
		printa_carro(pilha->vaga[i]);
	}
	return;
}
