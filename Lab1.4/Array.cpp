#include <cstdio>
#include <iostream>
#pragma warning(disable : 4996)

double* ArrayInput(int* n, char* fname)
{
    FILE* file;
    double* x;

    if ((file = fopen(fname, "r")) == NULL)
    {
        printf("Невозможно открыть файл '%s'\n", fname);
        return 0;
    }
    if (fscanf(file, "%d", n) < 1)
    {
        printf("Ошибка чтения из файла '%s'\n", fname);
        fclose(file);
        return 0;
    }
    if (*n < 0)
    {
        printf("Кол-во эл-тов массива должно быть больше или равно 1! (файл '%s')\n", fname);
        return 0;
    }

    try {
        x = new double[*n];
    }
    catch (std::bad_alloc) {
        printf("Не достаточно памяти для выделения массива в файле %s.", fname);
        return 0;
    }

    for (int i = 0; i < *n; i++)
        if (fscanf(file, "%lf", x + i) < 1)
        {
            printf("Ошибка чтения из файла '%s'\n", fname);
            fclose(file);
            return 0;
        }
    fclose(file);
    return x;
}

int AmountLessThan(double* x, int len, double n)
{
    int s = 0;

    for (int i = 0; i < len; i++)
        if (x[i] < n)s++;

    return s;
}

int Output(double* a, double* b, double* c, int na, int nb, int nc, int* sa, int* sb, int* sc, double* num) {
    FILE* file;
    const char* out = "output.txt";

    if ((file = fopen(out, "w")) == NULL)
    {
        printf("Невозможно открыть файл для записи\n");
        return 0;
    }

    fprintf(file, "Исходные данные:\n\nМассив A:\n");

    for (int i = 0; i < na; i++) {
        fprintf(file, "%-g ", a[i]);
    }

    fprintf(file, "\n");
    fprintf(file, "\n");

    fprintf(file, "Массив 'B':\n");

    for (int i = 0; i < nb; i++) {
        fprintf(file, "%-g ", b[i]);
    }

    fprintf(file, "\n");
    fprintf(file, "\n");
    fprintf(file, "Массив С:\n");
    for (int i = 0; i < nc; i++) {
        fprintf(file, "%-g ", c[i]);
    }

    fprintf(file, "\n");
    fprintf(file, "\n");


    if (sa == sb && sa == sc) printf("%s", "В трех массивах кол-во искомых элементов совпадают");
    else if (sa > sb && sa > sc) {
        fprintf(file, "%s %lg %s", "В массиве A кол-во элементов меньших ", *num, " наибольшее.\n");
        if (sb == sc)fprintf(file, "%s %lg %s", "В массиве B кол-во элементов меньших ", *num, " равно кол-ву элементов в C.");
    }
    else if (sb > sa && sb > sc) {
        fprintf(file, "%s %lg %s", "В массиве B кол-во элементов меньших ", *num, " наибольшее.\n");
        if (sa == sc)fprintf(file, "%s %g %s", "В массиве A кол-во элементов меньших ", *num, " равно кол-ву элементов в C.");
    }
    else if (sc > sa && sc > sb) {
        fprintf(file, "%s %lg %s", "В массиве C кол-во элементов меньших ", *num, " наибольшее.\n");
        if (sa == sb)fprintf(file, "%s %g %s", "В массиве B кол-во элементов меньших ", *num, " равно кол-ву элементов в A.");
    }
    else if (sa == sb && sa > sc) {
        fprintf(file, "%s %lg %s", "В массивах A и B кол-во элементов меньших ", *num, " наибольшее и равны между собой.");
    }
    else if (sb == sc && sb > sa) {
        fprintf(file, "%s %lg %s", "В массивах A и C кол-во элементов меньших ", *num, " наибольшее и равны между собой.");
    }
    else if (sa == sc && sc > sb) {
        fprintf(file, "%s %lg %s", "В массивах C и A кол-во элементов меньших ", *num, " наибольшее и равны между собой.");
    }

    return 1;
}