#include <bits/stdc++.h>
#include "aluno.h"

#include <bits/stdc++.h>
#include "aluno.h"
#define MAX 3

typedef struct{
	char matri[50];
	float n1, n2, n3, nf;
};aluno

main(){
	aluno **a
	int i;
	double media;
	char est;
	
	a = (aluno **)malloc(MAX*sizeof(aluno *));
    for(i=0; i<MAX; i++)
        a[i] = (aluno *)malloc(sizeof(aluno));
    for(i = 0; i < MAX; i++){
		printf("Matricula: \n");
		scanf(" %[^\n]", a[i]->matri);
		printf("Notas: \n");
		scanf("%f%f%f", &a[i]->n1, &a[i]->n2, &a[i]->n3);
	}
	
	for(i = 0; i < MAX; i++){
	
		media = mednot(a[i]->n1, a[i]->n2, a[i]->n3);
	
		printf("Media = %.2lf\n", media);
	
		est = situ(a[i]->n1, a[i]->n2, a[i]->n3);
	
		printf("O aluno foi %s\n", est);
	}
	
	for(i = 0; i < MAX; i++)
        free(a[i]);
    free(a);
    system("pause > nul");
    
    return 0;	
}
