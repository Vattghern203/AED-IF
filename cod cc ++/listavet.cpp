#include <bits/stdc++.h>

int fim=0; //FIM INICIA NA PRIMEIRA POSICAO DO VETOR

#define MAX 3

int lista[MAX];

int vazia(){
	if(fim==0){
		return 1;//1 - O C INTERPRETA 1 COMO TRUE, ENTÃO A LISTA ESTÁ VAZIA
	}

	return 0;//0 - O C INTERPRETA 0 COMO FALSE, LISTA NÃO ESTÁ VAZIA
}

void inserir(int valor){
	if(fim==MAX){ //CASO A VARIAVEL FIM SEJA = MAX A LISTA ESTA CHEIA
		printf("Nao inseriu %d, lista cheia\n", valor);
	} else {
		lista[fim]=valor; //INSERINDO O VALOR NO FIM DA LISTA
		fim++; //AUMENTANDO O CONTADOR QUE INDICA O FIM DA LISTA
		printf("Inserido %d OK\n",valor);
	}
}

void remover(int pos){
	int i;
	if(!vazia()){ //SE A LISTA NÃO ESTA VAZIA, FOR DIFERENTE DE 1 (1 = LISTA VAZIA)
		if(pos > fim-1){
			 //O FIM INDICA A POSICAO DO PROXIMO ELEMENTO A SER INSERIDO
            //DIMINUI-SE 1 PARA VERIFICAR SE A POSICAO ENVIADA PARA REMOÇÃO É VALIDA
			printf("Posicao nao e valida (%d)\n",pos);
		} else {
			printf("Removido elemento %d da posicao (%d)\n",lista[pos],pos);
			 //QUANDO SE REMOVE UM ITEM DEVE-SE MANTER A LISTA SEM ESPAÇOS
            //O LOOPING ABAIXO DESLOCA OS ITENS PARA UMA POSICAO ANTERIOR
			for(i= pos; i < fim; i++){
				lista[i]=lista[i+1];
			}
			fim--; //COMO UM ITEM FOI REMOVIDO O INDICE DO FIM TAMBEM DIMINUI
		}
		} else {
		printf("Lista vazia, nao removido\n");
	}
}

void imprimir(){
	int i;
	if(!vazia()){ //CASO A LISTA NAO ESTEJA VAZIA
		//LOOPING VAI DO COMECO DO ARRAY (0) ATE O FIM IMPRINDO ASSIM TODOS OS ELEMENTOS
		for(i=0; i<fim; i++){
			printf("O elemento %d eh %d\n", i, lista[i]);
		}
	} else {
		printf("Lista Vazia\n");
	}
}

int main(){

    //OS COMENTARIOS AO LADO DO MEDO INDICAM O QUE DEVE ACONTECER
    //SE A LISTA ESTIVER IMPLEMENTADA DE MANEIRA CORRETA

	imprimir(); //LISTA VAZIA
	remover(1); //POSICAO INVALIDA - LISTA VAZIA
	inserir(1);	//INSERIDO ELEMENTO 1
	inserir(6);	//INSERIDO ELEMENTO 6
	inserir(8);	//INSERIDO ELEMENTO 8
	inserir(7);	//A LISTA ESTÁ CHEIA
	imprimir(); //(1,6,8)
	remover(3);	//ERRO - POSICAO INVALIDA
	remover(1);	//REMOVIDO ELEMENTO 6
	imprimir();	//(1,8)
	inserir(12);//OK
	inserir(15);//CHEIA
	imprimir(); //(1,8,12)

	return 0;
}



