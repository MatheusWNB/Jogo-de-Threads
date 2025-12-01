#ifndef JOGADOR_1_H
#define JOGADOR_1_H

#include "actions/ataques_e_defesas.h"

typedef struct {
    char nome_jogador_1[20];
    double vida;
    double resistencia;
} info_jogador_1;

//Função para inicializar as informações do jogador 1
void func_info_jogador_1(info_jogador_1 *ptr_info_jogador_1);

//Função para inicializar as ações do jogador 1 
int escolha_ataque_jogador_1(ataques_e_defesas *ptr_ataques_e_defesas);

//Função para realizar o ataque do jogador 1 
double ataque_jogador_1(ataques_e_defesas *ptr_ataques_e_defesas, double vida_inimigo, int escolha_de_ataque);

#endif



