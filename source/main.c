#include "main.h"

ListAlunos LoadAlunos(ListAlunos alunos, char *ficheiro);
ListDisciplinas LoadDisciplinas(ListDisciplinas disciplinas, char *ficheiro);
void menu();
void clear_input();
void clear_console();
void replace_end_line(char *str);

int main(int argc, char const *argv[])
{
    int opc;
    // lista de alunos
    ListAlunos alunos = NULL;
    ListAlunos aluno_aux;
    Aluno aluno, al;
    
    // lista de disciplinas
    ListDisciplinas disciplinas = NULL;
    ListDisciplinas disciplina_aux;
    Disciplina disciplina, dc;
    
    alunos = LoadAlunos(alunos,"../ficheiros/alunos.txt");
    disciplinas = LoadDisciplinas(disciplinas,"../ficheiros/disciplinas.txt");
    clear_console();

    do{
        menu();
        if (scanf("%d", &opc) == 0)
            opc = 14;
        clear_input();
        clear_console();
        printf("Opcao: %d\n\n", opc);

        switch(opc)
        {
            case 0:
                printf("A Terminar...\n");
                // escreve no ficheiro
                // destroi estruturas
                alunos = destroi_listaAlunos(alunos);
                disciplinas = destroi_listaDisciplinas(disciplinas);
                return 0;
            case 1: // Criar Dados de Aluno
                printf("Insira os dados do aluno:\nNome: ");
                fgets(aluno.nome, MAX_NOME, stdin);
                replace_end_line(aluno.nome);
                printf("Numero: ");
                scanf(" %d", &aluno.num);
                printf("Ano: ");
                scanf(" %d", &aluno.ano);
                clear_input();
                printf("Regime: ");
                fgets(aluno.regime, MAX_NOME, stdin);
                replace_end_line(aluno.regime);
                //clear_input();
                printf("Curso: ");
                fgets(aluno.curso, MAX_NOME, stdin);
                replace_end_line(aluno.curso);

                clear_console();
                copy_aluno(&aluno,&aluno);
                
                alunos = insere_ordem_alunos(alunos, aluno);

                break;
            case 2: // Editar Dados de Aluno
                imprime_listaAlunos(alunos);
                printf("Numero de aluno a editar: ");
                scanf(" %d", &al.num);
                clear_input();

                aluno_aux = procura_aluno(alunos, al);
                if (aluno_aux == NULL)
                {
                    clear_console();
                    printf("\n -> Numero nao existente na base de dados\n");
                    break;
                }
                copy_aluno(&al, &aluno_aux->info);

                printf("Insira os dados do aluno:\nNome: ");
                fgets(aluno.nome, MAX_NOME, stdin);
                replace_end_line(aluno.nome);
                printf("Numero: ");
                scanf(" %d", &aluno.num);
                printf("Ano: ");
                scanf(" %d", &aluno.ano);
                clear_input();
                printf("Regime: ");
                fgets(aluno.regime, MAX_NOME, stdin);
                replace_end_line(aluno.regime);
                //clear_input();
                printf("Curso: ");
                fgets(aluno.curso, MAX_NOME, stdin);
                replace_end_line(aluno.curso);

                clear_console();
                copy_aluno(&aluno,&aluno);
                
                alunos = elimina_aluno_lista(alunos, al);
                
                if (procura_aluno(alunos, aluno) == NULL)
                {
                    alunos = insere_ordem_alunos(alunos, aluno);
                    clear_console();
                    printf("\n -> Dados de aluno editados com sucesso\n");
                }
                else
                {
                    alunos = insere_ordem_alunos(alunos, al);
                    clear_console();
                    printf("\n -> Erro a editar dados de aluno\n");
                }

                break;
            case 3: // Remover dados de aluno
                imprime_listaAlunos(alunos);
                printf("Numero de aluno a remover: ");
                scanf(" %d", &aluno.num);
                clear_console();
                alunos = elimina_aluno_lista(alunos,aluno);

                break;
            case 4: // Criar Dados de Disciplina
                printf("Insira os dados da disciplina:\nNome: ");
                fgets(disciplina.nome, MAX_NOME, stdin);
                replace_end_line(disciplina.nome);
                printf("Docente: ");
                fgets(disciplina.docente, MAX_NOME, stdin);
                replace_end_line(disciplina.docente);
                
                clear_console();
                copy_disciplina(&disciplina,&disciplina);
                
                disciplinas = insere_ordem_disciplinas(disciplinas, disciplina);

	            break;
	        case 5: // Editar Dados de Aluno
                imprime_listaDisciplinas(disciplinas);
                printf("Nome da disciplina a editar: ");
                fgets(dc.nome, MAX_NOME, stdin);
                replace_end_line(dc.nome);

                disciplina_aux = procura_disciplina(disciplinas, dc);
                if (disciplina_aux == NULL)
                {
                    clear_console();
                    printf("\n -> Nome nao existente na base de dados\n");
                    break;
                }
                copy_disciplina(&dc, &disciplina_aux->info);

                printf("Insira os dados da disciplina:\nNome: ");
                fgets(disciplina.nome, MAX_NOME, stdin);
                replace_end_line(disciplina.nome);
                printf("Docente: ");
                fgets(disciplina.docente, MAX_NOME, stdin);
                replace_end_line(disciplina.docente);

                clear_console();
                copy_disciplina(&disciplina, &disciplina);
                
                disciplinas = elimina_disciplina_lista(disciplinas, dc);
                
                if (procura_disciplina(disciplinas, disciplina) == NULL)
                {
                    disciplinas = insere_ordem_disciplinas(disciplinas, disciplina);
                    clear_console();
                    printf("\n -> Dados da disciplina editados com sucesso\n");
                }
                else
                {
                    disciplinas = insere_ordem_disciplinas(disciplinas, dc);
                    clear_console();
                    printf("\n -> Erro a editar dados da disciplina\n");
                }

	            break;
            case 6: // Remover Dados de Disciplina
                imprime_listaDisciplinas(disciplinas);
                printf("Nome de disciplina a remover: ");
                fgets(disciplina.nome, MAX_NOME, stdin);
                replace_end_line(disciplina.nome);

                clear_console();
                disciplinas = elimina_disciplina_lista(disciplinas,disciplina);

                break;
            case 7: // Criar Exames
                imprime_listaDisciplinas(disciplinas);
                break;
            case 8: // Apagar Exame
                break;
            case 9: // Listar Exames
                break;
            case 10: // Inscrever Aluno em Exame
                break;
            case 11: // Remover inscricao de Aluno num Exame
                break;
            case 12: // Listar Alunos de um Exame
            	break;
            case 13: // Verificar Salas
            	break;
            default: printf("ERRO! Por favor, selecione uma opcao valida!\n");
        }
    }while(1);


	return 0;
}

// função para limpar o stdin (input) equivalente
void clear_input()
{
    char c;
    do{
        scanf("%c", &c);
    }while (c != '\n' && c != EOF);
}

// comando para limpar a consola
void clear_console()
{
    system("clear");
}

void menu()
{
    printf("\n 1 -> Criar Dados de Aluno\n");
    printf(" 2 -> Editar Dados de Aluno\n");
    printf(" 3 -> Remover Dados de Aluno\n");
    printf(" 4 -> Criar Dados de Disciplina\n");
    printf(" 5 -> Editar Dados de Disciplina\n");
    printf(" 6 -> Remover Dados de Disciplina\n");
    printf(" 7 -> Criar Exame\n");
    printf(" 8 -> Apagar Exame\n");
    printf(" 9 -> Listar Exames\n");
    printf(" 10 -> Inscrever Aluno em Exame\n");
    printf(" 11 -> Remover inscricao de Aluno num Exame\n");
    printf(" 12 -> Listar Alunos de um Exame\n");
    printf(" 13 -> Verificar Salas\n");
    printf(" 0 -> SAIR\n");
    printf("Por favor, escolha uma opcao(0-13): ");
}

void replace_end_line(char *str)
{
	if (str[strlen(str)-1] == '\n')
		str[strlen(str)-1] = 0;
}


ListAlunos LoadAlunos(ListAlunos alunos, char *ficheiro)
{
    FILE *f;
    Aluno aluno;
    f = fopen(ficheiro, "r");
    if(f != NULL)
    {
        while(fgets(aluno.nome, MAX_NOME, f) != NULL)
        {
            replace_end_line(aluno.nome);
            fscanf(f, "%d\n%d\n", &aluno.num, &aluno.ano);
            fgets(aluno.regime, MAX_NOME, f);
            replace_end_line(aluno.regime);
            fgets(aluno.curso, MAX_NOME, f);
            replace_end_line(aluno.curso);
            alunos = insere_ordem_alunos(alunos, aluno);
        }
        fclose(f);
    }
    return alunos;
}

ListDisciplinas LoadDisciplinas(ListDisciplinas disciplinas, char *ficheiro)
{
    FILE *f;
    Disciplina disciplina;
    f = fopen(ficheiro, "r");
    if(f != NULL)
    {
        while(fgets(disciplina.nome, MAX_NOME, f) != NULL)
        {
            replace_end_line(disciplina.nome);
            fgets(disciplina.docente, MAX_NOME, f);
            replace_end_line(disciplina.docente);
            disciplinas = insere_ordem_disciplinas(disciplinas, disciplina);
        }
        fclose(f);
    }
    return disciplinas;
}
