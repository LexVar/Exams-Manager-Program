#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_NOME 51
#define MAX_SALA 30
#define FIM_CURSO 3

// estrutura de uma data
typedef struct
{
    int ano, mes, dia, hora;
}Data;

// Ponteiro para lista de ponteiros de alunos
typedef struct ExamePtrNode *ListPtrExames;

//----------------------------------ALUNOS-----------------------------------------

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
    ListPtrExames exames;
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


//----------------------------------DISCIPLINAS-----------------------------------------

// ponteiro para lista de disciplinas
typedef struct DisciplinaNode *ListDisciplinas;

// estrutura de uma Disciplina
typedef struct
{
    char nome[MAX_NOME];
    char docente[MAX_NOME];
}Disciplina;

// lista simples ligada de Disciplinas
typedef struct DisciplinaNode
{
    ListDisciplinas next;
    Disciplina info;
}disciplina_node;

//----------------------------------EXAMES-----------------------------------------

// Ponteiro para lista de Exames
typedef struct ExameNode *ListExames;

// estrutura de um exame
typedef struct
{
    Disciplina *disciplina;
    char epoca[MAX_NOME];
    Data data;
    int duracao;
    // lista de salas
    char sala[MAX_NOME];
    ListPtrAlunos alunos;
}Exame;

// lista ligada de Exames
typedef struct ExameNode
{
    ListExames next;
    Exame info;
}exame_node;

// Lista simples de apontadores de alunos
typedef struct ExamePtrNode
{
    Exame *info;
    ListPtrExames next;
}exame_ptr_node;

#endif 