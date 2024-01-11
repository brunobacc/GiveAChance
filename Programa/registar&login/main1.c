#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>


#define FILE_UTILIZADORES "utilizadores.dat"

// estrutura
typedef struct utilizador {
    char nome[30];
    char password[50];
    char email[100];
    int doacoesEfetuadas;
    int totalDoado;
    int missoesAceites[250];
    char idioma;
    int ativo;
    int id;
} Utilizador;

// subrotinas
void menuAutenticar(Utilizador *utilizadores);
int login();
void adicionarSubscritor();
int quantidadeUtilizadores();
void consultarUtilizadoresAtivos();


int main() {

    // variaveis
    Utilizador utilizadores[250];
    
    // remove(FILEUTILIZADORES);

    // pedir o idioma
    /* printf("Qual o seu idioma?\nPT\nIN\nR: ");
    scanf("%s", utilizadores.idioma); */
    
    // menu
    menuAutenticar(utilizadores);
}


void menuAutenticar(Utilizador *utilizadores) {

    // variaveis
    Utilizador utilizador;
    int i, index, quantidade, estado;
    char opcao;

    do {
        system("cls");
        puts("\t\tGIVE A CHANCE");
        puts("\t1 - Login");
        puts("\t2 - Registar");
        puts("\t3 - Ajuda");
        puts("\t4 - Listar");
        puts("\tS - Sair \n");
        printf("\tInsira a opcao: ");
        scanf("%c", &opcao);
        fflush(stdin);

        fflush(stdin);

        switch (opcao) {

        case '1':
            estado = login();
            if (estado == 1)
                printf("Logado com sucesso!");
            else
                printf("Erro ao efetuar login!");
            getchar();
            break;
        case '2': 
            adicionarSubscritor();
            break;
        case '3':
            //paginaAjuda();
            break;
        case '4':
            consultarUtilizadoresAtivos();
            getchar();
            break;
        case 'S': case 's':
            printf("\n\tAte breve..");
            break;
        default:
            printf("\n\tOpcao Invalida!");
            getchar();
            break;
        }
    
    } while (opcao != 'S' && opcao != 's');

}

int quantidadeUtilizadores() {

    // variaveis
    FILE* file;
    Utilizador utilizador;
    int quantidade = 0;

    // tenta abrir o ficheiro das missoes
    file = fopen(FILE_UTILIZADORES, "rb");

    // apresenta erro caso nao consiga abrir o ficheiro
    if (file == NULL)
    {
        printf("impossible to open the file!\n", FILE_UTILIZADORES);
        return 0;
    }

    // calcula a quantidade de registos
    while (fread(&utilizador, sizeof(Utilizador), 1, file) == 1) 
        quantidade++;

    // fechar o ficheiro
    fclose(file);

    // devolve a quantidade de registos
    return quantidade;
}

void adicionarSubscritor() {

    // limpar consola
    system("cls");

    // variaveis
    FILE* file;
    Utilizador utilizador;
    int registo = quantidadeUtilizadores();

    // tenta abrir o ficheiro das missoes
    file = fopen(FILE_UTILIZADORES, "ab");

    // apresenta erro caso nao consiga abrir o ficheiro
    if (file == NULL)
    {
        printf("impossible to open the file!\n", FILE_UTILIZADORES);
        return;
    }

    // adicionar utilizador
    utilizador.id = registo + 1;
    printf("\n\nInsira o seu nome: "); 
    gets(utilizador.nome);
    printf("\nInsira o seu email: "); 
    scanf("%s", utilizador.email);
    printf("\nInsira a palavra passe: "); 
    scanf("%s", utilizador.password);
    utilizador.ativo = 1;

    printf("\n\nRegisto efetuado com sucesso!");
    
    fflush(stdin);

    // escrever no ficheiro
    fwrite(&utilizador, sizeof(Utilizador), 1, file);

    // fechar ficheiro
    fclose(file);
}

// login
int login() {

    // variaveis
    FILE *file;
    Utilizador utilizador;
    char email[100], password[50], estado = 0;

    // Tenta abrir o ficheiro das missoes
    file = fopen(FILE_UTILIZADORES, "rb");

    // apresenta erro caso nao consiga abrir o ficheiro
    if (file == NULL) {
        printf("impossible to open the file!\n", FILE_UTILIZADORES);
        return 0;
    }

    // Vai para o inicio do ficherio
    rewind(file);

    // menu do login 
    puts("|=============[ Login ]=============|");
    printf("\tEmail: ");
    scanf("%s", email);
    printf("\tPassword: ");
    scanf("%s", password);
    fflush(stdin);


    // Apresentar todos as missoes ativas dentro do ficheiro
    while (fread(&utilizador, sizeof(Utilizador), 1, file) == 1 && estado == 0) 
    {
        if (utilizador.ativo != 0) 
        {
            if(strcmp(utilizador.email, email) == 0 && strcmp(utilizador.password, password) == 0)
            {
                estado = 1;
            }
        }
    }

    // fecha o ficheiro
    fclose(file);

    return estado;
}


void consultarUtilizadoresAtivos() {

    // variables
    FILE *file;
    Utilizador utilizador;

    // try to open the file
    file = fopen(FILE_UTILIZADORES, "rb");

    // it may be impossible to open the file (due to permissions as an example)
    if (file == NULL) {
        printf("impossible to open the file!\n", FILE_UTILIZADORES);
        return;
    }

    // point to the Begin Of File (BOF) --> use fseek(file, 0, SEEK_SET), or rewind(file) instruction
    rewind(file);

    // print the title
    puts("===========");
    printf("| %6s | %-20s | %-20s |\n","ID", "Nome", "Email");

    // Apresentar todos os utilizadores ativos dentro do ficheiro
    while (fread(&utilizador, sizeof(Utilizador), 1, file) == 1) 
    {
        if (utilizador.ativo != 0) 
        {
            printf("| %-6.6d | %-20s | %-20s |%d\n", utilizador.id, utilizador.nome, utilizador.email, utilizador.ativo);
        }
    }

    puts("----------------------------------------------------------------------------------------------------------------------------------------------------------");

    // fecha o ficheiro
    fclose(file);
}