#include "header.h"

int main()
{
    // delete the file
    //remove(FILE_MISSOES); // tests only...
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
        missao.desativo.dia = 0;
        missao.desativo.mes = 0;
        missao.desativo.ano = 0;
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
    puts("------------------------------------------------------------------------------------------ Missoes ------------------------------------------------------------------------------------------");
    printf("| %-5s | %-20s | %-20s | %-50s | %-10s | %-10s | %-15s | %-20s | %-11s |\n", "ID", "Titulo", "Instituicao", "Historia", "Valor", "Doado", "Financiadores", "Categoria", "Data_Inicio");

    // Passar os registos do ficheiro para um array
    fread(missoes, sizeof(Missao), MISSOES, file);

    // Apresentar todos as missoes ativas dentro do array
    for (int i = 0; i < quantidade; i++)
    {
        if (missoes[i].estado == 1)
            printf("| %-5.5d | %-20.20s | %-20.20s | %-50.50s | %-10.2f | %-10.2f | %-15d | %-20.20s | %-2.2d/%-2.2d/%-5d | %d\n", missoes[i].ID, missoes[i].titulo, missoes[i].instituicao, missoes[i].historia, missoes[i].valorFinal, missoes[i].valorFinanciado, missoes[i].quantidadeFinanciadores, missoes[i].categoria, missoes[i].inicio.dia, missoes[i].inicio.mes, missoes[i].inicio.ano, missoes[i].estado);
    }
    puts("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

    // fecha o ficheiro
    fclose(file);

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
    puts("------------------------------------------------------------------------------------------ Missoes ------------------------------------------------------------------------------------------");
    printf("| %-5s | %-15s | %-16s | %-30s | %-10s | %-16s | %-11s | %-16s |\n", "ID", "Titulo", "Instituicao", "Historia", "Valor", "Categoria", "Data_Inicio", "Data_Desativacao");

    // Passar os registos do ficheiro para um array
    fread(missoes, sizeof(Missao), MISSOES, file);

    // Apresentar todos as missoes ativas dentro do array
    for (int i = 0; i < quantidade; i++)
    {
        if(missoes[i].estado == 0)
            printf("| %-5.5d | %-15.15s | %-16.16s | %-30.30s | %-10.2f | %-16.16s | %-2.2d/%-2.2d/%-5d | %-2.2d/%-2.2d/%-10d | %d\n", missoes[i].ID, missoes[i].titulo, missoes[i].instituicao, missoes[i].historia, missoes[i].valorFinal, missoes[i].categoria, missoes[i].inicio.dia, missoes[i].inicio.mes, missoes[i].inicio.ano, missoes[i].desativo.dia, missoes[i].desativo.mes, missoes[i].desativo.ano, missoes[i].estado);
    }
    puts("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

    // fecha o ficheiro
    fclose(file);
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
        valor = alterarCampoFloat("o valor", missoes[id].valorFinal);
        alterarMissao.valorFinal = valor;
        alterarMissao.valorFinanciado = missoes[id].valorFinanciado;
        alterarMissao.quantidadeFinanciadores = missoes[id].quantidadeFinanciadores;
        alterarCampo("a categoria", missoes[id].categoria, alterarMissao.categoria);

        //guardar as datas
        alterarMissao.inicio.dia = missoes[id].inicio.dia;
        alterarMissao.inicio.mes = missoes[id].inicio.mes;
        alterarMissao.inicio.ano = missoes[id].inicio.ano;
        alterarMissao.desativo.dia = missoes[id].desativo.dia;
        alterarMissao.desativo.mes = missoes[id].desativo.mes;
        alterarMissao.desativo.ano = missoes[id].desativo.ano;
        alterarMissao.fim.dia = missoes[id].fim.dia;
        alterarMissao.fim.mes = missoes[id].fim.mes;
        alterarMissao.fim.ano = missoes[id].fim.ano;
        /*do
        {
            printf("Pretende alterar o titulo da missao?\n%s\n", missao.titulo);
            printf("Insira uma opcao(S/N): ");
            scanf("%c", &opcao);
            fflush(stdin);
            switch (opcao)
            {
            case 'S': case 's':
                printf("\nInsira o titulo: ");
                gets(alterarMissao.titulo);
                break;
            case 'N': case 'n':
                strcpy(alterarMissao.titulo, missao.titulo);
                break;
            default:
                printf("Essa opcao nao está disponivel!\n");
                break;
            }
        } while (opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n');

        do
        {
            printf("Pretende alterar a instituicao da missao?\n%s\n", missao.instituicao);
            printf("Insira uma opcao(S/N): ");
            scanf("%c", &opcao);
            fflush(stdin);
            switch (opcao)
            {
            case 'S': case 's':
                printf("\nInsira o instituicao: ");
                gets(alterarMissao.instituicao);
                break;
            case 'N': case 'n':
                strcpy(alterarMissao.instituicao, missao.instituicao);
                break;
            default:
                printf("Essa opcao nao está disponivel!\n");
                break;
            }
        } while (opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n');

        do
        {
            printf("Pretende alterar a historia da missao?\n%s\n", missao.historia);
            printf("Insira uma opcao(S/N): ");
            scanf("%c", &opcao);
            fflush(stdin);
            switch (opcao)
            {
            case 'S': case 's':
                printf("\nInsira a historia: ");
                gets(alterarMissao.historia);
                break;
            case 'N': case 'n':
                strcpy(alterarMissao.historia, missao.historia);
                break;
            default:
                printf("Essa opcao nao está disponivel!\n");
                break;
            }
        } while (opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n');

        do
        {
            printf("Pretende alterar a categoria da missao?\n%s\n", missao.categoria);
            printf("Insira uma opcao(S/N): ");
            scanf("%c", &opcao);
            fflush(stdin);
            switch (opcao)
            {
            case 'S': case 's':
                printf("\nInsira a categoria: ");
                gets(alterarMissao.categoria);
                break;
            case 'N': case 'n':
                strcpy(alterarMissao.categoria, missao.categoria);
                break;
            default:
                printf("Essa opcao nao está disponivel!\n");
                break;
            }
        } while (opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n');*/

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
        desativarMissao.inicio.dia = missoes[id].inicio.dia;
        desativarMissao.inicio.mes = missoes[id].inicio.mes;
        desativarMissao.inicio.ano = missoes[id].inicio.ano;
        desativarMissao.desativo.dia = now->tm_mday;
        desativarMissao.desativo.mes = now->tm_mon + 1;
        desativarMissao.desativo.ano = now->tm_year + 1900;
        desativarMissao.fim.dia = 0;
        desativarMissao.fim.mes = 0;
        desativarMissao.fim.ano = 0;
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
            doarMissao.inicio.dia = missoes[id].inicio.dia;
            doarMissao.inicio.mes = missoes[id].inicio.mes;
            doarMissao.inicio.ano = missoes[id].inicio.ano;
            doarMissao.desativo.dia = missoes[id].desativo.dia;
            doarMissao.desativo.mes = missoes[id].desativo.mes;
            doarMissao.desativo.ano = missoes[id].desativo.ano;
            doarMissao.fim.dia = missoes[id].fim.dia;
            doarMissao.fim.mes = missoes[id].fim.mes;
            doarMissao.fim.ano = missoes[id].fim.ano;
            doarMissao.estado = 1;
             
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

/*bool guardarData(char *endereco, char *endereco2)
{
    endereco.dia = missoes[id].inicio.dia;
    endereco.mes = missoes[id].inicio.mes;
    endereco.inicio.ano = missoes[id].inicio.ano;
}*/