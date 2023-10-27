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
    printf("Dia: "); //pode fazer usando o struct da biblioteca de data
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

void consulta(Lista *l){ //função de consulta de clientes já existentes
    printf("RG da conta que deseja ser consultado: ");
    char RG[8];
    scanf("%s", RG);
    Elista *c = l->inicio;
    for(int i = 0; i < l->qtde; i++){
        if(c->dados.rg == RG){
            break;
        }
        c = c->prox;
    }
    if(c->dados.rg != RG){
        printf("RG não cadastrado!\n");
        return;
    }
    printf("Nome: %s; Idade: %s; Data de criação: %d/%d/%d\n", c->dados.nome, c->dados.idade, c->dados.data.dia,
         c->dados.data.mes, c->dados.data.ano);
}

void lista_clientes(Lista *l){ //mostra a lista de clientes cadastrados no sistema
    printf("Lista de clientes: \n");
    Elista *c = l->inicio;
    for(int i = 0; i < l->qtde; i++){
        printf("Nome: %s; Idade: %d; RG: %s; Data de criação: %d/%d/%d\n", c->dados.nome, c->dados.idade, c->dados.rg,
             c->dados.data.dia, c->dados.data.mes, c->dados.data.ano);
        c = c->prox;
    }
    printf("\n");
}

void atualiza_cliente(Lista *l){ //função que atualiza um cliente já cadastrados
    printf("RG do cliente que deseja ser atualizado: ");
    char rg[8];
    scanf("%s", rg);
    Elista *c = l->inicio;
    for(int i = 0; i < l->qtde; i++){
        if(c->dados.rg == rg){
            break;
        }
        c = c->prox;
    }
    int alt;
    printf("Qual informação deseja ser alterada:\n 1: Nome\n 2: Idade\n");
    scanf("%d", &alt);
    if (alt == 1){
        printf("Nome: ");
        scanf("%s", c->dados.nome);
    }else if (alt == 2){
        printf("Idade: ");
        scanf("%s", c->dados.idade);
    }else{
        printf("Número inválido");
    }
}

void remover_cliente(Lista *l){ //remove um cliente da lista de clientes cadastrados

}