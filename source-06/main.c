#include <stdio.h>

typedef struct node{
	int info;
	struct node * next;
} TFila;

//sentinela
TFila * fila;

void primeiro(int informacao){
	fila = malloc(sizeof(TFila));
	fila->info = informacao;
}

void demais(int informacao){
	TFila * novo;
	TFila * ultimo = fila;
	
	novo = malloc(sizeof(TFila));
	novo->info = informacao;
	
	//levar ate o final
	while (ultimo->next != NULL){
		ultimo = ultimo->next;
	}
	
	ultimo->next = novo;
}

int main(int argc, char **argv)
{
	int leitura;
	scanf("%d",&leitura);
	
	primeiro(leitura);
	
	scanf("%d",&leitura);
	
	demais(leitura);
	

	
	return 0;
}

