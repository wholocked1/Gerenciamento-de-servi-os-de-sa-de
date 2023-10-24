#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

Lista *criar_lista(){ //função que cria a lista sem nenhuma informação
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->qtde = 0;
    return l;
}

Elista *cria_info(){ //cria o ponteiro do novo cliente recebendo as informações por scanf
    Elista *cliente = malloc(sizeof(Elista));
    printf("Nome: ");
    scanf("%s", cliente->dados.nome);
    printf("Idade: ");
    scanf("%d", cliente->dados.idade);
    printf("RG: ");
    scanf("%s", cliente->dados.rg);
    printf("Dia: ");
    scanf("%d", cliente->dados.data.dia);
    printf("Mês: ");
    scanf("%d", cliente->dados.data.mes);
    printf("Ano: ");
    scanf("%d", cliente->dados.data.ano);
    cliente->prox = NULL;
}

void inserir(Lista *l){ //função que inseri o novo cliente na lista
    Elista *c = cria_info();
    if(l->qtde == 0){
        l->inicio = c;
    }else{
        Elista *ant = l->inicio;
        c->prox = ant;
        l->inicio = c;
    }
    l->qtde++;
}