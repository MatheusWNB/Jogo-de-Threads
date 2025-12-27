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
#include "actions/vantagens_jogador.h"

#define THREADS_PRINCIPAIS 2

//DECLARAÇÕES
//Declaração das threads principais do jogo
typedef enum{
    THREAD_JOGADOR,
    THREAD_INIMIGO
} def_thread;

//Declaração das informações referentes ao controle do jogo e da rodada
typedef struct{
    int rodada_atual;
    int trava_ataque;
    int finalizar_rodada;
} dados_rodada;

typedef struct{
    vantagens_jogador 
}

//Declaração dos dados referentes ao jogador e do inimigo
typedef struct{
    pthread_mutex_t mutex;
    info_inimigo_1 info_inmg1;
    atq_def_inimigo_1 escolha_atq_def_inmg1;
    info_jogador_1 info_jogador_1;
    ataques_e_defesas escolha_ataques_e_defesas;
} dados_threads;

//Declaração dos dados que serão utilizados pelas threads principais
typedef struct {
    int thread_id;
    dados_threads *args_t;
    def_thread t_principais;
    dados_rodada *args_rodada;
} struct_threads;

//Função principal que gerencia as funções que cada thread receberá
void *gerenciar_threads (void *arg){
    struct_threads *args = (struct_threads *)arg;

    //Thread do jogador
    if (args->t_principais == THREAD_JOGADOR){
        while (true){

            pthread_mutex_lock(&args->args_t->mutex);
            
            if (args->args_rodada->finalizar_rodada == true)
            break;
            
            //Se "trava_ataque" for "true", a thread do jogador libera a vez para a thread do inimigo
            if (args->args_rodada->trava_ataque == true){
                pthread_mutex_unlock(&args->args_t->mutex);
                continue;
            }
            
            system("clear");
            printf("RODADA %d\n           SUA VEZ DE JOGAR!          \n\n", args->args_rodada->rodada_atual);
            
            // Realiza a jogada do usuário
            acao_do_jgdr(&args->args_t->info_jogador_1, &args->args_t->info_inmg1, &args->args_t->escolha_ataques_e_defesas);
            
            // Libera o ataque para o inimigo
            pthread_mutex_unlock(&args->args_t->mutex);
            args->args_rodada->trava_ataque = true;
        }
            
    //Thread do Inimigo
    } else if (args->t_principais == THREAD_INIMIGO){
        while (true){
            pthread_mutex_lock(&args->args_t->mutex);

            //Se "trava_ataque" for "false", a thread do inimigo libera a vez para a thread do jogador
            if (args->args_rodada->trava_ataque == false){
                pthread_mutex_unlock(&args->args_t->mutex);
                continue;
            }
            
            // Realiza a jogada do inimigo 1
            acao_do_inmg1(&args->args_t->info_jogador_1, &args->args_t->info_inmg1, &args->args_t->escolha_atq_def_inmg1);
            
            printf("Aperte 'ENTER' para ir para a próxima rodada\n");
            getchar();
            getchar();

            //Finaliza o jogo se a vida do inimigo ou jogador for igual ou menor que zero
            if (args->args_t->info_inmg1.vida <= 0 || args->args_t->info_jogador_1.vida <= 0){
                pthread_mutex_unlock(&args->args_t->mutex);
                pthread_mutex_destroy(&args->args_t->mutex);
                args->args_rodada->finalizar_rodada = true;
                break;
            }
            
            args->args_rodada->rodada_atual += 1;
            
            //Libera o ataque para o jogador 
            pthread_mutex_unlock(&args->args_t->mutex);
            args->args_rodada->trava_ataque = false;
        }   
    }

    pthread_exit(NULL);
}
    
int main(){
    srand(time(NULL));
    vantagens_jogador args_vantagens_jgdr;

    struct_threads struct_t[2];
    dados_threads dados_t; //Inicialização dos dados referentes ao inimigo e jogador na struct
    dados_rodada args_rodada_atual; //Inicializa dados da rodada
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

    //Inicializa vantagens do jogador

    //Inicializa dados referentes ao controle do jogo e da rodada
    args_rodada_atual.trava_ataque = false;
    args_rodada_atual.rodada_atual = 1;
    args_rodada_atual.finalizar_rodada = false;

    //Inicialização da identificação das threads na struct "struct_t"
    struct_t[0].args_t = &dados_t;
    struct_t[0].t_principais = THREAD_JOGADOR;
    struct_t[0].thread_id = 0;
    struct_t[0].args_rodada = &args_rodada_atual;

    struct_t[1].args_t = &dados_t;
    struct_t[1].t_principais = THREAD_INIMIGO;
    struct_t[1].thread_id = 1;
    struct_t[1].args_rodada = &args_rodada_atual;

    int status, i;
    pthread_t threads[THREADS_PRINCIPAIS];

    //Inicializa as duas threads principais do jogador e do inimigo 1
    for (i = 0; i < THREADS_PRINCIPAIS; i++){
        status = pthread_create(
            &threads[i],
            NULL,
            gerenciar_threads,
            (void *)&struct_t[i]
        );

        //Se a inicialização da thread falhou retorna código de erro
        if (status != 0){
            printf("Thread retornou código de erro\n");
            exit(-1);
        } 
    }

    //Uma thread finalizada espera as threads restantes finalizarem
    for(i = 0; i < THREADS_PRINCIPAIS; i++)
        pthread_join(threads[i], NULL);

    //Chama a função que mostra a tela de fim de jogo com o vencedor
    info_vencedor(&dados_t.info_jogador_1, &dados_t.info_inmg1);
    
    return 0;
}
