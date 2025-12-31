#include "libs/libs.h"
#include "infos/inimigo_1.h"
#include "actions/atq_def_inimigo_1.h"
#include <string.h>

//Informações do inimigo 
void init_info_inimigo(info_inimigo *arg_info_inimigo) {

    strcpy(arg_info_inimigo -> nome, "Nine fingers");
    arg_info_inimigo -> vida = 50;
    arg_info_inimigo -> resistencia = 100;

}

//Realiza a escolha aleatória do ataque do inimigo 
int escolha_atq_inimigo (inmg_atqs_defs *arg_atq_def){

    int laco = true;
    int indice;

    int tamanho = sizeof(arg_atq_def->atqs_basicos) / sizeof(double);
    indice = rand() % tamanho;

    return indice;

}