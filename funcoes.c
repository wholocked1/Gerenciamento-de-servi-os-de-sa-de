#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
    cliente->dados = malloc(sizeof(Registro)); //aloca memória para as informações do registro
    printf("Nome: ");
    scanf("%100s", cliente->dados->nome); //recebe o nome
    clearBuffer();
    printf("Idade: ");
    scanf("%d", &cliente->dados->idade); //recebe a idade
    printf("RG: ");
    scanf("%s", cliente->dados->rg); //recebe o RG
    printf("Dia: "); 
    scanf("%d", &cliente->dados->data.dia); //recebe o dia em que as informações foram recebidas
    printf("Mês: ");
    scanf("%d", &cliente->dados->data.mes); //recebe o mês em que as informações foram recebidas
    printf("Ano: ");
    scanf("%d", &cliente->dados->data.ano); //recebe o ano em que as informações foram recebidas
    cliente->prox = NULL; //deixa nulo o ponteiro do proximo desse cliente
  return cliente;
}

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
        if(strcmp(RG, c->dados->rg) == 0){
            break; //se encontrar, sai do loop
        }
        c = c->prox; //se não encontrar, ele vai para o próximo ponteiro da lista
    }
    if(i == l->qtde){ //verifica no final se o RG realmente não foi encontrado
        printf("RG não cadastrado!\n");
        return;
    }
    printf("Nome: %s; Idade: %d; Data de criação: %d/%d/%d\n", c->dados->nome, c->dados->idade, c->dados->data.dia,
         c->dados->data.mes, c->dados->data.ano); //se for encontrado, ele mostra na tela
}
//funciona
void lista_clientes(Lista *l){ //mostra a lista de clientes cadastrados no sistema
    printf("Lista de clientes: \n");
    Elista *c = l->inicio;
    for(int i = 0; i < l->qtde; i++){ //imprime a lista de clientes
        printf("Nome: %s; Idade: %d; RG: %s; Data de criação: %d/%d/%d\n", c->dados->nome, c->dados->idade, c->dados->rg,
             c->dados->data.dia, c->dados->data.mes, c->dados->data.ano);
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
        if(strcmp(rg, c->dados->rg) == 0){
            break;
        }
        c = c->prox;
    }
    int alt;
    printf("Qual informação deseja ser alterada:\n 1: Nome\n 2: Idade\n");
    scanf("%d", &alt); //recebe qual o tipo de informação que deseja ser modificada
    if (alt == 1){
        printf("Nome: ");
        scanf("%s", c->dados->nome); //recebe a mudança de dados e salva no ponteiro 
        clearBuffer();
    }else if (alt == 2){
        printf("Idade: ");
        int idade;
        scanf("%d", &idade); //recebe a mudança de dados e salva no ponteiro 
        c->dados->idade = idade;
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
        if(strcmp(rg, atual->dados->rg) == 0){
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

Fila *cria_fila(){ //cria uma fila nova para o atendimento 
    Fila *fila = malloc(sizeof(Fila));
    fila->head = NULL;
    fila->qtde = 0;
    fila->tail = NULL;
    return fila;
}

Efila *cria_efila(Lista *l){ //cria uma Efila (ficha do cliente que deseja ser atendido) com base nos dados do cadastro
    Efila *fila = malloc(sizeof(Efila));
    fila->dados = malloc(sizeof(Registro));
    fila->prox = NULL;
    printf("RG do cliente que deseja entrar na fila: ");
    int RG;
    scanf("%d", &RG);
    char rg[8];
    sprintf(rg, "%d", RG);
    Elista *c = l->inicio;
    int i;
    for(i = 0; i < l->qtde; i++){ //encontra o cliente na lista de clientes cadastrados
        if(strcmp(rg, c->dados->rg) == 0){
            break;
        }
        c = c->prox;
    }
    if(i == l->qtde){
        printf("RG não encontrado.\n");
        return NULL;
    }
    //passagem de informação para o ponteiro da fila
    sprintf(fila->dados->nome, "%s", c->dados->nome);
    fila->dados->idade = c->dados->idade;
    sprintf(fila->dados->rg, "%s", c->dados->rg);
    fila->dados->data.ano = c->dados->data.ano;
    fila->dados->data.mes = c->dados->data.mes;
    fila->dados->data.dia = c->dados->data.dia;
    return fila;
}

void enfileirar(Fila *fila, Lista *lista){ //coloca a pessoa na fila de clientes a serem atendidos
    Efila *cliente = cria_efila(lista);
    if(fila->qtde == 0){ //se não houver nenhum cliente
        fila->head = cliente;
        fila->tail = cliente;
        fila->qtde++;
    }else{ //se já houver cliente
        fila->tail->prox = cliente;
        fila->tail = cliente;
        fila->qtde++;
    }
}

void desinfileirar(Fila *fila){ //tira a pessoa que acabou de ser chamada ao atendimento (primeiro da fila)
    if(fila==0){
        printf("Fila vazia\n");
        return;
    }
    Efila *c = fila->head;
    if(fila->qtde == 1){ //se for o único da fila
        fila->head = NULL;
        fila->tail = NULL;
        fila->qtde--;
    }else{ //se não for o único da fila
        fila->head = fila->head->prox;
        fila->qtde--;
    }
    free(c); //libera o espaço ocupado por esse ponteiro na memória
}

void imprimir(Fila *fila){ //mostra a fila de paciêntes
    printf("Fila de clientes: \n");
    Efila *c = fila->head;
    while(c != NULL){
        printf("Nome: %s; RG: %s\n", c->dados->nome, c->dados->rg);
        c = c->prox;
    }
    printf("Final da fila.\n");
}

void salvar(Lista *lista){ //salva as informações dos clientes em um arquivo TXT
  FILE *arq = fopen("pacientes.txt", "w"); // Abre o arquivo para escrita
  Elista *c = lista->inicio;
  fprintf(arq, "%d\n", lista->qtde); // Anota a quantidade de elementos na lista de pacientes
  for (int i = 0; i < lista->qtde; i++) { // Roda o codigo abaixo para a quantidade de pacientes e salva no arquivo cada uma das informações
    fprintf(arq, "%s\n", c->dados->nome);
    fprintf(arq, "%d\n", c->dados->idade);
    fprintf(arq, "%s\n", c->dados->rg);
    fprintf(arq, "%d\n", c->dados->data.dia);
    fprintf(arq, "%d\n", c->dados->data.mes);
    fprintf(arq, "%d\n", c->dados->data.ano);
    c = c->prox; // Passa para o próximo cliente da lista
  }
  fclose(arq); // Fecha o arquivo
}

void carregar(Lista *lista){ //carrega as informações dos clientes de volta à função de um arquivo TXT
    FILE *arq =fopen("pacientes.txt", "r"); // Abre o arquivo dos pacientes para leitura
  fscanf(arq, "%d", &lista->qtde); // Atualiza a quantidade de clientes para qual tinha salvo no arquivo
  fclose(arq);
  carrega_info(lista, 0);
}

void carrega_info(Lista *lista, int i) { //função suporte para carregamento das informações
  if(i == lista->qtde){return;} // Caso me contador chega na quantidade de clientes e para a recursividade da função
  FILE *arq = fopen("pacientes.txt", "r"); // Abre o arquivo dos pacientes para leitura
  Elista *c = malloc(sizeof(Elista));
  c->prox = NULL;
  Registro *r = malloc(sizeof(Registro));
  // variáveis criadas para salvar os elementos do arquivo e passar para o struct de registro
  int buffer, idade, dia, mes, ano; 
  char nome [100];
  char rg[8];
  fscanf(arq, "%d", &buffer);
  for(int j = 0; j <= i; j++){ // roda o código para salvar os dados de um cliente
    fscanf(arq, "%s", nome);
    fscanf(arq, "%d", &idade);
    fscanf(arq, "%s", rg);
    fscanf(arq, "%d", &dia);
    fscanf(arq, "%d", &mes);
    fscanf(arq, "%d", &ano);
  }
  strcpy(r->nome, nome);
  r->idade = idade;
  strcpy(r->rg, rg);
  r->data.dia = dia;
  r->data.mes = mes;
  r->data.ano = ano;
  c->dados = r;
  if (i == 0) {      // se for o primeiro cliente da lista:
    lista->inicio = c;         // coloca esse cliente como o primeiro da lista
  } else {                 // se não for:
    Elista *dado = lista->inicio; // salva o cliente que estava no começo em um ponteiro
    while(dado->prox != NULL){
      dado = dado->prox;
    }
    dado->prox = c; // coloca esse cliente anterior como próximo do novo ponteiro
  }
  fclose(arq);
  carrega_info(lista, i+1); // recursividade da função para re adicionar todos os clientes na lista
}

Arvore *cria_arvore() { //cria a árvore
  Arvore *arvore = malloc(sizeof(Arvore));
  arvore->raiz = NULL;
  arvore->qtde = 0;

  return arvore;
}

Vertice *cria_vertice(Arvore *arvore, Registro *registro) { //cria um vértice novo
  Vertice *novo = malloc(sizeof(Vertice));
  novo->dir = NULL;
  novo->esq = NULL;
  novo->pai = NULL;
  novo->registro = registro;
  return novo;
}

void mostrar(Vertice *raiz){ //imprime a árvore
    if(raiz != NULL){
        mostrar(raiz->esq);
        printf("%s ", raiz->registro->nome);
        mostrar(raiz->dir);        
    }
}

void pesquisa_ano(Lista *lista){ //faz a pesquisa por ano de cadastro
    Elista *c = lista->inicio;
    Arvore *arvore = cria_arvore();
    for (int i = 0; i < lista->qtde; i++){
        insere_ano(arvore, c->dados);
        c=c->prox;
    }
    mostrar(arvore->raiz);
    printf("\n");
}

void pesquisa_mes(Lista *lista){ //faz a pesquisa por mês de cadastro
    Elista *c = lista->inicio;
    Arvore *arvore = cria_arvore();
    for (int i = 0; i < lista->qtde; i++){
        insere_mes(arvore, c->dados);
        c=c->prox;
    }
    mostrar(arvore->raiz);
    printf("\n");
}

void pesquisa_dia(Lista *lista){ //faz a pesquisa por dia de cadastro
    Elista *c = lista->inicio;
    Arvore *arvore = cria_arvore();
    for (int i = 0; i < lista->qtde; i++){
        insere_dia(arvore, c->dados);
        c=c->prox;
    }
    mostrar(arvore->raiz);
    printf("\n");
}

void pesquisa_idade(Lista *lista){ //faz a pesquisa pela idade do paciênte
    Elista *c = lista->inicio;
    Arvore *arvore = cria_arvore();
    for (int i = 0; i < lista->qtde; i++){
        insere_idade(arvore, c->dados);
        c=c->prox;
    }
    mostrar(arvore->raiz);
    printf("\n");
}

void insere_ano(Arvore *arvore, Registro *registro) { //cria a árvore por ano
  Vertice *vertice = cria_vertice(arvore, registro);
  int valor = registro->data.ano;
  if (arvore->qtde == 0) {
    arvore->raiz = vertice;
  } else {
    Vertice *aux = arvore->raiz;
    while (aux != NULL) {
      if (valor < aux->registro->data.ano && aux->esq == NULL) {
        aux->esq = vertice;
        vertice->pai = aux;
        break;
      } else if (valor > aux->registro->data.ano && aux->dir == NULL) {
        aux->dir = vertice;
        vertice->pai = aux;
        break;
      } else if (valor < aux->registro->data.ano) {
        aux = aux->esq;
      } else if (valor > aux->registro->data.ano) {
        aux = aux->dir;
      } else if ( valor == aux->registro->data.ano && aux->esq == NULL){
        aux->esq = vertice;
        vertice->pai = aux;
        break;
      }
    }
  }
  arvore->qtde++;
}

void insere_mes(Arvore *arvore, Registro *registro) {//cria a árvore por mês
  Vertice *vertice = cria_vertice(arvore, registro);
  int valor = registro->data.mes;
  if (arvore->qtde == 0) {
    arvore->raiz = vertice;
  } else {
    Vertice *aux = arvore->raiz;
    while (aux != NULL) {
      if (valor < aux->registro->data.mes && aux->esq == NULL) {
        aux->esq = vertice;
        vertice->pai = aux;
        break;
      } else if (valor > aux->registro->data.mes && aux->dir == NULL) {
        aux->dir = vertice;
        vertice->pai = aux;
        break;
      } else if (valor < aux->registro->data.mes) {
        aux = aux->esq;
      } else if (valor > aux->registro->data.mes) {
        aux = aux->dir;
      } else if ( valor == aux->registro->data.mes && aux->esq == NULL){
        aux->esq = vertice;
        vertice->pai = aux;
        break;
      }
    }
  }
  arvore->qtde++;
}

void insere_dia(Arvore *arvore, Registro *registro) { //cria a árvore por dia
  Vertice *vertice = cria_vertice(arvore, registro);
  int valor = registro->data.dia;
  if (arvore->qtde == 0) {
    arvore->raiz = vertice;
  } else {
    Vertice *aux = arvore->raiz;
    while (aux != NULL) {
      if (valor < aux->registro->data.dia && aux->esq == NULL) {
        aux->esq = vertice;
        vertice->pai = aux;
        break;
      } else if (valor > aux->registro->data.dia && aux->dir == NULL) {
        aux->dir = vertice;
        vertice->pai = aux;
        break;
      } else if (valor < aux->registro->data.dia) {
        aux = aux->esq;
      } else if (valor > aux->registro->data.dia) {
        aux = aux->dir;
      } else if ( valor == aux->registro->data.dia && aux->esq == NULL){
        aux->esq = vertice;
        vertice->pai = aux;
        break;
      }
    }
  }
  arvore->qtde++;
}

void insere_idade(Arvore *arvore, Registro *registro) { //cria a árvore por idade
  Vertice *vertice = cria_vertice(arvore, registro);
  int valor = registro->idade;
  if (arvore->qtde == 0) {
    arvore->raiz = vertice;
  } else {
    Vertice *aux = arvore->raiz;
    while (aux != NULL) {
      if (valor < aux->registro->idade && aux->esq == NULL) {
        aux->esq = vertice;
        vertice->pai = aux;
        break;
      } else if (valor > aux->registro->idade && aux->dir == NULL) {
        aux->dir = vertice;
        vertice->pai = aux;
        break;
      } else if (valor < aux->registro->idade) {
        aux = aux->esq;
      } else if (valor > aux->registro->idade) {
        aux = aux->dir;
      } else if ( valor == aux->registro->idade && aux->esq == NULL){
        aux->esq = vertice;
        vertice->pai = aux;
        break;
      }
    }
  }
  arvore->qtde++;
}