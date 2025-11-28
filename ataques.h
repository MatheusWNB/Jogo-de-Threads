#ifndef STRUCT_ATAQUES_H
#define STRUCT_ATAQUES_H

typedef struct {
    double ataque_basico1;
    double ataque_basico2;
} ataque_basico;

void definir_ataques (ataque_basico *ptr_ataques);

#endif