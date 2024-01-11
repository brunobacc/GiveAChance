#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_UTILIZADORES "utilizadores.dat"
#define FILE_MISSOES "missoes.dat"
#define FILE_CATEGORIAS "categorias.dat"
#define FILE_INSTITUICOES "instituicoes.dat"
#define UTILIZADORES 200
#define MISSOES 100
#define CATEGORIAS 10
#define INSTITUICOES 50

typedef struct data
{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct utilizador
{
    int ID;
    char nome[30];
    char email[50];
    char palavraPasse[20];
    Data registo;
    int financiamentosFeitos; // quantidade de missoes em que um subscritor financiou
    float totalFinanciado; // quantidade financiado por um subscritor
    int missoesAceites; // quantidade de missoes propostas por um subscritor que foram aceites
    int propostasValidades; // quantidade de propostas que um administrador validou
    int nivel; // 0 = inativo | 1 = administrador | 2 = subscritor
}Utilizador;

typedef struct instituicao{
    int ID;
    char nome[30];
    int missoesAtivas;
    int missoesFinalizadas;
    int ativo;
    Data registo;
}Instituicao;

typedef struct missao{
    int ID;
    char titulo[30];
    char instituicao[30];
    char historia[255];
    float valorFinal;
    float valorFinanciado;
    int quantidadeFinanciadores;
    char categoria[30];
    Data inicio;
    Data desativo;
    Data fim;
    int estado; // 0 = inativa | 1 = ativa | 2 = finalizada
}Missao;

typedef struct categoria{
    int ID;
    char descricao[30];
    int ativo;
}Categoria;

typedef enum { false, true, voltar } bool;

// login
void login();

// pagina dos subscritores
bool selecionarMissao();
bool doarMissao();

// menus
void menuAdministrador();
void menuUtilizadores();
void menuMissoes();
void menuConsultarMissoes();
void menuCategorias();
void menuInstituicoes();

// funçoes para calcular o numero de registos
int quantidadeRegistos();

//CRUD missoes
bool adicionarMissao();
//int guardarMissao();
void consultarMissoesAtivas();
void consultarMissoesInativas();
bool editarMissao();
bool desativarMissao();

// procedimnentos e funçoes para auxiliar a funçao "editarMissao"
void alterarCampo(char *frase, char *enderecoOriginal, char *enderecoAlterado);
float alterarCampoFloat(char *frase, float valorOriginal);

#endif