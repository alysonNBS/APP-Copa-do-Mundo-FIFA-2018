#include <stdio.h>
#include <stdlib.h>

#include "enumerador.h"
#include "baseDados.h"
#include "imprimi.h"


void menu_principal(void);
void menu_insercao(void);
void menu_exibicao(void);

int main()
{
    SETUP_GRUPOS();
    
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
        printf("0 - Sair do Aplicativo\n");
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
        
        printf("0 - Retronar ao Menu Principal\n");
        printf("\n\n");
        printf("Escolha uma op%c%co: ", 135, 198);


        leituraDeOpcao:
        scanf("%d", &opcao);

        
        switch (opcao)
        {

            case 0:
                break;

            default:
                printf("\nOp%c%co inv%clida! Tente novamente: ", 135, 198, 160);
                goto leituraDeOpcao;
                break;
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
        printf("0 - Retronar ao Menu Principal\n");
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

            case 0:
                break;

            default:
                printf("\nOp%c%co inv%clida! Tente novamente: ", 135, 198, 160);
                goto leituraDeOpcao;
                break;
            }
    } while(opcao != 0);
    
    printf("\nRetornando ao menu principal!\n");
}