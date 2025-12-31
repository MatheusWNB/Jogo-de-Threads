#include "libs/libs.h"
#include "actions/atq_def_inimigo_1.h"

void init_inmg_atq_def (inmg_atqs_defs *arg_atq_def){
    //Define os ataques do inimigo
    arg_atq_def -> atqs_basicos[0] = 5.0;
    arg_atq_def -> atqs_basicos[1] = 12.50;
    arg_atq_def -> atqs_basicos[2] = 18.50;

    //Define as defesas do inimigo
    arg_atq_def -> defs_basicas[0] = 50;
    arg_atq_def -> defs_basicas[1] = 85;
}