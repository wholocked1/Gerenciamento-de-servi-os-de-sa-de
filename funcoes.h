typedef struct{ //salva as informações da data de criação
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{ //salva as informações pessoais do cliente
    char nome[100];
    int idade;
    char rg[8]; //não conta com os pontos e traços
    Data data;
} Registro;

typedef struct Elista{ //struct que vai salvar os dados do cliente e marcar o próximo
    Registro dados;
    struct Elista *prox;
}Elista;

typedef struct Lista //struct que vai salvar o inicio da lista e a quantidade de pessoas na fila
{
    Elista *inicio;
    int qtde;
}Lista;

//funções

Lista *criar_lista();
Elista *cria_info();
void inserir(Lista *l);
void consulta(Lista *l);
void lista_clientes(Lista *l);
void atualiza_cliente(Lista *l);
void remover_cliente(Lista *l);