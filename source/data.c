#include "data.h"

/* retorna -1 se a primeira data for menor do que a segunda, 1 se a primeira for maior do que a segunda ou 0 se forem iguais */
int data_compare(Data d1, Data d2)
{
    if(d1.ano < d2.ano)
        return -1;
    else if(d1.ano > d2.ano)
        return 1;
    else
    {
        if(d1.mes < d2.mes)
            return -1;
        else if(d1.mes > d2.mes)
            return 1;
        else
        {
            if(d1.dia < d2.dia)
                return -1;
            else if(d1.dia > d2.dia)
                return 1;
            else
            {
                if(d1.hora < d2.hora)
                    return -1;
                else if(d1.hora > d2.hora)
                    return 1;
                else
         	        return 0;
            }
        }
    }
}

void data_scan(Data *p)
{
    scanf(" %d %d %d %d", &p->hora, &(p->dia), &(p->mes), &(p->ano));
}

/* copia os valores de uma struct Data para outra */
void copy_data(Data *d1, Data *d2)
{
    d1->ano = d2->ano;
    d1->mes = d2->mes;
    d1->dia = d2->dia;
    d1->hora = d2->hora;
}

void imprime_data(Data p)
{
    printf("%.2d:00-%.2d/%.2d/%d\n", p.hora, p.dia, p.mes, p.ano);
}