
#include <stack>
#include <iostream>

int main(){

	stack <string> cartas; 

	cartas.push("Rei de Copas");
	cartas.push("Rei de Ouros");
	cartas.push("Rei de Espadas");
	cartas.push("Rei de Paus");
	
	printf("Tamanho da Pilha: ", cartas.size()"\n");
	
	printf("Carta do Topo: ", cartas.pop())"\n";
	
	cartas.pop();
	cartas.pop();
	
	printf("Nova carta do topo: ", cartas.top()"\n");
	
	return 0;
}
