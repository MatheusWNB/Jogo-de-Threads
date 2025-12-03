#ifndef INFO_RODADA_ATUAL_H
#define INFO_RODADA_ATUAL_H

#include "jogador_1.h"
#include "inimigo_1.h"

void info_rodada_atual_jgdr1(info_jogador_1 *info_jgdr1, info_inimigo_1 *info_inmg1, ataques_e_defesas *atqs_e_defs, int atq, double vida);

void info_rodada_atual_inmg1(info_jogador_1 *info_jgdr1, info_inimigo_1 *info_inmg1, atq_def_inimigo_1 *atqs_e_defs, int atq);

#endif