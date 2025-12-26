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
double action_regenerar_vida (double *regenerar_vida, double vida){
    system("clear");
    printf("Você recebeu uma runa da vida! Deseja aceita-la? (s/n)\n");

    char resposta[1];
    scanf("%c", resposta);

    while (true){
        if (resposta == 's' || resposta == 'S'){
            int indice = 0 + rand() % 4;

            double porcentagem = regenerar_vida[indice] / 100;
            double resultado = vida * porcentagem;

            //Retorna a vida atual do jogador mais a porcentagem da vida atual
            return (vida) + resultado;

        } else if (resposta == 'n' || resposta == 'N'){
            return vida;
            
        } else {
            system("clear");
            printf("Por favor, digite uma opção válida! (s/n)\n");

        }
    }
}


