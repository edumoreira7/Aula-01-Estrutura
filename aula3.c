#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *anterior;
    struct Celula *proximo;
    int valor;
}Celula;

typedef struct{
    Celula *primeiro;
    int qtd;
}LDDE;

Celula *criarCelula(int valor){
    Celula *novo = malloc(sizeof(Celula));
    novo->anterior = NULL;
    novo->proximo = NULL;
    novo->valor = valor;
    return novo;
}

LDDE *criarLista(){
    LDDE *lista = malloc(sizeof(LDDE));
    lista->primeiro = NULL;
    lista->qtd = 0;
    return lista;
}

void inserir(LDDE *lista, int valor){
    Celula *novo = criarCelula(valor);
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;

    while(atual != NULL && atual->valor < novo->valor){
        anterior = atual;
        atual = atual->proximo;
    }
    //insercao inicio
    if(anterior == NULL){
        lista->primeiro = novo;
        if(atual !=NULL){
            novo->proximo = atual;
            atual->anterior = novo;
        }
    }else if(atual == NULL){        //insercao fim
        anterior->proximo = novo;
        novo->anterior = anterior;
    }else{                          //insercao mei
        anterior->proximo = novo;
        novo->anterior = anterior;
        novo->proximo = atual;
        atual->anterior = novo;
    }
    lista->qtd++;
}

void mostrar(LDDE *lista){
    Celula *atual = lista->primeiro;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main(){
    LDDE *lista = criarLista();
    inserir(lista, 12);//inicio em lista vazia
    mostrar(lista);
    inserir(lista, 8);//inicio em lista nao vazia
    mostrar(lista);
    inserir(lista, 18);//final
    mostrar(lista);
    inserir(lista, 15);//meio
    mostrar(lista);


    return 0;
}
