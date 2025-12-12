#include "libs/libs.h"
#include "actions/ataques_e_defesas.h"
#include "infos/jogador_1.h"
#include "actions/atq_def_inimigo_1.h"
#include "infos/inimigo_1.h"
#include <time.h>
#include "infos/info_rodada_atual.h"
#include <pthread.h>
#include <stdint.h>
#include "actions/acao_inmg1.h"
#include "actions/acao_jgdr.h"

#define THREADS_PRINCIPAIS 2

// typedef struct {
//     pthread_mutex_t mutex;
//     info_inimigo_1 info_inmg1;
//     atq_def_inimigo_1 escolha_atq_def_inmg1;
//     info_jogador_1 info_jogador_1;
//     ataques_e_defesas escolha_ataques_e_defesas;
// } vars;

typedef struct {
    int thread_id[2];
    // vars *s;
    pthread_mutex_t mutex;
    info_inimigo_1 info_inmg1;
    atq_def_inimigo_1 escolha_atq_def_inmg1;
    info_jogador_1 info_jogador_1;
    ataques_e_defesas escolha_ataques_e_defesas;
} struct_t;

void *gerenciar_threads (void *arg){

    // pthread_mutex_init(&mutex, 0);

    
    //Verifica se o inimigo pode atacar
    int ataque_liberado_inimigo = false;
    int *ptr_ataque_liberado_inimigo = &ataque_liberado_inimigo;
    
    //Verifica se a rodada atual finalizou
    int rodada_terminada = false;
    int *ptr_rodada_terminada = &rodada_terminada;
    
    int rodada_atual = 1;
    struct_t *args = (struct_t *)arg;
     //O identificador da thread
    int thread_id = 

    //Thread do jogador
    if (args->thread_id == 0){
        while (true){
            pthread_mutex_lock(&args->mutex);
            printf("entrei 1\n");
            pthread_mutex_unlock(&args->mutex);
            // pthread_mutex_lock(&mutex);
            
            // if (info_inmg->vida > 0){
            //     if (*ptr_ataque_liberado_inimigo == true){
            //         pthread_mutex_unlock(&mutex);
            //         continue;
            //     }
            // }
            
            //system("clear");
            // printf("RODADA %d\n           SUA VEZ DE JOGAR!          \n\n", rodada_atual);

            //Realiza a jogada do usuário
            // acao_do_jgdr(info_jgdr, info_inmg, escolha_jgdr);

            //Libera o ataque para o inimigo
            // *ptr_ataque_liberado_inimigo = true;
            // pthread_mutex_unlock(&mutex);
            // printf("%d", *ptr_ataque_liberado_inimigo);
        }
            
    //Thread do Inimigo
    } else if (args->thread_id == 1){
        while (true){
            // pthread_mutex_lock(&mutex);
            pthread_mutex_lock(&args->mutex);
            printf("entrei 1\n");
            pthread_mutex_unlock(&args->mutex);
                
            printf("oi");
            // if (*ptr_ataque_liberado_inimigo == false){
            //     pthread_mutex_unlock(&mutex);
            //     continue;
            // }

            //Realiza a jogada do inimigo 1
            // acao_do_inmg1(info_jgdr, info_inmg, escolha_inmg); 
                
            //Indica o fim da rodada atual
            // *ptr_rodada_terminada = true;
            // pthread_mutex_unlock(&mutex);
        }   
    }

    pthread_exit(NULL);
}
    
int main(){
    //Inicialização dos dados referentes ao inimigo e jogador na struct vars_players
    // vars vars_players;
    struct_t struct_thr;
    pthread_mutex_init(&struct_thr.mutex, 0);
    //INIMIGO 1:
    //Inicializa inimigo 1
    func_info_inimigo_1(&struct_thr.info_inmg1);

    //Inicializa ataques e defesas do inimigo 1
    func_atq_def_inimigo_1(&struct_thr.escolha_atq_def_inmg1);
        
    //JOGADOR 1:
    //Inicializa jogador 1
    func_info_jogador_1(&struct_thr.info_jogador_1);
            
    //Inicializa ataques e defesas
    func_ataques_e_defesas(&struct_thr.escolha_ataques_e_defesas);
    
    int status, i;

    // struct_thr.s = &vars_players;
    
    pthread_t threads[THREADS_PRINCIPAIS];
    
    for (i = 0; i < THREADS_PRINCIPAIS; i++){
        
        struct_thr.thread_id[i] = i;
        
        status = pthread_create(
            &threads[i],
            NULL,
            gerenciar_threads,
            (void *)&struct_thr
        );

        if (status != 0){
            printf("Thread retornou código de erro\n");
            exit(-1);
        } 
    }

    for(i = 0; i < THREADS_PRINCIPAIS; i++)
        pthread_join(threads[i], NULL);
    
    return 0;
}
