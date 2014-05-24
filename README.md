BDII-2
======

Eu criei um exemplo de tabela :

	no arquivo fs_tabela.dat esta organizado deste modo:

	id | nome Lógico | nome físico | diretório
	-------------------------------------------
	1  |  cliente     |  000001.dat | files/data


	no arquivo fs_coluna.dat esta organizado assim :

	id | nome do atributo  |  tipo  | tamanho
	-----------------------------------------
	 1 |       nome       |   S     | 20
	 1 |       ender      |   S     | 30
     1 |       idade      |   I     |  4

	e o arquivo 000001.dat :

	nome | ender  | idade
	---------------------
	Iron  | R. Oito| 450
	Steel | R. Nove| 670 
	Silver| R. Dez | 552


	O programa lê o fs_tabela.dat e o fs_coluna.dat e 000001.dat
	coloca no buffer e imprime.

	Acredito que as funcionalidades básicas já estão ok.

	Falta ainda fazer tratamento de erros.

	para executar usa 

	./(NOME ARQUIVO) [CAMINHO DE fs_tabela.dat] [NOME TABELA] [CAMINHO
	de fs_coluna.dat];

	NOME TABELA : tabela a ser aberta, neste caso só tem a tabela cliente
	nos arquivos
