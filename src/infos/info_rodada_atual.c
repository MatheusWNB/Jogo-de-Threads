#include "libs/libs.h"
#include "infos/info_rodada_atual.h"

//Mostra as informações da jogada do jogador 
void info_rodada_atual_jgdr(info_jogador *info_jgdr, info_inimigo *info_inmg, 
                            jgdr_atqs_defs *args_atq_def, int atq, double vida){
    printf(
        "Atacante: %s\n"
        "Ataque escolhido: Ataque básico %d\n"
        "Dano ao inimigo: Inimigo %s recebeu %0.2f de dano\n"
        "Vida inimigo: %0.2f -> %0.2f\n",
        info_jgdr->nome, atq, info_inmg->nome, 
        args_atq_def->atqs_basicos[atq], vida, info_inmg->vida
        );
        printf("--------------------------------------------\n");
}

//Mostra as informações da jogada do inimigo
void info_rodada_atual_inmg(info_jogador *info_jgdr, info_inimigo *info_inmg, 
                            inmg_atqs_defs *args_atq_def, int atq){
    printf(
        "Atacante: %s\n"
        "Ataque escolhido: Ataque básico %d\n"
        "Você recebeu %0.2f de dano!\n"
        "Sua vida atual: %0.2f\n",
        info_inmg->nome, atq, args_atq_def->atqs_basicos[atq], info_jgdr->vida
    );
} 

//Mostra quem foi o vencedor do jogo
void info_vencedor(info_jogador *info_jgdr, info_inimigo *info_inmg){

    system("clear");
    if (info_jgdr->vida > info_inmg->vida)
        printf("VOCÊ GANHOU O JOGO, '%s' FOI DERROTADO\n", info_inmg->nome);
    else 
        printf("VOCÊ PERDEU O JOGO SEU FRACASSADO, '%s' VENCEU!\n", info_inmg->nome);

}