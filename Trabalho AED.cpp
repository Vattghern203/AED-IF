#include <bits/stdc++.h>

int primo(int n) {
	int i;
	int m = n / 2;
	
	for (i = 2; i <= m; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

int pegarMDC(int n1, int n2) {
	int i, mdc;

	for(i = 1; i <= n1 && i <= n2; ++i){
		if(n1 % i == 0 && n2 % i == 0)
			mdc = i;
	}

	return mdc;
}

int mod(int A, int B, int n) {
	long long X = 1, Y = A;

	while (B > 0) {
		if (B % 2 != 0)
			X = (X * Y) % n;
		Y = (Y * Y) % n;
		B /= 2;
	}

	return X % n;
}

int main() {
	int P, Q, E, I;
	int n, Z;
	int num, criptografado, descriptografado;

	while (1) {
		printf("Coloque dois numeros primos P e Q: ");
		scanf("%d %d", &P, &Q);

		if (!(primo(P) && primo(Q)))
			printf("Numeros nao sao primos, coloque numeros primos...\n");
		else if (!primo(P))
			printf("Primeiro numero nao eh primo, coloque um numero primo...\n");
		else if (!primo(Q))
			printf("Segundo numero nao eh primo, coloque um numero primo...\n");
		else
			break;
	}
	
	n = P * Q;

	Z = (P - 1) * (Q - 1);
	printf("N = %d\nZ = %d\n", n, Z);
	printf("Escolha E (primo de Z e menor que N): ");
	scanf("%d", &E);
	if(E>=n){
		printf("E eh maior ou igual a N");
		return 0;
	}
	while(I = E){
		if (pegarMDC(Z, I) == 1)
				break;
		else{
			printf("E nao eh primo de Z");
			return 0;
		}
	}
	
	int D = 0;
	for (D = E + 1; D <= 100; D++) {
		if ( ((D * E) % Z) == 1)
			break;
	}

	printf("Valor do E: %d\nValor do D: %d\n", E, D);
	printf("Chave Publica: (%d,%d)\n", n, E);
	printf("Chave Privada: (%d,%d)\n", n, D);
	
	printf("Coloque uma sequencia numerica: ");
	scanf("%d", &num);

	criptografado = mod(num, E, n);
	printf("O texto criptografado eh: %d\n", criptografado);

	descriptografado = mod(criptografado, D, n);
	printf("O texto descriptografado eh: %d\n", descriptografado);
	
	return 0;
}
