#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int data_compare(Data d1, Data d2);
void data_scan(Data *p);
void copy_data(Data *d1, Data *d2);
void imprime_data(Data p);
void escreve_data(Data p, FILE *f);
int verifica_sobreposicao(Data d1, int dur1, Data d2, int dur2);


#endif