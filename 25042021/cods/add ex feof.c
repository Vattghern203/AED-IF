#include <stdio.h>
#include <string.h>

main(){
    FILE *p;
    int cont=0;
    char c;
    if((p=fopen("arq1.txt","r"))==NULL)
    {
        printf("arquivo não pode ser aberto\n");
    }
    while (!feof(p))	/* Enquanto não se chegar no final do arquivo */
 	{
  		c = getc(p);	/* Le um caracter no arquivo */
  		if(c=='a')
            cont++; /*   cont ocorrências */
  	}
  	printf("Numero de a: %d\n",cont);
	fclose(p);		/* Fecha o arquivo */
}
