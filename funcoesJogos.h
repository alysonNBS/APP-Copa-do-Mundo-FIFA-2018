struct selecao * vencedor(struct jogo jogo);
int empate(struct jogo j);


void processa_fase(Tjogo *jogos, int id, Tgrupo *grupos);

struct selecao * vencedor(struct jogo jogo)
{
    if(jogo.placar[0] > jogo.placar[1])
        return jogo.pais[0];
    if(jogo.placar[0] < jogo.placar[1])
        return jogo.pais[1];

    if(jogo.prorrogacao[0] > jogo.prorrogacao[1])
        return jogo.pais[0];
    if(jogo.prorrogacao[0] < jogo.prorrogacao[1])
        return jogo.pais[1];

    if(jogo.penaltes[0] > jogo.penaltes[1])
        return jogo.pais[0];
    if(jogo.penaltes[0] < jogo.penaltes[1])
        return jogo.pais[1];
    
    return NULL;
}



int empate(struct jogo j)
{
    if( vencedor(j) == NULL)
        return 1;
    return 0;
}



void processa_fase(Tjogo *jogos, const int id, Tgrupo *grupos)
{
    if(jogos[id].tipo == terc_lugar || jogos[id].tipo == final)
        return;
    
    if(jogos[id].tipo == faseDeGrupo)
    {
        
        int classificacao(const void *s1, const void *s2);
        int padrao(const void *s1, const void *s2);
        int cont_jogos, i;

        for(cont_jogos = i = 0; i<48; i++)
            if(jogos[i].placar[0] != -1)
                cont_jogos++;
        
        if(cont_jogos == 48)
        {
            for(i=0; i<8; i++)
                qsort(grupos[i].selecao, 4, sizeof(struct selecao *), classificacao);

            for(i=0; i<4; i++)
            {
                jogos[48+i].pais[0] = grupos[2*i].selecao[0];
                jogos[48+i].pais[1] = grupos[2*i+1].selecao[1];
                jogos[52+i].pais[1] = grupos[2*i].selecao[1];
                jogos[52+i].pais[0] = grupos[2*i+1].selecao[0];
            }

            for(i=0; i<8; i++)
                qsort(grupos[i].selecao, 4, sizeof(struct selecao *), padrao);
        }

    }
    else if(jogos[id].tipo == oitava)
    {
        const int time_quarta = id % 2;
        const int jogo_quarta = (id % 48) / 2 + 56;
        struct selecao *vencedor;

        if(jogos[id].placar[0] > jogos[id].placar[1] ||
            (jogos[id].placar[0] == jogos[id].placar[1] && jogos[id].penaltes[0] > jogos[id].penaltes[1]) )
            vencedor = jogos[id].pais[0];
        else
            vencedor = jogos[id].pais[1];


        jogos[jogo_quarta].pais[time_quarta] = vencedor;
    }
    else if(jogos[id].tipo == quarta)
    {
        const int time_semi = id % 2;
        const int jogo_semi = (id % 56) / 2 + 60;

        struct selecao *vencedor;

        if(jogos[id].placar[0] > jogos[id].placar[1] ||
            (jogos[id].placar[0] == jogos[id].placar[1] && jogos[id].penaltes[0] > jogos[id].penaltes[1]) )
            vencedor = jogos[id].pais[0];
        else
            vencedor = jogos[id].pais[1];
        
        jogos[jogo_semi].pais[time_semi] = vencedor;
    }
    else if(jogos[id].tipo == semi_final)
    {
        const int time_final_terc_lugar = id % 2;
        const int jogo_final = 63;
        const int jogo_terc_lugar = 62;

        struct selecao *vencedor;
        struct selecao *perdedor;
        

        if(jogos[id].placar[0] > jogos[id].placar[1] ||
            (jogos[id].placar[0] == jogos[id].placar[1] && jogos[id].penaltes[0] > jogos[id].penaltes[1]) )
        {
            vencedor = jogos[id].pais[0];
            perdedor = jogos[id].pais[1];
        }
        else
        {
            vencedor = jogos[id].pais[1];
            perdedor = jogos[id].pais[0];
        }
        
        jogos[jogo_final].pais[time_final_terc_lugar] = vencedor;
        jogos[jogo_terc_lugar].pais[time_final_terc_lugar] = perdedor;
    }
}