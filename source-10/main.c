#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node * next;
    struct node * prev;
} TLista;

typedef struct SDescritor{
	TLista * inicio;
	int qtd;
	TLista * fim;
}TDescritor;

TDescritor descritor;

void primeiro(int informacao){
    descritor.inicio = (TLista *) malloc(sizeof(TLista));
    descritor.inicio->info = informacao;
    descritor.inicio->next = NULL;
    descritor.inicio->prev = NULL;
    descritor.qtd = 1;
    descritor.fim = descritor.inicio;
}

void demais(int informacao){
    TLista * novo;
    novo = (TLista *) malloc(sizeof(TLista));
    novo->info = informacao;
    novo->next = NULL;
	descritor.qtd++;
    descritor.fim->next = novo;
    novo->prev = descritor.fim;
    descritor.fim = novo;
    
}

void adicionar(int informacao){
    if (descritor.inicio == NULL)
        primeiro(informacao);
    else
        demais(informacao);
}

void listar(){
    TLista * indice;
    printf("\n\nListando\n\n");
    for (indice = descritor.inicio; indice != NULL; indice = indice->next){
        printf("%d ",indice->info);
    }
}

void listarFim(){
    TLista * indice;
    printf("\n\nListando\n\n");
    for (indice = descritor.fim; indice != NULL; indice = indice->prev){
        printf("%d ",indice->info);
    }
}

TLista * buscar(int key){
    TLista * indice;
    printf("\n\nListando\n\n");
    for (indice = descritor.inicio; indice != NULL; indice = indice->next){
        if (key == indice->info)
            return indice;
    }
    return NULL;
}

void remover(){
    TLista * destruidor = descritor.inicio;
    descritor.inicio = descritor.inicio->next;
    descritor.inicio->prev = NULL;
    free(destruidor);
    descritor.qtd--;
}

int main(int argc, char **argv)
{
    int leitura;
    while(1){
        printf("Informe o valor: ");
        scanf("%d",&leitura);
        if (leitura == 0)
            break;
            
        adicionar(leitura);
    }
    
    listar();
    listarFim();
    printf("Informe a chave: ");
    int chave;
    scanf("%d",&chave);
    TLista * pos = buscar(chave);
    if (pos == NULL)
        printf("Chave inexistente");
    else
        printf("Chave encontrada na posicao: %p", pos);
    remover();
    remover();
    listar();
    listarFim();
    return 0;
}

