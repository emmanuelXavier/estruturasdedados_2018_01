#include <stdio.h>
#define TAM 50000



typedef struct SFila{
	int dados[TAM];
} TFila;

TFila fila;

long passos = 0;

void enfileirar(int informacao){
	int i;
	for (i = 0; i < TAM; i++){
		if (fila.dados[i] == 0){
			fila.dados[i] = informacao;
			return;
		}
	}
	printf("\nFila cheia\n");
}

void enfileirarTudo(){
	int i;
	for (i = 0; i < TAM; i++){
		fila.dados[i] = i + 1;
	}
}



void listar(){
	int i;
	printf("\nDados da fila\n");
	for (i = 0; i < TAM; i++){
		if (fila.dados[i] != 0){
			printf("%d ",fila.dados[i]);
		}
	}
}

void desenfileirar(){
	int i;
	for (i = 0; i < TAM - 1; i++){
		passos++;
		fila.dados[i] = fila.dados[i + 1];
	    if (fila.dados[i] == 0)
			return;
	}
	fila.dados[TAM - 1] = 0;
}

void desenfileirarTudo(){
	int i;
	for (i = 0; i < TAM; i++){
	 desenfileirar();
	}
}

int buscar(int chave){
	int i;
	for (i = 0; i < TAM; i++){
		if (fila.dados[i] == chave)
			return i;
	}
	return -1;
}


int main(int argc, char **argv)
{
	/*int leitura, key;
	while(1){
		printf("Informe o valor: ");
		scanf("%d",&leitura);
		if (leitura == 0)
			break;
			
		enfileirar(leitura);
	}*/
	enfileirarTudo();
	desenfileirarTudo();
	printf("Passos: %ld", passos);
	/*listar();
	
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

