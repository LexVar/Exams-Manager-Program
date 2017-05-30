#ifndef ALUNOS_H
#define ALUNOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "exames_ptr.h"

int aluno_compare(Aluno al1, Aluno al2);
void set_regime(Aluno *al, char * regime);
void imprime_aluno(Aluno al);
void imprime_listaAlunos(ListAlunos lista);
ListAlunos destroi_listaAlunos(ListAlunos lista);
void copy_aluno(Aluno *al1, Aluno *al2);
ListAlunos procura_aluno(ListAlunos lista, Aluno al);
ListAlunos elimina_aluno_lista(ListAlunos lista, Aluno x);
ListAlunos insere_ordem_alunos(ListAlunos lista, Aluno x);
void procura_aluno1(ListAlunos lista, Aluno x, ListAlunos *ant, ListAlunos *atual);
void escreve_alunos(Aluno al, FILE *f);
void escreve_listaAlunos(ListAlunos lista, char *ficheiro);

#endif 