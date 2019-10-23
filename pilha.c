#include "pilha.h"
#include "carro.h"

struct pilha{

	CARRO* vaga[TAM_PILHA];//Vetor de carros no estacionamento
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
	//Apaga todos os carros e depois a pilha
	int i;
	for(i=0;i<TAM_PILHA;i++)
		libera_carro((*pilha)->vaga[i]);

	free(*pilha);
	return;
}

int pilha_vazia(PILHA* pilha){
	//1 para vazia, 0 para cheia e -25 para erro
	return ((pilha != NULL) ? pilha->topo == 0 : -25);
}

int pilha_tamanho(PILHA* pilha){
	//Retorna o tamanho da pilha
	return ((pilha != NULL) ? pilha->topo : -25);
}

int pilha_buscar(PILHA *pilha, int chave){

	int i;
	for(i=0;i<TAM_PILHA;i++)
		if(pilha->vaga[i] != NULL){

			if(carro_placa(pilha->vaga[i]) == chave)
				return i;

		}

	return -1;

}

int pilha_menor_horario(PILHA* pilha, int chave){

	return (carro_saida(pilha->vaga[pilha->topo-1]) >= chave);

}

CARRO* pilha_topo(PILHA* pilha){
	//Retorna o carro no topo ou NULL
	return ((pilha != NULL) ? pilha->vaga[pilha->topo] : NULL);
}

int pilha_empilhar(PILHA* pilha, CARRO* carro){
	//Recebe o ponteiro de um carro ja alocado
	if ((pilha != NULL) && pilha_tamanho(pilha) < TAM_PILHA) {

		pilha->vaga[pilha->topo] = carro;
		pilha->topo++;

		return (1);
	}

	return (-25);
}

CARRO* pilha_desempilhar(PILHA* pilha){
	//Remove o ultimo carro e retorna ele
	CARRO* i;
	if ((pilha != NULL) && (!pilha_vazia(pilha))) {

		i = pilha_topo(pilha);
		pilha->topo--;
		return (i);

	}
	return (NULL);
}

void pilha_imprime(PILHA* pilha){

	int i;
	for(i=0;i<TAM_PILHA;i++){
		if(pilha->vaga[i] != NULL){
			
			imprime_carro(pilha->vaga[i]);
			printf(" | PILHA\n");

		}
	}

}
