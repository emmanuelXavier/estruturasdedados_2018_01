#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node * next;
} TPilha;

//sentinela
TPilha * pilha = NULL;

void primeiro(int informacao){
    pilha = (TPilha *) malloc(sizeof(TPilha));
    pilha->info = informacao;
    pilha->next = NULL;
}

void demais(int informacao){
    TPilha * novo;
    novo = (TPilha *) malloc(sizeof(TPilha));
    novo->info = informacao;
    novo->next = pilha;
    pilha = novo;
}

void empilhar(int informacao){
    if (pilha == NULL)
        primeiro(informacao);
    else
        demais(informacao);
}

void listar(){
    TPilha * indice;
    printf("\n\nListando\n\n");
    for (indice = pilha; indice != NULL; indice = indice->next){
        printf("%d ",indice->info);
    }
}

TPilha * buscar(int key){
    TPilha * indice;
    printf("\n\nListando\n\n");
    for (indice = pilha; indice != NULL; indice = indice->next){
        if (key == indice->info)
            return indice;
    }
    return NULL;
}

void desempilhar(){
    TPilha * destruidor = pilha;
    pilha = pilha->next;
    free(destruidor);
}

int main(int argc, char **argv)
{
    int leitura;
    while(1){
        printf("Informe o valor: ");
        scanf("%d",&leitura);
        if (leitura == 0)
            break;
            
        empilhar(leitura);
    }
    
    listar();
    printf("Informe a chave: ");
    int chave;
    scanf("%d",&chave);
    TPilha * pos = buscar(chave);
    if (pos == NULL)
        printf("Chave inexistente");
    else
        printf("Chave encontrada na posicao: %p", pos);
    desempilhar();
    desempilhar();
    listar();
    return 0;
}

