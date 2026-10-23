#include <stdio.h>
#include <stdlib.h>
#include "BibliotecaP1.h"
#include <locale.h>
#include <string.h>

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

int setCodSolicitacao(){

        int cod;

        do {
            printf("Código da solicitação (4 dígitos entre 1000 e 9999): ");

            // Se o scanf conseguir ler exatamente 1 número inteiro + armazena na variavel
            if (scanf("%d", &cod) == 1) {
                limpaBuffer(); // Limpa o '\n' (Enter) deixado no teclado para a proxima digitacao

                if (cod >= 1000 && cod <= 9999) {

                    return cod;

                } else {
                    printf("Erro! O código deve estar entre 1000 e 9999.\n");
                }
            } else {
                // Se o usuário digitou letras, o scanf falha e cai AQUI!
                printf("Erro! Digite apenas números (sem letras ou símbolos).\n");
                limpaBuffer(); // OBRIGATÓRIO: Descarta a letra do buffer para não travar o loop
            }

        } while (1);

}

int setPrioridade(){

    int prior;
        do{
            printf("Prioridades:\n");
            printf("1 - Alta\n");
            printf("2 - Média\n");
            printf("3 - Baixa\n");

            printf("Prioridade: ");
            scanf("%d", &prior);

            if(prior == 1 || prior == 2 || prior == 3 ){
                return prior;
            } else{
                printf("Erro! numero invalido.");
            }

            limpaBuffer();

        }while(1);

}

int setPeriodo(){

    int per;
        do{
            printf("Período em dias: ");
            scanf("%d", &per);

            if(per >= 1 && per<= 20 ){
                return per;

            } else{
                printf("Erro! numero invalido.");
            }

            limpaBuffer();

        }while(1);

}


int main(){

    setlocale(LC_ALL, "");

    // inputs
    int opcao;
    int codigoSolicitacao;
    int prioridade;
    int periodo;

    char codigoEquipamento[8];
    char nomeEquipamento[21];

    char entrada[30];
    char resposta;

    // Criacao da lista principal
    Lista *L;

    L = CriaLista();


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

        limpaBuffer();



    switch (opcao){

        case 1:
            printf("\n--- INSERIR SOLICITACAO ---\n");

            codigoSolicitacao = setCodSolicitacao();

    valido = 0;

                 do {
        printf("Digite o código do equipamento (3 letras e 3 números - Ex: OSC023): ");

        if (fgets(entrada, sizeof(entrada), stdin) != NULL) {

            entrada[strcspn(entrada, "\n")] = '\0';

            //strlen nao considera \0 na contagem! Por isso verificacao eh possivel
            if (strlen(entrada) == 6) {

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

    valido = 0;

    do{
            printf("Digite o nome do equipamento:");
        if (fgets(entrada, sizeof(entrada), stdin) != NULL) {

            entrada[strcspn(entrada, "\n")] = '\0';

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


        prioridade = setPrioridade();

        periodo = setPeriodo();

printf("\nCódigo inserido com sucesso: %d\n", codigoSolicitacao);
//printf("Código armazenado com sucesso: %s\n", codigoEquipamento);
//printf("Nome inserido com sucesso: %s\n", nomeEquipamento);
//printf("Prioridade inserida com sucesso %d \n", prioridade);
//printf("Periodo inserido com sucesso %d \n", periodo);

    InsereSolicitacao(L, codigoSolicitacao, codigoEquipamento, nomeEquipamento, prioridade, periodo);

                break;




        case 2:

                printf("\n--- REMOVER SOLICITAÇÃO ---\n");

                codigoSolicitacao = setCodSolicitacao();

                break;

        case 3:


                printf("\n--- CONSULTAR SOLICITAÇÃO ---\n");

                codigoSolicitacao = setCodSolicitacao();
                imprimeSolicitacao(L,codigoSolicitacao);

                break;

        case 4:

                printf("\n--- ALTERAR SOLICITACAO ---\n");

                codigoSolicitacao = setCodSolicitacao();

                prioridade = setPrioridade();

                periodo = setPeriodo();

                break;



        case 5:

                printf("\n--- ORDEM DE REALIZACAO DA MANUTENCAO ---\n");



                break;

        case 6:

                printf("\n--- TODAS AS SOLICITACOES ---\n");

                imprimeLista (L);

                break;

        case 0:

            do {

                printf("\n\nDeseja Realmente sair do programa? (S || N) \n");
                scanf("%c", &resposta);
                limpaBuffer();

                if ((resposta != 'S') && (resposta != 's') &&
                    (resposta != 'N') && (resposta != 'n'))
                {
                    printf("\n\n\t\t=> DIGITE SOMENTE S PARA SIM OU N PARA NÃO <=\n\n");
                    limpaBuffer();

                }

            } while ((resposta != 'S') && (resposta != 's') && (resposta != 'N') && (resposta != 'n'));

                if ((resposta == 'S') || (resposta == 's'))
                {
                    printf("\nFinalizando o programa...\n");

                    LiberaLista(L);
                    /*LiberaLista();*/ //Lista de impressao
                    printf("Programa finalizado.\n");
                    exit(0);
                }

                break;

            default: // caso nenhum dos casos seja digitado
                printf("\nOpcao invalida!\n");
        }

    } while (1); // codigo funciona ate exit(0)

}


