#include <stdio.h>


//PARA DEPOIS: ADICIONAR VALIDAÇÃO PARA VERIFICAR SE O JOGO JÁ TEM RESULTADO
void cadastrar_resultado(struct jogo *jogos, char *pais1, char *pais2, int gols1, int gols2, char fase){
    int i, teste=0;
    for(i=0;i<64;i++){
        if (fase==jogos[i].tipo){ 
            if(string_comp(pais1,jogos[i].pais[0]->nome)==0 && string_comp(pais2,jogos[i].pais[1]->nome)==0){
                jogos[i].placar[0] = gols1;
                jogos[i].placar[1] = gols2;
                teste=1;
            }
            if(string_comp(pais2,jogos[i].pais[0]->nome)==0 && string_comp(pais1,jogos[i].pais[1]->nome)==0){
                jogos[i].placar[0] = gols2;
                jogos[i].placar[1] = gols1;
                teste=1;
            }
        }
    }
    if (teste==0)
        printf("Jogo n%co encontrado.\n",198);
    else
        printf("Resultado inserido com sucesso!\n");
    system("PAUSE");
}


void ler_resultado(char *t1, char *t2, int *p1, int *p2){             
        printf("Insira o nome do primeiro time: \n");
        scanf("%s", t1);
        printf("Insira a quantidade de gols do primeiro time: \n");
        scanf("%d",p1);
        printf("Insira o nome do segundo time: \n");
        scanf("%s",t2);
        printf("Insira a quantidade de gols do segundo time: \n");
        scanf("%d",p2);
}