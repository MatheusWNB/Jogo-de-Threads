#ifndef VANTAGENS_JOGADOR_H
#define VANTAGENS_JOGADOR_H

#include "infos/jogador_1.h"

typedef struct {
    int regenerar_vida[4];
} vantagens_jogador;

void init_vantagens_jogador(vantagens_jogador *args);

double action_regenerar_vida (vantagens_jogador *args_vantagens, info_jogador_1 *arg_vida);

#endif 

