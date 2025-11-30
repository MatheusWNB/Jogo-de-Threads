#ifndef ATAQUES_E_DEFESAS_H
#define ATAQUES_E_DEFESAS_H

//Declarando a struct para escolha de ataque ou defesa
typedef struct {
    int escolha[2];
    double defesas_basicas[2];
    double ataques_basicos[2];
} ataques_e_defesas;

//Declarando função para definir a struct
void func_ataques_e_defesas(ataques_e_defesas *ptr_ataques_e_defesas);

#endif