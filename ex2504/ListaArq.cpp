#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){
	FILE *fp;
	int matri[35], i = 0;
	char nome[35], ender[100], curso[35];
	
	
	fp = fopen("alunoslista.txt", "w");
	
	while(i < 10){
		printf("Matrícula: \n");
		fscanf(fp, matri[i]);
		fputs(matri[i], fp)
		printf("nome do aluno: \n");
		gets(nome[i]);
		fputs(nome[i], fp)
		printf("endereço: \n");
		gets(ender[i]);
		fputs(ender[i], fp);
		printf("curso frequentado: \n");
		gets(curso[i], fp);
		fputs(curso[i], fp);
		
		i++;
	}
	
	return 0;
}
