#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main()
{
    FILE *fp;
    char str[80];
    if((fp=fopen("teste.txt", "w"))==NULL)
    {
        printf("arquivo não pode ser aberto\n");
        exit(1);
    }
    do
    {
        printf("Entre uma string (CR para sair) : \n");
        gets(str);
        strcat(str, "\n");
        fputs(str, fp);
    }
    while(*str != '\n' );
}
