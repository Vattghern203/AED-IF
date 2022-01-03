#include <bits/stdc++.h>
int topo = 0; //INICIALIZA NA PRIMEIRA POSICAO DO VETOR
#define MAX 3 //DEFINE O TAMANHO MAXIMO DA PILHA
int pilha[MAX];

//METODO UTILIZADO PARA INCLUIR UM VALOR NA PILHA
void push(int valor) {
    if ( topo < MAX ) {
        //CASO O TOPO SEJA MENOR QUE O MAX, A PILHA AINDA POSSUI POSICOES PARA SEREM UTILIZADAS
        pilha[topo] = valor; //O APONTADOR DO TOPO DA PILHA E UTILIZADO PARA INCLUIR O NOVO VALOR NO VETOR
        printf("topo=%d\n",pilha[topo]);
        topo++; //O APONTADOR DO TOPO DA PILHA E INCREMENTADO
    } else {
        printf("pilha cheia\n");
    }
}

//Implementar... exercício da lista
int pop() {

}

//Implementar... exercício da lista
void imprime_pilha(void){

}

int main(int argc, char** argv) {
    push(10); //10 - OK
    push(7); //10,7 - OK
    push(5); //10,7,5  - OK
    push(8); //10,7,5 - PILHA CHEIA

    return 0;
}
