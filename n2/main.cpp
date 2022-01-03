#include<bits/stdc++.h>
#include "N2PROVA.h"

int main(){
    int opcao;
    cliente* c;
    alocar();
    do{
    	printf("*******************\nSelecione uma opcao\n");
        printf("1 - Cadastrar Cliente\n2 - Acessar dados\n");
        printf("3 - Devolver perfil\n4 - Liberar memoria\n");
        printf("Opcao escolhida: ");
    	scanf("%d", &opcao);
        switch (opcao){
            case 1:
                criar_cliente();
                break;
            case 2:
                acessar_dados();
                break;
            case 3:
                devolve_perfil();
                break;
            case 4:
                liberar(c);
                break;
        }
    }while(opcao != 4);
    return 0;
}
