#include "carro.h"
#include "pilha.c"
#include "fila.c"

int main(){
	int operacao;
	pilha *p;
	fila *f;
	aloca_pilha(p, 5);
	aloca_fila(f, 10);
	
	do{
		printf("Digite:\n1 para adicionar um carro\n2 para imprimir os carros\n3 para sair\n");
		scanf("%d", &operacao);
		if(operacao == 1){
			//Adiciona um carro
			int placa, entrada, total_horas, alerta= 0;
			
			//Check in
			printf("Digite a placa do carro\n");
			scanf("%d", &placa);
			printf("Digite o horario de entrada\n");
			scanf("%d", &entrada);
			printf("Digite o total de horas\n");
			scanf("%d", &total_horas);
			alerta = busca_placa(p, f);//Se ja tiver a placa retorna 1,senao retorna 0
				
			//Check out
			imprime_carros(p, f);
			retira_carros(p, f, entrada);
			
			//Disponibilidade
			if(entrada >= 8 && entrada+total_horas <=22 && alerta==0){
				//Dentro do horario de funcionamento
				if(tamanho_pilha(p)==0){
					//Patio 1 vazio,neste caso o patio 2 nem importa
					adiciona_pilha(p, placa, entrada, entrada+total_horas);
				}
				else{
					if(tamanho_fila(f)==0){
						//So o patio 2 esta vazio
						adiciona_fila(f, placa, entrada, entrada+total_horas);
					}
					else{
						//Nenhum patio vazio
						if(tamanho_pilha(p) < 5){
							//Patio 1 com alguma vaga
							if(horario_vale_fila(p, entrada+total_horas)){
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
					}
			    }
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
		}
	}while(operacao != 3);
	//Desaloca tudo
	desaloca_pilha(p);
	desaloca_fila(f);
	
	return 0;
}
