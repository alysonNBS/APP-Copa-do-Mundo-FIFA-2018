int pontos(struct selecao s);
int jogos(struct selecao s);
int vitorias(struct selecao s);
int empates(struct selecao s);
int derrotas(struct selecao s);
int saldo(struct selecao s);
int gp(struct selecao s);
int gc(struct selecao s);

int classificacao(const void *s1, const void *s2);
int padrao(const void *s1, const void *s2);


int pontos(struct selecao s) {
    int i, p;

    for(p=i=0; i<3; i++)
        if(s.jogo[i]->placar[0] != -1) {
            if(empate(*s.jogo[i]))
                p+=1;
            else if(string_comp(s.nome, vencedor(*s.jogo[i])->nome) == 0)
                p+=3;
        }

    return p;
}



int jogos(struct selecao s) {
    int i, j;

    for(j=i=0; i<3; i++)
        if(s.jogo[i]->placar[0] != -1)
            j++;

    return j;
}



int vitorias(struct selecao s) {
    int i, v;

    for(v=i=0; i<3; i++)
        if(s.jogo[i]->placar[0] != -1) {
            Tselecao *vencedora = vencedor(*s.jogo[i]);

            if(vencedora != NULL && string_comp(s.nome, vencedora->nome) == 0)
                v++;
        }

    return v;
}



int empates(struct selecao s) {
    int i, e;

    for(e=i=0; i<3; i++)
        if(s.jogo[i]->placar[0] != -1)
            if(empate(*s.jogo[i]))
                e++;

    return e;
}



int derrotas(struct selecao s) {
    int i, d;

    for(d=i=0; i<3; i++)
        if(s.jogo[i]->placar[0] != -1)
            if(!empate(*s.jogo[i]) && string_comp(s.nome, vencedor(*s.jogo[i])->nome) != 0)
                d++;

    return d;
}



int saldo(struct selecao s) {
    return gp(s) - gc(s);
}



int gp(struct selecao s) {
    int i, gols;

    for(gols=i=0; i<3; i++)
        if(s.jogo[i]->placar[0] != -1) {
            if(string_comp(s.nome, s.jogo[i]->pais[0]->nome) == 0)
                gols += s.jogo[i]->placar[0];
            else
                gols += s.jogo[i]->placar[1];
        }

    return gols;
}



int gc(struct selecao s) {
    int i, gols;

    for(gols=i=0; i<3; i++)
        if(s.jogo[i]->placar[0] != -1) {
            if(string_comp(s.nome, s.jogo[i]->pais[0]->nome) == 0)
                gols += s.jogo[i]->placar[1];
            else
                gols += s.jogo[i]->placar[0];
        }

    return gols;
}