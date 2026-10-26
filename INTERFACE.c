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

int setCodSolicitacao(Lista *L){

        int cod;

        do {
            printf("\nCódigo da solicitação (4 dígitos entre 1000 e 9999): ");
            printf("\n==> ");

            // Se o scanf conseguir ler exatamente 1 número inteiro + armazena na variavel
            if (scanf("%d", &cod) == 1) {
                limpaBuffer(); // Limpa o '\n' deixado no teclado para a proxima digitacao

                if(cod == 0){
                    return cod;
                }

                if (cod >= 1000 && cod <= 9999) {


                    if(VerificaCodigo(L, cod)== 0){
                    return cod;
                    } else{
                        printf("\nCódigo já cadastrado! Utilize outro.\n\n ");
                    }

                } else {
                    printf("\nErro! O código deve estar entre 1000 e 9999.\n\n");
                }
            } else {
                // Se o usuário digitou letras, o scanf falha e cai aqui!
                printf("\nErro! Digite apenas números (sem letras ou símbolos).\n\n");
                limpaBuffer();
            }

        } while (1);

}

int setPrioridade(){

    int prior;
        do{
            printf("\nEscolha a prioridade (entre 1 e 3):\n");
            printf("1 - Alta\n");
            printf("2 - Média\n");
            printf("3 - Baixa\n");
            printf("==> ");
            if (scanf("%d", &prior) == 1)
            {

            if (prior >= 1 && prior <= 3)
            {
                return prior;
            } else{
                printf("\nErro! número invalido.\n\n");

                }
            } else{
                printf("\nErro! input inválido.\n\n");
            }

            limpaBuffer();

        }while(1);

}


int setPeriodo(int prior)
{
    int per;

    do {
        if(prior == 1){
            printf("\nPeriodo de dias para manutenção(entre 1 e 7 dias): ");
            printf("\n==> ");

            if (scanf("%d", &per) == 1) {
                limpaBuffer();

            if (per >= 1 && per <= 7) {
                return per;
            }
        } else {
            limpaBuffer();
        }

        printf("Erro! Input invalido.\n\n");
            }

        if(prior == 2){
            printf("\nPeriodo de dias para manutenção(entre 1 e 15 dias): ");
            printf("\n==> ");

            if (scanf("%d", &per) == 1) {
                limpaBuffer();

            if (per >= 1 && per <= 15) {
                return per;
            }
        } else {
            limpaBuffer();
        }

        printf("Erro! Input invalido.\n\n");
            }
        if(prior == 3){
            printf("\nPeriodo de dias para manutenção(entre 1 e 20 dias): ");
            printf("\n==> ");

            if (scanf("%d", &per) == 1) {
                limpaBuffer();

            if (per >= 1 && per <= 20) {
                return per;
            }
        } else {
            limpaBuffer();
        }

        printf("Erro! Input invalido.\n\n");
            }

    } while (1);
}


int main(){

    setlocale(LC_ALL, "");

    // inputs
    int opcao;
    int codigoSolicitacao;
    int prioridade;
    int periodo;
    int cancelou;

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
        printf("\n(Se deseja sair da função APENAS ao entrar, digite '0')\n");


        printf("\nEscolha uma opção: ");


        opcao = -9999; // valor que caia novamente no default apos primeiro uso de uma funcao


        scanf("%d", &opcao);
        limpaBuffer();



    switch (opcao){

        case 1:
            printf("\n--- INSERIR SOLICITACAO ---\n");

            codigoSolicitacao = setCodSolicitacao(L);
            if(codigoSolicitacao == 0){
                break;
            }
    valido = 0;

                 do {
        printf("\nDigite o código do equipamento (3 letras e 3 números - Ex: OSC023): ");
        printf("\n==> ");
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

                    if (VerificaCodigoEquipamento(L, entrada) == 0)
                    {
                        strcpy(codigoEquipamento, entrada);
                        valido = 1;
                    } else{
                        printf("Código já cadastrado! Utilize outro.\n");

                    }

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

do {
    printf("\nDigite o nome do equipamento: ");
    printf("\n==> ");

    if (fgets(entrada, sizeof(entrada), stdin) != NULL) {

        if (strchr(entrada, '\n') != NULL) {
            entrada[strcspn(entrada, "\n")] = '\0';
        }
        else {
            limpaBuffer();
        }

        if (strlen(entrada) >= 1 && strlen(entrada) <= 20) {
            valido = 1;
            strcpy(nomeEquipamento, entrada);
        }
        else {
            printf("Erro! O numero de caracteres maximo e 20.\n\n");
        }
    }
    else {
        printf("Erro na leitura!\n\n");
    }

} while (!valido);

        prioridade = setPrioridade();

        periodo = setPeriodo(prioridade);



        printf("\n--- SOLICITACAO ---\n");
        printf("\nCódigo de solicitação: %d\n", codigoSolicitacao);
        printf("Equipamento: %s", codigoEquipamento);
        printf("\n");
        printf("Nome: %s", nomeEquipamento);
        printf("\n");
        printf("Prioridade: %i", prioridade);
        printf("\n");
        printf("Periodo: %i", periodo);


        scanf("%d", &cancelou);
        limpaBuffer();
        if(cancelou == 0){
            break;
        }

        InsereSolicitacao(L, codigoSolicitacao, codigoEquipamento, nomeEquipamento, prioridade, periodo);
        printf("\n");
        printf("\n");
        printf("Solicitação inserida com sucesso! ");
        system("pause");

                break;




        case 2:

                printf("\n--- REMOVER SOLICITAÇÃO ---\n");

        if(VerificaLista(L) == 1){
            printf("\nNenhuma solicitação cadastrada.\n\n");

            system("pause");
            break;
        }
        imprimeLista (L);

        valido = 0;
        cancelou = 0;
                do {
            printf("Escolha pelo código da solicitação (4 dígitos entre 1000 e 9999): ");

            // Se o scanf conseguir ler exatamente 1 número inteiro + armazena na variavel
            if (scanf("%d", &codigoSolicitacao) == 1) {
                limpaBuffer(); // Limpa o '\n' (Enter) deixado no teclado para a proxima digitacao

                if(codigoSolicitacao == 0){
                    cancelou = 1;
                break;
            }
                if (codigoSolicitacao >= 1000 && codigoSolicitacao <= 9999) {
                    if(VerificaCodigo(L, codigoSolicitacao)== 1){
                        valido = 1;
                    } else{
                        printf("Solicitação não encontrada!\n");

                    }

                } else {
                    printf("Erro! O código deve estar entre 1000 e 9999.\n");
                }
            } else {
                // Se o usuário digitou letras, o scanf falha e cai AQUI!
                printf("Erro! Digite apenas números (sem letras ou símbolos).\n");
                limpaBuffer(); // OBRIGATÓRIO: Descarta a letra do buffer para não travar o loop
            }

        } while (!valido);

        if (cancelou) {
        break; // Sai do switch-case
    }

                RemoveSolicitacao(L, codigoSolicitacao);
                printf("\nSolicitação removida com sucesso!\n\n");
                system("pause");

                break;

        case 3:


                printf("\n--- CONSULTAR SOLICITAÇÃO ---\n");

        if(VerificaLista(L) == 1){
            printf("\nNenhuma solicitação cadastrada.\n\n");
            system("pause");
            break;
        }

        cancelou = 0;
        valido = 0;
                do {
            printf("\nEscolha pelo código da solicitação (4 dígitos entre 1000 e 9999): ");

            // Se o scanf conseguir ler exatamente 1 número inteiro + armazena na variavel
            if (scanf("%d", &codigoSolicitacao) == 1) {
                limpaBuffer(); // Limpa o '\n' (Enter) deixado no teclado para a proxima digitacao
                if(codigoSolicitacao == 0){
                    cancelou = 1;
                break;
            }
                if (codigoSolicitacao >= 1000 && codigoSolicitacao <= 9999) {
                    if(VerificaCodigo(L, codigoSolicitacao)== 1){
                        valido = 1;
                    } else{
                        printf("Solicitação não encontrada!\n");

                    }

                } else {
                    printf("Erro! O código deve estar entre 1000 e 9999.\n");
                }
            } else {
                // Se o usuário digitou letras, o scanf falha e cai aqui
                printf("Erro! Digite apenas números (sem letras ou símbolos).\n");
                limpaBuffer(); // OBRIGATÓRIO: Descarta a letra do buffer para não travar o loop
            }

        } while (!valido);

                if (cancelou) {
        break; // Sai do switch-case
        }

                imprimeSolicitacao(L,codigoSolicitacao);
                printf("\n\n");
                system("pause");

                break;

        case 4:

                printf("\n--- ALTERAR SOLICITACAO ---\n");
        if(VerificaLista(L) == 1){
            printf("\nNenhuma solicitação cadastrada.\n\n");
            system("pause");
            break;

        }

        imprimeLista (L);

        cancelou = 0;
        valido = 0;

                do {
            printf("Código da solicitação do item que deseja alterar (4 dígitos entre 1000 e 9999): ");

            // Se o scanf conseguir ler exatamente 1 número inteiro + armazena na variavel
            if (scanf("%d", &codigoSolicitacao) == 1) {
                limpaBuffer(); // Limpa o '\n' (Enter) deixado no teclado para a proxima digitacao

                if(codigoSolicitacao == 0){
                    cancelou = 1;
                break;
                }

                if (codigoSolicitacao >= 1000 && codigoSolicitacao <= 9999) {
                    if(VerificaCodigo(L, codigoSolicitacao)== 1){
                        valido = 1;
                    } else{
                        printf("Solicitação não encontrada!\n");

                    }

                } else {
                    printf("Erro! O código deve estar entre 1000 e 9999.\n");
                }
            } else {
                // Se o usuário digitou letras, o scanf falha e cai AQUI!
                printf("Erro! Digite apenas números (sem letras ou símbolos).\n");
                limpaBuffer(); // OBRIGATÓRIO: Descarta a letra do buffer para não travar o loop
            }

        } while (!valido);

            if (cancelou) {
                break; // Sai do switch-case
            }

                prioridade = setPrioridade();

                periodo = setPeriodo(prioridade);


                alteraprioridade(L, codigoSolicitacao, periodo, prioridade);


                break;



        case 5:

                printf("\n--- ORDEM DE REALIZACAO DA MANUTENCAO ---\n");

                OrdenaPrioridade(L);
                printf("\n");
                system("pause");
                break;

        case 6:

                printf("\n--- TODAS AS SOLICITACOES ---\n");

                imprimeLista (L);
                printf("\n");
                system("pause");

                break;

        case 0:

            do {

                printf("\nDeseja Realmente sair do programa? (S || N) \n");
                printf("==> ");
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
                    printf("Programa finalizado.\n");
                    exit(0);
                }

                break;

            default: // caso nenhum dos casos seja digitado
                printf("\nOpção inválida!\n");
                system("pause");

        }
    system("cls");
    } while (1); // codigo funciona ate exit(0)

}

