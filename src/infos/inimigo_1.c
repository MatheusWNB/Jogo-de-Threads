#include "libs/libs.h"
#include "infos/inimigo_1.h"
#include "actions/atq_def_inimigo_1.h"
#include <string.h>
#include <time.h>

void func_info_inimigo_1(info_inimigo_1 *ptr_info_inimigo_1) {
    
    strcpy(ptr_info_inimigo_1 -> nome, "Nine fingers");
    ptr_info_inimigo_1 -> vida = 200;
    ptr_info_inimigo_1 -> resistência = 100;

}

double escolha_ataque_inimigo_1 (atq_def_inimigo_1 *ptr_atq_def_inimigo_1){

    int tamanho = sizeof(ptr_atq_def_inimigo_1 -> ataques_basicos) / sizeof(ptr_atq_def_inimigo_1 -> ataques_basicos[0]);
    srand ((unsigned) time(NULL));
    int indice = rand() % tamanho;
    int atq_escolhido = ptr_atq_def_inimigo_1 -> ataques_basicos[indice];

    return atq_escolhido;
 
}