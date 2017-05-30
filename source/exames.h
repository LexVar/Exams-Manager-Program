#ifndef EXAMES_H
#define EXAMES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "disciplinas.h"
#include "data.h"
#include "alunos_ptr.h"

void copy_exame(Exame *v1, Exame *v2);
int exame_compare(Exame e1, Exame e2);
void imprime_exame(Exame v);
void imprime_listaExames(ListExames lista);
ListExames procura_exame(ListExames lista, Exame e);
void procura_exame1(ListExames lista, Exame x, ListExames *ant, ListExames *atual);
ListExames insere_ordem_exames(ListExames lista, Exame x);
ListExames elimina_exame_lista(ListExames lista, Exame x);
ListExames destroi_listaExames(ListExames lista);
ListExames exame_return(ListExames exames, int n);
void escreve_exame(Exame v, FILE *f);
void escreve_listaExames(ListExames lista, char *ficheiro);


#endif 