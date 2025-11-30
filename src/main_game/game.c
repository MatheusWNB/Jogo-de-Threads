#include "libs.h"
#include "ataques_e_defesas.h"
#include "jogador_1.h"

int main (){
    //Ataque escolhido
    int ataque_escolhido;

    //Inimigo provisório
    double vida_inimigo = 100;
    double vida_inimigo_anterior = vida_inimigo;

    //Inicializa ataques e defesas
    ataques_e_defesas escolha_ataques_e_defesas;
    func_ataques_e_defesas(&escolha_ataques_e_defesas);

    //Inicializa jogador 1
    info_jogador_1 info_jogador_1;
    func_info_jogador_1(&info_jogador_1);

    //Usuário escolhe qual ataque usar
    ataque_escolhido = escolha_ataque_jogador_1(&escolha_ataques_e_defesas);

    //Jogador 1 faz o ataque e da dano ao inimigo
    vida_inimigo = ataque_jogador_1(&escolha_ataques_e_defesas, vida_inimigo, ataque_escolhido);

    printf(
        "Atacante: %s\n"
        "Ataque escolhido: Ataque básico %d\n"
        "Dano ao inimigo: %0.2f\n"
        "Vida inimigo: %0.2f -> %0.2f\n",
        info_jogador_1.nome_jogador_1, ataque_escolhido, 
        escolha_ataques_e_defesas.ataques_basicos, vida_inimigo_anterior, vida_inimigo
    );

    return 0;
}