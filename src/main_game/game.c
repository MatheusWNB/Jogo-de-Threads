#include "libs/libs.h"
#include "actions/ataques_e_defesas.h"
#include "infos/jogador_1.h"
#include "actions/atq_def_inimigo_1.h"
#include "infos/inimigo_1.h"

int main (){
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

    //Usuário escolhe qual ataque usar
    atq_jogador1 = escolha_ataque_jogador_1(&escolha_ataques_e_defesas);

    double vida_anterior_inmg1 = info_inmg1.vida;
    info_inmg1.vida -= escolha_ataques_e_defesas.ataques_basicos[atq_jogador1];

    printf(
        "Atacante: %s\n"
        "Ataque escolhido: Ataque básico %d\n"
        "Dano ao inimigo: Inimigo %s recebeu %0.2f de dano\n"
        "Vida inimigo: %0.2f -> %0.2f\n",
        info_jogador_1.nome_jogador_1, atq_jogador1, info_inmg1.nome,
        escolha_ataques_e_defesas.ataques_basicos[atq_jogador1], vida_anterior_inmg1, info_inmg1.vida
    );

    return 0;
}