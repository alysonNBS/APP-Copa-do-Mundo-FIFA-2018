#include <stdio.h>


void print_grupos(struct grupo *grupos);
void print_oitavas(struct oitava *oitavas);
void print_quartas(struct quarta *quartas);
void print_semi_finais(struct semi_final *semis);
void print_final(struct final *final);
void print_terc_lugar(struct terceiro_lugar *terc_lugar);
void print_grupo(struct grupo g);
void print_jogo(struct jogo j);
void logo_app(void);
void print_data(struct data d);
void print_horario(struct hora h);
void time_oitava(int jogo, int time, char *nome);
void time_quarta(int jogo, int time, char *nome);
void time_semi(int jogo, int time, char *nome);
void time_final(int time, char *nome);
void time_terceiro_lugar(int time, char *nome);



void logo_app(void) {
        printf("************************************\n");
        printf("*                                  *\n");
        printf("*     Copa do Mundo FIFA 2018      *\n");
        printf("*                                  *\n");
        printf("************************************\n");
        printf("\n");
}



void print_grupos(struct grupo *grupos) {
    int i;
    for(i=A; i<=H; i++)
    {
        print_grupo(grupos[i]);
        printf("\n");
    }
}



void print_grupo(struct grupo g) {
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



void print_jogo(struct jogo j) {
    char pais1[50], pais2[50]; // variaveis auxiliares para impressao

    print_data(j.data);
    printf(" %s ", j.local);
    print_horario(j.hora);
    

    if(j.placar[0] == -1) {
        switch(j.tipo) {
            case faseDeGrupo:
                printf("\n\t %s     X     %s\n", j.pais[0]->sigla, j.pais[1]->sigla);
                break;

            case oitava:
                (j.pais[0]->nome != NULL) ? strcpy(pais1, j.pais[0]->nome)
                : time_oitava(j.id-48, 0, pais1);
                (j.pais[1]->nome != NULL) ? strcpy(pais2, j.pais[1]->nome)
                : time_oitava(j.id-48, 1, pais2);


                printf("\n\t %s     X     %s\n", pais1, pais2);
                break;

            case quarta:
                (j.pais[0]->nome != NULL) ? strcpy(pais1, j.pais[0]->nome)
                : time_quarta(j.id-56, 0, pais1);
                (j.pais[1]->nome != NULL) ? strcpy(pais2, j.pais[1]->nome)
                : time_quarta(j.id-56, 1, pais2);


                printf("\n%s     X     %s\n", pais1, pais2);
                break;

            case semi_final:
                (j.pais[0]->nome != NULL) ? strcpy(pais1, j.pais[0]->nome)
                : time_semi(j.id-60, 0, pais1);
                (j.pais[1]->nome != NULL) ? strcpy(pais2, j.pais[1]->nome)
                : time_semi(j.id-60, 1, pais2);


                printf("\n%s     X     %s\n", pais1, pais2);
                break;

            case final:
                (j.pais[0]->nome != NULL) ? strcpy(pais1, j.pais[0]->nome)
                : time_final(0, pais1);
                (j.pais[1]->nome != NULL) ? strcpy(pais2, j.pais[1]->nome)
                : time_final(1, pais2);


                printf("\n%s     X     %s\n", pais1, pais2);
                break;

            case terc_lugar:
                (j.pais[0]->nome != NULL) ? strcpy(pais1, j.pais[0]->nome)
                : time_terceiro_lugar(0, pais1);
                (j.pais[1]->nome != NULL) ? strcpy(pais2, j.pais[1]->nome)
                : time_terceiro_lugar(1, pais2);


                printf("\n%s     X     %s\n", pais1, pais2);
                break;
        }
    } else
    {
        printf("\n\t %s  %-3d X %3d  %s\n", j.pais[0]->sigla, j.placar[0], j.placar[1], j.pais[1]->sigla);
    }
}



void print_data(struct data d) {
    printf("%02d/%02d/%02d", d.dia, d.mes, d.ano);
}



void print_horario(struct hora h) {
    printf("%02d:%02d", h.hora, h.min);
}



void time_oitava(int jogo, int time, char *nome) {
    nome[0] = time + '1';
    nome[1] = -8;
    nome[2] = ' ';
    nome[3] = (jogo/4 == 0) ? 2*jogo + time + 'A' : 2*(jogo % 4) - time +'B';
    nome[4] = 0;
}



void time_quarta(int jogo, int time, char *nome) {
    strcpy(nome, "Venc. Oita. ");
    nome[12] = 2*jogo + time + '1';
    nome[13] = 0;
}



void time_semi(int jogo, int time, char *nome) {
    strcpy(nome, "Venc. Quar. ");
    nome[12] = time + '1';
    nome[13] = 0;
}



void time_final(int time, char *nome) {
    strcpy(nome, "Venc. Semi. ");
    nome[12] = time + '1';
    nome[13] = 0;
}



void time_terceiro_lugar(int time, char *nome) {
    strcpy(nome, "Perd. Semi. ");
    nome[12] = time + '1';
    nome[13] = 0;
}



void print_oitavas(struct oitava *oitavas)
{
    int i;
    
    for(i=0; i<8; i++)
    {
        printf("\n\t      Oitavas %d\n", i+1);
        print_jogo(*oitavas->jogo[i]);
        printf("\n");
    }
}



void print_quartas(struct quarta *quartas)
{
    int i;
    
    for(i=0; i<4; i++)
    {
        printf("\n\t      Quartas %d\n", i+1);
        print_jogo(*quartas->jogo[i]);
        printf("\n");
    }
}



void print_semi_finais(struct semi_final *semis)
{
    int i;
    
    for(i=0; i<2; i++)
    {
        printf("\n\t     Semifinal %d\n", i+1);
        print_jogo(*semis->jogo[i]);
        printf("\n");
    }
}



void print_final(struct final *final)
{
        printf("\n\t\tFinal\n");
        print_jogo(*final->jogo);
        printf("\n");
}



void print_terc_lugar(struct terceiro_lugar *terc_lugar)
{
    
        printf("\n\t    Terceiro Lugar\n");
        print_jogo(*terc_lugar->jogo);
        printf("\n");
}