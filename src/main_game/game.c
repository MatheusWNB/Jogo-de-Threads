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

typedef enum{
    THREAD_JOGADOR,
    THREAD_INIMIGO
} def_thread;

typedef struct{
    pthread_mutex_t mutex;
    info_inimigo_1 info_inmg1;
    atq_def_inimigo_1 escolha_atq_def_inmg1;
    info_jogador_1 info_jogador_1;
    ataques_e_defesas escolha_ataques_e_defesas;
    int ataque_liberado;
} dados_threads;

typedef struct {
    int thread_id;
    dados_threads *args_t;
    def_thread t_principais;
} struct_threads;

void *gerenciar_threads (void *arg){
    struct_threads *args = (struct_threads *)arg;

    int rodada_atual = 1;

    //Thread do jogador
    if (args->t_principais == THREAD_JOGADOR){
        while (true){
            pthread_mutex_lock(&args->args_t->mutex);
 
            if (args->args_t->ataque_liberado == true){
                pthread_mutex_unlock(&args->args_t->mutex);
                continue;
            }

            system("clear");
            printf("RODADA %d\n           SUA VEZ DE JOGAR!          \n\n", rodada_atual);

            // Realiza a jogada do usuário
            acao_do_jgdr(&args->args_t->info_jogador_1, &args->args_t->info_inmg1, &args->args_t->escolha_ataques_e_defesas);

            if (args->args_t->info_inmg1.vida <= 0 || args->args_t->info_jogador_1.vida <= 0)
                break;

            // Libera o ataque para o inimigo
            pthread_mutex_unlock(&args->args_t->mutex);
            args->args_t->ataque_liberado = true;
            //break;
        }
            
    //Thread do Inimigo
    } else if (args->t_principais == THREAD_INIMIGO){
        while (true){
            pthread_mutex_lock(&args->args_t->mutex);
            if (args->args_t->ataque_liberado == false){
                pthread_mutex_unlock(&args->args_t->mutex);
                continue;
            }
            
            // Realiza a jogada do inimigo 1
            acao_do_inmg1(&args->args_t->info_jogador_1, &args->args_t->info_inmg1, &args->args_t->escolha_atq_def_inmg1);
            
            printf("Aperte 'ENTER' para ir para a próxima rodada\n");
            getchar();
            getchar();
            
            if (args->args_t->info_inmg1.vida <= 0 || args->args_t->info_jogador_1.vida <= 0)
                break;

            pthread_mutex_unlock(&args->args_t->mutex);
            args->args_t->ataque_liberado = false;
            //break;
        }   
    }

    pthread_mutex_destroy(&args->args_t->mutex);
    pthread_exit(NULL);
}
    
int main(){
    struct_threads struct_t[2];
    dados_threads dados_t; //Inicialização dos dados referentes ao inimigo e jogador na struct 
    pthread_mutex_init(&dados_t.mutex, 0);
    //INIMIGO 1:
    //Inicializa inimigo 1
    func_info_inimigo_1(&dados_t.info_inmg1);

    //Inicializa ataques e defesas do inimigo 1
    func_atq_def_inimigo_1(&dados_t.escolha_atq_def_inmg1);
        
    //JOGADOR 1:
    //Inicializa jogador 1
    func_info_jogador_1(&dados_t.info_jogador_1);
            
    //Inicializa ataques e defesas do jogador 1
    func_ataques_e_defesas(&dados_t.escolha_ataques_e_defesas);

    dados_t.ataque_liberado = false;

    //Inicialização da identificação das threads na struct "struct_t"
    struct_t[0].args_t = &dados_t;
    struct_t[0].t_principais = THREAD_JOGADOR;
    struct_t[0].thread_id = 0;

    struct_t[1].args_t = &dados_t;
    struct_t[1].t_principais = THREAD_INIMIGO;
    struct_t[1].thread_id = 1;

    int status, i;
    pthread_t threads[THREADS_PRINCIPAIS];

    //Cria as duas threads principais do jogador e do inimigo
    for (i = 0; i < THREADS_PRINCIPAIS; i++){
        status = pthread_create(
            &threads[i],
            NULL,
            gerenciar_threads,
            (void *)&struct_t[i]
        );

        if (status != 0){
            printf("Thread retornou código de erro\n");
            exit(-1);
        } 
    }

    for(i = 0; i < THREADS_PRINCIPAIS; i++)
        pthread_join(threads[i], NULL);

    system("clear");
    if (dados_t.info_jogador_1.vida > dados_t.info_inmg1.vida)
        printf("VOCÊ GANHOU O JOGO, %s FOI DERROTADO\n", dados_t.info_inmg1.nome);
    else 
        printf("VOCÊ PERDEU O JOGO SEU FRACASSADO %s VENCEU!\n",dados_t.info_inmg1.nome);

    
    return 0;
}
