#include<stdio.h>

int main(){
    FILE *fp;
    char str[80];
    if((fp=fopen("Test.txt","w+"))==NULL){
        printf("O arquivo nao pode ser aberto.\n");
        exit(1);
    }
    do{
        printf("Digite uma string (CR para sair):\n");
        gets(str);
        strcat(str,"\n");
        fputs(str,fp);
    }while(*str!='\n');
    //Agora l� e mostra o arquivo
    rewind(fp);//Reinicializa o indicador de posi��o de arquivo para o come�o do arquivo
    while(!feof(fp)){
        fgets(str,79,fp);
        printf(str);
    }

    return 0;
}
