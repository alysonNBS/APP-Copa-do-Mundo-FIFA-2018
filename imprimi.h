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
    int colocacao=0, jogos=0, pontos=0, vitorias=0, empates=0, derrotas=0, saldo=0, gp=0, gc=0;
    float aprov=100;
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



    //qsort(g, 4, sizeof(struct grupo), classificacao);



    //selecoes
    printf("%c %d  %-46s %c %d %c %d %c %d %c %d %c %d %c %2d %c %2d %c %2d %c %5.1f %c\n",
        179, colocacao, "Brasil", 179, pontos, 179, jogos, 179, vitorias, 179, empates, 179, derrotas, 179,
        saldo, 179, gp, 179, gc, 179, aprov, 179);
    printf("%c %d  %-46s %c %d %c %d %c %d %c %d %c %d %c %2d %c %2d %c %2d %c %5.1f %c\n",
        179, colocacao, "Brasil", 179, pontos, 179, jogos, 179, vitorias, 179, empates, 179, derrotas, 179,
        saldo, 179, gp, 179, gc, 179, aprov, 179);
    printf("%c %d  %-46s %c %d %c %d %c %d %c %d %c %d %c %2d %c %2d %c %2d %c %5.1f %c\n",
        179, colocacao, "Brasil", 179, pontos, 179, jogos, 179, vitorias, 179, empates, 179, derrotas, 179,
        saldo, 179, gp, 179, gc, 179, aprov, 179);
    printf("%c %d  %-46s %c %d %c %d %c %d %c %d %c %d %c %2d %c %2d %c %2d %c %5.1f %c\n",
        179, colocacao, "Brasil", 179, pontos, 179, jogos, 179, vitorias, 179, empates, 179, derrotas, 179,
        saldo, 179, gp, 179, gc, 179, aprov, 179);
    

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



void imprimi_jogo(struct jogo j)
{
    printf("OK\n");
    printf("%s x %s\n", j.pais[0]->nome, j.pais[1]->nome);
}