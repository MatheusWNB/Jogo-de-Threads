#include "libs.h"
#include "ataques_e_defesas.h"

void func_ataques_e_defesas(ataques_e_defesas *ptr_ataques_e_defesas){

    //Escolha do usuário se defende ou ataca
    ptr_ataques_e_defesas -> escolha[0] = 1;//Defender
    ptr_ataques_e_defesas -> escolha[1] = 2;//Atacar

    //Escolha de ataques
    ptr_ataques_e_defesas -> ataques_basicos[0] = 10.0; //Ataque básico 1 (Toda rodada)
    ptr_ataques_e_defesas -> ataques_basicos[1] = 15.5; //Ataque básico 2 (A cada duas rodadas)

    //Escolha de defesas
    ptr_ataques_e_defesas ->  defesas_basicas[0] = 50.0; //Defesa básica 1 (Toda rodada)
    ptr_ataques_e_defesas -> defesas_basicas[1] = 85.0; //Defesa básica 2 (A cada duas rodadas)

}