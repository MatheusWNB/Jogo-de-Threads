#include "libs/libs.h"
#include "actions/vantagens_jogador.h"
#include "infos/jogador_1.h"

//Define as vantagens do jogador
void init_vantagens_jogador (vantagens_jogador *args){
    //Vantagem para regenerar vida
    args->regenerar_vida[0] = 10;
    args->regenerar_vida[1] = 25;
    args->regenerar_vida[2] = 50;
    args->regenerar_vida[3] = 75;
}

//Regenera a vida do jogador com base em uma porcentagem aleatória
double action_regenerar_vida (vantagens_jogador *args_vantagens, info_jogador_1 *arg_vida){
    system("clear");
    printf("Você recebeu uma runa da vida! Deseja aceita-la? (0/1)\n");

    int resposta;
    scanf("%d", &resposta);

    while (true){
        printf("%0.2f\n", arg_vida->vida);
        if (resposta == 0){
            int tamanho = sizeof(args_vantagens->regenerar_vida) / sizeof(int);
            int indice = rand() % tamanho;

            double porcentagem = (double)args_vantagens->regenerar_vida[indice] / 100;
            printf("%0.2f\n", porcentagem);
            double resultado = arg_vida->vida * porcentagem;

            printf("%0.2f\n", resultado);

            //Retorna a vida atual do jogador mais a porcentagem da vida atual
            printf("%0.2f\n", arg_vida->vida + resultado);
            return  arg_vida->vida + resultado;

        } else if (resposta == 1){
            return arg_vida->vida;
            
        } else {
            system("clear");
            printf("Por favor, digite uma opção válida! (s/n)\n");

        }
    }
}


