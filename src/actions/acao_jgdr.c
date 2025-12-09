#include "libs/libs.h"
#include "actions/acao_jgdr.h"

void acao_do_jgdr(info_jogador_1 *info_jgdr, info_inimigo_1 *info_inmg, ataques_e_defesas *escolha_jgdr){
    
    //Escolha de ataque do jogador
    int atq_jogador1 = escolha_ataque_jogador_1(escolha_jgdr);
    putchar('\n');
            
    //Reduz a vida do inimigo
    double vida_anterior_inmg1 = info_inmg->vida;
    info_inmg->vida -= escolha_jgdr->ataques_basicos[atq_jogador1];
            
    //Mostra as informações da jogada do jogador 1
    info_rodada_atual_jgdr1(info_jgdr, info_inmg, escolha_jgdr, atq_jogador1, vida_anterior_inmg1);

}