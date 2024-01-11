#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>


#define FILE_NOTIFICACOES "notificacoes.dat"

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

typedef struct notificacao {

    int id;
    int ativo;
    char descricao[300];
    int utilizador[];
} Notificacao;


menuNotificacoes(Utilizador utilizadores[], Notificacao notificacao);
mostrarNotificacoes(Utilizador Utilizadores[], Notificacao notificacao);
criarNotificacoes(Utilizador utilizadores[], Notificacao notificacao);


menuNotificacoes(Utilizador utilizadores[]) {

    Notificacao notificacao;

    // variaveis
    int opcao, i, j, a, b;
    char subopcao;

    printf("=============================================\n");
    printf("|               Notificacoes                |\n");
    printf("|===========================================|\n");
    printf("|                                           |\n");
    mostrarNotificacoes(utilizadores, notificacao);
    printf("|                                           |\n");
    printf("=============================================\n");

    if (opcao == 'S') {
        alterarPerfil();
    }
    
}

mostrarNotificacoes(Utilizador Utilizadores[], Notificacao notificacao) {
    
    // variables
    FILE *file;
    Utilizador utilizador;

    // try to open the file
    file = fopen(FILE_NOTIFICACOES, "rb");

    // it may be impossible to open the file (due to permissions as an example)
    if (file == NULL) {
        printf("impossible to open the file!\n", FILE_NOTIFICACOES);
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
    while (fread(&utilizador, sizeof(Utilizador), 1, file) == 1) {
        
        if (utilizador.ativo != 0 && utilizadores.id == notificacao.utilizador) {
            // print the customer data
            printf("%02d\t%-20s\n", notificacao.descricao);
        }
    }

    // close the file
    fclose(file);

    // print the end of report
    printf("======= end of report =========\n");

    getchar();
}


criarNotificacoes(Utilizador utilizadores[] ,Notificacao notificacao) {

    // limpar consola
    system("cls");

    // variaveis
    FILE* file;
    Utilizador utilizadores;
    int k;

    // tenta abrir o ficheiro das missoes
    file = fopen(FILE_NOTIFICACOES, "ab");

    // apresenta erro caso nao consiga abrir o ficheiro
    if (file == NULL)
    {
        printf("impossible to open the file!\n", FILE_NOTIFICACOES);
        return;
    }
    
    notificacao.id = quantidade + 1;

    strcpy(notificacao.descricao, "a missao em que doou foi concluida!");

    notificacao.utilizador = utilizador.id;

    notificacao.ativo = 1;

    encriptarPassword(utilizadores.password);

    printf("Registo efetuado com sucesso!");
    
    fflush(stdin);

    getchar();

    // escrever no ficheiro
    fwrite(&notificacao, sizeof(Utilizador), 1, file);

    // fechar ficheiro
    fclose(file);
}