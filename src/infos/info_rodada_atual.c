#include "libs/libs.h"
#include "infos/info_rodada_atual.h"

//Mostra as informações da jogada do jogador 1
void info_rodada_atual_jgdr1(info_jogador_1 *info_jgdr1, info_inimigo_1 *info_inmg1, 
                            ataques_e_defesas *atqs_e_defs, int atq, double vida){
    printf(
        "Atacante: %s\n"
        "Ataque escolhido: Ataque básico %d\n"
        "Dano ao inimigo: Inimigo %s recebeu %0.2f de dano\n"
        "Vida inimigo: %0.2f -> %0.2f\n",
        info_jgdr1->nome_jogador_1, atq, info_inmg1->nome, 
        atqs_e_defs->ataques_basicos[atq], vida, info_inmg1->vida
        );
        printf("--------------------------------------------\n");
}

//Mostra as informações da jogada do inimigo
void info_rodada_atual_inmg1(info_jogador_1 *info_jgdr1, info_inimigo_1 *info_inmg1, 
                            atq_def_inimigo_1 *atqs_e_defs, int atq){
    printf(
        "Atacante: %s\n"
        "Ataque escolhido: Ataque básico %d\n"
        "Você recebeu %0.2f de dano!\n"
        "Sua vida atual: %0.2f\n",
        info_inmg1->nome, atq, atqs_e_defs->ataques_basicos[atq], info_jgdr1->vida
    );
} 

//Mostra quem foi o vencedor do jogo
void info_vencedor(info_jogador_1 *info_jgdr, info_inimigo_1 *info_inmg1){

    system("clear");
    if (info_jgdr->vida > info_inmg1->vida)
        printf("VOCÊ GANHOU O JOGO, %s FOI DERROTADO\n", info_inmg1->nome);
    else 
        printf("VOCÊ PERDEU O JOGO SEU FRACASSADO %s VENCEU!\n", info_jgdr->nome_jogador_1);

}