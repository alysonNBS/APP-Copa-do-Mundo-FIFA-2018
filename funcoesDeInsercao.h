#include <stdio.h>

int cadastrar_resultado(struct jogo *jogos, char fase);
int valida_jogo(struct jogo *jogos, char *pais1, char *pais2, char fase);

int cadastrar_resultado(struct jogo *jogos, char fase)
{
    int ind_jogo, gol1, gol2, pen1, pen2;
    char pais1[50],pais2[50];

    printf("Insira o nome do primeiro time: \n");
    scanf("%*c%[^\n]", pais1);

    printf("Insira o nome do segundo time: \n");
    scanf("%*c%[^\n]", pais2);


    ind_jogo = valida_jogo(jogos, pais1, pais2, fase);

    if (ind_jogo == -1)
        return -1;

    
    printf("Insira a quantidade de gols do(a) %s: \n", pais1);
    scanf("%d", &gol1);

    printf("Insira a quantidade de gols do(a) %s: \n", pais2);
    scanf("%d", &gol2);

    if (string_comp(pais1, jogos[ind_jogo].pais[0]->nome) == 0 && string_comp(pais2, jogos[ind_jogo].pais[1]->nome) == 0)
    {
        jogos[ind_jogo].placar[0] = gol1;
        jogos[ind_jogo].placar[1] = gol2;
    }
    if (string_comp(pais2, jogos[ind_jogo].pais[0]->nome) == 0 && string_comp(pais1, jogos[ind_jogo].pais[1]->nome) == 0)
    {
        jogos[ind_jogo].placar[0] = gol2;
        jogos[ind_jogo].placar[1] = gol1;
    }
    if (gol1==gol2&&fase!=0){
        printf("Insira a quantidade de gols de penalti do(a) %s: \n", pais1);
        scanf("%d", &pen1);

        printf("Insira a quantidade de gols penalti do(a) %s: \n", pais2);
        scanf("%d", &pen2);
        
        if (string_comp(pais1, jogos[ind_jogo].pais[0]->nome) == 0 && string_comp(pais2, jogos[ind_jogo].pais[1]->nome) == 0)
        {
            jogos[ind_jogo].penaltes[0] = pen1;
            jogos[ind_jogo].penaltes[1] = pen2;
        }
        if (string_comp(pais2, jogos[ind_jogo].pais[0]->nome) == 0 && string_comp(pais1, jogos[ind_jogo].pais[1]->nome) == 0)
        {
            jogos[ind_jogo].penaltes[0] = pen2;
            jogos[ind_jogo].penaltes[1] = pen1;
        }
    }
    return ind_jogo;
}

//VERIFICA SE O JOGO EXISTE
int valida_jogo(struct jogo *jogos, char *pais1, char *pais2, char fase)
{
    int i;
    for (i = 0; i < 64; i++)
    {
        if (fase == jogos[i].tipo)
        {
            if (string_comp(pais1, jogos[i].pais[0]->nome) == 0 && string_comp(pais2, jogos[i].pais[1]->nome) == 0 ||
                string_comp(pais2, jogos[i].pais[0]->nome) == 0 && string_comp(pais1, jogos[i].pais[1]->nome) == 0)
                return i;
        }
    }
    return -1;
}