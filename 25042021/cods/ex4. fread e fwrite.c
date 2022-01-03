#include <stdio.h>
#include <stdlib.h>
main()
{
    FILE *fp;
    double d = 12.23;
    int i = 101;
    long l = 123023L;
    char nome[50]="Algor015itm0s e 357Estru248turas 065de d4ad0s 3";
    if ((fp=fopen("dados.dat", "wb+")) == NULL)
    {
        printf("arquivo não pode ser aberto\n");
        exit(1);
    }
    fwrite(&nome, sizeof(char[50]), 1, fp);
//    fwrite(&d, sizeof(double), 1, fp);
//    fwrite(&i, sizeof(int), 1, fp);
//    fwrite(&l, sizeof(long), 1, fp);
    rewind(fp);
//    fread(&d, sizeof(double), 1, fp);
//    fread(&i, sizeof(int), 1, fp);
//    fread(&l, sizeof(long), 1, fp);
    fread(&nome, sizeof(char[50]), 1, fp);
//    printf("%f %d %ld", d, i, l);
    printf("%s\n",nome);
    fclose(fp);
}
