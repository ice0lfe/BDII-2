#include "func.h"

int main(int rg, char *arq[]){
    //main demonstrativa, para mais detalhes consulte arquivo LEIAME.txt e func.c

   char *fs_tabela = arq[1], *Table_name = arq[2], *fs_coluna = arq[3]; //Faça a atribuição conforme a ordem de entrada na execução pela linha de comando

    struct page *buffer = inicializaBuffer();//ok

	struct CAMPOS *campos = leTabela(fs_tabela,Table_name, fs_coluna); // Traz pra memória o esquema dos dados //ok

    //carregaDados(buffer, data, meta, campos);

    //showBuffer(buffer, campos, meta);

    //showTupleBuffer(buffer, campos, meta, 0, 2);fs

    return 0;
}
