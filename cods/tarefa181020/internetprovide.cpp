#include <bits/stdc++.h>


typedef struct{
	char cod, mail;
	double hrs, total;
}cliente;

main(){
	cliente **c;
	int i, max = 10;
	c = (cliente **)malloc(max*sizeof(cliente *));
    for(i = 0; i < max; i++)
        c[i] = (cliente *)malloc(sizeof(cliente));
    for(i = 0; i < max; i++)
    {
    	printf("Digite o seu codigo: \n");
    	scanf(" %[^\n]", c[i]->cod);
    	printf("Digite seu email: \n");
    	scanf(" %[^\n]", c[i]->mail);
    	printf("Digite o tempo de uso: \n");
    	scanf("%d", &c[i]->hrs);
	}
	for(i = 0; i < max; i++){
		  	if(c[i]->hrs <= 20.00)
    			c[i]->total = 35.00;
    		else{
    			c[i]->total = (((c[i]->hrs - 20.00) / 60)*(2.50)+(35.00));
		}
		printf("Cliente %s, ira pagar : %.2lf reais \n", c[i]->cod, c[i]->total);	
	}

	for(i = 0; i < max; i++)
        free(c[i]);
    free(c);
    system("pause>nul");
}
