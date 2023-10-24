typedef struct{
    int dia;
    int mes;
    int ano;
}Data; //salva a data

typedef struct{
    char nome[100];
    int idade;
    char rg[8]; //não conta com os pontos e traços
    Data data;
} Registro;