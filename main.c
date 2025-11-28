#include "libs.h"
#include "ataques.h"

int main (){
    ataque_basico ataques;
    definir_ataques(&ataques);
    printf("%0.2f\n", ataques.ataque_basico1);
    printf("%0.2f\n", ataques.ataque_basico2);

    return 0;
}


    