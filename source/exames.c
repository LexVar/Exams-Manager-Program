#include "exames.h"

void copy_exame(Exame *v1, Exame *v2)
{
	v1->disciplina = v2->disciplina;
    strcpy(v1->epoca, v2->epoca);
    copy_data(&(v1->data), &(v2->data));
    v1->duracao = v2->duracao;
    strcpy(v1->sala, v2->sala);
    v1->alunos = v2->alunos;
    //
}

int exame_compare(Exame e1, Exame e2)
{
	if (disciplina_compare(*(e1.disciplina), *(e2.disciplina)) == 1 && data_compare(e1.data, e2.data) == 0)
		return 1;
	return 0;
}

void imprime_exame(Exame v)
{
    printf("Disciplina: %s\nDocente: %s\nData: ", v.disciplina->nome, v.disciplina->docente);
    imprime_data(v.data);
    printf("Epoca: %s\nDuracao: %d\n", v.epoca, v.duracao);
    // mudar para varias salas
    printf("Sala: %s\n", v.sala);
    printf("Numero de Alunos inscritos: %d\n--------------------\n", ListPtrAlunos_tamanho(v.alunos));
}

void imprime_listaExames(ListExames lista)
{
    ListExames p;
    int i;
    i = 1;
    p = lista;
    while(p != NULL)
    {
        printf("-------Exame %d------\n", i++);
        imprime_exame(p->info);
        p = p->next;
        printf("\n");
    }
}

ListExames procura_exame(ListExames lista, Exame e)
{
    ListExames aux;
    aux = lista;

    while(aux != NULL && exame_compare(e, aux->info) != 1)
        aux = aux->next;
    if(aux != NULL)
        return aux;
    return NULL;
}

void procura_exame1(ListExames lista, Exame x, ListExames *ant, ListExames *atual)
{
    *ant = NULL;
    *atual = lista;

    while(*atual != NULL && exame_compare(x, (*atual)->info) != 1)
    {
        (*ant) = (*atual);
        (*atual) = (*atual)->next;
    }
    if(*atual != NULL && exame_compare(x, (*atual)->info) != 1)
        *atual = NULL;
}

ListExames insere_ordem_exames(ListExames lista, Exame x)
{
    ListExames p, aux, ant;
    p = (ListExames)malloc(sizeof(exame_node));
    aux = lista;
    ant = NULL;
    if(p != NULL)
    {
        copy_exame(&p->info, &x);
        while(aux != NULL && data_compare(x.data, aux->info.data) > 0)
        {
            ant = aux;
            aux = aux->next;
        }
        if (aux != NULL && exame_compare(x, aux->info) == 1)
        {
            printf("\n -> Exame ja existe na base de dados\n");
            return lista;
        }
        p->next = aux;
        if (ant == NULL)
            lista = p;
        else ant->next = p;
        printf("\n -> Exame inserido com sucesso\n");
    }
    return lista;
}

ListExames elimina_exame_lista(ListExames lista, Exame x)
{
    ListExames aux, ant;
    procura_exame1(lista, x, &ant, &aux);
    if(aux != NULL && lista == aux)
    {
        ant = aux->next;
        destroi_listaPtrAlunos(aux->info.alunos);
        free(aux);
        printf("\n -> Exame Removido com sucesso\n");
        return ant;
    }
    else if(aux != NULL && ant != NULL)
    {
        ant->next = aux->next;
        destroi_listaPtrAlunos(aux->info.alunos);
        free(aux);
        printf("\n -> Exame Removido com sucesso\n");
    }
    else
        printf("\n -> Exame nao encontrado\n");
    return lista;
}

ListExames destroi_listaExames(ListExames lista)
{
    ListExames p;
    if(lista != NULL)
    {
        while(lista->next != NULL)
        {
            p = lista;
            lista = lista->next;
            destroi_listaPtrAlunos(p->info.alunos);
            free(p);
        }
        destroi_listaPtrAlunos(lista->info.alunos);
        free(lista);
    }
    return NULL;
}

ListExames exame_return(ListExames exames, int n)
{
    ListExames aux;
    int i;
    i = 1;
    aux = exames;
    while(aux != NULL && i < n)
    {
        aux = aux->next;
        i++;
    }
    if(n == i)
        return aux;
    else
        return NULL;
}

void escreve_exame(Exame v, FILE *f)
{
    fprintf(f, "Disciplina: %s\nDocente: %s\nData: ", v.disciplina->nome, v.disciplina->docente);
    escreve_data(v.data, f);
    fprintf(f, "Epoca: %s\nDuracao: %d\n", v.epoca, v.duracao);
    // mudar para varias salas
    fprintf(f, "Sala: %s\n", v.sala);
    fprintf(f, "Numero de Alunos inscritos: %d\n--------------------\n", ListPtrAlunos_tamanho(v.alunos));
}

void escreve_listaExames(ListExames lista, char *ficheiro)
{
    ListExames p;
    FILE *f = fopen(ficheiro, "a");
    int i;
    i = 1;
    p = lista;
    if (f != NULL)
    {
        while(p != NULL)
        {
            fprintf(f,"-------Exame %d------\n", i++);
            escreve_exame(p->info, f);
            p = p->next;
            printf("\n");
        }
        fclose(f);
    }
}