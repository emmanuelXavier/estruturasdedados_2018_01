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
    pilha->next = pilha;
}

void demais(int informacao){
    TPilha * novo;
    TPilha * ultimo = pilha;
    novo = (TPilha *) malloc(sizeof(TPilha));
    novo->info = informacao;
    
    novo->next = pilha;
    
    //levar ate o final
    while (ultimo->next != pilha){
        ultimo = ultimo->next;
    }
    ultimo->next = novo;
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
    indice = pilha;
    do{
        printf("%d ",indice->info);
        indice = indice->next;
    }while (indice != pilha); 
}

TPilha * buscar(int key){
    TPilha * indice;
    printf("\n\nListando\n\n");
    indice = pilha;
    do{
        if (key == indice->info)
            return indice;
        indice = indice->next;
    }while (indice != pilha); 
    return NULL;
}

void desempilhar(){
    TPilha * destruidor = pilha;
    TPilha * ultimo;
    
    ultimo = pilha;
    while (ultimo->next != pilha)
        ultimo = ultimo->next;
    
    pilha = pilha->next;
    free(destruidor);
    ultimo->next = pilha;    
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

