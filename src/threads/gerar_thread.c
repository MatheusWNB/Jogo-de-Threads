#include "threads/gerar_thread.h"
#include "libs/libs.h"

void gerar_thread(){
    
    #define THREADS_PRINCIPAIS 2

    int status, i;
    pthread_t threads[THREADS_PRINCIPAIS];

    for (i = 0; i < THREADS_PRINCIPAIS; i++){
        status = pthread_create(
            &threads[i],
            NULL,
            gerenciar_threads,
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

}
