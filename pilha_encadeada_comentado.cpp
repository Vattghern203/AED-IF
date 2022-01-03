#include <bits/stdc++.h>
//ESTRUTURA QUE POSSUI OS DADOS
struct Pessoa {
    char nome[30];
    int idade;
    char sexo;
};

//ESTRUTURA QUE CONTEM OS DADOS (PESSOA) E MAIS UM PONTEIRO
//PARA O PROXIMO NODO DO ENCADEAMENTO
struct Nodo {
    struct Pessoa pessoa;
    struct Nodo *pProximo;
};

//PONTEIRO CABEÇA/INICIO
//É NECESSÁRIO GRAVAR EM ALGUMA VARIAVEL O ENDERECO DO PRIMEIRO NODO
struct Nodo* pInicio = NULL;

void push(struct Nodo*);

struct Nodo* pop();

void push(struct Nodo *pNodo){

    //UMA PILHA SEGUE O PRINCIPIO LIFO (LAST IN, FIRST OUT)
    //OU SEJA, O ULTIMO ELEMENTO QUE ENTROU É O PRIMEIRO QUE DEVE SER RETIRADO
    //PORTANTO, SEMPRE QUE UM NODO É INSERIDO ELE DEVE SER INCLUIDO NO NODO INICIO
    //E O ELEMENTO QUE ERA O NODO INICIO DEVE SER "EMPURRADO" PARA A PROXIMA POSICAO

    //O PROXIMO DO NODO INSERIDO APONTA PARA O NODO QUE ATUALMENTE É O INICIO
	pNodo->pProximo = pInicio;

    //O INICIO AGORA APONTA PARA O NODO INSERIDO
	pInicio = pNodo;
}

struct Nodo* pop(){
	struct Nodo *pAux = pInicio;

	if(pInicio == NULL){
		printf("A pilha esta vazia!");
		return NULL;
	} else {
        //SEGUINDO A LOGICA DO PUSH, O ULTIMO ELEMENTO INCLUIDO ESTA SEMPRE NA PRIMEIRA POSICAO,
        //OU SEJA, O INICIO APONTA PARA O ULTIMO ELEMENTO INSERIDO
        //PARA RETIRAR BASTA COLOCAR O NODO QUE ESTA SENDO APONTADO PELO INICIO
        //EM UMA VARIAVEL AUXILAR
        //FAZER COM QUE O INICIO APONTE PARA O PROXIMO DO AUXILIAR (ANTIGO INICIO)
		pInicio = pAux->pProximo;
        //RETORNAR O AUX - O ELEMENTO A SER RETIRADO DA PILHA
		return pAux;
	}
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
    struct Nodo nodo2;
    struct Nodo nodo3;
    struct Nodo nodo4;
    struct Nodo nodo5;

    nodo1.pessoa.idade = 18;
    nodo1.pessoa.sexo = 'M';
    strcpy(nodo1.pessoa.nome, "Okabe");

    nodo2.pessoa.idade = 16;
    nodo2.pessoa.sexo = 'M';
    strcpy(nodo2.pessoa.nome, "Lukako");

    nodo3.pessoa.idade = 19;
    nodo3.pessoa.sexo = 'M';
    strcpy(nodo3.pessoa.nome, "Daru");

    nodo4.pessoa.idade = 18;
    nodo4.pessoa.sexo = 'F';
    strcpy(nodo4.pessoa.nome, "Kurisu");

    nodo5.pessoa.idade = 16;
    nodo5.pessoa.sexo = 'F';
    strcpy(nodo5.pessoa.nome, "Mayuri");

				  // Resultado da pilha
    push(&nodo1); //OK Tiago
    push(&nodo2); //OK Carlos - Tiago
    push(&nodo3); //OK Joao - Carlos - Tiago
    imprimir(pop()); //OK Carlos - Tiago
    imprimir(pop()); //OK Tiago
    push(&nodo4); //OK Julia - Tiago
	push(&nodo5); //OK Josue - Julia - Tiago
    imprimir(pop()); //OK Julia - Tiago
    imprimir(pop()); //OK Tiago
    imprimir(pop()); //Fila Vazia

    return 0;
}

