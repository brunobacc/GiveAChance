#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

// finalizar e melhorar o alterarPassword, usar strings no menu "mostrar perfil"


#define FILE_UTILIZADORES "Utilizadores.dat"

// estrutura
typedef struct utilizador {
    char nome[30];
    char password[50];
    char email[100];
    int doacoesEfetuadas;
    int totalDoado;
    int missoesAceites[250];
    //char idioma;
    int id;
    int tipo;
} Utilizador;


void alterarPerfil();


#define email jao123


menuPerfil(char email[]) {

    // variaveis
    int opcao, i , j;
    char subopcao;

    printf("=============================================\n");
    printf("|                  Perfil                   |\n");
    printf("|===========================================|\n");
    printf("|                                           |\n");
    printf("|                                           |\n");
    printf("| Nome: %s                                  |\n");
    printf("|                                           |\n");
    printf("| Doacoes feitas: %d                        |\n");
    printf("|                                           |\n");
    printf("| Total Doado: %d                           |\n");
    printf("|                                           |\n");
    printf("| Missoes Aceites: %d                       |\n");
    printf("|                                           |\n");
    printf("| Historico de missoes:                     |\n");
    printf("|===========================================|\n");
    for (i = 0; i < j; i++) {
        printf("|%43s-%s|\n");
    }
    printf("|===========================================|\n");
    printf("|                                           |\n");
    printf("| Alterar Perfil?                           |\n");
    printf("| 1 - Sim   2 - Nao                         |\n");
    printf("|                                           |\n");
    printf("| opcao: %-34s |\n");         scanf("%d", &opcao);
    printf("|                                           |\n");
    printf("=============================================\n");

    if (opcao == 'S') {
        alterarPerfil();
    }
    
}


void alterarPerfil() {

    // variaveis
    int opcao, i;
    char nome[30]; char email[100];


    printf("Quer Alterar o Nome?\n");
    printf("1 - Sim   2 - Nao");    scanf("%d", &opcao);

    for (i = 0; i < 1; i++) {
    
        if(opcao == 1) {
            printf("Novo nome: ");
            scanf("%s", nome);
        } else if (opcao == 2) {

        } else {
            printf("opcao invalida");
            i--;
        }
    }

    printf("Quer Alterar o Email?\n");
    printf("1 - Sim   2 - Nao");    scanf("%d", &opcao);

    for (i = 0; i < 1; i++) {
    
        if(opcao == 1) {
            printf("Novo email: ");
            scanf("%s", email);
        } else if (opcao == 2) {

        } else {
            printf("opcao invalida");
            i--;
        }
    }

    printf("Quer Alterar o Nome?\n");
    printf("1 - Sim   2 - Nao");    scanf("%d", &opcao);

    for (i = 0; i < 1; i++) {
    
        if(opcao == 1) {
            printf("\nSelecione o Idioma: ");
            printf("\n1 - PT");
            printf("\n2 - ENG");
        
            scanf("%d", opcao);
        } else if (opcao == 2) {

        } else {
            printf("opcao invalida");
            i--;
        }
    }

    printf("Quer Alterar a password?\n");
    printf("1 - Sim   2 - Nao");    scanf("%d", &opcao);

    for (i = 0; i < 1; i++) {
    
        if(opcao == 1) {
            alterarPassword();
        } else if (opcao == 2) {

        } else {
            printf("opcao invalida");
            i--;
        }
    }

}


void alterarPassword() {

    char password[50];
    Utilizador utilizador;

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

    //alterar password
    printf("Insira a nova password: ");
    scanf("%s", password);

    utilizadores.password = password;

    encriptarPassword(utilizadores.password);

    printf("Registo efetuado com sucesso!");
    
    fflush(stdin);

    getchar();

    // escrever no ficheiro
    // fwrite(&utilizadores, sizeof(Utilizador, 1, file);

    // fechar ficheiro
    fclose(file);
}