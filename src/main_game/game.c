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

//Declaração das vantagens do jogador
typedef struct{
    vantagens_jgdr regenerar_vida;
} dados_vantagens;

//Declaração dos dados do jogador e do inimigo
typedef struct{
    pthread_mutex_t mutex;
    info_inimigo info_inmg;
    inmg_atqs_defs atq_def_inmg;
    info_jogador info_jogador;
    jgdr_atqs_defs atq_def_jgdr;
} dados_jogadores;

//Declaração dos dados que serão utilizados pelas threads principais
typedef struct {
    int thread_id;
    dados_jogadores *args_jogadores;
    dados_vantagens *args_vantagens;
    def_thread threads_principais;
    dados_rodada *args_rodada;
} dados_threads;

//Função principal que gerencia as funções que cada thread receberá
void *gerenciar_threads (void *arg){
    dados_threads *args = (dados_threads *)arg;

    //Thread do jogador
    if (args->threads_principais == THREAD_JOGADOR){
        while (true){

            pthread_mutex_lock(&args->args_jogadores->mutex);
            
            if (args->args_rodada->finalizar_rodada == true)
            break;
            
            //Se "trava_ataque" for "true", a thread do jogador libera a vez para a thread do inimigo
            if (args->args_rodada->trava_ataque == true){
                pthread_mutex_unlock(&args->args_jogadores->mutex);
                continue;
            }
            
            system("clear");
            printf("RODADA %d\n           SUA VEZ DE JOGAR!          \n\n", args->args_rodada->rodada_atual);
            
            // Realiza a jogada do usuário
            acao_jgdr(&args->args_jogadores->info_jogador, &args->args_jogadores->info_inmg, 
                        &args->args_jogadores->atq_def_jgdr, 
                        &args->args_vantagens->regenerar_vida, &args->args_rodada->rodada_atual);

            
            //Finaliza o jogo se a vida do inimigo ou jogador for igual ou menor que zero
            if (args->args_jogadores->info_inmg.vida <= 0 || args->args_jogadores->info_jogador.vida <= 0){
                pthread_mutex_unlock(&args->args_jogadores->mutex);
                pthread_mutex_destroy(&args->args_jogadores->mutex);
                args->args_rodada->finalizar_rodada = true;
                break;
            }
            
            // Libera o ataque para o inimigo
            pthread_mutex_unlock(&args->args_jogadores->mutex);
            args->args_rodada->trava_ataque = true;
        }
            
    //Thread do inimigo
    } else if (args->threads_principais == THREAD_INIMIGO){
        while (true){
            pthread_mutex_lock(&args->args_jogadores->mutex);

            if(args->args_rodada->finalizar_rodada == true)
                break;
                
            //Se "trava_ataque" for "false", a thread do inimigo libera a vez para a thread do jogador
            if (args->args_rodada->trava_ataque == false){
                pthread_mutex_unlock(&args->args_jogadores->mutex);
                continue;
            }
            
            // Realiza a jogada do inimigo 
            acao_inmg(&args->args_jogadores->info_jogador, &args->args_jogadores->info_inmg, 
                            &args->args_jogadores->atq_def_inmg);
            
            printf("Aperte 'ENTER' para ir para a próxima rodada\n");
            getchar();
            getchar();

            //Finaliza o jogo se a vida do inimigo ou jogador for igual ou menor que zero
            if (args->args_jogadores->info_inmg.vida <= 0 || args->args_jogadores->info_jogador.vida <= 0){
                pthread_mutex_unlock(&args->args_jogadores->mutex);
                pthread_mutex_destroy(&args->args_jogadores->mutex);
                args->args_rodada->finalizar_rodada = true;
                break;
            }
            
            args->args_rodada->rodada_atual += 1;
            
            //Libera o ataque para o jogador 
            pthread_mutex_unlock(&args->args_jogadores->mutex);
            args->args_rodada->trava_ataque = false;
        }   
    }
                                            
    pthread_exit(NULL);
}
    
int main(){
    srand(time(NULL));
    dados_threads args_threads[2];
    dados_vantagens args_vantagens; //Inicializa vantagens do jogador
    dados_jogadores args_jogadores; //Inicializa dados referentes ao inimigo e jogador 
    dados_rodada args_rodada_atual; //Inicializa dados da rodada

    pthread_mutex_init(&args_jogadores.mutex, 0);//Inicializa o mutex

    //INIMIGO:
    //Inicializa inimigo 
    init_info_inimigo(&args_jogadores.info_inmg);

    //Inicializa ataques e defesas do inimigo 
    init_inmg_atq_def(&args_jogadores.atq_def_inmg);
        
    //JOGADOR:
    //Inicializa jogador 
    init_info_jogador(&args_jogadores.info_jogador);
            
    //Inicializa ataques e defesas do jogador 
    init_jgdr_atq_def(&args_jogadores.atq_def_jgdr);

    //Inicializa vantagens do jogador
    init_vantagens_jogador(&args_vantagens.regenerar_vida);

    //Inicializa dados referentes ao controle do jogo e da rodada
    args_rodada_atual.trava_ataque = false;
    args_rodada_atual.rodada_atual = 0;
    args_rodada_atual.finalizar_rodada = false;

    //Inicialização da identificação das threads 
    args_threads[0].args_jogadores = &args_jogadores;
    args_threads[0].threads_principais = THREAD_JOGADOR;
    args_threads[0].thread_id = 0;
    args_threads[0].args_rodada = &args_rodada_atual;
    args_threads[0].args_vantagens = &args_vantagens;

    args_threads[1].args_jogadores = &args_jogadores;
    args_threads[1].threads_principais = THREAD_INIMIGO;
    args_threads[1].thread_id = 1;
    args_threads[1].args_rodada = &args_rodada_atual;

    int status, i;
    pthread_t threads[THREADS_PRINCIPAIS];

    //Inicializa as duas threads principais do jogador e do inimigo 1
    for (i = 0; i < THREADS_PRINCIPAIS; i++){
        status = pthread_create(
            &threads[i],
            NULL,
            gerenciar_threads,
            (void *)&args_threads[i]
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
    info_vencedor(&args_jogadores.info_jogador, &args_jogadores.info_inmg);
    
    return 0;
}
