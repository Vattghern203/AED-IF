/*
De forma geral, o acesso ao arquivo é feito de forma sequencial, mas a linguagem C permite fazer o acesso
para operações de leitura e escrita de forma randômica usando a função seek().
int fseek(FILE *fp, long numbytes, int origem)
fp = ponteiro para o arquivo.
numbytes = total de bytes a ser pulado a partir da origem.
origem = a partir de onde os bytes serão contados.
Retorno é 0 caso sucesso, qq valor caso insucesso.

Constantes para o parâmetro origem:
SEEK_SET = 0 = início do arquivo
SEEK_CUR = 1 = ponto atual no arquivo
SEEK_END = 2 = fim do arquivo - especificar valor negativo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadastro{
    char nome[30], rua[30];
    int idade;
};

int main(){
    FILE *p;
    struct cadastro c[4]={"Joao","Rua JK",31,
                            "Carlos","Rua Vereador",60,
                            "Maria","Rua Dr Jose",34,
                            "Joaquina","Rua Bonifacio",71};


    if((p=fopen("arquivo.txt","wb"))==NULL){
        printf("O arquivo nao pode ser aberto!\n");
        return;
    }

    fwrite(c,sizeof(struct cadastro),4,p);
    fclose(p);

    if((p=fopen("arquivo.txt","rb"))==NULL){
        printf("O arquivo nao pode ser aberto!\n");
        return;
    }
    fseek(p,1*sizeof(struct cadastro),SEEK_SET);
    fread(&c,sizeof(struct cadastro),1,p);
    printf("%s\n%s\n%d\n",c[0].nome,c[0].rua,c[0].idade);
    fclose(p);

    return 0;
}
