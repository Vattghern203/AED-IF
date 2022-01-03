#include <bits/stdc++.h>
#include "matematica.h"

int main(){
	int x, y , op, res;
	float fx;
	
	do{
		printf("Escolha um operacao:\n1 - Potencia\n2 - Resto\n3 - Arredondamento\n4 - Finalizar\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				scanf("%d%d", &x, &y);
				res = potencia(x, y);
				printf("Resultado da potencia = %d\n", res);
				break;
			case 2:
				scanf("%d%d", &x, &y);
				res = resto(x, y);
				printf("Resto da divisao = %d\n", res);
				break;
			case 3:
				scanf("%f", &fx);
				res = arredonda(x);
				printf("arredondamento = %d\n", res);
				break;
		}
	}while(op != 4);
	return 0;
}


