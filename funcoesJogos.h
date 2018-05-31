struct selecao * vencedor(struct jogo jogo);
int empate(struct jogo j);


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
