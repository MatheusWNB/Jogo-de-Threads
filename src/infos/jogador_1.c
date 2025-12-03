#include "libs/libs.h"
#include "infos/jogador_1.h"
#include <string.h>

//Inicializa as informações do jogador 1
void func_info_jogador_1(info_jogador_1 *ptr_info_jogador_1){

    strcpy(ptr_info_jogador_1->nome_jogador_1, "Matheus");
    ptr_info_jogador_1 -> vida = 100;
    ptr_info_jogador_1 -> resistencia = 100;

}

//Função para o usuário digitar a sua opção de ataque
int escolha_ataque_jogador_1(ataques_e_defesas *ptr_ataques_e_defesas){
    int laco = true;
    int escolha_ataque;

    while(laco){

        printf(
            "Escolha seu ataque: \n"
            "Ataque básico 0 (dano: %0.2f). Pode ser usado toda rodada\n"
            "Ataque básico 1 (dano: %0.2f). Pode ser usado a cada 2 rodadas\n", 
            ptr_ataques_e_defesas->ataques_basicos[0], ptr_ataques_e_defesas->ataques_basicos[1]);

        scanf("%d", &escolha_ataque);

        //Verifica se a opção digitada está fora das opções disponíveis
        if (escolha_ataque < 0 || escolha_ataque > 1){
            system("clear");
            printf("Por favor, digite uma opção válida.\n");
            continue;

        } else if (escolha_ataque == 0 || escolha_ataque == 1) {
            laco = false;

        } else {
            printf("Não era pra entrar aqui :)\n");
        }
    }

    return escolha_ataque;

}
