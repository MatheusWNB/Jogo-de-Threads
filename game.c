#include "libs.h"
#include "ataques_e_defesas.h"
#include "jogador_1.h"

int main (){
    //Ataque escolhido
    int ataque_escolhido;

    //Inimigo provisório
    int vida_inimigo = 100;

    //Inicializa ataques e defesas
    ataques_e_defesas escolha_ataques_e_defesas;
    func_ataques_e_defesas(&escolha_ataques_e_defesas);

    //Inicializa jogador 1
    info_jogador_1 inicializar_jogador_1;
    func_info_jogador_1(&inicializar_jogador_1);

    ataque_escolhido = ataque_jogador_1(&escolha_ataques_e_defesas);

    printf("Esse foi o ataque escolhido: %d\n", ataque_escolhido);

    if (ataque_escolhido == 1)
        printf("Dano do ataque 1: %0.2f\n", escolha_ataques_e_defesas.ataques_basicos[0]);
    
    else if (ataque_escolhido == 2)
        printf("Dano do ataque 2: %0.2f\n", escolha_ataques_e_defesas.ataques_basicos[1]);

    return 0;
}


    