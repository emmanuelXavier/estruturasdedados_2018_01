#include <stdio.h>
#define TAM 5

typedef struct SLista{
	int dados[TAM];
} TLista;

TLista lista;

void inserir(int posicao, int informacao){
	if ((posicao < 0) || (posicao >= TAM)){
		printf("\nPosição invalida\n");
		return;
	}
	
	if (lista.dados[posicao] != 0){
		printf("\nPosição ocupada\n");
		return;
	}
	
	lista.dados[posicao] = informacao;	
}

void remover(int posicao){
	lista.dados[posicao] = 0;
}

void removerValor(int valor){
	int posRemover = buscar(valor);
	remover(posRemover);
}



void listar(){
	int i;
	printf("\nDados da fila\n");
	for (i = 0; i < TAM; i++)
		if (lista.dados[i] != 0)
			printf("%d ",lista.dados[i]);	
}

int buscar(int chave){
	int i;
	for (i = 0; i < TAM; i++){
		if (lista.dados[i] == chave){
			return i;
		}
	}
	return -1;
}


int main(int argc, char **argv)
{
	int leitura,pos, key;
	while(1){
		printf("Informe a posicao e o valor: ");
		scanf("%d %d",&pos, &leitura);
		if (leitura == 0)
			break;
			
		inserir(pos,leitura);
	}
	listar();
	
	int posRemover;
	while(1){
		printf("Informe a posicao que deseja remover: ");
		scanf("%d",&posRemover);
		if (posRemover == -1)
			break;
			
		remover(posRemover);
	}
	listar();
	
	printf("\n\nInforme a chave que deseja buscar na pilha: ");
	scanf("%d",&key);

	int posBusca = buscar(key);
	if (posBusca != -1)
		printf("Chave encontrada na posicao %d\n",posBusca);
	else
		printf("Chave inexistente\n");
				
	return 0;
}

