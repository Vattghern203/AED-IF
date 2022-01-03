#include<bits/stdc++.h>

typedef struct Nodo {
	int numero;
    struct Nodo *pProximo;
};

struct Nodo *pInicio=NULL;

void inserir(struct Nodo* pNodo){
    if(pInicio==NULL)
        pInicio=pNodo;
    else{
        struct Nodo* pFim=pInicio;
        while(pFim->pProximo!=NULL){
            pFim=pFim->pProximo;
        }
        pFim->pProximo=pNodo;
    }
    pNodo->pProximo=NULL;
}

void remover(struct Nodo* pNodo){
    if(pInicio!=NULL){
        if(pNodo==pInicio){
            pInicio=pNodo->pProximo;
        }else{
            struct Nodo *pAtual=pInicio;
            struct Nodo *pAnterior=NULL;
            while(pAtual!=pNodo&&pAtual!=NULL){
                pAnterior=pAtual;
                pAtual=pAtual->pProximo;
            }
            if(pAtual==NULL){
                printf("O Elemento nao foi encontrado na lista!\n");
            }else{
                pAnterior->pProximo=pAtual->pProximo;
            }
        }
    }
    else{
        printf("A lista esta vazia\n");
    }
}

void imprimir(){
    if(pInicio==NULL)
        printf("A lista está vazia!\n");
    else{
        struct Nodo*pAtual=pInicio;
        while(pAtual!=NULL){
            printf("%d\n",pAtual->numero);
            pAtual=pAtual->pProximo;
        }
    }
}

int main(){
    struct Nodo nodo1;
    nodo1.numero=10;
    struct Nodo nodo2;
    nodo2.numero=20;
    struct Nodo nodo3;
    nodo3.numero=5;
    struct Nodo nodo4;
    nodo4.numero=2;
    //imprimir();//VAZIO
    inserir(&nodo1);
    inserir(&nodo2);
    inserir(&nodo3);
    printf("Depois das inclusoes:\n");
    imprimir();//nodo1,nodo2,nodo3.
    remover(&nodo1);
    printf("Depois da exclusao:\n");
    imprimir();//nodo2,nodo3.
    inserir(&nodo4);
    printf("Depois da inclusao do nodo4:\n");
    imprimir();//nodo2,nodo3,nodo4.
    remover(&nodo3);
    printf("Depois da exclusao do nodo3:\n");
    imprimir();//nodo2,nodo4
    return 0;
}
