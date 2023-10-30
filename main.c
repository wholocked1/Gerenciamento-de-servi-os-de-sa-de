#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

void main(){
    printf("Escolha a alternativa com a ação desejada:\n1: Cadastro de clientes\n2: Atendimento\n3: Pesquisa\n4: Carregar/Salvar\n5: Sobre\n6: Sair");
    int alter;
    scanf("%d", &alter);
    Lista *lista = criar_lista();
    int esc;
    while(alter != 6){
        if(alter == 1){
            printf("Qual função deseja ser feita:\n1: Cadastrar novo paciente\n2: Consultar paciente cadastrado\n3: Mostrar a lista completa\n4: Atualizar cadastrado de um cliente\n5: Remover cliente\n6: Sair");
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
        }
    }
}