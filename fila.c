#include "fila.h"
#include "carro.h"

struct fila{

    CARRO* carros[TAM_FILA];
    int inicio;
    int fim;
    int tamanho;

};

FILA* fila_criar(void){

	FILA* fila;
	fila = (FILA*)malloc(sizeof(FILA));
	if(fila != NULL){

 		fila->inicio    = 0;
        fila->fim       = 0;
        fila->tamanho   = 0;
    
    }

	return (fila); 

}

void fila_apagar(FILA** fila){

	for(int i=0;i<TAM_FILA;i++)
		libera_carro((*fila)->carros[i]);

	free(*fila);
	return;

}

int fila_vazia(FILA* fila){

	return (fila->tamanho == 0);

}

int fila_cheia(FILA* fila){

    return (fila->tamanho == TAM_FILA);

}

int fila_tamanho(FILA* fila){

	//Retorna o tamanho da fila
	return ((fila != NULL) ? fila->tamanho : -25);

}

int fila_buscar(FILA* fila, int chave){

    for(int i=0;i<TAM_FILA;i++)
		if(fila->carros[i] != NULL){

            if(carro_placa(fila->carros[i]) == chave)
				return i;

        }

    return -1;

}

int fila_maior_horario(FILA* fila, int chave){

	return (carro_saida(fila->carros[fila->fim-1]) <= chave);

}

CARRO* fila_inicio(FILA* fila){

    return (fila->carros[fila->inicio]);

}

int fila_inserir(FILA* fila, CARRO* carro){

	//Recebe o ponteiro de um carro ja alocado
	if ((fila != NULL) && fila_tamanho(fila) < TAM_FILA){

		fila->carros[fila->fim] = carro;
		fila->fim = (fila->fim+1) % TAM_FILA;
		fila->tamanho++;

		return 1;

	}
	return 0;

}

CARRO* fila_remover(FILA* fila){

	if((fila != NULL) && (!fila_vazia(fila))){

        CARRO* carro = fila_inicio(fila);
        fila->carros[fila->inicio] = NULL;
        fila->inicio = (fila->inicio + 1) % TAM_FILA;
        fila->tamanho--;

		return (carro);

	}

	return (NULL);
    
}

void fila_imprime(FILA* fila){

	int i;
    for(int i=0;i<TAM_FILA;i++)
        if(fila->carros[i] != NULL){
            imprime_carro(fila->carros[i]);
			printf(" | FILA\n");
		}

}
