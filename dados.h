typedef struct data
{
    int ano, mes, dia;
} Tdata;

typedef struct hora
{
    int hora, min;
} Thora;

typedef struct jogo
{
    struct selecao *pais[2];

    int placar[2];
    int prorrogacao[2];
    int penaltes[2];
    char *local;
    struct data data;
    struct hora hora;
    char tipo;
} Tjogo;

typedef struct jogador
{
    unsigned char nome[100];
    int num;
    int posicao;
} Tjogador;

typedef struct selecao
{
    unsigned char nome[50];
    int num_jogos;
    struct jogo **jogo;
    struct jogador jogador[23];
    char g;
} Tselecao;

typedef struct grupo
{
    char g;
    struct selecao *selecao[4];
} Tgrupo;

typedef struct oitava
{
    struct jogo *jogo[8];
} Toitava;

typedef struct quarta
{
    struct jogo *jogo[4];
} Tquarta;

typedef struct semi_final
{
    struct jogo *jogo[2];
} Tsemi_final;

typedef struct final
{
    struct jogo *jogo;
} Tfinal;

typedef struct terceiro_lugar
{
    struct jogo *jogo;
} Tterceiro_lugar;