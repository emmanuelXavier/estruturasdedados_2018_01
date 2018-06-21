#include <stdio.h>
#define TAM 5

int pilha[TAM];

void empilhar(int informacao){
	int i;
	for (i = 0; i < TAM; i++){
		if (pilha[i] == 0){
			pilha[i] = informacao;
			break;
		}
	}
	if (i == TAM)	
		printf("\nPilha cheia\n");
}

void desempilhar(){
	int i;
	for (i = TAM - 1; i >= 0;i--){
		if (pilha[i] != 0){
			pilha[i] = 0;
			break;
		}	
	}
	if (i == -1)
		printf("\nPilha vazia\n");
}

void listar(){
	int i;
	for (i = TAM - 1; i >= 0; i--)
		if (pilha[i] != 0)
			printf("%d\n",pilha[i]);
}

int buscar(int chave){
	int i;
	for (i = TAM - 1; i >= 0; i--){
		if (pilha[i] == chave){
			return i;
		}	
	}
	return -1;
}

int main(int argc, char **argv)
{
	int leitura, key;
	while(1){
		printf("Informe o valor: ");
		scanf("%d",&leitura);
		if (leitura == 0)
			break;
			
		empilhar(leitura);
	}
	
	listar();
	
	printf("\n\nInforme a chave que deseja buscar na pilha: ");
	scanf("%d",&key);

	int posicao = buscar(key);
	if (posicao != -1)
		printf("Chave encontrada na posicao %d\n",posicao);
	else
		printf("Chave inexistente\n");
				
	desempilhar();
	desempilhar();
	desempilhar();
	listar();
	
	return 0;
}

