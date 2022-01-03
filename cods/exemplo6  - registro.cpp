#include<bits/stdc++.h>
typedef struct
{
    char nome[32];
    double peso;
    int idade;
} pessoa;
main()
{
    pessoa *p;
    int i,cont;
    p = (pessoa *)malloc(sizeof(pessoa));
    printf("Digite o nome da pessoa:\n");
    scanf(" %[^\n]",p->nome);
    printf("Digite o peso da pessoa:\n");
    scanf("%lf",&p->peso);
    printf("Digite a idade da pessoa:\n");
    scanf("%d",&p->idade);
    printf("%s %.1lf %d\n",p->nome,p->peso,p->idade);
    free(p);
}
