#include "carro.h"
#include "pilha.h"
#include "fila.h"

int placa_existe(PILHA *p, FILA *f, int placa);
void imprime_carros(PILHA *p, FILA *f);

int horario_vale_pilha(PILHA *p, int saida);
int horario_vale_fila(FILA *f, int saida);

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
			int placa, entrada, total_horas, alerta = 0;
			
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
			
			alerta = placa_existe(p, f, placa); //Se ja tiver a placa, retorna 1, se não, retorna 0

			//Check out
			imprime_carros(p, f);
			//retira_carros(p, f, entrada);

			//Verfica se está dentro do horario de funcionamento
			if(entrada >= 8 && entrada+total_horas <= 22 && alerta == 0){

				//Patio 1 vazio, neste caso o patio 2 nem importa
				if(pilha_tamanho(p) == 0){

					CARRO *c = aloca_carro(placa, entrada, entrada+total_horas);
					pilha_empilhar(p, c);

				}
				//So o patio 2 esta vazio
				else if(fila_tamanho(f) == 0){
					
					CARRO *c = aloca_carro(placa, entrada, entrada+total_horas);
					fila_inserir(f, c);

				}
				/*
				//Nenhum patio vazio
				else if(pilha_tamanho(p) < 5){

					//Patio 1 com alguma vaga
					if(horario_vale_pilha(p, entrada+total_horas)){
						adiciona_pilha(p, placa, entrada, entrada+total_horas);
					}

				}
				else{
					if(tamanho_fila(f) < 10){
						//Patio 2 com alguma vaga
						if(horario_vale_fila(f, entrada+total_horas)){
							adiciona_fila(f, placa, entrada, entrada+total_horas);
						}
					}
					else{
						//Sem vagas
						alerta = 2;
					}
				}
				*/
			}
			else{
				alerta = 3;
			}
			
			//Rejeicao
			switch(alerta){
				case 1:{
					printf("REJEITADO, carro com a mesma placa registrado no sistema\n");
					break;
				}
				case 2:{
					printf("REJEITADO,estacionamento sem vagas\n");
					break;
				}
				case 3:{
					printf("REJEITADO, carro fora do horario de funcionamento\n");
					break;
				}
			}

		}
		else if(operacao == 2){
			//Imprime todos os carros
			imprime_carros(p, f);
			getchar();
		}
		else
			break;

		//system("@cls||clear");

	} while(operacao != 3);

	//Desaloca tudo
	pilha_apagar(&p);
	fila_apagar(&f);

	system("@cls||clear");
	
	return 0;
}

int placa_existe(PILHA *p, FILA *f, int placa){

	if(pilha_buscar(p, placa) == -1 && fila_buscar(f, placa) == -1)
		return 0;

	return 1;

}

void imprime_carros(PILHA *p, FILA *f){

	pilha_imprime(p);
	fila_imprime(f);

}

int horario_vale_pilha(PILHA *p, int saida){



}
