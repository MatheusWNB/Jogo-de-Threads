#include "libs/libs.h"
#include "actions/ataques_e_defesas.h"
#include "infos/jogador_1.h"
#include "actions/atq_def_inimigo_1.h"
#include "infos/inimigo_1.h"
#include <time.h>
#include "infos/info_rodada_atual.h"

int main (){
    //Gera seed para escolha aleatória
    srand ((unsigned) time(NULL));

    //Ataque escolhido
    int atq_jogador1;
    int atq_inmg1;

    //INIMIGO 1:
    //Inicializa inimigo 1
    info_inimigo_1 info_inmg1;
    func_info_inimigo_1(&info_inmg1);
    
    //Inicializa ataques e defesas do inimigo 1
    atq_def_inimigo_1 escolha_atq_def_inmg1;
    func_atq_def_inimigo_1(&escolha_atq_def_inmg1);

    //JOGADOR 1:
    //Inicializa jogador 1
    info_jogador_1 info_jogador_1;
    func_info_jogador_1(&info_jogador_1);
    
    //Inicializa ataques e defesas
    ataques_e_defesas escolha_ataques_e_defesas;
    func_ataques_e_defesas(&escolha_ataques_e_defesas);

    int rodada_atual = 1;

    while (info_jogador_1.vida > 0 && info_inmg1.vida > 0){

        //Usuário escolhe qual ataque usar
        printf("RODADA %d. SUA VEZ DE JOGAR!\n", rodada_atual);
        atq_jogador1 = escolha_ataque_jogador_1(&escolha_ataques_e_defesas);

        double vida_anterior_inmg1 = info_inmg1.vida;
        info_inmg1.vida -= escolha_ataques_e_defesas.ataques_basicos[atq_jogador1];

        info_rodada_atual_jgdr1(&info_jogador_1, &info_inmg1, &escolha_ataques_e_defesas, atq_jogador1, vida_anterior_inmg1);


        //Inimigo gera ataque aleatório
        printf("RODADA %d. INIMIGO ESTÁ ATACANDO!\n", rodada_atual);
        atq_inmg1 = escolha_ataque_inimigo_1(&escolha_atq_def_inmg1);
        info_jogador_1.vida -= escolha_atq_def_inmg1.ataques_basicos[atq_inmg1];
        info_rodada_atual_inmg1(&info_jogador_1, &info_inmg1, &escolha_atq_def_inmg1, atq_inmg1);
        sleep(1.0);

        rodada_atual += 1;
        
    }



    return 0;
}