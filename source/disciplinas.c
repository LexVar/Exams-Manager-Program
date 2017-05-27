#include "disciplinas.h"

// compara o nome das disciplinas
int disciplina_compare(Disciplina dc1, Disciplina dc2)
{
    if(!strcmp(dc1.nome, dc2.nome))
        return 1;
    return 0;
}

void imprime_disciplina(Disciplina dc)
{
    printf("\nNome: %s\nDocente Responsavel: %s\n", dc.nome, dc.docente);
}

void imprime_listaDisciplinas(ListDisciplinas lista)
{
    ListDisciplinas p;
    p = lista;
    while(p != NULL)
    {
        imprime_disciplina(p->info);
        p = p->next;
    }
    printf("\n");
}

ListDisciplinas destroi_listaDisciplinas(ListDisciplinas lista)
{
    ListDisciplinas p;
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

// copia informacao de uma disciplina para outra
void copy_disciplina(Disciplina *dc1, Disciplina *dc2)
{
    strcpy(dc1->nome, dc2->nome);
    strcpy(dc1->docente, dc2->docente);
}

// verifica se a disciplina esta na lista
int verifica_Disciplinalista(ListDisciplinas lista, Disciplina dc)
{
    ListDisciplinas aux;
    aux = lista;
    while(aux != NULL && disciplina_compare(dc,aux->info) != 1)
        aux = aux->next;
    if(aux == NULL)
        return 0;
    else return 1;
}


ListDisciplinas insere_fim_listaDisciplinas(ListDisciplinas lista, Disciplina dc)
{
    ListDisciplinas p, aux;
    if(verifica_Disciplinalista(lista, dc) == 1)
        return lista;
    p = (ListDisciplinas)malloc(sizeof(disciplina_node));
    aux = lista;
    if(p != NULL)
    {
        copy_disciplina(&p->info, &dc);
        p->next = NULL;
        if(aux == NULL)
            return p;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = p;
    }
    return lista;
}

ListDisciplinas procura_disciplina(ListDisciplinas lista, Disciplina dc)
{
    ListDisciplinas aux;
    aux = lista;

    while(aux != NULL && disciplina_compare(dc, aux->info) != 1)
        aux = aux->next;
    if(aux != NULL)
        return aux;
    return NULL;
}

void procura_disciplina1(ListDisciplinas lista, Disciplina x, ListDisciplinas *ant, ListDisciplinas *atual)
{
    *ant = NULL;
    *atual = lista;

    while(*atual != NULL && disciplina_compare(x, (*atual)->info) != 1)
    {
        (*ant) = (*atual);
        (*atual) = (*atual)->next;
    }
    if(*atual != NULL && disciplina_compare(x, (*atual)->info) != 1)
        *atual = NULL;
}

ListDisciplinas insere_ordem_disciplinas(ListDisciplinas lista, Disciplina x)
{
    ListDisciplinas p, aux, ant;
    p = (ListDisciplinas)malloc(sizeof(disciplina_node));
    aux = lista;
    ant = NULL;
    if(p != NULL)
    {
        copy_disciplina(&p->info, &x);
        while(aux != NULL && strcmp(x.nome, aux->info.nome) > 0)
        {
            ant = aux;
            aux = aux->next;
        }
        if (aux != NULL && disciplina_compare(x, aux->info) == 1)
        {
            printf("\n -> Disciplina ja existe na base de dados\n");
            return lista;
        }
        p->next = aux;
        if (ant == NULL)
            lista = p;
        else ant->next = p;
        printf("\n -> Disciplina inserida com sucesso\n");
    }
    return lista;
}

ListDisciplinas elimina_disciplina_lista(ListDisciplinas lista, Disciplina x)
{
    ListDisciplinas aux, ant;
    procura_disciplina1(lista, x, &ant, &aux);
    if(aux != NULL)
    {
        ant->next = aux->next;
        free(aux);
        printf("\n -> Disciplina Removida com sucesso\n");
    }
    else
        printf("\n -> Disciplina nao encontrada\n");
    return lista;
}