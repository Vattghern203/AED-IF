#include<bits/stdc++.h>
#include "N2PROVA.h"

typedef struct Cliente{
    char nome[50];
    int codigo;
    double ent_vlr_mes;
    double sai_vlr_mes;
}cliente;

cliente* c;

void alocar(void){
	c = (cliente*) malloc(sizeof(cliente));
    if (c == NULL){
        printf("Memória insuficiente!\n");
        exit(1);
    }
}

void criar_cliente(void){
    printf("\nDigite o nome: ");
    scanf(" %[^\n]", &c->nome);

    printf("Digite o codigo: ");
    scanf("%d", &c->codigo);

    printf("Digite a entrada mensal: ");
    scanf("%lf", &c->ent_vlr_mes);

    printf("Digite a saida mensal: ");
    scanf("%lf", &c->sai_vlr_mes);

    printf("\n\n");
}

void liberar(Cliente* c){
    free(c);
    system("pause");
}

void acessar_dados(void){
    printf("\nNome: %s\n", c->nome);
    printf("Codigo: %d\n", c->codigo);
    printf("Entrada Mensal: %.2lf\n", c->ent_vlr_mes);
    printf("Saida Mensal: %.2lf\n", c->sai_vlr_mes);
    printf("\n\n");
}

void devolve_perfil(void){
    double saldo;
    saldo = c->ent_vlr_mes - c->sai_vlr_mes;
    if(saldo >= 2000){
        printf("Investidor\n");
        printf("\n\n");
    }
    else if((saldo <= 1000) && (saldo >= -1000)){
        printf("Conceder emprestimos\n");
        printf("\n\n");
    }
    else if(saldo < -1000){
        printf("Saldo inferior a -1000\n");
        printf("\n\n");
    }
}
