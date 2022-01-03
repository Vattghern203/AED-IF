//Professor eu dei uma reciclada no código menu fila, e ficou assim, td ok?
#include <bits/stdc++.h>

int fim = 0, inicio = 0, x;

#define MAX 10

int fila[MAX];

int vazia(){
	if(fim == 0){
		return 1;
	}
	
	return 0;
}

void insere(){
	int v;
	printf("Digite o valor a ser adicionado: ");
	scanf("%d", &v);
	if(fim == MAX){
		printf("Desculpe, a fila se encotra cheia\n");	
	}
	else{
		fila[fim] = v;
		fim++;
		printf("%d foi adcionado\n", v);
	}
}

void remove(){
	int i, pos;
	printf("Posicao:  ");
	scanf("%d", &pos);
	if(!vazia()){
		if(pos > fim - 1){
			printf("Posicao invalida (%d)! Tente denovo...\n", pos);
		}
		else{
			printf("Elemento %d removido da posicao %d\n", fila[pos], pos);
			for(i= pos; i < fim; i++){
				fila[i] = fila[i + 1];
			}
			fim--;
		} 
		}else {
			printf("Nao fora nada removido, pois a fila se encontra vazia\n");
		}
}


void imprime(){
	int i;
	if(!vazia()){
		for(i = 0; i < fim; i++){
			printf("O elemento %d eh %d\n", i, fila[i]);	
		}
	}
	else{
		printf("fila se encontra vazia\n");
	}
}

void ordena(){
	int aux;
	for(int i = 0; i < MAX; i++){
		for(int j = i + 1; j < MAX; j++){
            if(fila[i] > fila[j]){
                aux = fila[i];
                fila[i] = fila[j];
                fila[j] = aux;
            }
        }
    }
    for(int i = 0; i < MAX ; i++){
        printf("O elemento %d eh %d\n", i, fila[i]);
    }	
}

void fureikk(){
	int i, aux;
	if (fim < MAX) {
        for(i = fim; i > inicio; i--){
        	aux = fila[i];
			fila[i+1] = aux;
        	fila[i] = fila[i-1];
		}
		fim++;
		printf("valor que ira fazer a brasileiragem: ");
		scanf("%d", &x);
		fila[inicio] = x;	
    }
	else {
        printf("Fila cheia\n");
    }
}

	

int main(){
	int op;
		do{
			printf("1 - Inserir\n2 - Remover\n3 - Imprimir\n");
			printf("4 - Ordenar\n5 - Furar a Fila\n6 - Sair do programa\n");
			scanf("%d", &op);
			switch(op){
				case 1:
					insere();
					break;
				case 2:
					remove();
					break;
				case 3:
					imprime();
					break;
				case 4:
					ordena();
					break;
				case 5:
					fureikk();
					break;
			}	
		}while(op != 6);
	
	return 0;
}

