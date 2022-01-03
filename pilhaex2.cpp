#include <bits/stdc++.h>

struct Nodo{
	int n;
	struct Nodo *pProximo;
};

struct Nodo* pInicio = NULL;

void push(int numero){
	struct Nodo* pNodo;
	pNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	pNodo->n=numero;
	pNodo->pProximo = NULL;
	pInicio = pNodo;
	
}

struct Nodo* pop(){
	if(pInicio == NULL){
		printf("Vazio\n");
	}else{
		struct Nodo *pAux = pInicio;
		pInicio = pAux->pProximo;
		return pAux;
	}
}

void imprimir(struct Nodo* pNodo){
	if(pNodo != NULL)
		printf("Numero: %d\n", pNodo->n);
}

int main(){
	int op, num;
	struct Nodo *ret;
	
	do{
		printf("Escolha uma das operacoes:\n1 - Inserir Elemento\n2 - Remover Elemento\n");
		printf("3 - Mostrar Elemento do topo\n4 - Sair do Programa\n");
		scanf("%d", &op);
		switch(op){
		case 1: 
			printf("Valor que deseja inserir: \n");
			scanf("%d", &num);
			push(num);
			break;
		case 2:
			ret = pop();
			printf("Removido : \n");
			imprimir(ret);
			break;
		case 3:
			printf("Topo: \n");
			imprimir(pInicio);
			break;
		}
	}while(op != 4);
	return 0;
}
