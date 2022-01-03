#include<stdio.h>

main()
{
    char ch;
    printf("Entre com algum texto (digite a tecla ENTER para sair)");
    do
    {
        ch = getchar();
        if (islower(ch))
            ch = toupper(ch);
        else
            ch = tolower(ch);
        putchar(ch);
    }
    while (ch != '\n');
}
