#include <bits/stdc++.h>
#include "perfil.h"

int main(){
	int op;
	perfil *p;
	aloc();
	
	do{
		printf("Bem-Vindo\nEscolha uma das opcoes abaixo: \n");
		printf("1 - Cria cliente\n2 - Liberar memoria\n3 - Acessar dados\n4 - Ver perfil criado\n5 - Sair\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				cria();
				break;
			case 2:
				libera(p);
				break;
			case 3:
				acessa();
				break;
			case 4:
				perfila();
				break;
		}
	}while(op != 5);
    return 0;	
}
