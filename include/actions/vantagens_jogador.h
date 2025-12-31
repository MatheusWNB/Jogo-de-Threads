#ifndef VANTAGENS_JOGADOR_H
#define VANTAGENS_JOGADOR_H

#include "infos/jogador_1.h"

//Declaração das vantagens do jogador
typedef struct {
    int regenerar_vida[4];
} vantagens_jgdr;

//Inicia vantagens do jogador
void init_vantagens_jogador(vantagens_jgdr *args);

//Função para regenerar vida do jogador
double action_regenerar_vida (vantagens_jgdr *args_vantagens, info_jogador *arg_vida);

#endif 