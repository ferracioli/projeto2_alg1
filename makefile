all: projeto
	
projeto: carro.o fila.o pilha.o main.o
	gcc -o projeto carro.o fila.o pilha.o main.o

carro.o: carro.h carro.c
	gcc -c carro.h carro.c

pilha.o: pilha.h pilha.c
	gcc -c pilha.h pilha.c

fila.o: fila.h fila.c
	gcc -c fila.h fila.c

main.o: main.c
	gcc -c main.c
