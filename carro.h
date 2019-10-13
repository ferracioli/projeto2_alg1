#include <stdio.h>
#include <stdlib.h>

typedef struct vrum carro;

void libera_carro(CARRO *vrum);
CARRO *aloca_carro(int placa, int entrada, int total);
