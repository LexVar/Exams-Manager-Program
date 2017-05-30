#include "main.h"

ListExames LoadExames(ListExames exames, ListDisciplinas disciplinas, ListAlunos alunos, char *ficheiro);
ListAlunos LoadAlunos(ListAlunos alunos, char *ficheiro);
ListDisciplinas LoadDisciplinas(ListDisciplinas disciplinas, char *ficheiro);
void menu();
void clear_input();
void clear_console();
void imprime_exames_aluno(ListExames exames, Aluno aluno);
void replace_end_line(char *str);
void escreveDisciplinas(ListDisciplinas disciplinas, char *ficheiro);
void escreveAlunos(ListAlunos alunos, char *ficheiro);
void escreveExames(ListExames exames, char *ficheiro);
void elimina_ligacoes_aluno(ListExames exames, Aluno x);
void elimina_exames_disciplina(ListExames exames, Disciplina x);
int verifica_inscricao_aluno(Exame exame, Aluno aluno);
int verifica_disponibilidade_sala(ListExames exames, Exame exame);
void escreve_exames_aluno(ListExames exames, Aluno aluno, char *ficheiro);
void elimina_exames_alunos(ListAlunos exames, Exame x);

int main(int argc, char const *argv[])
{
    int opc, n;
    char enter, escreve;
    // lista de alunos
    ListAlunos alunos = NULL;
    ListAlunos aluno_aux;
    Aluno aluno, al;
    ListPtrAlunos ptr_alunos_aux;
    
    // lista de disciplinas
    ListDisciplinas disciplinas = NULL;
    ListDisciplinas disciplina_aux;
    Disciplina disciplina, dc;

    // lista de Exames
    ListExames exames = NULL;
    ListExames exame_aux;
    Exame exame;
    
    alunos = LoadAlunos(alunos,"../ficheiros/alunos.txt");
    disciplinas = LoadDisciplinas(disciplinas,"../ficheiros/disciplinas.txt");
    exames = LoadExames(exames, disciplinas, alunos, "../ficheiros/exames.txt");
    clear_console();

    do{
        menu();
        if (scanf("%d", &opc) == 0)
            opc = 17;
        clear_input();
        clear_console();
        printf("Opcao: %d\n\n", opc);

        switch(opc)
        {
            case 0:
                printf("A Terminar...\n");
                escreveAlunos(alunos, "../ficheiros/alunos.txt");
                escreveDisciplinas(disciplinas, "../ficheiros/disciplinas.txt");
                escreveExames(exames, "../ficheiros/exames.txt");

                // destroi estruturas
                exames = destroi_listaExames(exames);
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
                aluno.exames = NULL;

                if (strcmp(aluno.nome, "") == 0 || strcmp(aluno.regime, "") == 0 || strcmp(aluno.curso, "") == 0)
                {
                    clear_console();
                    printf("\n -> Dados inseridos nao validos\n\n");
                    break;
                }
                clear_console();
                copy_aluno(&aluno,&aluno);
                
                alunos = insere_ordem_alunos(alunos, aluno);
                escreveAlunos(alunos, "../ficheiros/alunos.txt");

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
                    printf("\n -> Numero nao existente na base de dados\n\n");
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

                if (strcmp(aluno.nome, "") == 0 || strcmp(aluno.regime, "") == 0 || strcmp(aluno.curso, "") == 0)
                {
                    clear_console();
                    printf("\n -> Dados inseridos nao validos\n\n");
                    break;
                }

                clear_console();
                copy_aluno(&aluno,&aluno);
                
                alunos = elimina_aluno_lista(alunos, al);
                
                if (procura_aluno(alunos, aluno) == NULL)
                {
                    alunos = insere_ordem_alunos(alunos, aluno);
                    clear_console();
                    printf("\n -> Dados de aluno editados com sucesso\n\n");
                }
                else
                {
                    alunos = insere_ordem_alunos(alunos, al);
                    clear_console();
                    printf("\n -> Erro a editar dados de aluno\n\n");
                }

                escreveAlunos(alunos, "../ficheiros/alunos.txt");
                break;
            case 3: // Remover dados de aluno
                imprime_listaAlunos(alunos);
                printf("Numero de aluno a remover: ");
                scanf(" %d", &aluno.num);
                clear_input();
                clear_console();
                elimina_ligacoes_aluno(exames, aluno);
                alunos = elimina_aluno_lista(alunos,aluno);

                escreveAlunos(alunos, "../ficheiros/alunos.txt");
                break;
            case 4: // Criar Dados de Disciplina
                printf("Insira os dados da disciplina:\nNome: ");
                fgets(disciplina.nome, MAX_NOME, stdin);
                replace_end_line(disciplina.nome);
                printf("Docente: ");
                fgets(disciplina.docente, MAX_NOME, stdin);
                replace_end_line(disciplina.docente);
                
                if (strcmp(disciplina.nome, "") == 0 || strcmp(disciplina.docente, "") == 0)
                {
                    clear_console();
                    printf("\n -> Dados inseridos nao validos\n\n");
                    break;
                }

                clear_console();
                copy_disciplina(&disciplina,&disciplina);
                
                disciplinas = insere_ordem_disciplinas(disciplinas, disciplina);

                escreveDisciplinas(disciplinas, "../ficheiros/disciplinas.txt");
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
                    printf("\n -> Nome nao existente na base de dados\n\n");
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
                    printf("\n -> Dados da disciplina editados com sucesso\n\n");
                }
                else
                {
                    disciplinas = insere_ordem_disciplinas(disciplinas, dc);
                    clear_console();
                    printf("\n -> Erro a editar dados da disciplina\n\n");
                }

                escreveDisciplinas(disciplinas, "../ficheiros/disciplinas.txt");
	            break;
            case 6: // Remover Dados de Disciplina
                imprime_listaDisciplinas(disciplinas);
                printf("Nome de disciplina a remover: ");
                fgets(disciplina.nome, MAX_NOME, stdin);
                replace_end_line(disciplina.nome);

                clear_console();
                elimina_exames_disciplina(exames, disciplina);
                disciplinas = elimina_disciplina_lista(disciplinas,disciplina);

                escreveDisciplinas(disciplinas, "../ficheiros/disciplinas.txt");
                break;
            case 7: // Criar Exames
                printf("Insira os dados do Exame:\nDisciplina: ");
                fgets(disciplina.nome, MAX_NOME, stdin);
                replace_end_line(disciplina.nome);

                disciplina_aux = procura_disciplina(disciplinas, disciplina);
                if (disciplina_aux == NULL)
                {
                    clear_console();
                    printf("\n -> Disciplina inexistente!\n\n");
                    break;
                }
                else
                {
                   exame.disciplina = &(disciplina_aux->info);
                }

                printf("Insira a data (hora dia mes ano): ");
                data_scan(&(exame.data));
                clear_input();
                printf("Duracao: ");
                scanf(" %d", &exame.duracao);
                clear_input();
                printf("Epoca: ");
                fgets(exame.epoca, MAX_NOME, stdin);
                replace_end_line(exame.epoca);
                
                printf("Sala: ");
                fgets(exame.sala, MAX_NOME, stdin);
                replace_end_line(exame.sala);

                clear_console();
                exame.alunos = NULL;
                copy_exame(&exame,&exame);
                // verificar disponibilidade da sala
                if (verifica_disponibilidade_sala(exames, exame) == 0)
                {
                    clear_console();
                    printf("\n -> Sala indisponivel nesta data!\n\n");
                    break;
                }                
                exames = insere_ordem_exames(exames, exame);

                escreveExames(exames, "../ficheiros/exames.txt");
                break;
            case 8: // Apagar Exame
                imprime_listaExames(exames);
                printf("Numero de Exame a apagar: ");
                scanf(" %d", &n);
                clear_input();

                clear_console();
                exame_aux = exame_return(exames, n);

                if (exame_aux == NULL)
                    printf("\n -> Exame nao existente!\n\n");
                else
                {
                    elimina_exames_alunos(alunos, exame_aux->info);
                    exames = elimina_exame_lista(exames,exame_aux->info);
                }

                escreveExames(exames, "../ficheiros/exames.txt");
                break;
            case 9: // Listar Exames
                imprime_listaExames(exames);
                printf("Deseja guardar listagem em ficheiro(y/n): ");
                escreve = getchar();
                clear_input();
                clear_console();
                if (escreve == 'y' || escreve == 'Y')
                    escreve_listaExames(exames, "../ficheiros/listagens.txt");

                break;
            case 10: // Inscrever Aluno em Exame
                imprime_listaExames(exames);
                printf("Numero do Exame: ");
                scanf(" %d", &n);
                clear_input();

                clear_console();
                exame_aux = exame_return(exames, n);
                if (exame_aux == NULL)
                {
                    printf("\n -> Exame inexistente!\n\n");
                    break;
                }
                
                imprime_listaAlunos(alunos);
                printf("Numero de aluno a inscrever: ");
                scanf(" %d", &aluno.num);
                clear_input();
                clear_console();

                aluno_aux = procura_aluno(alunos, aluno);
                if (aluno_aux == NULL)
                {
                    clear_console();
                    printf("\n -> Aluno nao existente\n\n");
                    break;
                }

                ptr_alunos_aux = find_alunoPtr(exame_aux->info.alunos, aluno);
                if (ptr_alunos_aux != NULL)
                {
                    clear_console();
                    printf("\n -> Aluno ja inscrito no exame\n\n");
                    break;
                }

                if (verifica_inscricao_aluno(exame_aux->info, aluno_aux->info) == 0)
                {
                    clear_console();
                    printf("\n -> Aluno nao se pode inscrever nesta epoca de exame\n\n");
                    break;
                }
                exame_aux->info.alunos = insere_fim_listaPtrAlunos(exame_aux->info.alunos, &aluno_aux->info);
                aluno_aux->info.exames = insere_fim_listaPtrExames(aluno_aux->info.exames, &exame_aux->info);
                printf("\n -> Aluno inscrito no exame\n\n");
                escreveExames(exames, "../ficheiros/exames.txt");
                break;
            case 11: // Remover inscricao de Aluno num Exame
                imprime_listaExames(exames);
                printf("Numero do Exame: ");
                scanf(" %d", &n);
                clear_input();

                clear_console();
                exame_aux = exame_return(exames, n);
                if (exame_aux == NULL)
                {
                    printf("\n -> Exame inexistente!\n\n");
                    break;
                }
                
                imprime_listaPtrAlunos(exame_aux->info.alunos);
                printf("Numero de aluno a remover: ");
                scanf(" %d", &aluno.num);
                clear_input();
                clear_console();
                if (find_alunoPtr(exame_aux->info.alunos, aluno) == NULL)
                {
                    clear_console();
                    printf("\n -> Aluno nao esta inscrito no exame\n\n");
                    break;
                }
                aluno_aux = procura_aluno(alunos, aluno);
                exame_aux->info.alunos = elimina_PtrAluno(exame_aux->info.alunos, aluno);
                aluno_aux->info.exames = elimina_PtrExame(aluno_aux->info.exames, exame_aux->info);
                printf("\n -> Removida inscricao de aluno\n\n");
                escreveExames(exames, "../ficheiros/exames.txt");
                break;
            case 12: // Listar Alunos de um Exame
                imprime_listaExames(exames);
                printf("Numero do Exame: ");
                scanf(" %d", &n);
                clear_input();

                clear_console();
                exame_aux = exame_return(exames, n);
                if (exame_aux == NULL)
                {
                    printf("\n -> Exame inexistente!\n\n");
                    break;
                }
                imprime_listaPtrAlunos(exame_aux->info.alunos);

                printf("Deseja guardar listagem em ficheiro(y/n): ");
                escreve = getchar();
                clear_input();
                clear_console();
                if (escreve == 'y' || escreve == 'Y')
                    escreve_listaPtrAlunos(exame_aux->info.alunos, "../ficheiros/listagens.txt");

            	break;
            case 13: // Listar Exames de um aluno
                imprime_listaAlunos(alunos);
                printf("Numero de aluno: ");
                scanf(" %d", &aluno.num);
                clear_input();
                clear_console();
                aluno_aux = procura_aluno(alunos, aluno);
                if (aluno_aux == NULL)
                {
                    printf("\n -> Aluno inexistente!\n\n");
                    break;
                }
                imprime_listaPtrExames(aluno_aux->info.exames);
                //imprime_exames_aluno(exames, aluno);
                printf("Deseja guardar listagem em ficheiro(y/n): ");
                escreve = getchar();
                clear_input();
                clear_console();
                if (escreve == 'y' || escreve == 'Y')
                    escreve_listaPtrExames(aluno_aux->info.exames, "../ficheiros/listagens.txt");
                    //escreve_exames_aluno(exames, aluno, "../ficheiros/listagens.txt");

                break;
            case 14: // Verificar Salas
                imprime_listaExames(exames);
                printf("Numero do Exame: ");
                scanf(" %d", &n);
                clear_input();

                clear_console();
                exame_aux = exame_return(exames, n);
                if (exame_aux == NULL)
                {
                    printf("\n -> Exame inexistente!\n\n");
                    break;
                }
                if (ListPtrAlunos_tamanho(exame_aux->info.alunos) > MAX_SALA)
                    printf("\n -> Sala(s) sobrelotadas!\n");
                else
                    printf("\n -> Sala(s) com lotacao suficiente\n");
            	break;
            case 15:
                imprime_listaAlunos(alunos);
                printf("Deseja guardar listagem em ficheiro(y/n): ");
                escreve = getchar();
                clear_input();
                clear_console();
                if (escreve == 'y' || escreve == 'Y')
                    escreve_listaAlunos(alunos, "../ficheiros/listagens.txt");

                break;
            case 16:
                imprime_listaDisciplinas(disciplinas);
                printf("Deseja guardar listagem em ficheiro(y/n): ");
                escreve = getchar();
                clear_input();
                clear_console();
                if (escreve == 'y' || escreve == 'Y')
                    escreve_listaDisciplinas(disciplinas, "../ficheiros/listagens.txt");

                break;
            default: printf("ERRO! Por favor, selecione uma opcao valida!\n");
        }
        printf("Press enter to continue\n");
        enter = 0;
        while (enter != '\r' && enter != '\n') { enter = getchar(); }
        clear_console();
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
    printf(" 13 -> Listar Exames em que um aluno esta inscrito\n");
    printf(" 14 -> Verificar Salas\n");
    printf(" 15 -> Listar Alunos\n");
    printf(" 16 -> Listar Disciplinas\n");
    printf(" 0 -> SAIR\n");
    printf("Por favor, escolha uma opcao(0-16): ");
}

void imprime_exames_aluno(ListExames exames, Aluno aluno)
{
    ListExames aux;
    aux = exames;

    while (aux != NULL)
    {
        if (find_alunoPtr(aux->info.alunos, aluno) != NULL)
            imprime_exame(aux->info);
        aux = aux->next;
    }
}

void escreve_exames_aluno(ListExames exames, Aluno aluno, char *ficheiro)
{
    FILE *f = fopen(ficheiro, "a");
    ListExames aux;
    aux = exames;

    if (f != NULL)
    {
        while (aux != NULL)
        {
            if (find_alunoPtr(aux->info.alunos, aluno) != NULL)
                escreve_exame(aux->info, f);
            aux = aux->next;
        }
        fclose(f);
    }
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
            aluno.exames = NULL;
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

ListExames LoadExames(ListExames exames, ListDisciplinas disciplinas, ListAlunos alunos, char *ficheiro)
{
    FILE *f;
    ListExames exame_aux;
    ListDisciplinas disciplina_aux;
    Exame exame;
    Disciplina disciplina;
    ListAlunos aluno;
    Aluno al;
    char temp[MAX_NOME];
    f = fopen(ficheiro, "r");
    if(f != NULL)
    {
        while(fgets(disciplina.nome, MAX_NOME, f) != NULL)
        {
            replace_end_line(disciplina.nome);

            disciplina_aux = procura_disciplina(disciplinas, disciplina);
            exame.disciplina = &(disciplina_aux->info);

            fgets(exame.epoca, MAX_NOME, f);
            replace_end_line(exame.epoca);

            fscanf(f, "%d-%d/%d/%d*%d\n", &exame.data.hora, &exame.data.dia, &exame.data.mes, &exame.data.ano, &exame.duracao);

            fgets(exame.sala, MAX_NOME, f);
            replace_end_line(exame.sala);


            fgets(temp, MAX_NOME, f);
            exame.alunos = NULL;
            exames = insere_ordem_exames(exames, exame);
            exame_aux = procura_exame(exames, exame);
            do{
                fgets(temp, MAX_NOME, f);
                al.num = atoi(temp);
                aluno = procura_aluno(alunos, al);
                if(aluno != NULL)
                {
                    exame_aux->info.alunos = insere_fim_listaPtrAlunos(exame_aux->info.alunos, &aluno->info);
                    aluno->info.exames = insere_fim_listaPtrExames(aluno->info.exames, &exame_aux->info);
                }
            }while(al.num != 0);

        }
        fclose(f);
    }
    return exames;
}

void escreveAlunos(ListAlunos alunos, char *ficheiro)
{

    FILE *f;
    ListAlunos aux;
    f = fopen(ficheiro, "w");
    if(f != NULL)
    {
        aux = alunos;
        while(aux != NULL)
        {
            fprintf(f, "%s\n%d\n%d\n%s\n%s\n", aux->info.nome, aux->info.num, aux->info.ano, aux->info.regime, aux->info.curso);
            aux = aux->next;
        }
        fclose(f);
    }
}

void escreveDisciplinas(ListDisciplinas disciplinas, char *ficheiro)
{

    FILE *f;
    ListDisciplinas aux;
    f = fopen(ficheiro, "w");
    if(f != NULL)
    {
        aux = disciplinas;
        while(aux != NULL)
        {
            fprintf(f, "%s\n%s\n", aux->info.nome, aux->info.docente);
            aux = aux->next;
        }
        fclose(f);
    }
}

void escreveExames(ListExames exames, char *ficheiro)
{
    FILE *f;
    ListExames aux;
    ListPtrAlunos ptr_alunos;
    f = fopen(ficheiro, "w");
    if(f != NULL)
    {
        aux = exames;
        while(aux != NULL)
        {
            fprintf(f, "%s\n%s\n", aux->info.disciplina->nome, aux->info.epoca);
            fprintf(f, "%d-%d/%d/%d*%d\n", aux->info.data.hora, aux->info.data.dia, aux->info.data.mes, aux->info.data.ano, aux->info.duracao);
            fprintf(f, "%s\nALUNOS\n", aux->info.sala);
            ptr_alunos = aux->info.alunos;
            while(ptr_alunos != NULL)
            {
                fprintf(f, "%d\n", ptr_alunos->info->num);
                ptr_alunos = ptr_alunos->next;
            }
            fprintf(f, "END\n");
            aux = aux->next;
        }
        fclose(f);
    }
}

void elimina_ligacoes_aluno(ListExames exames, Aluno x)
{
    ListExames aux;
    aux = exames;
    while (aux != NULL)
    {
        if (find_alunoPtr(aux->info.alunos, x) != NULL)
            aux->info.alunos = elimina_PtrAluno(aux->info.alunos, x);
        aux = aux->next;
    }
}

void elimina_exames_disciplina(ListExames exames, Disciplina x)
{
    ListExames aux, ant = NULL;
    aux = exames;
    while (aux != NULL)
    {
        ant = aux;
        aux = aux->next;
        if (disciplina_compare(*ant->info.disciplina, x) == 1)
            exames = elimina_exame_lista(exames, ant->info);
    }
}

void elimina_exames_alunos(ListAlunos exames, Exame x)
{
    ListAlunos aux;
    aux = exames;
    while (aux != NULL)
    {
        if (find_examePtr(aux->info.exames, x) != NULL)
            aux->info.exames = elimina_PtrExame(aux->info.exames, x);
        aux = aux->next;
    }
}

// verifica se o aluno se pode inscrever na epoca do exame
int verifica_inscricao_aluno(Exame exame, Aluno aluno)
{
    if (strcmp(exame.epoca, "Especial") == 0)
    {
        if (aluno.ano == FIM_CURSO || strcmp(aluno.regime, "Trabalhador-estudante") == 0 || strcmp(aluno.regime, "Atleta") == 0 || strcmp(aluno.regime, "Dirigente associativo") == 0)
            return 1;
        else return 0;
    }
    else
        return 1;
}

int verifica_disponibilidade_sala(ListExames exames, Exame exame)
{
    ListExames aux;
    aux = exames;
    while (aux != NULL)
    {
        if (strcmp(aux->info.sala, exame.sala) == 0 && verifica_sobreposicao(aux->info.data, aux->info.duracao, exame.data, exame.duracao) == 1)
            return 0;
        aux = aux->next;
    }
    return 1;
}