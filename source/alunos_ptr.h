#ifndef ALUNOS_PTR_H
#define ALUNOS_PTR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


ListPtrAlunos find_alunoPtr(ListPtrAlunos lista, Aluno al);
int ListPtrAlunos_tamanho(ListPtrAlunos lista);
ListPtrAlunos destroi_listaPtrAlunos(ListPtrAlunos lista);
ListPtrAlunos insere_fim_listaPtrAlunos(ListPtrAlunos lista, Aluno *c);
void imprime_listaPtrAlunos(ListPtrAlunos lista);
ListPtrAlunos elimina_PtrAluno(ListPtrAlunos lista, Aluno c);

#endif 