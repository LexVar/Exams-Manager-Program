#include "alunos_ptr.h"
#include "alunos.h"

ListPtrAlunos find_alunoPtr(ListPtrAlunos lista, Aluno al)
{
    ListPtrAlunos aux;
    aux = lista;

    while(aux != NULL && aluno_compare(al, *(aux->info)) != 1)
        aux = aux->next;
    if(aux != NULL)
        return aux;
    return NULL;
}

int ListPtrAlunos_tamanho(ListPtrAlunos lista)
{
    ListPtrAlunos aux;
    int i;
    i = 0;
    aux = lista;
    while(aux != NULL)
    {
        i++;
        aux = aux->next;
    }
    return i;
}

ListPtrAlunos destroi_listaPtrAlunos(ListPtrAlunos lista)
{
    ListPtrAlunos p;
    if(lista != NULL)
    {
        while(lista->next != NULL)
        {
            p = lista;
            lista = lista->next;
            free(p);
        }
        free(lista);
    }
    return NULL;
}

ListPtrAlunos insere_fim_listaPtrAlunos(ListPtrAlunos lista, Aluno *c)
{
    ListPtrAlunos p, aux;
    p = (ListPtrAlunos)malloc(sizeof(aluno_ptr_node));
    aux = lista;
    if(p != NULL)
    {
        p->info = c;
        p->next = NULL;
        if(aux == NULL)
            return p;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = p;
    }
    return lista;
}

void imprime_listaPtrAlunos(ListPtrAlunos lista)
{
    ListPtrAlunos p;
    p = lista;
    while(p != NULL)
    {
        imprime_aluno(*p->info);
        p = p->next;
    }
    printf("\n");
}

ListPtrAlunos elimina_PtrAluno(ListPtrAlunos lista, Aluno c)
{
    ListPtrAlunos aux, ant;
    aux = lista;
    ant = NULL;
    while(aux != NULL && aluno_compare(c, *(aux->info)) != 1)
    {
        ant = aux;
        aux = aux->next;
    }
    if(aux != NULL && lista == aux)
    {
        ant = aux->next;
        free(aux);
        return ant;
    }
    else if(aux != NULL && ant != NULL)
    {
        ant->next = aux->next;
        free(aux);
    }
    return lista;
}