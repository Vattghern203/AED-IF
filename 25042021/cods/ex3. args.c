/* No prompt digita:
Nome_do_executável  nome_do_arquivo_exibido
*/
#include <stdio.h>
#include <stdlib.h>
main(int argc, char *argv[])
{
    FILE *fp;
    char ch;
    if (argc!=2)
    {
        printf("entrar com o nome do arquivo");
        exit(1);
    }
    if((fp=fopen(argv[1],"r"))==NULL)
    {
        printf("arquivo não pode ser aberto\n");
        exit(1);
    }
    ch = getc(fp);
    while(ch != EOF)
    {
        putchar(ch);
        ch = getc(fp);
    }
    fclose(fp);
}
