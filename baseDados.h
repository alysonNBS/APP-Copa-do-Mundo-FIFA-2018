#define NUM_JOGOS 48+8+4+2+2

//selecoes participantes da copa
struct selecao Selecao[32] = {
{"Arabia Saudita", "ARA"}, {"Egito", "EGI"}, {"Russia", "RUS"}, {"Uruguai", "URU"},
{"Espanha", "ESP"}, {"Ira", "IRA"}, {"Marrocos", "MAR"}, {"Portugal", "POR"},
{"Australia", "AUS"},  {"Dinamarca", "DIN"}, {"Franca", "FRA"}, {"Peru", "PER"},
{"Argentina", "ARG"}, {"Croacia", "CRO"}, {"Islandia", "ISL"}, {"Nigeria", "NIG"},
{"Brasil", "BRA"}, {"Costa Rica", "COS"}, {"Servia", "SER"}, {"Suica", "SUI"},
{"Alemanha", "ALE"}, {"Coreia do Sul", "COR"}, {"Mexico", "MEX"}, {"Suecia", "SUE"}, 
{"Belgica", "BEL"}, {"Inglaterra", "ING"}, {"Panama", "PAN"}, {"Tunisia", "TUN"},
{"Colombia", "COL"}, {"Japao", "JAP"}, {"Polonia", "POL"}, {"Senegal", "SEN"}
};
//todos os jogos da copa
struct jogo Jogo[NUM_JOGOS];
//grupos formados para a copa
struct grupo Grupo[8] = { {'A'}, {'B'}, {'C'}, {'D'}, {'E'}, {'F'}, {'G'}, {'H'} };
//jogos apenas das oitavas
struct oitava Oitavas;



void corrige_acentos_nomes(void)
{
    int a_tio = 198, a_agudo = 160, a_circuflexo = 131, e_agudo = 130, i_agudo = 214, o_circuflexo = 147, u_agudo = 163, c_cedilha = 135;

    Selecao[Panama].nome[5] = Selecao[Croacia].nome[3] = Selecao[Australia].nome[5] = Selecao[Arabia_Saudita].nome[2] = a_agudo;
    Selecao[Russia].nome[1] = u_agudo;
    Selecao[Japao].nome[3] = Selecao[Ira].nome[2] = a_tio;
    Selecao[Suica].nome[3] = Selecao[Franca].nome[4] = c_cedilha;
    Selecao[Islandia].nome[3] = a_circuflexo;
    Selecao[Belgica].nome[1] = Selecao[Suecia].nome[2] = Selecao[Mexico].nome[1] = Selecao[Servia].nome[1] = Selecao[Nigeria].nome[3] = e_agudo;
    Selecao[Tunisia].nome[3] = Selecao[Suica].nome[2] = i_agudo;
    Selecao[Polonia].nome[2] = Selecao[Colombia].nome[3] = o_circuflexo;
}



void SETUP_GRUPOS(void)
{
    int i, j;
    
    for(i=0; i<8; i++)
        for(j=0; j<4; j++)
            Grupo[i].selecao[j] = &Selecao[4*i+j];

}



void SETUP_SELECOES(void)
{
    int i;
    for(i=0; i<32; i++)
    {
        Selecao[i].num_jogos = 0;
        Selecao[i].jogo = malloc(3*sizeof(struct jogo *));
    }

    corrige_acentos_nomes();
}



void insere_jogo(const int id, Tselecao *pais1, Tselecao *pais2, char *local, Tdata data, Thora hora, int tipo)
{
    Jogo[id].pais[0] = pais1;
    Jogo[id].pais[1] = pais2;
    Jogo[id].local = local;
    Jogo[id].data = data;
    Jogo[id].hora = hora;
    Jogo[id].tipo = tipo;
    
    Jogo[id].placar[0] = Jogo[id].placar[1] = Jogo[id].prorrogacao[0] =
    Jogo[id].prorrogacao[1] = Jogo[id].penaltes[0] = Jogo[id].penaltes[1] = -1;


    if(pais1 != NULL && pais2 != NULL)
        pais2->jogo[(pais2->num_jogos)++] = pais1->jogo[(pais1->num_jogos)++] = &Jogo[id];
}



void SETUP_JOGOS_FASE_GRUPO(void)
{
    //Grupo A
    insere_jogo(0, &Selecao[Russia], &Selecao[Arabia_Saudita], "OLÍMPICO LUJNIKI", (Tdata) {2018, 06, 14}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(1, &Selecao[Egito], &Selecao[Uruguai], "ECATERIMBURGO", (Tdata) {2018, 06, 15}, (Thora) {9, 00} , faseDeGrupo);
    insere_jogo(2, &Selecao[Russia], &Selecao[Egito], "SÃO PETERSBURGO", (Tdata) {2018, 06, 19}, (Thora) {15, 00} , faseDeGrupo);
    insere_jogo(3, &Selecao[Uruguai], &Selecao[Arabia_Saudita], "ROSTOV", (Tdata) {2018, 06, 20}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(4, &Selecao[Uruguai], &Selecao[Russia], "SAMARA", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);
    insere_jogo(5, &Selecao[Arabia_Saudita], &Selecao[Egito], "VOLGOGRADO", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);
    /*
    //Grupo B
    insere_jogo(6, &Selecao[Marrocos], &Selecao[Ira], "OLÍMPICO LUJNIKI", (Tdata) {2018, 06, 14}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(7, &Selecao[Egito], &Selecao[Uruguai], "ECATERIMBURGO", (Tdata) {2018, 06, 15}, (Thora) {9, 00} , faseDeGrupo);
    insere_jogo(8, &Selecao[Russia], &Selecao[Egito], "SÃO PETERSBURGO", (Tdata) {2018, 06, 19}, (Thora) {15, 00} , faseDeGrupo);
    insere_jogo(9, &Selecao[Uruguai], &Selecao[Arabia_Saudita], "ROSTOV", (Tdata) {2018, 06, 20}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(10, &Selecao[Uruguai], &Selecao[Russia], "SAMARA", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);
    insere_jogo(11, &Selecao[Arabia_Saudita], &Selecao[Egito], "VOLGOGRADO", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);

    //Grupo C
    insere_jogo(12, &Selecao[Russia], &Selecao[Arabia_Saudita], "OLÍMPICO LUJNIKI", (Tdata) {2018, 06, 14}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(13, &Selecao[Egito], &Selecao[Uruguai], "ECATERIMBURGO", (Tdata) {2018, 06, 15}, (Thora) {9, 00} , faseDeGrupo);
    insere_jogo(14, &Selecao[Russia], &Selecao[Egito], "SÃO PETERSBURGO", (Tdata) {2018, 06, 19}, (Thora) {15, 00} , faseDeGrupo);
    insere_jogo(15, &Selecao[Uruguai], &Selecao[Arabia_Saudita], "ROSTOV", (Tdata) {2018, 06, 20}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(16, &Selecao[Uruguai], &Selecao[Russia], "SAMARA", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);
    insere_jogo(17, &Selecao[Arabia_Saudita], &Selecao[Egito], "VOLGOGRADO", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);

    //Grupo D
    insere_jogo(18, &Selecao[Russia], &Selecao[Arabia_Saudita], "OLÍMPICO LUJNIKI", (Tdata) {2018, 06, 14}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(19, &Selecao[Egito], &Selecao[Uruguai], "ECATERIMBURGO", (Tdata) {2018, 06, 15}, (Thora) {9, 00} , faseDeGrupo);
    insere_jogo(20, &Selecao[Russia], &Selecao[Egito], "SÃO PETERSBURGO", (Tdata) {2018, 06, 19}, (Thora) {15, 00} , faseDeGrupo);
    insere_jogo(21, &Selecao[Uruguai], &Selecao[Arabia_Saudita], "ROSTOV", (Tdata) {2018, 06, 20}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(22, &Selecao[Uruguai], &Selecao[Russia], "SAMARA", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);
    insere_jogo(23, &Selecao[Arabia_Saudita], &Selecao[Egito], "VOLGOGRADO", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);

    //Grupo E
    insere_jogo(24, &Selecao[Russia], &Selecao[Arabia_Saudita], "OLÍMPICO LUJNIKI", (Tdata) {2018, 06, 14}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(25, &Selecao[Egito], &Selecao[Uruguai], "ECATERIMBURGO", (Tdata) {2018, 06, 15}, (Thora) {9, 00} , faseDeGrupo);
    insere_jogo(26, &Selecao[Russia], &Selecao[Egito], "SÃO PETERSBURGO", (Tdata) {2018, 06, 19}, (Thora) {15, 00} , faseDeGrupo);
    insere_jogo(27, &Selecao[Uruguai], &Selecao[Arabia_Saudita], "ROSTOV", (Tdata) {2018, 06, 20}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(28, &Selecao[Uruguai], &Selecao[Russia], "SAMARA", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);
    insere_jogo(29, &Selecao[Arabia_Saudita], &Selecao[Egito], "VOLGOGRADO", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);

    //Grupo F
    insere_jogo(30, &Selecao[Russia], &Selecao[Arabia_Saudita], "OLÍMPICO LUJNIKI", (Tdata) {2018, 06, 14}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(31, &Selecao[Egito], &Selecao[Uruguai], "ECATERIMBURGO", (Tdata) {2018, 06, 15}, (Thora) {9, 00} , faseDeGrupo);
    insere_jogo(32, &Selecao[Russia], &Selecao[Egito], "SÃO PETERSBURGO", (Tdata) {2018, 06, 19}, (Thora) {15, 00} , faseDeGrupo);
    insere_jogo(33, &Selecao[Uruguai], &Selecao[Arabia_Saudita], "ROSTOV", (Tdata) {2018, 06, 20}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(34, &Selecao[Uruguai], &Selecao[Russia], "SAMARA", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);
    insere_jogo(35, &Selecao[Arabia_Saudita], &Selecao[Egito], "VOLGOGRADO", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);

    //Grupo G
    insere_jogo(36, &Selecao[Russia], &Selecao[Arabia_Saudita], "OLÍMPICO LUJNIKI", (Tdata) {2018, 06, 14}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(37, &Selecao[Egito], &Selecao[Uruguai], "ECATERIMBURGO", (Tdata) {2018, 06, 15}, (Thora) {9, 00} , faseDeGrupo);
    insere_jogo(38, &Selecao[Russia], &Selecao[Egito], "SÃO PETERSBURGO", (Tdata) {2018, 06, 19}, (Thora) {15, 00} , faseDeGrupo);
    insere_jogo(39, &Selecao[Uruguai], &Selecao[Arabia_Saudita], "ROSTOV", (Tdata) {2018, 06, 20}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(40, &Selecao[Uruguai], &Selecao[Russia], "SAMARA", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);
    insere_jogo(41, &Selecao[Arabia_Saudita], &Selecao[Egito], "VOLGOGRADO", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);

    //Grupo H
    insere_jogo(42, &Selecao[Russia], &Selecao[Arabia_Saudita], "OLÍMPICO LUJNIKI", (Tdata) {2018, 06, 14}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(43, &Selecao[Egito], &Selecao[Uruguai], "ECATERIMBURGO", (Tdata) {2018, 06, 15}, (Thora) {9, 00} , faseDeGrupo);
    insere_jogo(44, &Selecao[Russia], &Selecao[Egito], "SÃO PETERSBURGO", (Tdata) {2018, 06, 19}, (Thora) {15, 00} , faseDeGrupo);
    insere_jogo(45, &Selecao[Uruguai], &Selecao[Arabia_Saudita], "ROSTOV", (Tdata) {2018, 06, 20}, (Thora) {12, 00} , faseDeGrupo);
    insere_jogo(46, &Selecao[Uruguai], &Selecao[Russia], "SAMARA", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);
    insere_jogo(47, &Selecao[Arabia_Saudita], &Selecao[Egito], "VOLGOGRADO", (Tdata) {2018, 06, 25}, (Thora) {11, 00} , faseDeGrupo);
    */

    //Oitavas
    insere_jogo(48, NULL, NULL, "OLÍMPICO DE SOCHI", (Tdata) {2018, 06, 30}, (Thora) {15, 00} , oitava);

    Oitavas.jogo[0] = &Jogo[48];
    Oitavas.jogo[1] = &Jogo[48];
    Oitavas.jogo[2] = &Jogo[48];
    Oitavas.jogo[3] = &Jogo[48];
    Oitavas.jogo[4] = &Jogo[48];
    Oitavas.jogo[5] = &Jogo[48];
    Oitavas.jogo[6] = &Jogo[48];
    Oitavas.jogo[7] = &Jogo[48];

}