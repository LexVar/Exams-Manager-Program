#include "alunos.h"

// compara o numero dos alunos
int aluno_compare(Aluno al1, Aluno al2)
{
    if(al1.num == al2.num)
        return 1;
    return 0;
}

void set_regime(Aluno *al, char * regime)
{
    if (strcmp(regime, "Normal") == 0 || strcmp(regime, "Trabalhador-estudante") == 0 || strcmp(regime, "Atleta") == 0 || strcmp(regime, "Dirigente associativo") == 0 || strcmp(regime, "Erasmus") == 0)
        strcpy(al->regime, regime);
    else
    {
        printf("\n !!Regime inexistente\n");
        strcpy(al->regime, "Normal");
    }
}

void imprime_aluno(Aluno al)
{
    printf("\nNome: %s\nNumero: %d\n", al.nome, al.num);
    printf("Ano Curso: %d\nRegime: %s\nCurso: %s\n", al.ano, al.regime, al.curso);
}

void imprime_listaAlunos(ListAlunos lista)
{
    ListAlunos p;
    p = lista;
    while(p != NULL)
    {
        imprime_aluno(p->info);
        p = p->next;
    }
    printf("\n");
}

ListAlunos destroi_listaAlunos(ListAlunos lista)
{
    ListAlunos p;
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

// copia informacao de um aluno para outro
void copy_aluno(Aluno *al1, Aluno *al2)
{
    strcpy(al1->nome, al2->nome);
    al1->num = al2->num;
    al1->ano = al2->ano;
    set_regime(al1,al2->regime);
    strcpy(al1->curso, al2->curso);
}

// verifica se o aluno esta na lista
int verifica_Alunolista(ListAlunos lista, Aluno al)
{
    ListAlunos aux;
    aux = lista;
    while(aux != NULL && aux->info.num != al.num)
        aux = aux->next;
    if(aux == NULL)
        return 0;
    else return 1;
}


ListAlunos insere_fim_listaAlunos(ListAlunos lista, Aluno al)
{
    ListAlunos p, aux;
    if(verifica_Alunolista(lista, al) == 1)
        return lista;
    p = (ListAlunos)malloc(sizeof(aluno_node));
    aux = lista;
    if(p != NULL)
    {
        copy_aluno(&p->info, &al);
        p->next = NULL;
        if(aux == NULL)
            return p;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = p;
    }
    return lista;
}

ListAlunos procura_aluno(ListAlunos lista, Aluno al)
{
    ListAlunos aux;
    aux = lista;

    while(aux != NULL && aluno_compare(al, aux->info) != 1)
        aux = aux->next;
    if(aux != NULL)
        return aux;
    return NULL;
}

void procura_aluno1(ListAlunos lista, Aluno x, ListAlunos *ant, ListAlunos *atual)
{
    *ant = NULL;
    *atual = lista;

    while(*atual != NULL && aluno_compare(x, (*atual)->info) != 1)
    {
        (*ant) = (*atual);
        (*atual) = (*atual)->next;
    }
    if(*atual != NULL && aluno_compare(x, (*atual)->info) != 1)
        *atual = NULL;
}

ListAlunos insere_ordem_alunos(ListAlunos lista, Aluno x)
{
    ListAlunos p, aux, ant;
    p = (ListAlunos)malloc(sizeof(aluno_node));
    aux = lista;
    ant = NULL;
    if(p != NULL)
    {
        copy_aluno(&p->info, &x);
        while(aux != NULL && x.num > aux->info.num)
        {
            ant = aux;
            aux = aux->next;
        }
        if (aux != NULL && aluno_compare(x, aux->info) == 1)
        {
            printf("\n -> Aluno ja existe na base de dados\n");
            return lista;
        }
        p->next = aux;
        if (ant == NULL)
            lista = p;
        else ant->next = p;
        printf("\n -> Aluno inserido com sucesso\n");
    }
    return lista;
}

ListAlunos elimina_aluno_lista(ListAlunos lista, Aluno x)
{
    ListAlunos aux, ant;
    procura_aluno1(lista, x, &ant, &aux);
    if(aux != NULL)
    {
        ant->next = aux->next;
        free(aux);
        printf("\n -> Aluno Removido com sucesso\n");
    }
    else
        printf("\n -> Aluno nao encontrado\n");
    return lista;
}