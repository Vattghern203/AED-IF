#include <stdio.h>
#include <stdlib.h>
#define MAX 5
main()
{
    int **matriz, i,j;
    matriz = (int **)malloc(MAX*sizeof(int *));
    for(i=0; i<MAX; i++)
        matriz[i] = (int *)malloc(MAX*sizeof(int));
    for(i=0; i<MAX; i++)
    {
        for(j=0; j<MAX; j++)
        {
            matriz[i][j]=i+j;
        }
    }
    for(i=0; i<MAX; i++)
        free(matriz[i]);
    free(matriz);
    system("pause>nul");
}
