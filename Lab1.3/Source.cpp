#include <cstdio>
#include <iostream>
#include <locale.h>
#pragma warning(disable : 4996)


const int nmax = 100;

int ArrayInput(int* n, double x[], char* fname);
int AmountLessThan(double[], int, double);    
int OutputArray(double[], int, FILE*);


int main(int argc, char* argv[])
{
    double a[nmax], b[nmax], c[nmax];
    double num;
    int na, nb, nc, sa = 0, sb = 0, sc = 0;

    FILE* file;

    if ((file = fopen("output.txt", "w")) == NULL) {
        printf("Невозможно открыть файл для записи\n");
        return 1;
    }

    setlocale(LC_ALL, "rus");


    printf("%s", "Введите число: ");
    scanf_s("%lf", &num);

    if (argc < 4)
    {
        printf("Недостаточно параметров!\n");
        return 1;
    }
    if (!ArrayInput(&na, a, argv[1]))
        return 1;
    if (!ArrayInput(&nb, b, argv[2]))
        return 1;
    if (!ArrayInput(&nc, c, argv[3]))
        return 1;


    printf("Исходные данные массива A:\n");
    if (!OutputArray(a, na, file)) {
        return 1;
    }

    printf("Исходные данные массива B:\n");
    if (!OutputArray(b, nb, file)) {
        return 1;
    }

    printf("Исходные данные массива C:\n");
    if (!OutputArray(c, nc, file)) {
        return 1;
    }

    sa = AmountLessThan(a, na, num);
    sb = AmountLessThan(b, nb, num);
    sc = AmountLessThan(c, nc, num);

    if (sa == sb && sa == sc) printf("%s", "В трех массивах кол-во искомых элементов совпадают");
    else if (sa > sb && sa > sc) {
        printf("%s %lg %s", "В массиве A кол-во элементов меньших ", num, " наибольшее.\n");
        if (sb == sc)printf("%s %lg %s", "В массиве B кол-во элементов меньших ", num, " равно кол-ву элементов в C.");
    }
    else if (sb > sa && sb > sc) {
        printf("%s %lg %s", "В массиве B кол-во элементов меньших ", num, " наибольшее.\n");
        if (sa == sc)printf("%s %g %s", "В массиве A кол-во элементов меньших ", num, " равно кол-ву элементов в C.");
    }
    else if (sc > sa && sc > sb) {
        printf("%s %lg %s", "В массиве C кол-во элементов меньших ", num, " наибольшее.\n");
        if (sa == sb)printf("%s %g %s", "В массиве B кол-во элементов меньших ", num, " равно кол-ву элементов в A.");
    }
    else if (sa == sb && sa > sc) {
        printf("%s %lg %s", "В массивах A и B кол-во элементов меньших ", num, " наибольшее и равны между собой.");
    }
    else if (sb == sc && sb > sa) {
        printf("%s %lg %s", "В массивах A и C кол-во элементов меньших ", num, " наибольшее и равны между собой.");
    }
    else if (sa == sc && sc > sb) {
        printf("%s %lg %s", "В массивах C и A кол-во элементов меньших ", num, " наибольшее и равны между собой.");
    }

    fclose(file);
}

int OutputArray(double a[], int na, FILE* file) {

    for (int i = 0; i < na; i++) {
        if (fprintf(file, "%-g ", a[i]) < 1) {
            return 0;
        }
    }

    fprintf(file, "\n");
    fprintf(file, "\n");


    return 1;
}
int ArrayInput(int* n, double x[], char* fname)
{
    FILE* file;

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
    if (*n < 0 || *n > nmax)
    {
        printf("Кол-во эл-тов массива должно быть от 1 до %d! (файл '%s')\n", nmax, fname);
        return 0;
    }
    for (int i = 0; i < *n; i++)
        if (fscanf(file, "%lf", &x[i]) < 1)
        {
            printf("Ошибка чтения из файла '%s'\n", fname);
            fclose(file);
            return 0;
        }
    fclose(file);
    return 1;
}

int AmountLessThan(double x[], int len, double n)
{
    int s = 0;

    for (int i = 0; i < len; i++)
        if (x[i] < n)s++;

    return s;
}