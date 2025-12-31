#ifndef INFO_RODADA_ATUAL_H
#define INFO_RODADA_ATUAL_H

#include "jogador_1.h"
#include "inimigo_1.h"

//Mostra as informações da jogada do jogador 
void info_rodada_atual_jgdr(info_jogador *info_jgdr, info_inimigo *info_inmg, 
                            jgdr_atqs_defs *args_atq_def, int atq, double vida);

//Mostra as informações da jogada do inimigo
void info_rodada_atual_inmg(info_jogador *info_jgdr, info_inimigo *info_inmg, 
                            inmg_atqs_defs *args_atq_def, int atq);

//Mostra quem foi o vencedor do jogo                          
void info_vencedor(info_jogador *info_jgdr, info_inimigo *info_inmg);

#endif