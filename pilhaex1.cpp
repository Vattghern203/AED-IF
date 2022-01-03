#include <bits/stdc++.h>

int topo = 0;

#define MAX 3

int pilha[MAX], s;

void push(int valor){
	if(topo < MAX){
		pilha[topo] = valor; 
		printf("topo = %d\n", pilha[topo]);
		topo ++;	
	}
	else{
		("Putz! Parece que a pilha tá chaei\n");
	}
	
}

int pop(){
		int aux;
		if(pilha[MAX] == NULL)
			printf("vazio\n");
		else{
			aux = pilha[MAX];
			aux = NULL;
			return aux;
		}
}

void imprime_pilha(int){
	if(pilha[MAX] != NULL)
		for(int i = MAX; i > 0; i--){	
		printf("Numero: %d\n", pilha[i]);
		}
	}

int main(int argc, char** argv){
	push(10);
	push(7);
	push(5);
	push(8);
	
	return 0;
}

