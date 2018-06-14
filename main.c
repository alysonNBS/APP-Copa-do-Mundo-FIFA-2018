#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "enumerador.h"
#include "funcoes.h"
#include "funcoesJogos.h"
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
    // SETUP_JOGOS();

    CARREGAR_JOGOS();
    /*
    Jogo[48].pais[0] = &Selecao[Russia];
    Jogo[48].pais[1] = &Selecao[Marrocos];
    Jogo[49].pais[0] = &Selecao[Franca];
    Jogo[49].pais[1] = &Selecao[Argentina];
    Jogo[50].pais[0] = &Selecao[Brasil];
    Jogo[50].pais[1] = &Selecao[Alemanha];
    Jogo[51].pais[0] = &Selecao[Belgica];
    Jogo[51].pais[1] = &Selecao[Colombia];
    Jogo[52].pais[0] = &Selecao[Portugal];
    Jogo[52].pais[1] = &Selecao[Arabia_Saudita];
    Jogo[53].pais[0] = &Selecao[Islandia];
    Jogo[53].pais[1] = &Selecao[Peru];
    Jogo[54].pais[0] = &Selecao[Suecia];
    Jogo[54].pais[1] = &Selecao[Servia];
    Jogo[55].pais[0] = &Selecao[Senegal];
    Jogo[55].pais[1] = &Selecao[Inglaterra];
    */
   /*
   int i;
   for(i=0; i<47; i++)
   {
       Jogo[i].placar[0] = 1;
       Jogo[i].placar[1] = 0;
   }*/

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
    int retorno_cad_res;

    do
    {
        system("cls");
        logo_app();
        printf("\tSELECIONE A FASE\n\n", 128, 199);
        
        printf("1 - Fase de grupo\n");
        printf("2 - Oitavas\n");
        printf("3 - Quartas\n");
        printf("4 - Semi-finais\n");
        printf("5 - Terceiro Lugar\n");
        printf("6 - Final\n");
        printf("0 - Retornar ao Menu de Inser%c%co\n", 135, 198);
        printf("\n\n");
        printf("Escolha uma op%c%co: ", 135, 198);


        leituraDeOpcao:
        scanf("%d", &opcao);
        
        switch (opcao)
        {
            case 1:
            case 2:
            case 3:           
            case 4:
            case 5:
            case 6:
                retorno_cad_res = cadastrar_resultado(Jogo, opcao-1);
                if (retorno_cad_res == -1)
                {
                    printf("O jogo n%co existe. Tente novamente.\n", 198);
                    //print_jogo(Jogo[(retorno_cad_res % 48) / 2 + 56]);
                }
                else
                {
                    printf("Resultado cadastrado com sucesso!\n");
                    processa_fase(Jogo, retorno_cad_res, Grupo);
                    SALVAR_JOGOS();
                }
                system("PAUSE");
                break;

            case 0:
                break;

            default:
                printf("\nOp%c%co inv%clida! Tente novamente: ", 135, 198, 160);
                goto leituraDeOpcao;
            }
    } while(opcao != 0);
    
    printf("\nRetornando ao Menu de Inser%c%co!\n", 135, 198);
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