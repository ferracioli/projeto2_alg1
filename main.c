#include "carro.h"
#include "pilha.h"
#include "fila.h"
#include <time.h>

int placa_existe(PILHA *p, FILA *f, int placa);
void imprime_carros(PILHA *p, FILA *f);

void erro(int codigo);

void retira_carros(PILHA *p, FILA *f, int entrada);
void sorteio(PILHA *p, FILA *f, int entrada);

int main(){

	int operacao;
	PILHA *p;
	FILA *f;
	
	p = pilha_criar();
	f = fila_criar();

	system("@cls||clear");
	
	do{

		printf("Digite:\n1 para adicionar um carro\n2 para imprimir os carros\n3 para sair\n");
		scanf("%d", &operacao);

		if(operacao == 1){

			//Adiciona um carro
			int placa, entrada, total_horas;
			
			//Check in

			system("@cls||clear");
			printf("Digite a placa do carro\n");
			scanf("%d", &placa);

			system("@cls||clear");
			printf("Digite o horario de entrada\n");
			scanf("%d", &entrada);

			system("@cls||clear");
			printf("Digite o total de horas\n");
			scanf("%d", &total_horas);
			
			if(placa_existe(p, f, placa)){
				erro(1);
				continue;
			}

			//Check out
			imprime_carros(p, f);
			retira_carros(p, f, entrada);


			sorteio(PILHA *p, FILA *f, int entrada);

			//Verfica se está dentro do horario de funcionamento
			if(entrada >= 8 && entrada+total_horas <= 22){

				//Patio 1 vazio, neste caso o patio 2 nem importa
				if(pilha_tamanho(p) == 0){

					CARRO *c = aloca_carro(placa, entrada, total_horas);
					pilha_empilhar(p, c);

				}
				//So o patio 2 esta vazio
				else if(fila_tamanho(f) == 0){

					CARRO *c = aloca_carro(placa, entrada, total_horas);
					fila_inserir(f, c);

				}

				//Nenhum patio vazio
				else if(pilha_tamanho(p) < 5 && pilha_menor_horario(p, entrada+total_horas)){

					//Patio 1 com alguma vaga
					CARRO *c = aloca_carro(placa, entrada, total_horas);
					pilha_empilhar(p, c);

				}
				else if(fila_tamanho(f) < 10 && fila_maior_horario(f, entrada+total_horas)){

					//Patio 2 com alguma vaga
					CARRO *c = aloca_carro(placa, entrada, total_horas);
					fila_inserir(f, c);

				}
				else{

					//Sem vagas
					erro(2);
					continue;

				}

			}
			else{

				erro(3);
				continue;

			}

		}
		else if(operacao == 2){

			//Imprime todos os carros
			imprime_carros(p, f);
			
		}
		else
			break;

		system("@cls||clear");

	} while(operacao != 3);

	//Desaloca tudo
	pilha_apagar(&p);
	fila_apagar(&f);

	system("@cls||clear");
	
	return 0;
}

void erro(int codigo){

	system("@cls||clear");

	switch(codigo){
		case 1:{
			printf("REJEITADO, carro com a mesma placa registrado no sistema\n");
			break;
		}
		case 2:{
			printf("REJEITADO, estacionamento sem vagas\n");
			break;
		}
		case 3:{
			printf("REJEITADO, carro fora do horario de funcionamento\n");
			break;
		}
	}

	getchar();
	getchar();

	system("@cls||clear");

}

int placa_existe(PILHA *p, FILA *f, int placa){

	if(pilha_buscar(p, placa) == -1 && fila_buscar(f, placa) == -1)
		return 0;

	return 1;

}

void imprime_carros(PILHA *p, FILA *f){

	system("@cls||clear");

	pilha_imprime(p);
	fila_imprime(f);

	getchar();
	getchar();

}


void retira_carros(PILHA *p, FILA *f, int entrada){
 	//Remove da pilha e fila todos os carros com horario de saida <= horario de entrada
 	CARRO *carro;

 	while(!pilha_vazia(p) && pilha_horario_topo(p) <= entrada){
 		//Retira todos os carros que ja podem sair da pilha

 		carro = pilha_desempilhar(p);
 	}
 	
 	while(!fila_vazia(f) && fila_horario_primeiro(f) <= entrada){
 		//Retira todos os carros com horario esgotado na fila

 		carro = fila_remover(f);
 	}

 	return;
 }


 void sorteio(PILHA *p, FILA *f, int entrada){
 	int nro_carros;
 	nro_carros = fila_tamanho(f) + pilha_tamanho(p);

 	srand(time(NULL));

 	if(nro_carros >= 4){
 		//Quantidade minima para o sorteio ocorrer

 		if(entrada==9 || entrada==12 || entrada==15 || entrada==18){
 			//Horarios especificos dos sorteios

 			int *vetor = (int*)malloc(nro_carros, sizeof(int));//Alocacao da roleta
 			int aleatorio = rand() % 100;//Quantidade de movimentos ate a roleta parar
 			int i = 0;//Posicao em que a roleta para

 			while(aleatorio != 0){
 				//Verifica em qual casa a roleta para de girar

 				if(i < nro_carros-1){
 					i++;
 					aleatorio--;
 				}
 				else{
 					//Volta para o inicio da roleta
 					i = 0;
 					aleatorio--;
 				}
 			}
 			//A ordem escolhida para o vetor eh: todos os carros da pilha e todos os carros da fila em sequencia.
 			//Verificamos se i+1 eh maior que o tamanho da pilha,se for, o carro premiado estara na fila
 			//Caso contrario, o carro vencedor esta na pilha

 			if(i+1 > pilha_tamanho(p)){
 				//Olhamos os carros da fila

 				i -= pilha_tamanho(p);
 				//pois i estava guardando o tamanho da pilha junto

 				atualiza_fila(f, i);

 			}
 			else{
 				//Olhamos os carros da pilha

 				atualiza_pilha(p, i);
 			}
 			free(vetor);
 		}
 	}
 	return;
 }