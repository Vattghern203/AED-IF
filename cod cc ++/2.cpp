#include<bits/stdc++.h>

typedef struct Nodo{
    int dado;
    struct Nodo *proximo;
}Nodo;

Nodo *pLista;
int i=0;

void inicio(Nodo *pNodo){
    (pNodo)->proximo = NULL;
}

void inserir(Nodo *pNodo){
    Nodo *temporario;
    int valor;
    printf("\nInforme um valor a ser inserido : ");
    scanf("%d",&valor);
    temporario = (Nodo * )malloc(sizeof(Nodo));
    temporario->dado = valor;
    temporario->proximo = (pNodo)->proximo;
    (pNodo)->proximo = temporario;
}

int imprimir(Nodo *pNodo){
    Nodo *temporario;
    int cont=0;
    if((pNodo)->proximo == NULL){
        printf("Lista Vazia!\n");
    }else{
        temporario = (Nodo * )malloc(sizeof(Nodo));
        temporario = (pNodo)->proximo;
        system("cls");
        while(temporario!=NULL){
            printf("[%d] Valor : %d \n",i,temporario->dado);
            temporario = temporario->proximo;
            i++;
            cont++;
        }
    }
    return cont;
}

void remover(Nodo *pNodo){
    Nodo *temporario;
    if((pNodo)->proximo == NULL){
        printf("\nLista Vazia!");
    }else{
        temporario = (pNodo)->proximo;
        (pNodo)->proximo = temporario->proximo;
        free(temporario);
    }
}

void inserirPosicao(Nodo *pNodo)
{
    int pos;
    printf("Qual a posicao:");
    scanf("%d",&pos);
    if (i==0)
    {
        inserir(pLista);
        return;
    }else{
        Nodo *atual,*anterior,*novo;
        atual=pNodo;
        anterior=pNodo->proximo;
        for(i=0 ; i<=pos ; i++){
            anterior=atual;
            atual=atual->proximo;
            anterior->proximo = novo;
            novo->proximo = atual;
    }


    }
}


int main()
{
    int opcao=0,r;

    pLista = new Nodo;
    inicio(pLista);

    do{
        printf("\n1 - Inserir : ");
        printf("\n2 - Consultar : ");
        printf("\n3 - Remover : ");
        printf("\n4 - INSERIR EM POSICAO QUALQUER : ");
        printf("\n5 - Mostrar quantos elementos tem na lista:");
        printf("\n6 - Sair\n\t");
        scanf("%d",&opcao);
        switch(opcao)
        {
                case 1:
                    inserir(pLista);
                    break;
                case 2:
                    imprimir(pLista);
                    break;
                case 3:
                    remover(pLista);
                    break;
                case 4:
                    inserirPosicao(pLista);
                case 5:
                    r=imprimir(pLista);
                    printf("%d",r);
        }
    }while(opcao!=6);
    return 0;
}








