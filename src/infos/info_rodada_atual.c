#include "libs/libs.h"
#include "infos/info_rodada_atual.h"

void info_rodada_atual_jgdr1(info_jogador_1 *info_jgdr1, info_inimigo_1 *info_inmg1, ataques_e_defesas *atqs_e_defs, int atq, double vida){
    printf(
        "Atacante: %s\n"
        "Ataque escolhido: Ataque básico %d\n"
        "Dano ao inimigo: Inimigo %s recebeu %0.2f de dano\n"
        "Vida inimigo: %0.2f -> %0.2f\n",
        info_jgdr1->nome_jogador_1, atq, info_inmg1->nome, atqs_e_defs->ataques_basicos[atq], vida, info_inmg1->vida
        );
        printf("--------------------------------------------\n");
}

void info_rodada_atual_inmg1(info_jogador_1 *info_jgdr1, info_inimigo_1 *info_inmg1, atq_def_inimigo_1 *atqs_e_defs, int atq){
    printf(
        "Atacante: %s\n"
        "Ataque escolhido: Ataque básico %d\n"
        "Você recebeu %0.2f de dano!\n"
        "Sua vida atual: %0.2f\n",
        info_inmg1->nome, atq, atqs_e_defs->ataques_basicos[atq], info_jgdr1->vida
    );
} 