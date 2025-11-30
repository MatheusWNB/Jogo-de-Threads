#include "libs.h"
#include "ataques_e_defesas.h"
#include "jogador_1.h"

int main (){
    //Inicializa ataques e defesas
    ataques_e_defesas escolha_ataques_e_defesas;
    func_ataques_e_defesas(&escolha_ataques_e_defesas);

    //Inicializa jogador 1
    info_jogador_1 inicializar_jogador_1;
    func_info_jogador_1(&inicializar_jogador_1);

    //Jogador 1
    printf("Nome jogador 1 %s\n", 
        inicializar_jogador_1.nome_jogador_1);

    printf("Vida %d\n", 
        inicializar_jogador_1.vida);

    printf("Resistência %d\n", 
        inicializar_jogador_1.resistencia);

    //Ataques e defesas
    printf("Escolhas %d %d\n", 
        escolha_ataques_e_defesas.escolha[0], escolha_ataques_e_defesas.escolha[1]);

    printf("Ataques %0.2f %0.2f\n", 
        escolha_ataques_e_defesas.ataques_basicos[0], escolha_ataques_e_defesas.ataques_basicos[1]);

    printf("Defesas %0.2f %0.2f\n", 
        escolha_ataques_e_defesas.defesas_basicas[0], escolha_ataques_e_defesas.defesas_basicas[1]);

    return 0;
}


    