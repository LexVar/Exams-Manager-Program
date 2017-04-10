#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_NOME 51

// estrutura de uma data
typedef struct
{
    int ano, mes, dia, hora;
}Data;

// ponteiro para lista de alunos
typedef struct AlunoNode *ListAlunos;

// Ponteiro para lista de ponteiros de alunos
typedef struct AlunoPtrNode *ListPtrAlunos;

// estrutura de um Aluno
typedef struct
{
    char nome[MAX_NOME];
    int num;
    int ano;
    char regime[MAX_NOME];
    char curso[MAX_NOME];
}Aluno;

// lista simples ligada de Alunos
typedef struct AlunoNode
{
    ListAlunos next;
    Aluno info;
}aluno_node;

// Lista simples de apontadores de alunos
typedef struct AlunoPtrNode
{
    Aluno *info;
    ListPtrAlunos next;
}aluno_ptr_node;

// estrutura de uma Disciplina
typedef struct
{
    char nome[MAX_NOME];
    char docente[MAX_NOME];
}Disciplina;

// Ponteiro para lista de Exames
typedef struct ExameNode *ListExames;

// estrutura de um exame
typedef struct
{
    Disciplina disciplina;
    char epoca[MAX_NOME];
    Data data;
    int duracao;
    // lista de salas ?s
    char sala[MAX_NOME];
    ListPtrAlunos alunos;
}Exame;

// lista ligada de Exames
typedef struct ExameNode
{
    ListExames next;
    Exame info;
}exame_node;

#endif 