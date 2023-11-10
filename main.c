#include <stdlib.h>
#include <string.h>
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
            printf("Qual função deseja ser realizada:\n1: colocar um paciente na fila\n2: tirar um paciente da fila\n3: mostrar a fila atual\n");
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
        }else if(alter == 3){
            printf("Qual função deseja ser realizada:\n1: Ordenar por ano de registro.\n2: Ordenar por mes de registro.\n3: Ordenar por dia de registro.\n4: Ordenar por idade do paciente.\n");
            scanf("%d", &esc);
            if(esc == 1){
                pesquisa_ano(lista);
            } else if( esc == 2){
                pesquisa_mes(lista);
            } else if ( esc == 3){
                pesquisa_dia(lista);
            } else if( esc == 4) {
                pesquisa_idade(lista);
            } else {
                printf("Opção inválida\n");
            }

        }else if(alter == 4){
            printf("Qual função deseja ser realizada:\n1: Salvar\n2: Carregar\n");
            scanf("%d", &esc);
            if(esc == 1){
                salvar(lista);
            }else if(esc == 2){
                carregar(lista);
            }else{
                printf("Opção inválida\n");
            }
        }else if(alter == 5){
            printf(" Nome dos participantes: Ana Carolina Cogo Nami & Enzo Lima Cassin\n Ciclo: 4º ciclo/semestre\n Curso: Ciência da Computação\n Disciplina: Estrutura de Dados\n Data: 10/11/2023\n");
        }
        printf("Escolha a alternativa com a ação desejada:\n1: Cadastro de clientes\n2: Atendimento\n3: Pesquisa\n4: Carregar/Salvar\n5: Sobre\n6: Sair\n");
        scanf("%d", &alter);
    }
    return 0;
}

