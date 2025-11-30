#include "libs.h"
#include "jogador_1.h"
#include <string.h>

//Inicializa as informações do jogador 1
void func_info_jogador_1(info_jogador_1 *ptr_info_jogador_1){

    strcpy(ptr_info_jogador_1->nome_jogador_1, "Matheus");
    ptr_info_jogador_1 -> vida = 100;
    ptr_info_jogador_1 -> resistencia = 100;

}

int ataque_jogador_1(ataques_e_defesas *ptr_ataques_e_defesas){
    int escolha_ataque;

    printf(
        "Escolha seu ataque: \n"
        "Ataque básico 1 (dano: %0.2f). Pode ser usado toda rodada\n"
        "Ataque básico 2 (dano: %0.2f). Pode ser usado a cada 2 rodadas\n", 
        ptr_ataques_e_defesas->ataques_basicos[0], ptr_ataques_e_defesas->ataques_basicos[1]);

    scanf("%d", &escolha_ataque);

    return escolha_ataque;

}
