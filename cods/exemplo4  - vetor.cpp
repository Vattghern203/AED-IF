#include <bits/stdc++.h>
#define MAX 100000000
main()
{
    int *vetor, i;
    vetor = (int *)malloc(MAX*sizeof(int));
    if(vetor==NULL)
    {
        printf("Sem memoria!");
        system("pause>nul");
        exit(0);
    }
    for(i=0; i<MAX; i++)
    {
        vetor[i]=i;
    }
    free(vetor);
    system("pause>nul");
}
