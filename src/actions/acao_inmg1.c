#include "libs/libs.h"
#include "actions/acao_inmg1.h"

void acao_inmg(info_jogador *info_jgdr, info_inimigo *info_inmg, inmg_atqs_defs *escolha_inmg){
    //Escolha de ataque aleatório do inimigo 
    int atq_inmg = escolha_atq_inimigo(escolha_inmg); 

    //Reduz a vida do jogador 
    info_jgdr->vida -= escolha_inmg->atqs_basicos[atq_inmg]; 
                
    //Mostra as informações da jogada do inimigo
    sleep(1.0);
    info_rodada_atual_inmg(info_jgdr, info_inmg, escolha_inmg, atq_inmg);
}



                    