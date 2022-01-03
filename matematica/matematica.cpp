#include "matematica.h"
#include <bits/stdc++.h>

int potencia(int base, int expo){
	int r = 0;
	for(int i = 0; i < expo; i++){
		r = r + base * base;
	}
	return r;
}

int resto(int val, int div){
	int ri;
	ri = val % div;
	return ri;
}

int arredonda(float vlr){
	int r;
	r = floor(vlr);
	return r;
}
