#include <bits/stdc++.h>

struct Nodo{
	int numero;
	struct Nodo *pProximo;
};

struct Nodo *pInicio=NULL;

int adicionar(struct Nodo *pNodo, int pos){
	if(pInicio == NULL){
		if(pos != 1){
			return 0;
		}
		if(pNodo == NULL){
			return 0;
		}
		pNodo->pProximo = NULL;
		pInicio = pNodo;
		return 1;
	}
	if(pos == 1){
		if(pNodo == NULL){
			return 0;
		}
		pNodo->pProximo = pInicio;
		pInicio = pNodo;
		return 1;
	}
	struct Nodo *aux;
	aux = pInicio;
	int k = 1;
	while(k < pos - 1 && aux != NULL){
		aux = aux->pProximo;
		k++;
	}
	if(pNodo == NULL)
		return 0;
	if(aux == NULL)
		return 0;
	pNodo->pProximo = aux->pProximo;
	aux->pProximo = pNodo;
	return 1;
}

void remover(int elem){
	bool flag = false;
	struct Nodo *pAtual = pInicio;
	if(pInicio != NULL){
		if(elem == pInicio->numero){
			pInicio = pAtual->pProximo;
			free(pAtual);
			printf("Elemento foi removido com sucesso\n");
		}
		else{
			struct Nodo *pAtual=pInicio;
			struct Nodo *pAux=NULL;
			while(pAtual != NULL && flag!=true){
				if(pAux->numero != elem){
					pAux = pAtual;
					pAtual = pAtual->pProximo;
				}
				else{
					flag = true;
				}
			}
			if(pAtual==NULL){
				printf("Elemento nao encontrado, procure novamente...\n");
			}
			else{
				pAux->pProximo = pAtual->pProximo;
				free(pAtual);
			}
		}			
	}
	else{
		printf("Lista se encontra vazia \n");
	}
}

void mostraLista(){
	if(pInicio == NULL)
		printf("Lista se encontra vazia\n");
	else{
		struct Nodo *pAtual = pInicio;
		printf("Elementos que se encontram na lista: \n");
		while(pAtual != NULL){
			printf("%d\n", pAtual->numero);
			pAtual = pAtual->pProximo;
		}
	}
}

void tamanho(){
	int i = 0;
	struct Nodo *pAtual = pInicio;
	while(pAtual!=NULL){
		pAtual = pAtual->pProximo;
		i++;
	}
	printf("O tamnho da lista eh: %d\n", i);
}

void Maior(){
	int maiore = -1;
	if(pInicio==NULL)
		printf("Lista vazia\n");
	else{
		struct Nodo *pAtual=pInicio;
		while(pAtual!=NULL){
			if(maiore<pAtual->numero){
				maiore=pAtual->numero;
			}
			pAtual=pAtual->pProximo;
		}
	}
	printf("%d Eh o maior de todos\n", maiore);
}

int main(){
	int op, elemento, posicao, res;
	struct Nodo *x;
	do{
		printf("1 - Adicionar\n2 - Remover\n3 - Tamanho da lista\n4 - Mostrar a lista\n5 - Maior elemento da Lista\n6 - Sair\n");
		scanf("%d", &op);
		switch(op){
		case 1:
			x = (struct Nodo*)malloc(sizeof(struct Nodo));
			printf("Elemento a ser adicionado: ");
			scanf("%d", &x->numero);
			printf("Posicao desejada: ", x->numero);
			scanf("%d", &posicao);
			res = adicionar(x, posicao);
			if(res == 0)
				printf("Erro!!\n");
			else
				printf("Elemento a ser inserido\n");
			break;
		case 2:
			printf("Elemento a ser removido: ");
			scanf("%d", &elemento);
			remover(elemento);
			break;
		case 3:
			tamanho();
			break;
		case 4:
			mostraLista();
			break;
		case 5:
			Maior();
			break;
		}
	}while(op!=6);
	return 0;
}

