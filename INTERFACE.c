#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "BibliotecaP1.h"
#include <locale.h>

void limpaBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Verifica se um caractere é uma letra (A-Z ou a-z) usando a Tabela ASCII
int ehLetra(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// Verifica se um caractere é um dígito numérico ('0' a '9') usando a Tabela ASCII
int ehNumero(char c) {
    return (c >= '0' && c <= '9');
}



int main(){

    setlocale(LC_ALL, "");

    // inputs
    int opcao;
    int codigoSolicitacao;
    int prioridade;
    int periodo;

    char codigoEquipamento[7];
    char nomeEquipamento[21];

    char entrada[30]; // configurei como 30 para verificacao de tamanho de string


    // Criacao da lista principal
    Lista *L;


    int valido = 0;

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



    switch (opcao){

        case 1:
           printf("\n--- INSERIR SOLICITACAO ---\n");

        valido = 0; //verificador do-while

    do {
        printf("Código da solicitação (4 dígitos entre 1000 e 9999): ");

        // Se o scanf conseguir ler exatamente 1 número inteiro + armazena na variavel
        if (scanf("%d", &codigoSolicitacao) == 1) {
            limpaBuffer(); // Limpa o '\n' (Enter) deixado no teclado para a proxima digitacao

            if (codigoSolicitacao >= 1000 && codigoSolicitacao <= 9999) {
                valido = 1;

            } else {
                printf("Erro! O código deve estar entre 1000 e 9999.\n");
            }
        }
        else {
            // Se o usuário digitou letras, o scanf falha e cai AQUI!
            printf("Erro! Digite apenas números (sem letras ou símbolos).\n");
            limpaBuffer(); // OBRIGATÓRIO: Descarta a letra do buffer para não travar o loop
        }

    } while (valido == 0);
     printf("\nCódigo inserido com sucesso: %d\n", codigoSolicitacao);


    valido = 0;

                 do {
        printf("Digite o código do equipamento (3 letras e 3 números - Ex: OSC023): ");

        if (fgets(entrada, sizeof(entrada), stdin) != NULL) {

            //strlen nao considera \0 na contagem! Por isso verificacao eh possivel
            if (strlen(entrada) == 7) {

                // Verifica se os índices 0, 1 e 2 são letras
                int letrasValidas = ehLetra(entrada[0]) && ehLetra(entrada[1]) && ehLetra(entrada[2]);

                // Verifica se os índices 3, 4 e 5 são números
                int numerosValidos = ehNumero(entrada[3]) && ehNumero(entrada[4]) && ehNumero(entrada[5]);

                // retorna 1 (verdadeiro) se as variaves foram aprovadas
                if (letrasValidas && numerosValidos) {

                    // Copia o código aprovado para a string oficial
                    strcpy(codigoEquipamento, entrada);
                    valido = 1;

                } else {
                    printf("Erro! O formato correto é 3 LETRAS seguidas de 3 NÚMEROS.\n\n");
                }

            } else {
                printf("Erro! O código deve conter exatamente 6 caracteres.\n\n");
            }

        } else {
            printf("Erro na leitura! Tente novamente.\n\n");
        }

    } while (!valido);


    // Confirmação do código armazenado
    printf("\n---------------------------------------------\n");
    printf("Código armazenado com sucesso no char[7]: %s\n", codigoEquipamento);
    printf("Tamanho da string final (strlen): %zu caracteres\n", strlen(codigoEquipamento));
    printf("---------------------------------------------\n");


    valido = 0;

    do{
            printf("Digite o nome do equipamento: \n\n");
        if (fgets(entrada, sizeof(entrada), stdin) != NULL) {

            if (strlen(entrada) <= 21) {

                    valido = 1;
                    strcpy(nomeEquipamento, entrada);
                } else{
                    printf("Erro! O numero de caracteres maximo eh 20.\n\n");
                }

                } else{

            printf("Erro na leitura! Tente novamente.\n\n");

        }

    }while(!valido);
    printf("\nNome inserido com sucesso: %s\n", entrada);

    valido = 0;
            do{
                printf("\nPrioridades:\n");
                printf("1 - Alta\n");
                printf("2 - Média\n");
                printf("3 - Baixa\n");

                printf("Prioridade: ");
                scanf("%d", &prioridade);

                if(prioridade == 1 || prioridade == 2 || prioridade == 3 ){
                    valido = 1;
                } else{
                    printf("Erro! numero invalido.");
                }
                limpaBuffer();

            }while(!valido);


            valido = 0;
            do{
                printf("Período em dias: ");
                scanf("%d", &periodo);

                if(periodo >= 1 && periodo<= 20 ){
                    valido = 1;

                } else{
                    printf("Erro! numero invalido.");
                }
                limpaBuffer();

            }while(!valido);

printf("\nCódigo inserido com sucesso: %d\n", codigoSolicitacao);
printf("Código armazenado com sucesso no char[7]: %s\n", codigoEquipamento);
printf("\nNome inserido com sucesso: %s\n", nomeEquipamento);
printf("\nPrioridade inserida com sucesso %d \n", prioridade);
printf("\Periodo inserido com sucesso %d \n", periodo);

                InsereSolicitacao(L, codigoSolicitacao, codigoEquipamento, nomeEquipamento, prioridade, periodo);

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

                BuscaSolicitacao(L, codigoSolicitacao);


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


                printf("\nDeseja Realmente sair do programa? (S/N) \n");


                printf("\nFinalizando o programa...\n");

                printf("Programa finalizado.\n");

                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    }while (opcao != 0);

}



