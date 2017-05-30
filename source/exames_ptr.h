#ifndef EXAMES_PTR_H
#define EXAMES_PTR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "exames.h"


ListPtrExames find_examePtr(ListPtrExames lista, Exame al);
int ListPtrExames_tamanho(ListPtrExames lista);
ListPtrExames destroi_listaPtrExames(ListPtrExames lista);
ListPtrExames insere_fim_listaPtrExames(ListPtrExames lista, Exame *c);
void imprime_listaPtrExames(ListPtrExames lista);
void escreve_listaPtrExames(ListPtrExames lista, char *ficheiro);
ListPtrExames elimina_PtrExame(ListPtrExames lista, Exame c);

#endif 