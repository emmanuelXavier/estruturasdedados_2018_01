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
	fila->next = NULL;
}

void demais(int informacao){
	TFila * novo;
	TFila * ultimo = fila;
	
	novo = (TFila *) malloc(sizeof(TFila));
	novo->info = informacao;
	novo->next = NULL;
	
	//levar ate o final
	while (ultimo->next != NULL){
		ultimo = ultimo->next;
	}
	
	ultimo->next = novo;
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
	for (indice = fila; indice != NULL; indice = indice->next){
		printf("%d ",indice->info);
	}
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
	

	
	return 0;
}

