
#include <bits/stdc++.h>

int fim=0;

#define MAX 3

int lista[MAX];

int vazia(){
	if(fim==0){
		return 1;
	}

	return 0;
}

void inserir(){
    int valor;
    printf("Qual valor a ser inserido:");
    scanf("%d",&valor);
	if(fim==MAX){
		printf("Nao inseriu %d, lista cheia\n", valor);
	} else {
		lista[fim]=valor;
		fim++;
		printf("Inserido %d OK\n",valor);
	}
}

void remover(){
	int i,pos;
	printf("Qual a posicao:");
	scanf("%d",&pos);
	if(!vazia()){
		if(pos > fim-1){
			printf("Posicao nao e valida (%d)\n",pos);
		} else {
			printf("Removido elemento %d da posicao (%d)\n",lista[pos],pos);
			for(i= pos; i < fim; i++){
				lista[i]=lista[i+1];
			}
			fim--;
		}
		} else {
		printf("Lista vazia, nao removido\n");
	}
}

void imprimir(){
	int i;
	if(!vazia()){
		for(i=0; i<fim; i++){
			printf("O elemento %d eh %d\n", i, lista[i]);
		}
	} else {
		printf("Lista Vazia\n");
	}
}

void ordenar(){
    int aux;
    for(int i=0;i<MAX;i++){
        for(int j=i+1;j<MAX;j++){
            if(lista[i]>lista[j]){
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
    for(int i=0;i<MAX;i++){
        printf("O elemento %d eh %d\n",i,lista[i]);
    }
}

int main(){
    int op;
        do{
                printf("1- Iserir:\n");
                printf("2- Remover:\n");
                printf("3- Imprimir:\n");
                printf("4- Ordenar:\n");
                printf("5- Sair:\n");
                scanf("%d",&op);
                switch(op){
                case 1:
                    inserir();
                    break;
                case 2:
                    remover();
                    break;
                case 3:
                    imprimir();
                    break;
                case 4:
                    ordenar();
                    break;

                }

        }while(op!=5);

	return 0;
}



