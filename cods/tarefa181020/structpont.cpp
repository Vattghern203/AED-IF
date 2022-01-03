#include <bits/stdc++.h>

typedef struct{
	char matr[30], nome[32];
	int nasc;
}aluno;

main(){
	aluno **a;
	int max, i;
	
	printf("Quantos alunos sao no total? \n");
	scanf("%d", &max);
    a = (aluno **)malloc(max*sizeof(aluno *));
    for(i = 0; i < max; i++)
        a[i] = (aluno *)malloc(sizeof(aluno));
    for(i = 0; i < max; i++)
    {
        printf("Digite o numero da matricula do aluno:\n");
        scanf(" %[^\n]",a[i]->matr);
        printf("Digite o nome do aluno:\n");
        scanf(" %[^\n]",&a[i]->nome);
        printf("Digite o ano de nascimento:\n");
        scanf("%d",&a[i]->nasc);
		printf("%s %s %d\n",a[i]->matr,a[i]->nome,a[i]->nasc);    
    }
    for(i = 0; i < max; i++)
        free(a[i]);
    free(a);
    system("pause>nul");
}
