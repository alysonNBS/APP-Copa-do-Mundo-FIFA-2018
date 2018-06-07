#include <stdio.h>


void print_grupo(struct grupo g);
void print_grupos(struct grupo *grupos);
void logo_app(void);

void logo_app(void)
{
        printf("************************************\n");
        printf("*                                  *\n");
        printf("*     Copa do Mundo FIFA 2018      *\n");
        printf("*                                  *\n");
        printf("************************************\n");
        printf("\n");
}



void print_grupos(struct grupo *grupos)
{
    int i;
    for(i=A; i<=H; i++)
    {
        print_grupo(grupos[i]);
        printf("\n");
    }
}



void print_grupo(struct grupo g)
{
    int i;

    printf("GRUPO %c\n", g.g);

    // linha superior
    printf("%c", 218);
    for(i=0; i<51; i++)
        printf("%c",196);
    printf("%c", 194);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 194);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 194);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 194);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 194);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 194);
    for(i=0; i<4; i++)
        printf("%c",196);
    printf("%c", 194);
    for(i=0; i<4; i++)
        printf("%c",196);
    printf("%c", 194);
    for(i=0; i<4; i++)
        printf("%c",196);
    printf("%c", 194);
    for(i=0; i<7; i++)
        printf("%c",196);
    printf("%c", 191);
    printf("\n");
    

    //segunda linha
    printf("%c Classifica%c%co", 179, 135, 198);
    for(i=0; i<51-14; i++)
        printf(" ");
    printf("%c P %c J %c V %c E %c D %c SG %c GP %c GC %c   %%   %c", 179, 179, 179, 179, 179, 179, 179, 179, 179, 179);
    printf("\n");


    //possivel linha intermediaria
    printf("%c", 195);
    for(i=0; i<51; i++)
        printf("%c",196);
    printf("%c", 197);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 197);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 197);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 197);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 197);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 197);
    for(i=0; i<4; i++)
        printf("%c",196);
    printf("%c", 197);
    for(i=0; i<4; i++)
        printf("%c",196);
    printf("%c", 197);
    for(i=0; i<4; i++)
        printf("%c",196);
    printf("%c", 197);
    for(i=0; i<7; i++)
        printf("%c",196);
    printf("%c", 180);
    printf("\n");



    
    //selecoes
    int colocacao=1, aux_colocacao=1;

    //qsort(g.selecao, 4, sizeof(struct grupo), classificacao);


    printf("%c %d  %-46s %c %d %c %d %c %d %c %d %c %d %c %2d %c %2d %c %2d %c %5.1f %c\n",
        179, colocacao, g.selecao[0]->nome, 179, pontos(*g.selecao[0]), 179, jogos(*g.selecao[0]), 179,
        vitorias(*g.selecao[0]), 179, empates(*g.selecao[0]), 179, derrotas(*g.selecao[0]), 179,
        saldo(*g.selecao[0]), 179, gp(*g.selecao[0]), 179, gc(*g.selecao[0]), 179, 
        ( jogos(*g.selecao[0]) ) ? 100.0 * pontos(*g.selecao[0])/(3*jogos(*g.selecao[0])) : 0.0, 179);
    
    for(i=1; i<4; i++)
    {
        //if( classificacao(g.selecao+i-1, g.selecao+i) != 0)
        {
            colocacao += aux_colocacao;
            aux_colocacao = 0;
        }


        printf("%c %d  %-46s %c %d %c %d %c %d %c %d %c %d %c %2d %c %2d %c %2d %c %5.1f %c\n",
            179, colocacao, g.selecao[i]->nome, 179, pontos(*g.selecao[i]), 179, jogos(*g.selecao[i]), 179,
            vitorias(*g.selecao[i]), 179, empates(*g.selecao[i]), 179, derrotas(*g.selecao[i]), 179,
            saldo(*g.selecao[i]), 179, gp(*g.selecao[i]), 179, gc(*g.selecao[i]), 179, 
            ( jogos(*g.selecao[i]) ) ? 100.0 * pontos(*g.selecao[i])/(3*jogos(*g.selecao[i])) : 0.0, 179);


        aux_colocacao++;
    }

    
    //qsort(g.selecao, 4, sizeof(struct grupo), padrao);
    


    //linha inferior
    printf("%c", 192);
    for(i=0; i<51; i++)
        printf("%c",196);
    printf("%c", 193);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 193);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 193);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 193);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 193);
    for(i=0; i<3; i++)
        printf("%c",196);
    printf("%c", 193);
    for(i=0; i<4; i++)
        printf("%c",196);
    printf("%c", 193);
    for(i=0; i<4; i++)
        printf("%c",196);
    printf("%c", 193);
    for(i=0; i<4; i++)
        printf("%c",196);
    printf("%c", 193);
    for(i=0; i<7; i++)
        printf("%c",196);
    printf("%c", 217);
    printf("\n");
}

void print_jogo(struct jogo j)
{
    printf("OK\n");
    printf("%s x %s\n", j.pais[0]->nome, j.pais[1]->nome);
}