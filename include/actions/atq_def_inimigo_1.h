#ifndef ATQ_DEF_INIMIGO_H
#define ATQ_DEF_INIMIGO_H

//Declarando struct para ataques e defesas do inimigo 
typedef struct {
    double atqs_basicos[3];
    double defs_basicas[2];
} inmg_atqs_defs;

//Função para definir os ataques e defesas do inimigo 
void init_inmg_atq_def(inmg_atqs_defs *args_atq_def);

#endif