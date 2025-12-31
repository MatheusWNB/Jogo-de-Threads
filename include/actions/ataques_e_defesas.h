#ifndef ATQ_DEF_JGDR_H
#define ATQ_DEF_JGDR_H

//Declaração da struct para escolha de ataque e defesa do jogador
typedef struct {
    int escolha[2];
    double defs_basicas[2];
    double atqs_basicos[2];
} jgdr_atqs_defs;

//Declarando função para definir os ataques e defesas do jogador 1
void init_jgdr_atq_def(jgdr_atqs_defs *args_atq_def);

#endif