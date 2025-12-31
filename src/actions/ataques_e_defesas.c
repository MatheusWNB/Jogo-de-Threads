#include "libs/libs.h"
#include "actions/ataques_e_defesas.h"

//As informações dos ataques e defesas do jogador 1
void init_jgdr_atq_def(jgdr_atqs_defs *arg_atq_def){
    //Escolha do usuário se defende ou ataca
    arg_atq_def -> escolha[0] = 1;//Defender
    arg_atq_def -> escolha[1] = 2;//Atacar

    //Escolha de ataques
    arg_atq_def -> atqs_basicos[0] = 10.0; //Ataque básico 1 (Toda rodada)
    arg_atq_def -> atqs_basicos[1] = 15.5; //Ataque básico 2 (A cada duas rodadas)

    //Escolha de defesas
    arg_atq_def ->  defs_basicas[0] = 50.0; //Defesa básica 1 (Toda rodada)
    arg_atq_def -> defs_basicas[1] = 85.0; //Defesa básica 2 (A cada duas rodadas)
}