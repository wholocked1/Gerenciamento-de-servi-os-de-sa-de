#include <stdlib.h>
#include <stdio.h>

#include "funcoes.h"

void clearBuffer() { // função que limpa buffer para usar no funções_conta.c
  char c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}

Lista *criar_lista(){ //função que cria a lista sem nenhuma informação
    Lista *l = malloc(sizeof(Lista)); //aloca memória do struct
    l->inicio = NULL;
    l->qtde = 0;
    return l;
}

Elista *cria_info(){ //cria o ponteiro do novo cliente recebendo as informações por scanf
    Elista *cliente = malloc(sizeof(Elista)); //aloca memória do struct
    printf("Nome: ");
    scanf("%s", cliente->dados.nome); //recebe o nome
    printf("Idade: ");
    scanf("%d", &cliente->dados.idade); //recebe a idade
    printf("RG: ");
    scanf("%s", cliente->dados.rg); //recebe o RG
    printf("Dia: "); 
    scanf("%d", &cliente->dados.data.dia); //recebe o dia em que as informações foram recebidas
    printf("Mês: ");
    scanf("%d", &cliente->dados.data.mes); //recebe o mês em que as informações foram recebidas
    printf("Ano: ");
    scanf("%d", &cliente->dados.data.ano); //recebe o ano em que as informações foram recebidas
    cliente->prox = NULL; //deixa nulo o ponteiro do proximo desse cliente
  return cliente;
}
//funciona
void inserir(Lista *l){ //função que inseri o novo cliente na lista
    Elista *c = cria_info(); //cria um novo cliente
    if(l->qtde == 0){ //se for o primeiro cliente da lista:
        l->inicio = c; //coloca esse cliente como o primeiro da lista
    }else{ //se não for:
        Elista *ant = l->inicio; //salva o cliente que estava no começo em um ponteiro
        c->prox = ant; //coloca esse cliente anterior como próximo do novo ponteiro
        l->inicio = c; //coloca o novo ponteiro no início da lista
    }
    l->qtde++; //aumenta o contador de contas em 1
}

void consulta(Lista *l){ //função de consulta de clientes já existentes
    printf("RG da conta que deseja ser consultado: ");
    char RG[8];
    scanf("%s", RG); //recebe o RG do cliente
    Elista *c = l->inicio; //gera um ponteiro de controle para encontrar o cliente com o RG desejado
    int i;
    for(i = 0; i < l->qtde; i++){
        if(strcmp(RG, c->dados.rg) == 0){
            break; //se encontrar, sai do loop
        }
        c = c->prox; //se não encontrar, ele vai para o próximo ponteiro da lista
    }
    if(i == l->qtde){ //verifica no final se o RG realmente não foi encontrado
        printf("RG não cadastrado!\n");
        return;
    }
    printf("Nome: %s; Idade: %d; Data de criação: %d/%d/%d\n", c->dados.nome, c->dados.idade, c->dados.data.dia,
         c->dados.data.mes, c->dados.data.ano); //se for encontrado, ele mostra na tela
}
//funciona
void lista_clientes(Lista *l){ //mostra a lista de clientes cadastrados no sistema
    printf("Lista de clientes: \n");
    Elista *c = l->inicio;
    for(int i = 0; i < l->qtde; i++){ //imprime a lista de clientes
        printf("Nome: %s; Idade: %d; RG: %s; Data de criação: %d/%d/%d\n", c->dados.nome, c->dados.idade, c->dados.rg,
             c->dados.data.dia, c->dados.data.mes, c->dados.data.ano);
        c = c->prox;
    }
    printf("\n");
}

void atualiza_cliente(Lista *l){ //função que atualiza um cliente já cadastrados
    printf("RG do cliente que deseja ser atualizado: ");
    char rg[8];
    scanf("%s", rg); //recebe o RG do cliente que deseja ser atualizado
    Elista *c = l->inicio;
    for(int i = 0; i < l->qtde; i++){ //encontra o cliente na lista de clientes cadastrados
        if(strcmp(rg, c->dados.rg) == 0){
            break;
        }
        c = c->prox;
    }
    int alt;
    printf("Qual informação deseja ser alterada:\n 1: Nome\n 2: Idade\n");
    scanf("%d", &alt); //recebe qual o tipo de informação que deseja ser modificada
    if (alt == 1){
        printf("Nome: ");
        scanf("%s", c->dados.nome); //recebe a mudança de dados e salva no ponteiro 
        clearBuffer();
    }else if (alt == 2){
        printf("Idade: ");
        scanf("%d", &c->dados.idade); //recebe a mudança de dados e salva no ponteiro 
    }else{
        printf("Número inválido");
    }
}

void remover_cliente(Lista *l){ //remove um cliente da lista de clientes cadastrados
    printf("RG da conta que deseja ser removida: ");
    char rg[8];
    scanf("%s", rg); //recebe o RG do cliente que deseja ser apagado
    Elista *atual = l->inicio;
    Elista *ant = NULL;
    if(l->qtde == 1){
      l->inicio = NULL;
      free(atual);
      l->qtde--;
      return;
    }
    for(int i = 0; i < l->qtde; i++){ //encontra o cliente na lista de clientes
        if(strcmp(rg, atual->dados.rg) == 0){
            break;
        }
        ant = atual;
        atual = atual->prox;
    }
    if(atual->prox == NULL){ //se for o último cliente da lista, transforma o ponteiro anterior a ele em nulo
        ant->prox = NULL;
    }else if(ant == NULL){
      l->inicio = atual->prox; //se for o primeiro cliente da lista, transforma o ponteiro inicio no próximo cliente da lista (ou cliente anterior)
    }else{ //se for no meio, ele coloca o ponteiro do anterior no próximo desse ponteiro
        ant->prox = atual->prox;
    }
    free(atual);
    l->qtde--;
}

Fila *cria_fila(){
    Fila *fila = malloc(sizeof(Fila));
    fila->head = NULL;
    fila->qtde = 0;
    fila->tail = NULL;
    return fila;
}

Efila *cria_efila(Lista *l){
    Efila *fila = malloc(sizeof(Efila));
    fila->prox = NULL;
    printf("RG do cliente que deseja entrar na fila: ");
    char RG[8];
    scanf("%s", RG);
    Elista *c = l->inicio;
    int i;
    for(i = 0; i < l->qtde; i++){ //encontra o cliente na lista de clientes cadastrados
        if(strcmp(RG, c->dados.rg) == 0){
            break;
        }
        c = c->prox;
    }
    if(i == l->qtde){
        printf("RG não encontrado.\n");
        return;
    }
}

void enfileirar(){

}