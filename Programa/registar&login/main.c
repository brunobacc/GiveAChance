#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>


#define FILE_UTILIZADORES "Utilizadores.dat"

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
    int tipo;
} Utilizador;

// subrotinas
void menuAutenticar(Utilizador *utilizadores);
void addRegisto();
void encriptarPassword(char *password);
int quantidadeUtilizadores();
void login();
void showActiveCustomers();
void paginaAjuda();



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

    int i, index, quantidade;
    char opcao;

    do {
        system("cls");
        puts("\t\tGIVE A CHANCE");
        printf("\n\t1 - Login\n\t2 - Registar\n\t3 - Ajuda\n\tS - Sair");
        printf("\n\n\tOpcao: ");
        scanf("%c", &opcao);

        fflush(stdin);

        switch (opcao) {

        case '1':
            login();
            break;
        case '2': 
            addRegisto();
            break;
        case '3':
            paginaAjuda();
            break;
        case 'V': case 'v':
            showActiveCustomers();
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


void addRegisto() {

    // limpar consola
    system("cls");

    // variaveis
    FILE* file;
    Utilizador utilizadores;
    int quantidade = quantidadeUtilizadores();

    // tenta abrir o ficheiro das missoes
    file = fopen(FILE_UTILIZADORES, "ab");

    // apresenta erro caso nao consiga abrir o ficheiro
    if (file == NULL)
    {
        printf("impossible to open the file!\n", FILE_UTILIZADORES);
        return;
    }

    // adicionar utilizador
    utilizadores.id = quantidade + 1;
    printf("|---------------------- Registar -------------------------|");
    printf("\n\nInsira o seu nome: "); gets(utilizadores.nome);
    printf("\nInsira o seu email: "); scanf("%s", utilizadores.email);
    printf("\nInsira a palavra passe: "); scanf("%s", utilizadores.password);
    printf("\n|---------------------- Registar -------------------------|\n\n");
    utilizadores.ativo = 1;
    utilizadores.tipo = 0;

    encriptarPassword(utilizadores.password);

    printf("Registo efetuado com sucesso!");
    
    fflush(stdin);

    getchar();

    // escrever no ficheiro
    fwrite(&utilizadores, sizeof(Utilizador), 1, file);

    // fechar ficheiro
    fclose(file);
}


void encriptarPassword(char *password) {

  //  password[50] *= 5;

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


// login
void login() {

    // variaveis
    FILE *file;
    Utilizador utilizador;
    char email[100], password[50];
    int logado = 0, aux;

    // Tenta abrir o ficheiro das missoes
    file = fopen(FILE_UTILIZADORES, "rb");

    // apresenta erro caso nao consiga abrir o ficheiro
    if (file == NULL) {
        printf("impossible to open the file!\n", FILE_UTILIZADORES);
        return;
    }

    // Vai para o inicio do ficherio
    rewind(file);

    // menu do login 
    puts("\n");
    printf("|=============[ Login ]=============|");
    puts("\n");
    printf("\tEmail: ");
    scanf("%s", email);
    puts("");
    printf("\tPassword: ");
    scanf("%s", password);

    encriptarPassword(password);

    puts("\n");
    printf("|=============[ Entrar ]=============|");
    puts("\n\n");

    // Apresentar todos as missoes ativas dentro do ficheiro
    while (fread(&utilizador, sizeof(Utilizador), 1, file) == 1 || logado == 1) {

        if (utilizador.ativo != 0) {
            if(strcmp(utilizador.email, email) == 0 && strcmp(utilizador.password, password) == 0) {
                if (utilizador.tipo == 0) {
                    aux = menuMissoes();
                } else if (utilizador.tipo == 1) {
                    aux = menuAdministradores();
                }
                
                printf("Login feito com sucesso!");
                logado == 1;
            }
        }
    }

    if(logado == 0) {
        printf("Falha ao realizar o login!");
    }

    // fecha o ficheiro
    fclose(file);

    fflush(stdin);

    getchar();

    aux;
}


void showActiveCustomers() {

    // variables
    FILE *file;
    Utilizador utilizadores1;

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
    printf("\n\n===============================\n");
    printf("%6s\t%-20s\n","ID", "NOME");

    /* fread()
     * Load sizeof(Customer) number of bytes, that corresponds to one (1) record that must be saved
     * on the customer variable.
     * At the end of the fread(), pointer is pointing to the next record inside de file.
     * The fread() return value 1, means that a record was correctly read.
    */
    while (fread(&utilizadores1, sizeof(Utilizador), 1, file) == 1) {
        
        if (utilizadores1.ativo != 0) {
            // print the customer data
            printf("%02d\t%-20s\n", utilizadores1.id, utilizadores1.nome);
        }
    }

    // close the file
    fclose(file);

    // print the end of report
    printf("======= end of report =========\n");

    getchar();
}


void paginaAjuda(){

    char opcao;
    int nota1, nota2, nota3, nota4, nota5;

    system("cls");

    printf("|------------------------------------- Ajuda -------------------------------------|\n\n");

    printf("Se ainda nao tem conta, clique na opcao Registar, apos isso introduza os seus dados\n nos campos e clique em Criar, apos isso a sua conta estara criada!\nApos isto clique em Login e insira o seu email e palavra-passe que registou!\nApos isso tera acesso a sua conta, Alem de poder ver as missoes e doar!\nEsperamos que tenha uma boa experiencia!\n\n\t1  2  3  4  5\n\nAvalio-nos!\ninsira 0 para voltar!");
    
    printf("\n\n|------------------------------------- Ajuda -------------------------------------|\n\n");

    printf("\t\topcao: ");
    scanf("%c", &opcao);

    switch (opcao) {

    case 0: 
        printf("Esperemos que tenha ajudado!");
        break;
    case 1: 
        nota1++;
    case 2: 
        nota2++;
    case 3: 
        nota3++;
    case 4: 
        nota4++;
    case 5:
        nota5++;
        printf("Obrigado pela Avaliacao!");
        break;
    default:
        break;
    }     
    
    
}
