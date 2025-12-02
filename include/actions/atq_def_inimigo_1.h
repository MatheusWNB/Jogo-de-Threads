#ifndef ATQ_DEF_INIMIGO_1
#define ATQ_DEF_INIMIGO_1

//Declarando struct para ataques e defesas do inimigo 1
typedef struct {
    double ataques_basicos[3];
    double defesas_basicas[2];
} atq_def_inimigo_1;

//Função para definir os ataques e defesas
void func_atq_def_inimigo_1(atq_def_inimigo_1 *ptr_atq_def_inimigo_1);

#endif