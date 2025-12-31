#ifndef JOGADOR_1_H
#define JOGADOR_1_H

#include "actions/ataques_e_defesas.h"

//Declara a struct para as informações do jogador
typedef struct {
    char nome[20];
    double vida;
    double resistencia;
} info_jogador;

//Função para inicializar as informações do jogador 
void init_info_jogador(info_jogador *arg_info_jogador);

//Função para inicializar as ações do jogador  
int escolha_atq_jogador(jgdr_atqs_defs *arg_atq_def);

#endif



