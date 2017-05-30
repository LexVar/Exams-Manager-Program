#include "exames_ptr.h"

ListPtrExames find_examePtr(ListPtrExames lista, Exame al)
{
    ListPtrExames aux;
    aux = lista;

    while(aux != NULL && exame_compare(al, *(aux->info)) != 1)
        aux = aux->next;
    if(aux != NULL)
        return aux;
    return NULL;
}

int ListPtrExames_tamanho(ListPtrExames lista)
{
    ListPtrExames aux;
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

ListPtrExames destroi_listaPtrExames(ListPtrExames lista)
{
    ListPtrExames p;
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

ListPtrExames insere_fim_listaPtrExames(ListPtrExames lista, Exame *c)
{
    ListPtrExames p, aux;
    p = (ListPtrExames)malloc(sizeof(exame_ptr_node));
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

void imprime_listaPtrExames(ListPtrExames lista)
{
    ListPtrExames p;
    p = lista;
    while(p != NULL)
    {
        imprime_exame(*p->info);
        p = p->next;
    }
    printf("\n");
}

void escreve_listaPtrExames(ListPtrExames lista, char *ficheiro)
{
    FILE *f = fopen(ficheiro, "a");
    ListPtrExames p;
    p = lista;
    if (f != NULL)
    {
        while(p != NULL)
        {
            escreve_exame(*p->info, f);
            p = p->next;
        }
        fprintf(f, "\n");
        fclose(f);
    }
}

ListPtrExames elimina_PtrExame(ListPtrExames lista, Exame c)
{
    ListPtrExames aux, ant;
    aux = lista;
    ant = NULL;
    while(aux != NULL && exame_compare(c, *(aux->info)) != 1)
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