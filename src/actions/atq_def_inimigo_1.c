#include "libs/libs.h"
#include "actions/atq_def_inimigo_1.h"

void func_atq_def_inimigo_1 (atq_def_inimigo_1 *ptr_atq_def_inimigo_1){
    //Define os ataques do inimigo
    ptr_atq_def_inimigo_1 -> ataques_basicos[0] = 5.0;
    ptr_atq_def_inimigo_1 -> ataques_basicos[1] = 12.50;
    ptr_atq_def_inimigo_1 -> ataques_basicos[3] = 18.50;

    //Define as defesas do inimigo
    ptr_atq_def_inimigo_1 -> defesas_basicas[0] = 50;
    ptr_atq_def_inimigo_1 -> defesas_basicas[1] = 85;

}