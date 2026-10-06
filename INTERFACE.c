#include <stdio.h>
#include <stdlib.h>
#include "LISTA.h"




int main(void)
{
    int opcao;
    int codigoSolicitacao;
    int prioridade;
    int periodo;

    char codigoEquipamento[7];
    char nomeEquipamento[21];

    /*
        Declare aqui posteriormente a lista principal.

        Exemplo:

        Lista *lista;

        lista = criaLista();
    */

    do
    {
        printf("\n");
        printf("=============================================\n");
        printf("   GERENCIADOR DE MANUTENCAO DE EQUIPAMENTOS\n");
        printf("=============================================\n");
        printf("1 - Inserir uma solicitacao de manutencao\n");
        printf("2 - Remover uma solicitacao\n");
        printf("3 - Consultar uma solicitacao\n");
        printf("4 - Alterar prioridade e/ou periodo\n");
        printf("5 - Exibir ordem da realizacao da manutencao\n");
        printf("6 - Exibir todas as solicitacoes\n");
        printf("0 - Finalizar\n");
        printf("=============================================\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            /* ===================================================== */
            /* INSERIR SOLICITACAO                                    */
            /* ===================================================== */

            case 1:

                printf("\n--- INSERIR SOLICITACAO ---\n");

                printf("Codigo da solicitacao (4 digitos): ");
                scanf("%d", &codigoSolicitacao);

                printf("Codigo do equipamento (3 letras e 3 digitos): ");
                scanf("%6s", codigoEquipamento);

                printf("Nome do equipamento: ");
                scanf(" %20[^\n]", nomeEquipamento);

                printf("\nPrioridades:\n");
                printf("1 - Alta\n");
                printf("2 - Media\n");
                printf("3 - Baixa\n");

                printf("Prioridade: ");
                scanf("%d", &prioridade);

                printf("Periodo em dias: ");
                scanf("%d", &periodo);

                /*
                    Chamada da sua funcao de insercao.

                    Exemplo:

                    inserirSolicitacao(lista,
                                      codigoSolicitacao,
                                      codigoEquipamento,
                                      nomeEquipamento,
                                      prioridade,
                                      periodo);
                */
                system("cls");
                break;


            /* ===================================================== */
            /* REMOVER SOLICITACAO                                    */
            /* ===================================================== */

            case 2:

                printf("\n--- REMOVER SOLICITACAO ---\n");

                printf("Digite o codigo da solicitacao: ");
                scanf("%d", &codigoSolicitacao);

                /*
                    Chamada da sua funcao de remocao.

                    Exemplo:

                    removerSolicitacao(lista, codigoSolicitacao);
                */

                break;


            /* ===================================================== */
            /* CONSULTAR SOLICITACAO                                  */
            /* ===================================================== */

            case 3:

                printf("\n--- CONSULTAR SOLICITACAO ---\n");

                printf("Digite o codigo da solicitacao: ");
                scanf("%d", &codigoSolicitacao);

                /*
                    Chamada da sua funcao de consulta.

                    Exemplo:

                    consultarSolicitacao(lista, codigoSolicitacao);
                */

                break;


            /* ===================================================== */
            /* ALTERAR PRIORIDADE / PERIODO                           */
            /* ===================================================== */

            case 4:

                printf("\n--- ALTERAR SOLICITACAO ---\n");

                printf("Digite o codigo da solicitacao: ");
                scanf("%d", &codigoSolicitacao);

                printf("\nNova prioridade:\n");
                printf("1 - Alta\n");
                printf("2 - Media\n");
                printf("3 - Baixa\n");

                printf("Prioridade: ");
                scanf("%d", &prioridade);

                printf("Novo periodo em dias: ");
                scanf("%d", &periodo);

                /*
                    Chamada da sua funcao de alteracao.

                    Exemplo:

                    alterarSolicitacao(lista,
                                      codigoSolicitacao,
                                      prioridade,
                                      periodo);
                */

                break;


            /* ===================================================== */
            /* ORDEM DE MANUTENCAO                                    */
            /* ===================================================== */

            case 5:

                printf("\n--- ORDEM DE REALIZACAO DA MANUTENCAO ---\n");

                /*
                    Aqui sua funcao devera criar uma NOVA lista,
                    sem alterar a lista principal.

                    Exemplo:

                    exibirOrdemManutencao(lista);
                */

                break;


            /* ===================================================== */
            /* EXIBIR TODAS AS SOLICITACOES                           */
            /* ===================================================== */

            case 6:

                printf("\n--- TODAS AS SOLICITACOES ---\n");

                /*
                    Chamada da sua funcao de exibicao.

                    Exemplo:

                    exibirSolicitacoes(lista);
                */

                break;


            /* ===================================================== */
            /* FINALIZAR                                              */
            /* ===================================================== */

            case 0:

                printf("\nFinalizando o programa...\n");

                /*
                    Antes de encerrar, libere toda memoria alocada.

                    Exemplo:

                    liberarLista(lista);
                */

                printf("Programa finalizado.\n");

                break;


            /* ===================================================== */

            default:

                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
