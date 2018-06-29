#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node * next;
} TFila;

//sentinela
TFila * fila = NULL;

void primeiro(int informacao){
	fila = (TFila *) malloc(sizeof(TFila));
	fila->info = informacao;
	fila->next = fila;
}

void demais(int informacao){
	TFila * novo;
	TFila * ultimo = fila;
	novo = (TFila *) malloc(sizeof(TFila));
	novo->info = informacao;
	//levar ate o final
	while (ultimo->next != fila){
		ultimo = ultimo->next;
	}
	ultimo->next = novo;
	novo->next = fila;
}

void enfileirar(int informacao){
	if (fila == NULL)
		primeiro(informacao);
	else
		demais(informacao);
}

void listar(){
	TFila * indice;
	printf("\n\nListando\n\n");
	indice = fila;
	do{
		printf("%d ",indice->info);
		indice = indice->next;
	}while (indice != fila); 
}

TFila * buscar(int key){
	TFila * indice;
	printf("\n\nListando\n\n");
	indice = fila;
	do{
		if (key == indice->info)
			return indice;
		indice = indice->next;
	}while (indice != fila); 
	return NULL;
}

void desenfileirar(){
	TFila * destruidor = fila;
	TFila * ultimo;
	
	ultimo = fila;
	while (ultimo->next != fila)
		ultimo = ultimo->next;
	
	fila = fila->next;
	free(destruidor);
	ultimo->next = fila;	
}

int main(int argc, char **argv)
{
	int leitura;
	while(1){
		printf("Informe o valor: ");
		scanf("%d",&leitura);
		if (leitura == 0)
			break;
			
		enfileirar(leitura);
	}
	
	listar();
	printf("Informe a chave: ");
	int chave;
	scanf("%d",&chave);
	TFila * pos = buscar(chave);
	if (pos == NULL)
		printf("Chave inexistente");
	else
		printf("Chave encontrada na posicao: %p", pos);
	desenfileirar();
	desenfileirar();
	listar();
	return 0;
}

