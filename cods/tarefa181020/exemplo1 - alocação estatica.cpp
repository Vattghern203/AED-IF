#include <bits/stdc++.h>

int main(){
	float x, y, *r, soma;
	r = (float *) malloc(sizeof(float));
	scanf("%f%f", &x, &y);
	soma = x + y;
	r = &soma;
	printf("Soma = %.2f\n", *r);
	return 0;
}
