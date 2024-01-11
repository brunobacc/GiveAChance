#include "header.h"

int main()
{
    // delete the file
    // remove(FILE_MISSOES); // tests only...
    menuAdministrador();
}

void menuAdministrador()
{
    // variaveis
    char opcao;

    do
    {
        //limpar consola
        system("cls");

        //apresentar menu
        puts("================ Menu Administrador ================");
        puts("\t1 - Gerir Utilizadores");
        puts("\t2 - Gerir Missoes");
        puts("\t3 - Gerir Categorias");
        puts("\t4 - Gerir Instituicoes");
        puts("\tS - Sair \n");
        // pedir ao utilizador que insira uma opçao e fazer a recolha da mesma
        printf("\tInsira a opcao: ");
        scanf("%c", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case '1':
            //menuUtilizadores();
            break;
        case '2':
            menuMissoes();
            break;
        case '3':
            //menuCategorias();
            break;
        case '4':
            //menuInstituicoes();
            break;
        case 'S': 
        case 's':
            printf("Volte em breve!");
            break;
        default:
            printf("Essa opcao nao existe.\n");
            getchar();
            break;
        }
    } while (opcao != 's' && opcao != 'S');
}

/*void menuUtilizadores()
{
    // variaveis
    char opcao;
    bool retorno;

    do
    {
        // limpar consola
        system("cls");

        // apresentar menu da consulta de missões
        puts("================ Gerir Utilizadores ================");
        puts("\t1 - Consultar Utilizadores(Ativos)");
        puts("\t2 - Consultar Utilizadores(Inativos)");
        puts("\t3 - Adicionar Administrador");
        puts("\t4 - Editar Administrador");
        puts("\t5 - Eliminar Administrador");
        // pedir ao utilizador que insira uma opçao e fazer a recolha da mesma
        printf("\tInsira a opcao: ");
        scanf("%c", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case '1':
            consultarUtilizadoresAtivos();
            break;
        case '2':
            consultarUtilizadoresInativos();
            break;
        case '3':
            retorno = adicionarAdministrador();
            if (retorno == true)
                printf("Administrador adicionado com sucesso!");
            else
                printf("Erro ao adicionar administrador!");
            getchar();
            break;
        case '4':
            retorno = editarAdministrador();
            if (retorno == true)
                printf("Administrador alterada com sucesso!");
            else if (retorno == false)
                printf("Erro ao editar o administrador!");
            else
                printf("A voltar....");
            getchar();
            break;
        case '5':
            retorno = desativarAdministrador();
            if (retorno == true)
                printf("Administrador eliminada com sucesso!");
            else if (retorno == false)
                printf("Erro ao eliminar o administrador!");
            else
                printf("A voltar....");
            getchar();
            break;
        case 'S': 
        case 's':
            break;
        default:
            printf("Essa opcao nao existe.\n");
            getchar();
            break;
        }
    } while (opcao != 's' && opcao != 'S');
}*/

void menuMissoes()
{
    // variaveis
    char opcao;
    bool retorno;

    do
    {
        // limpar consola
        system("cls");

        // apresentar menu da consulta de missões
        puts("================ Gerir Missoes ================");
        puts("\t1 - Consultar Missoes");
        puts("\t2 - Adicionar Missoes");
        puts("\t3 - Editar Missao");
        puts("\t4 - Eliminar Missao");
        // pedir ao utilizador que insira uma opçao e fazer a recolha da mesma
        printf("\tInsira a opcao: ");
        scanf("%c", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case '1':
            menuConsultarMissoes();
            break;
        case '2':
            retorno = adicionarMissao();
            if (retorno == true)
                printf("Missoes adicionadas com sucesso!");
            else
                printf("Erro ao adicionar a missao!");
            getchar();
            break;
        case '3':
            retorno = editarMissao();
            if (retorno == true)
                printf("Missao alterada com sucesso!");
            else if (retorno == false)
                printf("Erro ao editar a missao!");
            else
                printf("A voltar....");
            getchar();
            break;
        case '4':
            retorno = desativarMissao();
            if (retorno == true)
                printf("Missao eliminada com sucesso!");
            else if (retorno == false)
                printf("Erro ao eliminar a missao!");
            else
                printf("A voltar....");
            getchar();
            break;
        case '5':
            retorno = selecionarMissao();
            if (retorno == true)
                printf("Doacao efetuada com sucesso!");
            else if (retorno == false)
                printf("Erro ao doar ou a selecionar a missao!");
            else
                printf("A voltar....");
            getchar();
            break;
        case 'S': 
        case 's':
            break;
        default:
            printf("Essa opcao nao existe.\n");
            getchar();
            break;
        }
    } while (opcao != 's' && opcao != 'S');
}

void menuConsultarMissoes()
{
    // variaveis
    char opcao;

    do
    {
        // limpar consola
        system("cls");

        // apresentar menu da consulta de missões
        puts("================ Consultar Missoes ================");
        puts("\t1 - Missoes Ativas");
        puts("\t2 - Missoes Inativas");
        puts("\t3 - Missoes Finalizadas");
        puts("\tS - Voltar \n");
        // pedir ao utilizador que insira uma opçao e fazer a recolha da mesma
        printf("\tInsira a opcao: ");
        scanf("%c", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case '1':
            consultarMissoesAtivas();
            getchar();
            break;
        case '2':
            consultarMissoesInativas();
            getchar();
            break;
        case '3':
            consultarMissoesFinalizadas();
            getchar();
            break;
        case 'S': 
        case 's':
            break;
        default:
            printf("Essa opcao nao existe.\n");
            getchar();
            break;
        }
    } while (opcao != 's' && opcao != 'S');
}

//void menuCategorias()

//void menuInstituicoes()

int quantidadeRegistos()
{
    // variaveis
    FILE* file;
    Missao missao;
    int quantidade = 0;

    // tenta abrir o ficheiro das missoes
    file = fopen(FILE_MISSOES, "rb");

    // retorna a quantidade que sera 0, caso nao consiga abrir o ficheiro
    if (file == NULL)
    {
        return quantidade;
    }

    // calcula a quantiade de registos
    while (fread(&missao, sizeof(Missao), 1, file) == 1)
        quantidade++;

    // fechar o ficheiro
    fclose(file);
    
    // devolve a quantidade de registos
    return quantidade;
}

bool adicionarMissao()
{
    // variaveis
    FILE* file;
    Missao missao;
    char continuar;
    int registo = quantidadeRegistos();

    //variaveis necessarias para atribuir a data de criaçao da missao
    time_t t = time(0);
    struct tm * now = localtime(&t);

    // tenta abrir o ficheiro das missoes
    file = fopen(FILE_MISSOES, "ab");

    // apresenta erro caso nao consiga abrir o ficheiro
    if (file == NULL)
    {
        //printf("Ocorreu um erro ao abrir o ficheiro %s!\n", FILE_MISSOES);
        return false;
    }

    // adicionar missoes até o utilizador inserir uma letra diferente de "s"
    do
    {
        // limpar consola
        system("cls");

        // atrubuir o codigo a missao
        missao.ID = registo + 1;

        // recolher informaçao da missao
        printf("=========== Adicionar Missao ===========\n");
        printf("Insira o titulo: ");
        gets(missao.titulo);
        printf("Insira a instituicao: ");
        gets(missao.instituicao);
        printf("Insira a historia: ");
        gets(missao.historia);
        printf("Insira o valor necessario: ");
        scanf("%f", &missao.valorFinal);
        fflush(stdin);
        missao.valorFinanciado = 0;
        missao.quantidadeFinanciadores = 0;
        printf("Insira a categoria: ");
        scanf("%s", missao.categoria);
        fflush(stdin);

        //guardar a data atual
        missao.inicio.dia = now->tm_mday;
        missao.inicio.mes = now->tm_mon + 1;
        missao.inicio.ano = now->tm_year + 1900;
        missao.desativacao.dia = 0;
        missao.desativacao.mes = 0;
        missao.desativacao.ano = 0;
        missao.fim.dia = 0;
        missao.fim.mes = 0;
        missao.fim.ano = 0;
        missao.estado = 1;

        // escrever no ficheiro
        fwrite(&missao, sizeof(Missao), 1, file);

        do
        {
            printf("Deseja continuar? (s/n)");
            scanf("%c", &continuar);
            fflush(stdin);

            if (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n')
            {
                // limpar consola
                system("cls");

                printf("Essa opcao nao está disponivel!\n");
            }
        } while (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n');
        
        if(continuar == 'S' || continuar == 's')
            registo++;
    } while (continuar == 'S' || continuar == 's');
    // fechar ficheiro
    fclose(file);

    return true;
}

void consultarMissoesAtivas()
{
    // variaveis
    FILE *file;
    int quantidade = quantidadeRegistos();
    Missao *missoes;

    missoes = (Missao*)malloc(MISSOES * sizeof(Missao));

    // Tenta abrir o ficheiro das missoes
    file = fopen(FILE_MISSOES, "rb");

    // apresenta erro caso nao consiga abrir o ficheiro
    if (file == NULL)
    {
        printf("Ocorreu um erro ao abrir o ficheiro %s!\n", FILE_MISSOES);
        return;
    }

    // Vai para o inicio do ficherio
    rewind(file);

    // Apresentar titulo
    puts("--------------------------------------------------------------------- Missoes(Ativas) -----------------------------------------------------------------------");
    printf("| %-5s | %-15s | %-16s | %-30s | %-10s | %-10s | %-16s | %-16s | %-11s |\n", "ID", "Titulo", "Instituicao", "Historia", "Valor", "Doado", "Financiadores", "Categoria", "Data_Inicio");

    // Passar os registos do ficheiro para um array
    fread(missoes, sizeof(Missao), MISSOES, file);

    // Apresentar todos as missoes ativas dentro do array
    for (int i = 0; i < quantidade; i++)
    {
        if (missoes[i].estado == 1)
            printf("| %-5.5d | %-15.15s | %-16.16s | %-30.30s | %-10.2f | %-10.2f | %-16d | %-16.16s | %-2.2d/%-2.2d/%-5d | %d\n", missoes[i].ID, missoes[i].titulo, missoes[i].instituicao, missoes[i].historia, missoes[i].valorFinal, missoes[i].valorFinanciado, missoes[i].quantidadeFinanciadores, missoes[i].categoria, missoes[i].inicio.dia, missoes[i].inicio.mes, missoes[i].inicio.ano, missoes[i].estado);
    }
    puts("-------------------------------------------------------------------------------------------------------------------------------------------------------------");

    // fecha o ficheiro
    fclose(file);

    // liberar memoria
    free(missoes);
}

void consultarMissoesInativas()
{
    // variaveis
    FILE *file;
    int quantidade = quantidadeRegistos();
    Missao *missoes;

    missoes = (Missao*)malloc(MISSOES * sizeof(Missao));

    // Tenta abrir o ficheiro das missoes
    file = fopen(FILE_MISSOES, "rb");

    // apresenta erro caso nao consiga abrir o ficheiro
    if (file == NULL)
    {
        printf("Ocorreu um erro ao abrir o ficheiro %s!\n", FILE_MISSOES);
        return;
    }

    // Vai para o inicio do ficherio
    rewind(file);

    // Apresentar titulo
    puts("--------------------------------------------------------------- Missoes(Inativas) --------------------------------------------------------------");
    printf("| %-5s | %-15s | %-16s | %-30s | %-10s | %-16s | %-11s | %-16s |\n", "ID", "Titulo", "Instituicao", "Historia", "Valor", "Categoria", "Data_Inicio", "Data_Desativacao");

    // Passar os registos do ficheiro para um array
    fread(missoes, sizeof(Missao), MISSOES, file);

    // Apresentar todos as missoes ativas dentro do array
    for (int i = 0; i < quantidade; i++)
    {
        if(missoes[i].estado == 0)
            printf("| %-5.5d | %-15.15s | %-16.16s | %-30.30s | %-10.2f | %-16.16s | %-2.2d/%-2.2d/%-5d | %-2.2d/%-2.2d/%-10d | %d\n", missoes[i].ID, missoes[i].titulo, missoes[i].instituicao, missoes[i].historia, missoes[i].valorFinal, missoes[i].categoria, missoes[i].inicio.dia, missoes[i].inicio.mes, missoes[i].inicio.ano, missoes[i].desativacao.dia, missoes[i].desativacao.mes, missoes[i].desativacao.ano, missoes[i].estado);
    }
    puts("------------------------------------------------------------------------------------------------------------------------------------------------");

    // fecha o ficheiro
    fclose(file);

    // liberar memoria
    free(missoes);
}

void consultarMissoesFinalizadas()
{
    // variaveis
    FILE *file;
    int quantidade = quantidadeRegistos();
    Missao *missoes;

    missoes = (Missao*)malloc(MISSOES * sizeof(Missao));

    // Tenta abrir o ficheiro das missoes
    file = fopen(FILE_MISSOES, "rb");

    // apresenta erro caso nao consiga abrir o ficheiro
    if (file == NULL)
    {
        printf("Ocorreu um erro ao abrir o ficheiro %s!\n", FILE_MISSOES);
        return;
    }

    // Vai para o inicio do ficherio
    rewind(file);

    // Apresentar titulo
    puts("--------------------------------------------------------------- Missoes(Finalizadas) --------------------------------------------------------------");
    printf("| %-5s | %-15s | %-16s | %-30s | %-10s | %-16s | %-16s | %-11s | %-11s |\n", "ID", "Titulo", "Instituicao", "Historia", "Valor", "Financiadores", "Categoria", "Data_Inicio", "Data_Fim");

    // Passar os registos do ficheiro para um array
    fread(missoes, sizeof(Missao), MISSOES, file);

    // Apresentar todos as missoes ativas dentro do array
    for (int i = 0; i < quantidade; i++)
    {
        if(missoes[i].estado == 2)
            printf("| %-5.5d | %-15.15s | %-16.16s | %-30.30s | %-10.2f | %-16.2d | %-16.16s | %-2.2d/%-2.2d/%-5d | %-2.2d/%-2.2d/%-5d | %d\n", missoes[i].ID, missoes[i].titulo, missoes[i].instituicao, missoes[i].historia, missoes[i].valorFinal, missoes[i].quantidadeFinanciadores ,missoes[i].categoria, missoes[i].inicio.dia, missoes[i].inicio.mes, missoes[i].inicio.ano, missoes[i].fim.dia, missoes[i].fim.mes, missoes[i].fim.ano, missoes[i].estado);
    }
    puts("------------------------------------------------------------------------------------------------------------------------------------------------");

    // fecha o ficheiro
    fclose(file);

    // liberar memoria
    free(missoes);
}

bool guardarDataInicio(Missao *missoes, Missao *missao, int id)
{
    missao->inicio.dia = missoes[id].inicio.dia;
    missao->inicio.mes = missoes[id].inicio.mes;
    missao->inicio.ano = missoes[id].inicio.ano;
    return true;
}

bool guardarDataDesativacao(Missao *missoes, Missao *missao, int id, int alteracao)
{
    //variaveis necessarias para atribuir a data de criaçao da missao
    time_t t = time(0);
    struct tm * now = localtime(&t);

    if (alteracao == 0)
    {
        missao->desativacao.dia = now->tm_mday;
        missao->desativacao.mes = now->tm_mon + 1;
        missao->desativacao.ano = now->tm_year + 1900;
    }
    else if (alteracao == 1)
    {
        missao->desativacao.dia = missoes[id].desativacao.dia;
        missao->desativacao.mes = missoes[id].desativacao.mes;
        missao->desativacao.ano = missoes[id].desativacao.ano;
    }
    else
        return false;
    return true;
}

bool guardarDataFim(Missao *missoes, Missao *missao, int id, int alteracao)
{
    //variaveis necessarias para atribuir a data de criaçao da missao
    time_t t = time(0);
    struct tm * now = localtime(&t);

    if (alteracao == 0)
    {
        missao->fim.dia = now->tm_mday;
        missao->fim.mes = now->tm_mon + 1;
        missao->fim.ano = now->tm_year + 1900;
    }
    else if (alteracao == 1)
    {
        missao->fim.dia = missoes[id].fim.dia;
        missao->fim.mes = missoes[id].fim.mes;
        missao->fim.ano = missoes[id].fim.ano;
    }
    else
        return false;
    return true;
}

bool editarMissao()
{
    // variaveis
    FILE *file;
    Missao alterarMissao, *missoes;
    int id, ultimoRegisto = quantidadeRegistos();
    float valor;

    missoes = (Missao*)malloc(MISSOES * sizeof(Missao));

    // tenta abrir o ficheiro
    file = fopen(FILE_MISSOES, "r+b");

    // apresenta erro caso nao consiga abrir o ficheiro
    if (file == NULL)
    {
        printf("Ocorreu um erro ao abrir o ficheiro %s!\n", FILE_MISSOES);
        getchar();
        return false;
    }

    // pedir um ID de uma missao até que o ID inserido corresponda ao ID de uma das missoes
    do
    {
        //limpar consola
        system("cls");

        // apresentar a tabela das missoes ativas
        consultarMissoesAtivas();
        
        //pedir o ID ao utilizador
        printf("Insira o ID da missao que deseja alterar (Retroceder = 0): ");
        scanf("%d", &id);
        fflush(stdin);
        
        // verificar se o ID inserido corresponda ao ID de uma das missoes, se nao corresponder vai apresentar um erro e depois pedir novamente ao utilizador para inserir um ID
        if (id < 0 || id > ultimoRegisto)
        {
            printf("\n\tO ID %d nao existe, no momento!\n", id);
            getchar();
        }

        // caso o utilizador nao queira mais editar uma missão, terá a oportunidade de voltar atrás.
        if (id == 0)
            return voltar;
        
    } while (id <= 0 || id > ultimoRegisto);

    //limpar consola
    system("cls");

    // Passar os registos do ficheiro para um array
    fread(missoes, sizeof(Missao), MISSOES, file);

    // subtrair 1 ao id pois como é um array o primeiro registo esta na posição 0
    id--;

    if (missoes[id].estado == 1)
    {
        // manter o id do registo
        alterarMissao.ID = missoes[id].ID;
        
        // pedir a informaçao que deseja alerar no registo
        printf("-------------Alterar dados da missao %d-------------\n", id);

        // funçao para perguntar se o utilizador deseja alterar ou manter um certo campo do registo que selecionou anteriormente
        alterarCampo("o titulo", missoes[id].titulo, alterarMissao.titulo);
        alterarCampo("a instituicao", missoes[id].instituicao, alterarMissao.instituicao);
        alterarCampo("a historia", missoes[id].historia, alterarMissao.historia);
        // se a missao ja foi financiada por alguem o administrador, nao poderá fazer alteraçao no valor final
        if (missoes[id].valorFinanciado == 0)
            valor = alterarCampoFloat("o valor", missoes[id].valorFinal);
        else
            valor = missoes[id].valorFinal;
        alterarMissao.valorFinal = valor;
        alterarMissao.valorFinanciado = missoes[id].valorFinanciado;
        alterarMissao.quantidadeFinanciadores = missoes[id].quantidadeFinanciadores;
        alterarCampo("a categoria", missoes[id].categoria, alterarMissao.categoria);

        //guardar as datas
        guardarDataInicio(missoes, &alterarMissao, id);
        guardarDataDesativacao(missoes, &alterarMissao, id, 1);
        guardarDataFim(missoes, &alterarMissao, id, 1);
        
        // manter a missao ativa, pois para conseguir alterar uma missao a mesma tem que estar ativa
        alterarMissao.estado = 1;

        // procurar a posição definida
        fseek(file, sizeof(Missao) * id, SEEK_SET);

        // escrever no ficheiro o registo alterado
        fwrite(&alterarMissao, sizeof(Missao), 1, file);
    }
    else
    {
        // apresentar erro, caso a missao nao esteje ativa
        printf("Essa missao nao esta ativa!");
        getchar();
        return false;
    }

    // fechar o ficheiro
    fclose(file);

    return true;
}

bool desativarMissao()
{
    // variaveis
    FILE *file;
    Missao desativarMissao, *missoes;
    int id, ultimoRegisto = quantidadeRegistos();

    //variaveis necessarias para atribuir a data de desativaçao da missao
    time_t t = time(0);
    struct tm * now = localtime(&t);

    missoes = (Missao*)malloc(MISSOES * sizeof(Missao));

    // tenta abrir o ficheiro
    file = fopen(FILE_MISSOES, "r+b");

    // apresenta erro caso nao consiga abrir o ficheiro
    if (file == NULL)
    {
        printf("Ocorreu um erro ao abrir o ficheiro %s!\n", FILE_MISSOES);
        getchar();
        return false;
    }

    // pedir um ID de uma missao até que o ID inserido corresponda ao ID de uma das missoes
    do
    {
        //limpar consola
        system("cls");

        // apresentar a tabela das missoes ativas
        consultarMissoesAtivas();
        
        //pedir o ID ao utilizador
        printf("Insira o ID da missao que deseja eliminar (Retroceder = 0): ");
        scanf("%d", &id);
        fflush(stdin);
        
        // verificar se o ID inserido corresponda ao ID de uma das missoes, se nao corresponder vai apresentar um erro e depois pedir novamente ao utilizador para inserir um ID
        if (id < 0 || id > ultimoRegisto)
        {
            printf("\n\tO ID %d nao existe, no momento!\n", id);
            getchar();
        }

        // caso o utilizador nao queira mais eliminar uma missão, terá a oportunidade de voltar atrás.
        if (id == 0)
            return voltar;
        
    } while (id <= 0 || id > ultimoRegisto);

    // Passar os registos do ficheiro para um array
    fread(missoes, sizeof(Missao), MISSOES, file);

    // subtrair 1 ao id pois como é um array o primeiro registo esta na posição 0
    id--;

    if (missoes[id].estado == 1)
    {
        //guardar os dados da missao e desativar
        desativarMissao.ID = missoes[id].ID;
        strcpy(desativarMissao.titulo, missoes[id].titulo);
        strcpy(desativarMissao.instituicao, missoes[id].instituicao);
        strcpy(desativarMissao.historia, missoes[id].historia);
        desativarMissao.valorFinal = missoes[id].valorFinal;
        desativarMissao.valorFinanciado = missoes[id].valorFinanciado;
        desativarMissao.quantidadeFinanciadores = missoes[id].quantidadeFinanciadores;
        strcpy(desativarMissao.categoria, missoes[id].categoria);

        //guardar os registos da data de criaçao e a data atual em que esta a ser desativada a missao
        guardarDataInicio(missoes, &desativarMissao, id);
        guardarDataDesativacao(missoes, &desativarMissao, id, 0);
        guardarDataFim(missoes, &desativarMissao, id, 1);

        desativarMissao.estado = 0;

        // procurar a posição definida
        fseek(file, sizeof(Missao) * id, SEEK_SET);

        // escrever no ficheiro o registo alterado
        fwrite(&desativarMissao, sizeof(Missao), 1, file);
    }
    else
    {
        // apresentar erro, caso a missao nao esteje ativa
        printf("Essa missao nao esta ativa!");
        getchar();
        return false;
    }

    // fechar o ficheiro
    fclose(file);

    // devolve verdadeiro
    return true;
}

void alterarCampo(char *frase, char *enderecoOriginal, char *enderecoAlterado)
{
    // limpar consola
    system("cls");

    // variaveis
    char opcao;

    // perguntar se pretende alterar aquele tipo de campo ate o utilizador inserir (S/N)
    do
    {
        // perguntar ao utilizador se pretende alterar e que o mesmo insira uma opçao sendo essas "S" ou "N"
        printf("Pretende alterar %s da missao?\n%s\n", frase, enderecoOriginal);
        printf("Insira uma opcao(S/N): ");
        // ler opçao inserida pelo utilziador
        scanf("%c", &opcao);
        fflush(stdin);
        switch (opcao)
        {
        case 'S': case 's':
            // se pretende alterar o utilizador terá que escrever a nova informaçao para ser guardada
            printf("\nInsira %s: ", frase);
            gets(enderecoAlterado);
            break;
        case 'N': case 'n':
            // se nao pretender alterar o sistema automaticamente irá pegar na informaçao que já esta no registo
            strcpy(enderecoAlterado, enderecoOriginal);
            break;
        default:
            // se o utilizador nao inserir um "S" ou "N", apresentará este erro
            printf("Essa opcao nao está disponivel!\n");
            break;
        }
    } while (opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n');
}

float alterarCampoFloat(char *frase, float valorOriginal)
{
    // limpar consola
    system("cls");

    // variaveis
    char opcao;
    float valor;

    // perguntar se pretende alterar aquele tipo de campo até que o utilizador insira (S/N)
    do
    {
        // perguntar ao utilizador se pretende alterar e que o mesmo insira uma opçao sendo essas "S" ou "N"
        printf("Pretende alterar %s da missao?\n%.2f\n", frase, valorOriginal);
        printf("Insira uma opcao(S/N): ");
        // ler opçao inserida pelo utilziador
        scanf("%c", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 'S': case 's':
            // se pretende alterar o utilizador terá que escrever a nova informaçao para ser guardada
            printf("\nInsira %s: ", frase);
            scanf("%f", &valor);
            fflush(stdin);
            break;
        case 'N': case 'n':
            // se nao pretender alterar o sistema automaticamente irá pegar na informaçao que já esta no registo
            valor = valorOriginal;
            break;
        default:
            // se o utilizador nao inserir um "S" ou "N", apresentará este erro
            printf("Essa opcao nao está disponivel!\n");
            break;
        }
    } while (opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n');

    return valor;
}

bool selecionarMissao()
{
    // variaveis
    FILE *file;
    int id, ultimoRegisto = quantidadeRegistos();
    bool retorno;

    // tenta abrir o ficheiro
    file = fopen(FILE_MISSOES, "r+b");

    // apresenta erro caso nao consiga abrir o ficheiro
    if (file == NULL)
    {
        printf("Ocorreu um erro ao abrir o ficheiro %s!\n", FILE_MISSOES);
        getchar();
        return false;
    }

    // pedir um ID de uma missao até que o ID inserido corresponda ao ID de uma das missoes
    do
    {
        //limpar consola
        system("cls");

        // apresentar a tabela das missoes ativas
        consultarMissoesAtivas();
        
        //pedir o ID ao utilizador
        printf("Insira o ID da missao que deseja eliminar (Retroceder = 0): ");
        scanf("%d", &id);
        fflush(stdin);
        
        // verificar se o ID inserido corresponda ao ID de uma das missoes, se nao corresponder vai apresentar um erro e depois pedir novamente ao utilizador para inserir um ID
        if (id < 0 || id > ultimoRegisto)
        {
            printf("\n\tO ID %d nao existe, no momento!\n", id);
            getchar();
        }

        // caso o utilizador nao queira mais eliminar uma missão, terá a oportunidade de voltar atrás.
        if (id == 0)
            return voltar;
        
    } while (id <= 0 || id > ultimoRegisto);

    retorno = doarMissao(id);
    if (retorno == true)
        printf("Doacao efetuada com sucesso!");
    else if (retorno == false)
        printf("Erro ao doar ou a selecionar a missao!");
    else
        printf("A voltar....");
    getchar();
}

bool doarMissao(int id)
{
    // limpar consola
    system("cls");

    // variaveis
    FILE *file;
    Missao doarMissao, *missoes;
    float doar;

    missoes = (Missao*)malloc(MISSOES * sizeof(Missao));

    // tenta abrir o ficheiro
    file = fopen(FILE_MISSOES, "r+b");

    // apresenta erro caso nao consiga abrir o ficheiro
    if (file == NULL)
    {
        printf("Ocorreu um erro ao abrir o ficheiro %s!\n", FILE_MISSOES);
        getchar();
        return false;
    }

    // Passar os registos do ficheiro para um array
    fread(missoes, sizeof(Missao), MISSOES, file);

    // subtrair 1 ao id pois como é um array o primeiro registo esta na posição 0
    id--;
    
    if (missoes[id].estado == 1)
    {
        // variaveis
        float valorNecessario = (missoes[id].valorFinal - missoes[id].valorFinanciado);

        // apresentar informaçoes sobre a missao selecionada
        printf("\t%s\n\n", missoes[id].titulo);
        printf("Instituicao:\n%s\n\n", missoes[id].instituicao);
        printf("Historia:\n%s\n\n", missoes[id].historia);
        printf("Valor Total:\n%.2f\n", missoes[id].valorFinal);

        // perguntar e recolher o quanto vai ser doado, caso insira 0 ira voltar a tela inicial
        printf("Insira a quantidade que deseja doar(minimo 0.25€/maximo %.2f€):", valorNecessario);
        scanf("%f", &doar);
        fflush(stdin);

        if (doar >= 0.25 && doar <= valorNecessario)
        {
            doarMissao.ID = missoes[id].ID;
            strcpy(doarMissao.titulo, missoes[id].titulo);
            strcpy(doarMissao.instituicao, missoes[id].instituicao);
            strcpy(doarMissao.historia, missoes[id].historia);
            doarMissao.valorFinal = missoes[id].valorFinal;
            doarMissao.valorFinanciado = missoes[id].valorFinanciado + doar;
            doarMissao.quantidadeFinanciadores = missoes[id].quantidadeFinanciadores + 1;
            strcpy(doarMissao.categoria, missoes[id].categoria);
            //guardar as datas
            guardarDataInicio(missoes, &doarMissao, id);
            guardarDataDesativacao(missoes, &doarMissao, id, 1);

            if (doarMissao.valorFinal == doarMissao.valorFinanciado)
            {
                guardarDataFim(missoes, &doarMissao, id, 0);
                doarMissao.estado = 2;
            }
            else
            {
                guardarDataFim(missoes, &doarMissao, id, 0);
                doarMissao.estado = 1;
            }
            
            // procurar a posição definida
            fseek(file, sizeof(Missao) * id, SEEK_SET);

            // escrever no ficheiro o registo alterado
            fwrite(&doarMissao, sizeof(Missao), 1, file);
        }
        else
        {
            printf("O valor inserido nao esta dentro dos limites definidos!");
            getchar();
            return false;
        }
    }
    else
    {
        // apresentar erro, caso a missao nao esteje ativa
        printf("Essa missao nao esta ativa!");
        getchar();
        return false;
    }

    // fechar o ficheiro
    fclose(file);

    // devolve verdadeiro
    return true;
}