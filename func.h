/*
Executado no Ubuntu 12.04
Compilado com gcc version 4.6.3

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BP 512
#define SIZE 1024

struct CAMPOS
 {
   unsigned int id;  //identificador
   char nome[40];
   char tipo;
   int tamanho;
};

struct page {
   unsigned int nrec;            // numero de registros
   char data[SIZE];              //armazenamento das tuplas da página
   unsigned int pc;              // pin_count -> contador de uso da página
   unsigned int db;              // dirty_bit -> se dados foram modificados
   unsigned int position;        // posição livre da página
};

struct OBJ {
	unsigned int id; //identificador
	char lnome[30]; //nome lógico
	char fnome[30]; //nome físico
	char dir[30];  //diretório
};


struct CAMPOS *leMetadados(char *meta); //Identifica a estrutura de metadados 
int tamTupla(struct CAMPOS *campos, char *meta); //tamanho de uma tupla (tamanho dos atributos somados)
void leTupla(struct CAMPOS *campos, char *meta, char *linha); //impressão na tela 
int qtCampos(char *meta); //Quantidade campos de uma tablea
char *getTupla(struct CAMPOS *campos, char *meta, char *dado, int from); //Carrega uma tupla  do arquivo de dados em forma de string 
void carregaDados(struct page *buffer, char *data,char *meta, struct CAMPOS *campos); //Função principal entre CARREGAR TUPLA E COLOCAR NO BUFFER
struct page *inicializaBuffer(); //Valores default para cada pagina
void setTupla(struct page *buffer,char *tupla, int tam, int pos); //Função complementar de colocaTuplaBuffer
void colocaTuplaBuffer(struct page *buffer, char *tupla, struct CAMPOS *campos, char *meta); //Controle do buffer e páginas
char *strcop(char *data, int k, int tam); //Copia uma tupla do buffer para a impressao na tela
void showBuffer(struct page *buffer, struct CAMPOS *campos, char *meta); //Funções de IMPRESSÃO
void showTupleBuffer(struct page *buffer, struct CAMPOS *campos, char *meta, int pg, int rg);


