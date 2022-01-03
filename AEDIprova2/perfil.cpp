#include <bits/stdc++.h>
#include "perfil.h"

typedef struct Perfil{
	char nome[45];
	int cod;
	double valm;
	double saim;
}perfil;

perfil* p;

void aloc(void){
	p = (perfil*)malloc(sizeof(perfil));
	if(p == NULL){
		printf("Nao ha espaco na memoria\n");
		exit(1);
	}
}

void libera(Perfil* p){
	free(p);
	system("pause");
}

void acessa(void){
	printf("\nNome: %s\n", p->nome);
    printf("Codigo: %s\n", p->cod);
    printf("Entrada Mensal: %.2lf\n", p->valm);
    printf("Saida Mensal: %.2lf\n", p->saim);
}

void cria(void){
	printf("\nCodigo da conta: ");
	scanf(" %[^\n]", &p->cod);
	
	printf("\nNome do Titular: ");
	scanf(" %[^\n]", &p->nome);
	
	printf("\nSua entrada mensal: ");
	scanf("%lf", &p->valm);
	
	printf("\nSua retirada mensal: ");
	scanf("%lf", &p->saim);
}

void perfila(void){
    double conta;
    conta = p->valm - p->saim;
    if(conta >= 2000){
        printf("Investidor\n");
    }
    else if((conta <= 1000) && (conta >= -1000)){
        printf("Conceder Emprestimos\n");
    }
    else if(conta < -1000){
        printf("Saldo baixo na conta\n");
    }
}
