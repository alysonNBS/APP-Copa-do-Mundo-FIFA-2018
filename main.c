#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "funcoes.h"
#include "funcoesJogos.h"
#include "enumerador.h"
#include "baseDados.h"
#include "funcoesFaseGrupo.h"
#include "imprimi.h"
#include "funcoesDeInsercao.h"

void menu_principal(void);
void menu_insercao(void);
void menu_insercao_fase(void);
void menu_exibicao(void);



int main()
{
    // SETUP_SELECOES();
    // SETUP_GRUPOS();
    // SETUP_JOGOS_FASE_GRUPO();

    CARREGAR_JOGOS();
    
    menu_principal();

    return 0;
}



void menu_principal(void)
{
    int opcao;

    do
    {
        system("cls");

        logo_app();
        printf("\t MENU PRINCIPAL \n\n");
        printf("1 - Acessar painel de inser%c%co\n", 135, 198);
        printf("2 - Acessar painel de exibi%c%co\n", 135, 198);
        printf("0 - Sair e Salvar\n");
        printf("\n\n");
        printf("Escolha uma op%c%co: ", 135, 198);

        leituraDeOpcao:
        scanf("%d", &opcao);

        
        switch (opcao)
        {
            case 1:
                menu_insercao();
                break;

            case 2:
                menu_exibicao();
                break;

            case 0:
                SALVAR_JOGOS();
                break;

            default:
                printf("\nOp%c%co inv%clida! Tente novamente: ", 135, 198, 160);
                goto leituraDeOpcao;
                break;
            }
    } while(opcao != 0);


    printf("\nObrigado por usar nosso aplicativo!\n");
}



void menu_insercao(void)
{
    int opcao;

    do
    {
        system("cls");

        logo_app();
        printf("\t MENU DE INSER%c%cO \n\n", 128, 199);
        
        printf("1 - Inserir resultado de jogo\n");
        printf("0 - Retornar ao Menu Principal\n");
        printf("\n\n");
        printf("Escolha uma op%c%co: ", 135, 198);




        leituraDeOpcao:
        scanf("%d", &opcao);

        
        switch (opcao)
        {
            case 1:
                menu_insercao_fase();
                break;


            case 0:
                break;

            default:
                printf("\nOp%c%co inv%clida! Tente novamente: ", 135, 198, 160);
                goto leituraDeOpcao;
            }
    } while(opcao != 0);
    
    printf("\nRetornando ao Menu Principal!\n");
}

void menu_insercao_fase(void)
{
    int opcao;

    do
    {
        system("cls");
        char t1[50], t2[50];
        int p1, p2;
        logo_app();
        printf("\tSELECIONE A FASE\n\n", 128, 199);
        
        printf("1 - Fase de grupo\n");
        printf("2 - Oitavas\n");
        printf("3 - Quartas\n");
        printf("4 - Semi-finais\n");
        printf("5 - Terceiro Lugar\n");
        printf("6 - Final\n");
        printf("0 - Retornar ao Menu Principal\n");
        printf("\n\n");
        printf("Escolha uma op%c%co: ", 135, 198);


        leituraDeOpcao:
        scanf("%d", &opcao);

        
        switch (opcao)
        {
            case 1:
                ler_resultado(t1,t2,&p1,&p2);
                cadastrar_resultado(Jogo,t1,t2,p1,p2,0);
                break;
            case 2:
                ler_resultado(t1,t2,&p1,&p2);
                cadastrar_resultado(Jogo,t1,t2,p1,p2,1);
                break;
            case 3:
                ler_resultado(t1,t2,&p1,&p2);
                cadastrar_resultado(Jogo,t1,t2,p1,p2,2);
                break;            
            case 4:
                ler_resultado(t1,t2,&p1,&p2);
                cadastrar_resultado(Jogo,t1,t2,p1,p2,3);
                break;
            case 5:
                ler_resultado(t1,t2,&p1,&p2);
                cadastrar_resultado(Jogo,t1,t2,p1,p2,4);
                break;
            case 6:
                ler_resultado(t1,t2,&p1,&p2);
                cadastrar_resultado(Jogo,t1,t2,p1,p2,5);
                break;

            case 0:
                break;

            default:
                printf("\nOp%c%co inv%clida! Tente novamente: ", 135, 198, 160);
                goto leituraDeOpcao;
            }
    } while(opcao != 0);
    
    printf("\nRetornando ao Menu Principal!\n");
}




void menu_exibicao(void)
{
    int opcao;

    do
    {
        system("cls");

        logo_app();
        printf("\t MENU DE EXIB%c%cO \n\n", 128, 199);
        printf("1 - Exibir Grupos\n");
        printf("2 - Exibir Oitavas\n");
        printf("3 - Exibir Quartas\n");
        printf("4 - Exibir Semi-Final\n");
        printf("5 - Exibir Final\n");
        printf("6 - Exibir Disputa de Terceiro Lugar\n");
        printf("0 - Retornar ao Menu Principal\n");
        printf("\n\n");
        printf("Escolha uma op%c%co: ", 135, 198);

        
        leituraDeOpcao:
        scanf("%d", &opcao);

        
        switch (opcao)
        {
            case 1:
                system("cls");
                print_grupos(Grupo);
                system("pause");
                break;
            
            case 2:
                system("cls");
                print_oitavas(&Oitavas);
                system("pause");
                break;

            case 3:
                system("cls");
                print_quartas(&Quartas);
                system("pause");
                break;

            case 4:
                system("cls");
                print_semi_finais(&Semi_final);
                system("pause");
                break;

            case 5:
                system("cls");
                print_final(&Final);
                system("pause");
                break;

            case 6:
                system("cls");
                print_terc_lugar(&Terc_lugar);
                system("pause");
                break;

            case 0:
                break;

            default:
                printf("\nOp%c%co inv%clida! Tente novamente: ", 135, 198, 160);
                goto leituraDeOpcao;
            }
    } while(opcao != 0);
    
    printf("\nRetornando ao menu principal!\n");
}