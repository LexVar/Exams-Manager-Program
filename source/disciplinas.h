#ifndef DISCIPLINAS_H
#define DISCIPLINAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


int disciplina_compare(Disciplina dc1, Disciplina dc2);
void imprime_disciplina(Disciplina dc);
void imprime_listaDisciplinas(ListDisciplinas lista);
ListDisciplinas destroi_listaDisciplinas(ListDisciplinas lista);
void copy_disciplina(Disciplina *dc1, Disciplina *dc2);
ListDisciplinas procura_disciplina(ListDisciplinas lista, Disciplina dc);
void procura_disciplina1(ListDisciplinas lista, Disciplina x, ListDisciplinas *ant, ListDisciplinas *atual);
ListDisciplinas insere_ordem_disciplinas(ListDisciplinas lista, Disciplina x);
ListDisciplinas elimina_disciplina_lista(ListDisciplinas lista, Disciplina x);
void escreve_disciplina(Disciplina dc, FILE *f);
void escreve_listaDisciplinas(ListDisciplinas lista, char *ficheiro);

#endif 