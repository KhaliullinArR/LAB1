#include <cstdio>
#include <iostream>
#pragma warning(disable : 4996)

void ArrayInput(int* n, char* fname, double *&x)
{
    FILE* file;

    if ((file = fopen(fname, "r")) == NULL)
    {
        printf("Невозможно открыть файл '%s'\n", fname);
        x = 0;
        return;
    }
    if (fscanf(file, "%d", n) < 1)
    {
        printf("Ошибка чтения из файла '%s'\n", fname);
        fclose(file);
        x = 0;
        return;
    }
    if (*n < 0)
    {
        printf("Кол-во эл-тов массива должно быть больше или равно 1! (файл '%s')\n", fname);
        x = 0;
        return;
    }

    try {
        x = new double[*n];
    }
    catch (std::bad_alloc) {
        printf("Не достаточно памяти для выделения массива в файле %s.", fname);
        x = 0;
        return;
    }

    for (int i = 0; i < *n; i++)
        if (fscanf(file, "%lf", x + i) < 1)
        {
            printf("Ошибка чтения из файла '%s'\n", fname);
            fclose(file);
            x = 0;
            return;
        }
    fclose(file);
    return;
}

int AmountLessThan(double* x, int len, double n)
{
    int s = 0;

    for (int i = 0; i < len; i++)
        if (x[i] < n)s++;

    return s;
}

int OutputArray(double* a, int na, FILE* file) {
    for (int i = 0; i < na; i++) {
        if (fprintf(file, "%-g ", a[i]) < 1) {
            return 0;
        }
    }

    fprintf(file, "\n");
    fprintf(file, "\n");

    return 1;
}