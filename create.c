#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define T 30


void leTupla(char *linha, int b){ //Lê uma tupla da memória

    char *auxStr; //Variável auxiliar para leitura de stringd

    if(linha == NULL)
        return;

    int qtdCampos, j, k=0 ; // k é a posição do byte dentro da tupla
    qtdCampos = 3;

    for(j=0 ; j<qtdCampos; j++){
        if(j!=0)
            printf(" | ");
        if(b == 0){
            auxStr = linha + k;    //acesso a posição de inínio de uma string
            printf("%-20s", auxStr);
            k += 20;     //Atualição de leitura do número de bytes para char
            b++;
        }else if(b == 525){
            double *n = (double *)&linha[k];
            printf("%-20.2f", *n);
            k += sizeof(double);   //Atualição de leitura do número de bytes para double
		}
        else if(b == 1){
			auxStr = linha + k;    //acesso a posição de inínio de uma string
            printf("%-20s", auxStr);
            k += 30;     //Atualição de leitura do número de bytes para cha
            b++;
        }
        else if(b == 2){
            int *n = (int *)&linha[k];
            printf("%-20d", *n);
            k += sizeof(int);   //Atualição de leitura do número de bytes para int
        }
    }
    printf("\n");

}

//CRIAÇÃO DE fs_tabela.dat
int main(){

	FILE *arq = NULL;
	int id =  1;
	/*arq = fopen("files/fs_tabela.dat", "a+");
	
	char lnome[T] = "cliente\0";
	char fnome[T] = "000001.dat\0";
	char dir[T] = "files/data\0";
	fwrite(&id,sizeof(int), 1, arq);
	fwrite(lnome,sizeof(char),T, arq);
	fwrite(fnome,sizeof(char),T, arq);
	fwrite(dir,sizeof(char),T, arq);
	
	
	
	fseek(arq,0,SEEK_SET);
	
	int id1;
	char lnome1[T];
	char fnome1[T];
	char dir1[T];
	

		/*fread(&id1, sizeof(int),1, arq);
		fread(lnome1, sizeof(char),30,arq);
		fread(fnome1,sizeof(char),30, arq);
		fread(dir1,sizeof(char),30,arq);
	
	
	printf("id :%d\n", id1);
	puts(lnome1);
	puts(fnome1);
	puts(dir1);
	
	fclose(arq);*/
	
	
	//A partir daqui criação do fs_coluna
	/*struct v{
		int id;
		char atnome[40];
		char tipo;
		int tam;
	};
	
	struct v vet[3];
	struct v vet1[3];
	int i =0;
	
	arq = fopen("files/fs_coluna.dat", "a+");
	//fseek(arq,0,SEEK_SET);
	
	
	//vet[0].atnome[40] = t;
			
	while( i < 3){
		if(i == 0){
			strcpy(vet[i].atnome,"nome\0");
			vet[i].tipo = 'S';
			vet[i].tam = 20;
		}else if(i == 1){
			strcpy(vet[i].atnome,"ender\0");
			vet[i].tipo = 'S';
			vet[i].tam = 30;
		}else{
			strcpy(vet[i].atnome,"idade\0");
			vet[i].tipo = 'I';
			vet[i].tam = 4;
		}
		fwrite(&id,sizeof(int), 1, arq);
		fwrite(vet[i].atnome,sizeof(char),40, arq);
		fwrite(&vet[i].tipo,sizeof(char),1, arq);
		fwrite(&vet[i].tam,sizeof(int),1, arq);
		i++;
	}
	i = 0;
	fseek(arq,0,SEEK_SET);
	while(i < 3){
		fread(&vet1[i].id,sizeof(int),1, arq);
		fread(vet1[i].atnome,sizeof(char),T+10,arq);
		fread(&vet1[i].tipo,sizeof(char),1,arq);
		fread(&vet1[i].tam,sizeof(int),1,arq);
		printf("ID : %d\n", vet1[i].id);
		puts(vet1[i].atnome);
		printf("TIpo : %c\n",vet1[i].tipo);
		printf("TAM  : %d\n", vet1[i].tam);
		printf("\n");
		i++;
	}
	fclose(arq);	*/
	
	//criação de uma base de dados
		
	arq = fopen("files/data/000001.dat", "a+");
	
	struct dados {
		char nome[20];
		char ender[30];
		int idade;
	};
	
	struct dados d[3];
	struct dados d1[3];
	
	int n = 0;
	
	while(n < 3){
		if ( n ==0){
			strcpy(d[n].nome, "Iron\0"); 
			strcpy(d[n].ender, "R. Oito\0");
			d[n].idade = 450;
	    }
	    else if(n == 1){
			strcpy(d[n].nome, "Steel\0");
			strcpy(d[n].ender, "R. Nove\0");
			d[n].idade = 670;
		}
		else{
			strcpy(d[n].nome, "Silver\0");
			strcpy(d[n].ender, "R. Dez\0");
			d[n].idade = 552;
		}
		int j;
		
		
			
	 fwrite(d[n].nome,sizeof(char),20,arq);
	 fwrite(d[n].ender,sizeof(char),30,arq);
	 fwrite(&d[n].idade,sizeof(int),1, arq);	
	 n++;
	}
	n = 0;
	fseek(arq,0,SEEK_SET);
	/*char tuple[162];
	int loop = 0;
	fread(tuple,sizeof(char),162,arq);
	while( loop < 3){
		leTupla(tuple, n);
		loop++;
	}*/
	
	while( n < 3){
	fread(d1[n].nome,sizeof(char),20,arq);
	fread(d1[n].ender,sizeof(char),30,arq);
	fread(&d1[n].idade,sizeof(int),1,arq);
	
	puts(d1[n].nome);
	puts(d1[n].ender);
	printf("Idade : %d\n\n", d1[n].idade);
	
	n++;
	}
	fclose(arq);
	
	
	return 0;
}
