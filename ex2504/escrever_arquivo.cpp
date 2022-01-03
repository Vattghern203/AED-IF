#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){
	FILE *fp;
	char str[100];

	fp = fopen("arquivoteste.txt", "w");
	
	do
    {
        printf("Escreva sua mensagem(tecle enter 2x para finalizar):\n");
        gets(str);
        strcat(str, "\n");
        fputs(str, fp);
    }
    while(*str != '\n' );

	return 0;
}
