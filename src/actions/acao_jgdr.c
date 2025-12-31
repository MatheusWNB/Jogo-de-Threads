#include "libs/libs.h"
#include "actions/acao_jgdr.h"
#include "actions/vantagens_jogador.h"

void acao_jgdr(info_jogador *info_jgdr, info_inimigo *info_inmg, 
                    jgdr_atqs_defs *escolha_jgdr, vantagens_jgdr *args_vantagens, int *rodada){

    //A cada duas rodadas o jogador recebe uma vantagem de regenerar vida
    if (*rodada != 0 && (*rodada) % 2 == 0)
        info_jgdr->vida = action_regenerar_vida(args_vantagens, info_jgdr);

    //Escolha de ataque do jogador
    int atq_jogador = escolha_atq_jogador(escolha_jgdr);
    putchar('\n');
            
    //Reduz a vida do inimigo
    double vida_anterior_inmg = info_inmg->vida;
    info_inmg->vida -= escolha_jgdr->atqs_basicos[atq_jogador];
            
    //Mostra as informações da jogada do jogador 
    info_rodada_atual_jgdr(info_jgdr, info_inmg, escolha_jgdr, atq_jogador, vida_anterior_inmg);
}