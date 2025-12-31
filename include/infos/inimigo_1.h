#ifndef INIMIGO_1_H
#define INIMIGO_1_H

#include "actions/atq_def_inimigo_1.h"

//Declara a struct para as informações do inimigo 
typedef struct {
    char nome[20];
    double vida;
    double resistencia;
} info_inimigo;

//Função para inicializar as informações do jogador 
void init_info_inimigo(info_inimigo *arg_info_inimigo);

//Função para inicializar as ações do jogador 1 
int escolha_atq_inimigo(inmg_atqs_defs *arg_atq_def);

#endif

