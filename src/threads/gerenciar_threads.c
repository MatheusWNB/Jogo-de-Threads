#include "threads/gerar_thread.h"
#include "libs/libs_inimigo.h"
#include "libs/libs_jogador_1.h"
#include "actions/atq_def_inimigo_1.h"
#include "threads/gerenciar_threads.h"
#include "infos/jogador_1.h"
#include "stdbool.h"
#include "libs/libs.h"

pthread_mutex_t mutex_1;

void *gerenciar_threads (void *arg){
    pthread_mutex_init(&mutex_1, 0);

    int ataque_liberado_inimigo = false;
    int rodada_terminada = false;
    int fim_de_jogo = false;

    int atq_inmg1;
    int atq_jogador1;

    double vida_anterior_inmg1;

    //INIMIGO 1:
    //Inicializa inimigo 1
    info_inimigo_1 info_inmg1;
    func_info_inimigo_1(&info_inmg1);
        
    //Inicializa ataques e defesas do inimigo 1
    atq_def_inimigo_1 escolha_atq_def_inmg1;
    func_atq_def_inimigo_1(&escolha_atq_def_inmg1);

    //JOGADOR 1:
    //Inicializa jogador 1
    info_jogador_1 info_jogador_1;
    func_info_jogador_1(&info_jogador_1);

    //Inicializa ataques e defesas
    ataques_e_defesas escolha_ataques_e_defesas;
    func_ataques_e_defesas(&escolha_ataques_e_defesas);

    
    int rodada_atual = 1;
    int laco1 = true;
    int laco2 = true;
    //int laco3 = true;

    int tid = (int)(intptr_t)arg;
    //Thread do jogador
    if (tid == 0){
        while (laco1){
            pthread_mutex_lock(&mutex_1);
            if (info_inmg1.vida > 0){
                    
                if (ataque_liberado_inimigo == true){
                    pthread_mutex_unlock(&mutex_1);
                    continue;
                }
            }

            system("clear");
            
            //Usuário escolhe qual ataque usar
            printf("RODADA %d\n           SUA VEZ DE JOGAR!          \n\n", rodada_atual);
            atq_jogador1 = escolha_ataque_jogador_1(&escolha_ataques_e_defesas);//Escolha de ataque do jogador
            putchar('\n');

            double vida_anterior_inmg1 = info_inmg1.vida;
            info_inmg1.vida -= escolha_ataques_e_defesas.ataques_basicos[atq_jogador1]; //Reduz a vida do inimigo

            //Mostra as informações da jogada do jogador 1
            info_rodada_atual_jgdr1(&info_jogador_1, &info_inmg1, &escolha_ataques_e_defesas, 
                                    atq_jogador1, vida_anterior_inmg1);

            ataque_liberado_inimigo == true;
            pthread_mutex_unlock(&mutex_1);
        }

    }

    //Thread do inimigo
    if (tid == 1){
        while (laco2){
            pthread_mutex_lock(&mutex_1);

            if (ataque_liberado_inimigo == false){
                pthread_mutex_unlock(&mutex_1);
                continue;
            }

            atq_inmg1 = escolha_ataque_inimigo_1(&escolha_atq_def_inmg1); //Escolha de ataque aleatório do inimigo 1
            info_jogador_1.vida -= escolha_atq_def_inmg1.ataques_basicos[atq_inmg1]; //Reduz a vida do jogador 1

            //Mostra as informações da jogada do inimigo
            sleep(1.0);
            info_rodada_atual_inmg1(&info_jogador_1, &info_inmg1, 
                                        &escolha_atq_def_inmg1, atq_inmg1);

            rodada_terminada = true;
            pthread_mutex_unlock(&mutex_1);
        }   
    }
        // if (tid == 2){
        //     //pthread_mutex_lock(&mutex_1);

        //     if (info_jogador_1.vida <= 0 || info_inmg1.vida <= 0){
        //         system("clear");
        //         if (info_jogador_1.vida > info_inmg1.vida)
        //         printf("VOCÊ GANHOU O JOGO, %s FOI DERROTADO\n", info_inmg1.nome);
        //         else 
        //         printf("VOCÊ PERDEU O JOGO SEU FRACASSADO %s VENCEU!\n", info_inmg1.nome);
                
        //         fim_de_jogo = true;
        //         pthread_mutex_destroy(&mutex_1);
        //         break;
        //     }

        //     if (rodada_terminada == true){
        //         putchar('\n');
        //         rodada_atual += 1;
        //         printf("Aperte 'ENTER' para ir para a próxima rodada\n");
        //         getchar();
        //         getchar();
        //         rodada_atual += 1;
        //     } else {
        //         pthread_mutex_unlock(&mutex_1);
        //     }
                

        // }

    pthread_exit(NULL);

}