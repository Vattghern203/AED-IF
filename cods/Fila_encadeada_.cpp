#include <bits/stdc++.h>

struct Pessoa {
    char nome[30];
    int idade;
    char sexo;
};

struct Nodo {
    struct Pessoa pessoa;
    struct Nodo *pProximo;
};

struct Nodo* pInicio = NULL;
struct Nodo* pFim = NULL;

void enqueue(struct Nodo* pNodo) {
    if ( pInicio==NULL ) {
        pInicio = pNodo;
    } else {
        pFim->pProximo=pNodo;
    }

    pFim = pNodo;
    pNodo->pProximo = NULL;
}

struct Nodo* denqueue() {
    struct Nodo* pAux = pInicio;
    if ( pInicio != NULL )
        pInicio = pAux->pProximo;
    return pAux;
}

void imprimir(struct Nodo *pNodo) {
    if ( pNodo != NULL ) {
        printf("Nome %s, idade %d, sexo %c\n",
                pNodo->pessoa.nome,
                pNodo->pessoa.idade,
                pNodo->pessoa.sexo);
    } else {
        printf("Vazio\n");
    }
}

int main(int argc, char** argv) {

    struct Nodo nodo1;
    nodo1.pessoa.idade = 30;
    nodo1.pessoa.sexo = 'M';
    strcpy(nodo1.pessoa.nome, "Tiago");

    struct Nodo nodo2;
    nodo2.pessoa.idade = 35;
    nodo2.pessoa.sexo = 'F';
    strcpy(nodo2.pessoa.nome, "Fernanda");

    struct Nodo nodo3;
    nodo3.pessoa.idade = 12;
    nodo3.pessoa.sexo = 'M';
    strcpy(nodo3.pessoa.nome, "Joao");

    struct Nodo nodo4;
    nodo4.pessoa.idade = 14;
    nodo4.pessoa.sexo = 'F';
    strcpy(nodo4.pessoa.nome, "Julia");

    struct Nodo nodo5;
    nodo5.pessoa.idade = 12;
    nodo5.pessoa.sexo = 'M';
    strcpy(nodo5.pessoa.nome, "Josue");

    enqueue(&nodo1); //OK Tiago
    enqueue(&nodo2); //OK Tiago - Fernanda
    enqueue(&nodo3); //OK Tiago - Fernanda - Joao
    imprimir(denqueue()); //Imprime Tiago (Fernanda - Joao)
    enqueue(&nodo4); //OK Fernanda - Joao - Julia
    enqueue(&nodo4); //OK Fernanda - Joao - Julia
    imprimir(denqueue()); //Imprime Fernanda (Joao - Julia)
    imprimir(denqueue()); //Imprime Joao (Julia)
    imprimir(denqueue()); //Imprime Julia (VAZIO)
    imprimir(denqueue()); //Fila Vazia
    enqueue(&nodo5); //OK Josue
    imprimir(denqueue()); //Imprime Josue (VAZIO)
    imprimir(denqueue()); //Fila Vazia

    return 0;
}

