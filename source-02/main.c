#include <stdio.h>
#define TAM 5

typedef struct SPilha{
	int dados[TAM];
	int topo;
}TPilha;

TPilha pilha;

void empilhar(int informacao){
	
	if (pilha.topo + 1 == TAM){
		printf("Pilha cheia\n");
		return;
	}
	
	pilha.dados[++pilha.topo] = informacao;		
}

void desempilhar(){
	if (pilha.topo == -1){
		printf("\nPilha vazia\n");
		return;
	}
	
	pilha.dados[pilha.topo] = 0;
	pilha.topo--;			
}

void listar(){
	int i;
	printf("\n\nListando\n\n");
	for (i = pilha.topo; i >= 0; i--)
			printf("%d\n",pilha.dados[i]);
}


int buscar(int chave){
	int i;
	for (i = pilha.topo; i >= 0; i--){
		if (pilha.dados[i] == chave){
			return i;
		}	
	}
	return -1;
}

int main(int argc, char **argv)
{
	pilha.topo = -1;
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

	int pos = buscar(key);
	if (pos != -1)
		printf("Chave encontrada na posicao %d\n",pos);
	else
		printf("Chave inexistente\n");
				
	desempilhar();
	desempilhar();
	desempilhar();

	
	listar();
	
	return 0;
}

