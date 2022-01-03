#include <bits/stdc++.h>

typedef struct Nodo{
    int numero;
    struct Nodo *prox;
}Nodo;

Nodo *pL;
int i = 0;

void inicio(Nodo *pNodo){
    (pNodo)->prox = NULL;
}

void insere(Nodo *pNodo){
    Nodo *temp;
    int v;
    printf("Valor a ser inserido:   ");
    scanf("%d", &v);
    temp = (Nodo * )malloc(sizeof(Nodo));
    temp->numero = v;
    temp->prox = (pNodo)->prox;
    (pNodo)->prox = temp;
}

int imprime(Nodo *pNodo){
    Nodo *temp;
    int cont = 0;
    if((pNodo)->prox == NULL){
        printf("A lista se encontra vazia\n");
    }else{
        temp = (Nodo * )malloc(sizeof(Nodo));
        temp = (pNodo)->prox;
        system("cls");
        while(temp != NULL){
            printf("%d numero & %d \n", i ,temp->numero);
            temp = temp->prox;
            i++;
            cont++;
        }
    }
    return cont;
}

void remove(Nodo *pNodo){
    Nodo *temp;
    if((pNodo)->prox == NULL){
        printf("A lista se encontra vazia\n");
    }else{
        temp = (pNodo)->prox;
        (pNodo)->prox = temp->prox;
        free(temp);
    }
}

void insereNum(Nodo *pNodo)
{
    int pos;
    printf("Posicao:   ");
    scanf("%d",&pos);
    if(i == 0){
        insere(pL);
        return;
    }else{
        Nodo *presente, *passado, *futuro;
        presente = pNodo;
        passado = pNodo->prox;
        for(i = 0; i <= pos; i++){
            passado = presente;
            passado = presente->prox;
            passado->prox = futuro;
          	futuro->prox = presente;
    }

    }
}

int main()
{
    int op = 0 , f;
    
	pL = new Nodo;
    inicio(pL);

    do{
        printf("1 - Inserir\n2 - Consultar\n 3 - Remover\n");
        printf("4 - Inserir livremente\n5 - Quantidade de Elementos\n6 - Sair do programa\n");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                insere(pL);
                break;
            case 2:
                imprime(pL);
                break;
            case 3:
                remove(pL);
                break;
            case 4:
                insereNum(pL);
            case 5:
                f = imprime(pL);
                printf("%d", f);
        }
    }while(op != 6);
    return 0;
}








