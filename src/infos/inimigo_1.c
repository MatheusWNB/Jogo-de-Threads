#include "libs.h"
#include "inimigo_1.h"
#include <string.h>

void func_info_inimigo_1(info_inimigo_1 *ptr_info_inimigo_1) {
    
    strcpy(ptr_info_inimigo_1 -> nome, "Nine fingers");
    ptr_info_inimigo_1 -> vida = 200;
    ptr_info_inimigo_1 -> resistência = 100;

}