#include "libs.h"
#include "ataques_e_defesas.h"

int main (){
    ataques_e_defesas escolha_ataques_e_defesas;
    func_ataques_e_defesas(&escolha_ataques_e_defesas);

    printf("Escolhas %d %d\n", 
        escolha_ataques_e_defesas.escolha[0], escolha_ataques_e_defesas.escolha[1]);

    printf("Ataques %0.2f %0.2f\n", 
        escolha_ataques_e_defesas.ataques_basicos[0], escolha_ataques_e_defesas.ataques_basicos[1]);

    printf("Defesas %0.2f %0.2f\n", 
        escolha_ataques_e_defesas.defesas_basicas[0], escolha_ataques_e_defesas.defesas_basicas[1]);

    return 0;
}


    