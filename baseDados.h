#include "dados.h"
#include <stdlib.h>

#define NUM_JOGOS 48+8+4+2+2


//selecoes participantes da copa
struct selecao Selecao[32] = {
{"Rússia"}, {"Arábia Saudita"}, {"Egito"}, {"Uruguai"},
{"Portugal"}, {"Espanha"}, {"Marrocos"}, {"Irã"},
{"França"}, {"Austrália"}, {"Peru"}, {"Dinamarca"},
{"Argentina"}, {"Islândia"}, {"Croácia"}, {"Nigéria"},
{"Brasil"}, {"Suíça"}, {"Costa Rica"}, {"Sérvia"},
{"Alemanha"}, {"México"}, {"Suécia"}, {"Coreia do Sul"},
{"Bélgica"}, {"Panamá"}, {"Tunísia"}, {"Inglaterra"},
{"Polônia"}, {"Senegal"}, {"Colômbia"}, {"Japão"}
};

/*
struct selecao Russia = {"Rússia"};
struct selecao Brasil = {"Brasil"};
struct selecao Ira = {"Irã"};
struct selecao Japao = {"Japão"};
struct selecao Mexico = {"México"};
struct selecao Belgica = {"Bélgica"};
struct selecao Coreia_do_Sul = {"Coreia do Sul"};
struct selecao Arabia_Saudita = {"Arábia Saudita"};
struct selecao Alemanha = {"Alemanha"};
struct selecao Inglaterra = {"Inglaterra"};
struct selecao Espanha = {"Espanha"};
struct selecao Nigeria = {"Nigéria"};
struct selecao Costa_Rica  = {"Costa Rica"};
struct selecao Polonia = {"Polônia"};
struct selecao Egito = {"Egito"};
struct selecao Islandia = {"Islândia"};
struct selecao Servia = {"Sérvia"};
struct selecao Franca = {"França"};
struct selecao Portugal = {"Portugal"};
struct selecao Argentina = {"Argentina"};
struct selecao Colombia = {"Colômbia"};
struct selecao Uruguai = {"Uruguai"};
struct selecao Panama = {"Panamá"};
struct selecao Senegal = {"Senegal"};
struct selecao Marrocos = {"Marrocos"};
struct selecao Tunisia = {"Tunísia"};
struct selecao Suica = {"Suíça"};
struct selecao Croacia = {"Croácia"};
struct selecao Suecia = {"Suécia"};
struct selecao Dinamarca = {"Dinamarca"};
struct selecao Australia = {"Austrália"};
struct selecao Peru = {"Peru"};
*/



//grupos formados para a copa
struct grupo Grupo[8] = { {'A'}, {'B'}, {'C'}, {'D'}, {'E'}, {'F'}, {'G'}, {'H'} };

void SETUP_GRUPOS(void)
{
    int i, j;

    for(i=0; i<8; i++)
        Grupo[i].selecao = malloc( 4*sizeof(struct selecao*));
    
    for(i=0; i<8; i++)
        for(j=0; j<4; j++)
            Grupo[i].selecao[j] = &Selecao[4*i+j];

}



struct jogo Jogo[NUM_JOGOS];

void insere_jogo(const int id, Tselecao *pais1, Tselecao *pais2, char *local, Tdata data, Thora hora, int tipo)
{
    Jogo[id].pais[0] = pais1;
    Jogo[id].pais[1] = pais2;
    Jogo[id].local = local;
    Jogo[id].data = data;
    Jogo[id].hora = hora;
    Jogo[id].tipo = tipo;
    
    Jogo[id].placar[0] = Jogo[id].placar[1] = Jogo[id].prorrogacao[0] =
    Jogo[id].prorrogacao[1] = Jogo[id].penaltes[0] = Jogo[id].penaltes[1] = 0;


    pais2->jogo[(pais2->num_jogos)++] = pais1->jogo[(pais1->num_jogos)++] = &Jogo[id];
}

void SETUP_JOGOS_FASE_GRUPO(void)
{
    insere_jogo(0, &Selecao[Russia], &Selecao[Egito], "SÃO PETERSBURGO", (Tdata) {2018, 06, 19}, (Thora) {15, 00} , faseDeGrupo);

}