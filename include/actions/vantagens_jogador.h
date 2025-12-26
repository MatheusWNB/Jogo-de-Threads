#ifndef VANTAGENS_JOGADOR_H
#define VANTAGENS_JOGADOR_H

typedef struct {
    double regenerar_vida[4];
} vantagens_jogador;

void init_vantagens_jogador(vantagens_jogador *args);

double action_regenerar_vida (double *regenerar_vida, double vida);

#endif VANTAGENS_JOGADOR_H

