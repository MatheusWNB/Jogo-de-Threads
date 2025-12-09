#include "libs/libs.h"
#include "actions/acao_inmg1.h"

void acao_do_inmg1(info_jogador_1 *info_jgdr, info_inimigo_1 *info_inmg, atq_def_inimigo_1 *escolha_inmg){

    //Escolha de ataque aleatório do inimigo 1
    int atq_inmg1 = escolha_ataque_inimigo_1(escolha_inmg); 
    //Reduz a vida do jogador 1
    info_jgdr->vida -= escolha_inmg->ataques_basicos[atq_inmg1]; 
                
    //Mostra as informações da jogada do inimigo
    sleep(1.0);
    info_rodada_atual_inmg1(info_jgdr, info_inmg, escolha_inmg, atq_inmg1);

}



                    