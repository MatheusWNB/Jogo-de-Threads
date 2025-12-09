#include "libs/libs.h"
#include "actions/ataques_e_defesas.h"
#include "infos/jogador_1.h"
#include "actions/atq_def_inimigo_1.h"
#include "infos/inimigo_1.h"
#include <time.h>
#include "infos/info_rodada_atual.h"
#include <pthread.h>
#include <stdint.h>



pthread_mutex_t mutex_1;
#define THREADS_PRINCIPAIS 2

void *gerenciar_threads (void *arg, info_jogador_1 *info_jgdr, info_inimigo_1 *info_inmg, 
                        ataques_e_defesas *escolha_jgdr, atq_def_inimigo_1 *escolha_inmg, int *liberar_ataque, int *fim_rodada){

    pthread_mutex_init(&mutex_1, 0);
    
    
    int atq_inmg1;
    int atq_jogador1;
    
    double vida_anterior_inmg1;
    
    int rodada_atual = 1;
    int tid = (int)(intptr_t)arg;
    
    //Thread do jogador
    if (tid == 0){
        int laco1 = true;
        while (laco1){
            pthread_mutex_lock(&mutex_1);
            if (info_inmg->vida > 0){
                if (*liberar_ataque == true){
                    pthread_mutex_unlock(&mutex_1);
                    continue;
                }
            }
            
            system("clear");
            
            //Usuário escolhe qual ataque usar
            printf("RODADA %d\n           SUA VEZ DE JOGAR!          \n\n", rodada_atual);
            atq_jogador1 = escolha_ataque_jogador_1(escolha_jgdr);//Escolha de ataque do jogador
            putchar('\n');
            
            vida_anterior_inmg1 = info_inmg->vida;
            info_inmg->vida -= escolha_jgdr->ataques_basicos[atq_jogador1]; //Reduz a vida do inimigo
            
            //Mostra as informações da jogada do jogador 1
            info_rodada_atual_jgdr1(info_jgdr, info_inmg, escolha_jgdr, 
                atq_jogador1, vida_anterior_inmg1);
                
            *liberar_ataque = true;
            pthread_mutex_unlock(&mutex_1);
        }
            
    }
        
    //Thread do inimigo
    if (tid == 1){
        int laco2 = true;
        while (laco2){
            pthread_mutex_lock(&mutex_1);
                
            printf("oi");
            if (*liberar_ataque == false){
                pthread_mutex_unlock(&mutex_1);
            }
                
            atq_inmg1 = escolha_ataque_inimigo_1(escolha_inmg); //Escolha de ataque aleatório do inimigo 1
            info_jgdr->vida -= escolha_inmg->ataques_basicos[atq_inmg1]; //Reduz a vida do jogador 1
                
            //Mostra as informações da jogada do inimigo
            sleep(1.0);
            info_rodada_atual_inmg1(info_jgdr, info_inmg, escolha_inmg, atq_inmg1);
                
            *fim_rodada = true;
            pthread_mutex_unlock(&mutex_1);
        }   
    }
}
    
int main (){
    int ataque_liberado_inimigo = true;
    int *ptr_ataque_liberado_inimigo = &ataque_liberado_inimigo;
        
    int rodada_terminada = false;
    int *ptr_rodada_terminada = &rodada_terminada;

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
            
            
    int status, i;
    pthread_t threads[THREADS_PRINCIPAIS];
            
    for (i = 0; i < THREADS_PRINCIPAIS; i++){
        status = pthread_create(
            &threads[i],
            NULL,
            gerenciar_threads((void *)(intptr_t)i, &info_jogador_1, &info_inmg1, &escolha_ataques_e_defesas, &escolha_atq_def_inmg1,
                                ptr_ataque_liberado_inimigo, ptr_rodada_terminada),
            (void *)(intptr_t)i
        );

        if (status != 0){
            printf("Thread retornou código de erro\n");
            exit(-1);
        } 
    }

    for(i = 0; i < THREADS_PRINCIPAIS; i++){
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}
