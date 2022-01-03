#include <bits/stdc++.h>

int inicio = 0, fim = 0;
#define MAX 5 //DEFINE O TAMANHO MAXIMO DA FILA
int fila[MAX];

void enqueue(int valor) {
    if (fim < MAX) {
        fila[fim] = valor;
        printf("%d entrou na fila\n",fila[fim]);
        fim++;
    } else {
        printf("Fila cheia\n");
    }
}

int denqueue() {
    int ret;
    if (fim > 0) {
        ret=fila[inicio];
        inicio++;
        return ret;
    } else {
        printf("Fila vazia!\n");
    }
}

void mostraFila(){
    int i;
    printf("Mostrando fila:\n");
    for(i=inicio;i<fim;i++){
        printf("%d\n",fila[i]);
    }
}

int main(int argc, char** argv) {
    enqueue(10); //10 - OK
    enqueue(7); //10,7 - OK
    enqueue(5); //10,7,5  - OK
    enqueue(8); //10,7,5, 8 - OK
    printf("Saiu da fila: %d\n",denqueue());
    mostraFila();//7,5,8
    enqueue(1);//7,5,8,1
    mostraFila();//7,5,8,1
    enqueue(3);//FILA CHEIA
    return 0;
}
