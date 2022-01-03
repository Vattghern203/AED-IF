#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){
	FILE *fp, *fp2;
	char str[100], str2[100];
	
	if((fp=fopen("arquivoteste.txt", "r"))==NULL)
    {
        printf("arquivo não pode ser aberto\n");
        exit(1);
    }
    
    fputs(str, fp);
    
    fp2 = fopen("copiateste.txt", "w");
    
    fputs(str2, fp2);
    
    
    return 0;
}
