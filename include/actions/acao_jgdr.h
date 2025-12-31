#ifndef ACAO_JGDR_H
#define ACAO_JGDR_H

#include "libs/libs_inimigo.h"
#include "libs/libs_jogador_1.h"
#include "actions/vantagens_jogador.h"

//Declara as ações do jogador
void acao_jgdr(info_jogador *info_jgdr, info_inimigo *info_inmg, jgdr_atqs_defs *escolha_jgdr,
                    vantagens_jgdr *args_vantagens, int *rodada);

#endif
