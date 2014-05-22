#include<stdio.h>
#define T 30


//CRIAÇÃO DE fs_tabela.dat
int main(){

	FILE *arq = NULL;
	
	arq = fopen("files/fs_tabela.dat", "a+");
	int id =  1;
	char lnome[T] = "cliente\0";
	char fnome[T] = "000001.dat\0";
	char dir[T] = "files/data\0";
	/*fwrite(&id,sizeof(int), 1, arq);
	fwrite(lnome,sizeof(char),T, arq);
	fwrite(fnome,sizeof(char),T, arq);
	fwrite(dir,sizeof(char),T, arq);
	*/
	fseek(arq,0,SEEK_SET);
	
	int id1;
	char lnome1[T];
	char fnome1[T];
	char dir1[T];
	

		fread(&id1, sizeof(int),1, arq);
		fread(lnome1, sizeof(char),30,arq);
		fread(fnome1,sizeof(char),30, arq);
		fread(dir1,sizeof(char),30,arq);
	
	
	printf("id :%d\n", id1);
	puts(lnome1);
	puts(fnome1);
	puts(dir1);
	
	return 0;
}
