#ifndef INIMIGO_1_H
#define INIMIGO_1_H

#include "actions/atq_def_inimigo_1.h"

typedef struct {
    char nome[20];
    double vida;
    double resistência;
} info_inimigo_1;

void func_info_inimigo_1(info_inimigo_1 *ptr_info_inimigo_1);

double escolha_ataque_inimigo_1(atq_def_inimigo_1 *ptr_atq_def_inimigo_1);

#endif

