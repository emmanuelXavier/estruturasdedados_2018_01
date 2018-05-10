#include <stdio.h>
#define TAM 50000000

typedef struct SFila{
	int inicio;
	int fim;
	int dados[TAM];
} TFila;

TFila fila;

int passos = 0;

void enfileirar(int informacao){
	if ((fila.fim != -1) && ((fila.fim + 1) % TAM == fila.inicio)){
		printf("\nFila cheia\n");
		return;
	}
	fila.fim = (fila.fim + 1) % TAM;
	fila.dados[fila.fim] = informacao;	
}

void desenfileirar(){
	fila.inicio = (fila.inicio + 1) % TAM;	
	passos++;
}

void listar(){
	int i;
	printf("\nDados da fila\n");
	i = fila.inicio - 1;
	do{	
		i = (i + 1)%TAM;
		printf("%d ",fila.dados[i]);
		
	}while (i % TAM != fila.fim);
}


int main(int argc, char **argv)
{
	fila.inicio = 0;
	fila.fim = -1;
	int leitura = 0, key;
	/*while(1){
		printf("Informe o valor: ");
		scanf("%d",&leitura);
		if (leitura == 0)
			break;
			
		enfileirar(leitura);
	}*/
	while (leitura++ < TAM){
		enfileirar(leitura);
	}
	leitura = 0;
	while (leitura++ < TAM){
		desenfileirar();
	}
	printf("passos: %d",passos);
	//enfileirarTudo();
	//desenfileirarTudo();
	//printf("Passos: %ld", passos);
	/*listar();
	desenfileirar();
	enfileirar(6);
	enfileirar(7);
	listar();
	/*
	printf("\n\nInforme a chave que deseja buscar na pilha: ");
	scanf("%d",&key);

	int pos = buscar(key);
	if (pos != -1)
		printf("Chave encontrada na posicao %d\n",pos);
	else
		printf("Chave inexistente\n");
				
		
	desenfileirar();
	desenfileirar();
	desenfileirar();
	listar();
	*/
	return 0;
}

