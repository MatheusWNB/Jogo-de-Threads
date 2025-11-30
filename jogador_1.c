#include "libs.h"
#include "jogador_1.h"
#include <string.h>

//Inicializa as informações do jogador 1
void func_info_jogador_1(info_jogador_1 *ptr_info_jogador_1){

    strcpy(ptr_info_jogador_1->nome_jogador_1, "Matheus");
    ptr_info_jogador_1 -> vida = 100;
    ptr_info_jogador_1 -> resistencia = 100;

}

