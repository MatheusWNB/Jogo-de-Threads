#include "libs/libs.h"
#include "infos/inimigo_1.h"
#include "actions/atq_def_inimigo_1.h"
#include <string.h>

void func_info_inimigo_1(info_inimigo_1 *ptr_info_inimigo_1) {
    
    strcpy(ptr_info_inimigo_1 -> nome, "Nine fingers");
    ptr_info_inimigo_1 -> vida = 200;
    ptr_info_inimigo_1 -> resistência = 100;

}

int escolha_ataque_inimigo_1 (atq_def_inimigo_1 *ptr_atq_def_inimigo_1){
    int laco = true;
    int indice;

    while (laco){

        int tamanho = sizeof(ptr_atq_def_inimigo_1 -> ataques_basicos) / (sizeof(8));
        indice = rand() % tamanho;

        if (indice >= 3)
            continue;
        
        else
            laco = false;

    }
        
    return indice;
 
}