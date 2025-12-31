#include "libs/libs.h"
#include "infos/jogador_1.h"
#include <string.h>

//Inicializa as informações do jogador 
void init_info_jogador(info_jogador *arg_info_jogador){

    strcpy(arg_info_jogador->nome, "Matheus");
    arg_info_jogador -> vida = 50;
    arg_info_jogador -> resistencia = 100;

}

//Função para o usuário digitar a sua opção de ataque
int escolha_atq_jogador(jgdr_atqs_defs *arg_atq_def){
    int laco = true;
    int escolha_ataque;

    while(laco){
        printf(
            "Escolha seu ataque: \n"
            "Ataque básico 0 (dano: %0.2f). Pode ser usado toda rodada\n"
            "Ataque básico 1 (dano: %0.2f). Pode ser usado a cada 2 rodadas\n", 
            arg_atq_def->atqs_basicos[0], arg_atq_def->atqs_basicos[1]);

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
