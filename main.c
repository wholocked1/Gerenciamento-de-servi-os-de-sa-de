#include <stdlib.h>

#include <stdio.h>
#include "funcoes.h"

int main(void){
    printf("Escolha a alternativa com a ação desejada:\n1: Cadastro de clientes\n2: Atendimento\n3: Pesquisa\n4: Carregar/Salvar\n5: Sobre\n6: Sair\n");
    int alter;
    scanf("%d", &alter);
    Lista *lista = criar_lista();
    Fila *fila = cria_fila();
    int esc;
    while(alter != 6){
        if(alter == 1){
            printf("Qual função deseja ser feita:\n1: Cadastrar novo paciente\n2: Consultar paciente cadastrado\n3: Mostrar a lista completa\n4: Atualizar cadastrado de um cliente\n5: Remover cliente\n6: Sair\n");
            scanf("%d", &esc);
            if(esc == 1){
                inserir(lista);
            }else if(esc == 2){
                consulta(lista);
            }else if(esc == 3){
                lista_clientes(lista);
            }else if(esc == 4){
                atualiza_cliente(lista);
            }else if(esc == 5){
                remover_cliente(lista);
            }
        }else if(alter == 2){
            printf("Qual função deseja ser realizada:\n1: colocar um paciente na fila\n2: tirar um paciente da fila\n3: mostrar a fila atual");
            scanf("%d", &esc);
            if(esc == 1){
                enfileirar(fila, lista);
            }else if(esc == 2){
                desinfileirar(fila);
            }else if(esc == 3){
                imprimir(fila);
            }else{
                printf("Opção inválida\n");
            }
        }
        printf("Escolha a alternativa com a ação desejada:\n1: Cadastro de clientes\n2: Atendimento\n3: Pesquisa\n4: Carregar/Salvar\n5: Sobre\n6: Sair\n");
        scanf("%d", &alter);
    }
    return 0;
}

