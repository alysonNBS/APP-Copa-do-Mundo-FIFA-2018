#define NUM_JOGOS 48+8+4+2+2

#define OLIMPICO_LUJNIKI "OL\xD6MPICO LUJNIKI"
#define ECATERIMBURGO "ECATERIMBURGO"
#define SAO_PETERSBURGO "S\xC7O PETERSBURGO"
#define ROSTOV "ROSTOV"
#define SAMARA "SAMARA"
#define VOLGOGRADO "VOLGOGRADO"
#define OLIMPICO_DE_SOCHI "OL\xD6MPICO DE SOCHI"
#define ARENA_KAZAN "ARENA KAZAN"
#define SARANSK "SARANSK"
#define KALININGRADO "KALININGRADO"
#define SPARTAK "SPARTAK"
#define NIZHNY_NOVGOROD "NIZHNY NOVGOROD"


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
struct jogo Jogo[NUM_JOGOS];
struct grupo Grupo[8] = { {'A'}, {'B'}, {'C'}, {'D'}, {'E'}, {'F'}, {'G'}, {'H'} };
struct oitava Oitavas;
struct quarta Quartas;
struct semi_final Semi_final;
struct terceiro_lugar Terc_lugar;
struct final Final;


void corrige_acentos_nomes(void)
{
    int a_tio = 198, a_agudo = 160, a_circuflexo = 131, e_agudo = 130, i_agudo = 161, o_circuflexo = 147, u_agudo = 163, c_cedilha = 135;

    Selecao[Panama].nome[5] = Selecao[Croacia].nome[3] = Selecao[Australia].nome[5] = Selecao[Arabia_Saudita].nome[2] = a_agudo;
    Selecao[Russia].nome[1] = u_agudo;
    Selecao[Japao].nome[3] = Selecao[Ira].nome[2] = a_tio;
    Selecao[Suica].nome[3] = Selecao[Franca].nome[4] = c_cedilha;
    Selecao[Islandia].nome[3] = a_circuflexo;
    Selecao[Belgica].nome[1] = Selecao[Suecia].nome[2] = Selecao[Mexico].nome[1] = Selecao[Servia].nome[1] = Selecao[Nigeria].nome[3] = e_agudo;
    Selecao[Tunisia].nome[3] = Selecao[Suica].nome[2] = i_agudo;
    Selecao[Polonia].nome[3] = Selecao[Colombia].nome[3] = o_circuflexo;
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
        Selecao[i].id = i+1;
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
    Jogo[id].id = id;
    
    Jogo[id].placar[0] = Jogo[id].placar[1] = Jogo[id].prorrogacao[0] =
    Jogo[id].prorrogacao[1] = Jogo[id].penaltes[0] = Jogo[id].penaltes[1] = -1;


    if(pais1 != NULL && pais2 != NULL)
        pais2->jogo[(pais2->num_jogos)++] = pais1->jogo[(pais1->num_jogos)++] = &Jogo[id];
}



void SETUP_JOGOS(void)
{
    //GRUPO A
    insere_jogo(0, &Selecao[Russia], &Selecao[Arabia_Saudita], OLIMPICO_LUJNIKI, (Tdata){2018, 06, 14}, (Thora){12, 00}, faseDeGrupo);
    insere_jogo(1, &Selecao[Egito], &Selecao[Uruguai], ECATERIMBURGO, (Tdata){2018, 06, 15}, (Thora){9, 00}, faseDeGrupo);
    insere_jogo(2, &Selecao[Russia], &Selecao[Egito], SAO_PETERSBURGO, (Tdata){2018, 06, 19}, (Thora){15, 00}, faseDeGrupo);
    insere_jogo(3, &Selecao[Uruguai], &Selecao[Arabia_Saudita], ROSTOV, (Tdata){2018, 06, 20}, (Thora){12, 00}, faseDeGrupo);
    insere_jogo(4, &Selecao[Uruguai], &Selecao[Russia], SAMARA, (Tdata){2018, 06, 25}, (Thora){11, 00}, faseDeGrupo);
    insere_jogo(5, &Selecao[Arabia_Saudita], &Selecao[Egito], VOLGOGRADO, (Tdata){2018, 06, 25}, (Thora){11, 00}, faseDeGrupo);
    //GRUPO B
    insere_jogo(6, &Selecao[Marrocos], &Selecao[Ira], SAO_PETERSBURGO, (Tdata){2018, 06, 15}, (Thora){12, 00}, faseDeGrupo);
    insere_jogo(7, &Selecao[Portugal], &Selecao[Espanha], OLIMPICO_DE_SOCHI, (Tdata){2018, 06, 15}, (Thora){15, 00}, faseDeGrupo);
    insere_jogo(8, &Selecao[Portugal], &Selecao[Marrocos], OLIMPICO_LUJNIKI, (Tdata){2018, 06, 20}, (Thora){9, 00}, faseDeGrupo);
    insere_jogo(9, &Selecao[Ira], &Selecao[Espanha], ARENA_KAZAN, (Tdata){2018, 06, 20}, (Thora){15, 00}, faseDeGrupo);
    insere_jogo(10, &Selecao[Ira], &Selecao[Portugal], SARANSK, (Tdata){2018, 06, 25}, (Thora){15, 00}, faseDeGrupo);
    insere_jogo(11, &Selecao[Espanha], &Selecao[Marrocos], KALININGRADO, (Tdata){2018, 06, 25}, (Thora){15, 00}, faseDeGrupo);
    //GRUPO C
    insere_jogo(12, &Selecao[Franca], &Selecao[Australia], ARENA_KAZAN, (Tdata){2018, 06, 16}, (Thora){7, 00}, faseDeGrupo);
    insere_jogo(13, &Selecao[Peru], &Selecao[Dinamarca], SARANSK, (Tdata){2018, 06, 16}, (Thora){13, 00}, faseDeGrupo);
    insere_jogo(14, &Selecao[Dinamarca], &Selecao[Australia], SAMARA, (Tdata){2018, 06, 21}, (Thora){9, 00}, faseDeGrupo);
    insere_jogo(15, &Selecao[Franca], &Selecao[Peru], ECATERIMBURGO, (Tdata){2018, 06, 21}, (Thora){12, 00}, faseDeGrupo);
    insere_jogo(16, &Selecao[Dinamarca], &Selecao[Franca], OLIMPICO_LUJNIKI, (Tdata){2018, 06, 26}, (Thora){11, 00}, faseDeGrupo);
    insere_jogo(17, &Selecao[Australia], &Selecao[Peru], OLIMPICO_DE_SOCHI, (Tdata){2018, 06, 26}, (Thora){11, 00}, faseDeGrupo);
    //GRUPO D
    insere_jogo(18, &Selecao[Argentina], &Selecao[Islandia], SPARTAK, (Tdata){2018, 06, 16}, (Thora){10, 00}, faseDeGrupo);
    insere_jogo(19, &Selecao[Croacia], &Selecao[Nigeria], KALININGRADO, (Tdata){2018, 06, 16}, (Thora){16, 00}, faseDeGrupo);
    insere_jogo(20, &Selecao[Argentina], &Selecao[Croacia], NIZHNY_NOVGOROD, (Tdata){2018, 06, 21}, (Thora){15, 00}, faseDeGrupo);
    insere_jogo(21, &Selecao[Nigeria], &Selecao[Islandia], VOLGOGRADO, (Tdata){2018, 06, 22}, (Thora){12, 00}, faseDeGrupo);
    insere_jogo(22, &Selecao[Nigeria], &Selecao[Argentina], SAO_PETERSBURGO, (Tdata){2018, 06, 26}, (Thora){15, 00}, faseDeGrupo);
    insere_jogo(23, &Selecao[Islandia], &Selecao[Croacia], ROSTOV, (Tdata){2018, 06, 26}, (Thora){15, 00}, faseDeGrupo);

    //GRUPO E
    insere_jogo(24, &Selecao[Costa_Rica], &Selecao[Servia], SAMARA, (Tdata){2018, 06, 17}, (Thora){9, 00}, faseDeGrupo);
    insere_jogo(25, &Selecao[Brasil], &Selecao[Suica], ROSTOV, (Tdata){2018, 06, 17}, (Thora){15, 00}, faseDeGrupo);
    insere_jogo(26, &Selecao[Brasil], &Selecao[Costa_Rica], SAO_PETERSBURGO, (Tdata){2018, 06, 22}, (Thora){9, 00}, faseDeGrupo);
    insere_jogo(27, &Selecao[Servia], &Selecao[Suica], KALININGRADO, (Tdata){2018, 06, 22}, (Thora){15, 00}, faseDeGrupo);
    insere_jogo(28, &Selecao[Servia], &Selecao[Brasil], SPARTAK, (Tdata){2018, 06, 27}, (Thora){15, 00}, faseDeGrupo);
    insere_jogo(29, &Selecao[Suica], &Selecao[Costa_Rica], NIZHNY_NOVGOROD, (Tdata){2018, 06, 27}, (Thora){15, 00}, faseDeGrupo);

    //GRUPO F
    insere_jogo(30, &Selecao[Alemanha], &Selecao[Mexico], OLIMPICO_LUJNIKI, (Tdata){2018, 06, 17}, (Thora){12, 00}, faseDeGrupo);
    insere_jogo(31, &Selecao[Suecia], &Selecao[Coreia_do_Sul], NIZHNY_NOVGOROD, (Tdata){2018, 06, 18}, (Thora){9, 00}, faseDeGrupo);
    insere_jogo(32, &Selecao[Coreia_do_Sul], &Selecao[Mexico], ROSTOV, (Tdata){2018, 06, 23}, (Thora){12, 00}, faseDeGrupo);
    insere_jogo(33, &Selecao[Alemanha], &Selecao[Suecia], OLIMPICO_DE_SOCHI, (Tdata){2018, 06, 23}, (Thora){15, 00}, faseDeGrupo);
    insere_jogo(34, &Selecao[Coreia_do_Sul], &Selecao[Alemanha], ARENA_KAZAN, (Tdata){2018, 06, 27}, (Thora){11, 00}, faseDeGrupo);
    insere_jogo(35, &Selecao[Mexico], &Selecao[Suecia], ECATERIMBURGO, (Tdata){2018, 06, 27}, (Thora){11, 00}, faseDeGrupo);

    //GRUPO G
    insere_jogo(36, &Selecao[Belgica], &Selecao[Panama], OLIMPICO_DE_SOCHI, (Tdata){2018, 06, 18}, (Thora){12, 00}, faseDeGrupo);
    insere_jogo(37, &Selecao[Tunisia], &Selecao[Inglaterra], VOLGOGRADO, (Tdata){2018, 06, 18}, (Thora){15, 00}, faseDeGrupo);
    insere_jogo(38, &Selecao[Belgica], &Selecao[Tunisia], SPARTAK, (Tdata){2018, 06, 23}, (Thora){9, 00}, faseDeGrupo);
    insere_jogo(39, &Selecao[Inglaterra], &Selecao[Panama], NIZHNY_NOVGOROD, (Tdata){2018, 06, 24}, (Thora){9, 00}, faseDeGrupo);
    insere_jogo(40, &Selecao[Inglaterra], &Selecao[Belgica], KALININGRADO, (Tdata){2018, 06, 28}, (Thora){15, 00}, faseDeGrupo);
    insere_jogo(41, &Selecao[Panama], &Selecao[Tunisia], KALININGRADO, (Tdata){2018, 06, 28}, (Thora){15, 00}, faseDeGrupo);

    //GRUPO H
    insere_jogo(42, &Selecao[Colombia], &Selecao[Japao], SARANSK, (Tdata){2018, 06, 19}, (Thora){9, 00}, faseDeGrupo);
    insere_jogo(43, &Selecao[Polonia], &Selecao[Senegal], SPARTAK, (Tdata){2018, 06, 19}, (Thora){12, 00}, faseDeGrupo);
    insere_jogo(44, &Selecao[Japao], &Selecao[Senegal], ECATERIMBURGO, (Tdata){2018, 06, 24}, (Thora){12, 00}, faseDeGrupo);
    insere_jogo(45, &Selecao[Polonia], &Selecao[Colombia], ARENA_KAZAN, (Tdata){2018, 06, 24}, (Thora){15, 00}, faseDeGrupo);
    insere_jogo(46, &Selecao[Japao], &Selecao[Polonia], VOLGOGRADO, (Tdata){2018, 06, 28}, (Thora){11, 00}, faseDeGrupo);
    insere_jogo(47, &Selecao[Senegal], &Selecao[Colombia], SAMARA, (Tdata){2018, 06, 28}, (Thora){11, 00}, faseDeGrupo);

    //OITAVAS DE FINAL
    insere_jogo(48, NULL, NULL, OLIMPICO_DE_SOCHI, (Tdata){2018, 06, 30}, (Thora){15, 00}, oitava);
    insere_jogo(49, NULL, NULL, ARENA_KAZAN, (Tdata){2018, 06, 30}, (Thora){11, 00}, oitava);
    insere_jogo(50, NULL, NULL, SAMARA, (Tdata){2018, 07, 02}, (Thora){11, 00}, oitava);
    insere_jogo(51, NULL, NULL, ROSTOV, (Tdata){2018, 07, 02}, (Thora){15, 00}, oitava);
    insere_jogo(52, NULL, NULL, OLIMPICO_LUJNIKI, (Tdata){2018, 07, 01}, (Thora){11, 00}, oitava);
    insere_jogo(53, NULL, NULL, NIZHNY_NOVGOROD, (Tdata){2018, 07, 01}, (Thora){15, 00}, oitava);
    insere_jogo(54, NULL, NULL, SAO_PETERSBURGO, (Tdata){2018, 07, 03}, (Thora){11, 00}, oitava);
    insere_jogo(55, NULL, NULL, SPARTAK, (Tdata){2018, 07, 03}, (Thora){15, 00}, oitava);

    //QUARTAS DE FINAL
    insere_jogo(56, NULL, NULL, NIZHNY_NOVGOROD, (Tdata){2018, 07, 06}, (Thora){11, 00}, quarta);
    insere_jogo(57, NULL, NULL, ARENA_KAZAN, (Tdata){2018, 07, 06}, (Thora){15, 00}, quarta);
    insere_jogo(58, NULL, NULL, OLIMPICO_DE_SOCHI, (Tdata){2018, 07, 07}, (Thora){15, 00}, quarta);
    insere_jogo(59, NULL, NULL, SAMARA, (Tdata){2018, 07, 07}, (Thora){11, 00}, quarta);

    //SEMI-FINAL
    insere_jogo(60, NULL, NULL, SAO_PETERSBURGO, (Tdata){2018, 07, 10}, (Thora){15, 00}, semi_final);
    insere_jogo(61, NULL, NULL, OLIMPICO_LUJNIKI, (Tdata){2018, 07, 11}, (Thora){15, 00}, semi_final);

    //DISPUTA PELO TERCEIRO LUGAR
    insere_jogo(62, NULL, NULL, SAO_PETERSBURGO, (Tdata){2018, 07, 14}, (Thora){11, 00}, terc_lugar);

    //FINAL
    insere_jogo(63, NULL, NULL, OLIMPICO_LUJNIKI, (Tdata){2018, 07, 15}, (Thora){12, 00}, final);


}


void SALVAR_JOGOS()
{
    FILE *fp;
    int i, nulo=0;
    fp = fopen("carga_jogos.arq", "wb");
    for (i = 0; i < 64; i++)
    {
            if (Jogo[i].pais[0]==NULL)
                fwrite(&nulo, sizeof(int), 1, fp);
            else
                fwrite(&Jogo[i].pais[0]->id, sizeof(int), 1, fp);
            if (Jogo[i].pais[1]==NULL)
                fwrite(&nulo, sizeof(int), 1, fp);
            else
                fwrite(&Jogo[i].pais[1]->id, sizeof(int), 1, fp);
            fwrite(&(Jogo[i].placar), sizeof(Jogo[i].placar), 2, fp);
            fwrite(&(Jogo[i].prorrogacao), sizeof(Jogo[i].prorrogacao), 2, fp);
            fwrite(&(Jogo[i].penaltes), sizeof(Jogo[i].penaltes), 2, fp);
            fwrite(Jogo[i].local, 50*sizeof(char), 1, fp);
            fwrite(&(Jogo[i].data), sizeof(Jogo[i].data), 1, fp);
            fwrite(&(Jogo[i].hora), sizeof(Jogo[i].hora), 1, fp);
            fwrite(&(Jogo[i].tipo), sizeof(Jogo[i].tipo), 1, fp);
            fwrite(&(Jogo[i].id), sizeof(Jogo[i].id), 1, fp);
            
            // printf("\n\n%s  -  %s \n",Jogo[i].pais[0]->nome, Jogo[i].pais[1]->nome);
    }
    fclose(fp);
}

void CARREGAR_JOGOS()
{
    int i;
    FILE *fp3;

    SETUP_GRUPOS();
    SETUP_SELECOES();
    int auxid;
    fp3 = fopen("carga_jogos.arq", "rb");

    if (fp3 == NULL){
        SETUP_JOGOS();
        SALVAR_JOGOS();
    }else{
        for (i = 0; i < 64; i++)
        {
            Jogo[i].pais[0] = malloc(sizeof(struct selecao));
            fread(&auxid, sizeof(int), 1, fp3);
            if (auxid == 0)
                Jogo[i].pais[0] = NULL;
            else
                Jogo[i].pais[0] = &Selecao[auxid-1];
            Jogo[i].pais[1] = malloc(sizeof(struct selecao));
            fread(&auxid, sizeof(int), 1, fp3);
            if (auxid == 0)
                Jogo[i].pais[1] = NULL;
            else
                Jogo[i].pais[1] = &Selecao[auxid-1];
            fread(&(Jogo[i].placar), sizeof(Jogo[i].placar), 2, fp3);
            fread(&(Jogo[i].prorrogacao), sizeof(Jogo[i].prorrogacao), 2, fp3);
            fread(&(Jogo[i].penaltes), sizeof(Jogo[i].penaltes), 2, fp3);
            Jogo[i].local = malloc(50*sizeof(char));
            fread(Jogo[i].local, 50*sizeof(char), 1, fp3);
            fread(&(Jogo[i].data), sizeof(Jogo[i].data), 1, fp3);
            fread(&(Jogo[i].hora), sizeof(Jogo[i].hora), 1, fp3);
            fread(&(Jogo[i].tipo), sizeof(Jogo[i].tipo), 1, fp3);
            fread(&(Jogo[i].id), sizeof(Jogo[i].id), 1, fp3);
            if (Jogo[i].pais[0] != NULL && Jogo[i].pais[1] != NULL)
                Jogo[i].pais[0]->jogo[(Jogo[i].pais[0]->num_jogos)++] = Jogo[i].pais[1]->jogo[(Jogo[i].pais[1]->num_jogos)++] = &Jogo[i];
        }
    }

    //VINCULAÇÃO DOS JOGOS COM AS STRUCTS DE FASES
    Oitavas.jogo[0] = &Jogo[48];
    Oitavas.jogo[1] = &Jogo[49];
    Oitavas.jogo[2] = &Jogo[50];
    Oitavas.jogo[3] = &Jogo[51];
    Oitavas.jogo[4] = &Jogo[52];
    Oitavas.jogo[5] = &Jogo[53];
    Oitavas.jogo[6] = &Jogo[54];
    Oitavas.jogo[7] = &Jogo[55];

    Quartas.jogo[0] = &Jogo[56];
    Quartas.jogo[1] = &Jogo[57];
    Quartas.jogo[2] = &Jogo[58];
    Quartas.jogo[3] = &Jogo[59];

    Semi_final.jogo[0] = &Jogo[60];
    Semi_final.jogo[1] = &Jogo[61];

    Terc_lugar.jogo = &Jogo[62];

    Final.jogo = &Jogo[63];

    fclose(fp3);
}

