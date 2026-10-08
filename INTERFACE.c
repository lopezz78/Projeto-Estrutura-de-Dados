#include <stdio.h>
#include <stdlib.h>
#include "LISTA.h"
#include <locale.h>



int main(void)
{

    setlocale(LC_ALL, "");

    // inputs
    int opcao;
    int codigoSolicitacao;
    int prioridade;
    int periodo;

    char codigoEquipamento[7];
    char nomeEquipamento[21];


    Lista *L;


    do
    {
        printf("\n");
        printf("=============================================\n");
        printf("   GERENCIADOR DE MANUTENCAO DE EQUIPAMENTOS\n");
        printf("=============================================\n");
        printf("1 - Inserir uma solicitação de manutenção\n");
        printf("2 - Remover uma solicitação\n");
        printf("3 - Consultar uma solicitação\n");
        printf("4 - Alterar prioridade e/ou período\n");
        printf("5 - Exibir ordem da realização da manutenção\n");
        printf("6 - Exibir todas as solicitações\n");
        printf("0 - Finalizar\n");
        printf("=============================================\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

            case 1:
                printf("\n--- INSERIR SOLICITACAO ---\n");
                do{
                printf("Código da solicitação (4 digitos): ");
                scanf("%d", &codigoSolicitacao);
                } while(codigoSolicitacao < 1000 || codigoSolicitacao >9999);


                printf("Código do equipamento (3 letras e 3 digitos): ");
                scanf("%s", &codigoEquipamento);
                printf("%s",codigoEquipamento);


                printf("Nome do equipamento: ");
                scanf(" %s", nomeEquipamento);


                printf("\nPrioridades:\n");
                printf("1 - Alta\n");
                printf("2 - Média\n");
                printf("3 - Baixa\n");

                printf("Prioridade: ");
                scanf("%d", &prioridade);

                printf("Período em dias: ");
                scanf("%d", &periodo);


                system("cls");
                break;

            case 2:

                printf("\n--- REMOVER SOLICITAÇÃO ---\n");

                printf("Digite o codigo da solicitação: ");
                scanf("%d", &codigoSolicitacao);

                break;



            case 3:

                printf("\n--- CONSULTAR SOLICITAÇÃO ---\n");

                printf("Digite o código da solicitação: ");
                scanf("%d", &codigoSolicitacao);


                break;

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






                break;



            case 5:

                printf("\n--- ORDEM DE REALIZACAO DA MANUTENCAO ---\n");



                break;

            case 6:

                printf("\n--- TODAS AS SOLICITACOES ---\n");

                break;

            case 0:

                printf("\nFinalizando o programa...\n");

                printf("Programa finalizado.\n");

                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
