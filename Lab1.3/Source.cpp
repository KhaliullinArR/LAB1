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
        printf("���������� ������� ���� ��� ������\n");
        return 1;
    }

    setlocale(LC_ALL, "rus");


    printf("%s", "������� �����: ");
    scanf_s("%lf", &num);

    if (argc < 4)
    {
        printf("������������ ����������!\n");
        return 1;
    }
    if (!ArrayInput(&na, a, argv[1]))
        return 1;
    if (!ArrayInput(&nb, b, argv[2]))
        return 1;
    if (!ArrayInput(&nc, c, argv[3]))
        return 1;


    printf("�������� ������ ������� A:\n");
    if (!OutputArray(a, na, file)) {
        return 1;
    }

    printf("�������� ������ ������� B:\n");
    if (!OutputArray(b, nb, file)) {
        return 1;
    }

    printf("�������� ������ ������� C:\n");
    if (!OutputArray(c, nc, file)) {
        return 1;
    }

    sa = AmountLessThan(a, na, num);
    sb = AmountLessThan(b, nb, num);
    sc = AmountLessThan(c, nc, num);

    if (sa == sb && sa == sc) printf("%s", "� ���� �������� ���-�� ������� ��������� ���������");
    else if (sa > sb && sa > sc) {
        printf("%s %lg %s", "� ������� A ���-�� ��������� ������� ", num, " ����������.\n");
        if (sb == sc)printf("%s %lg %s", "� ������� B ���-�� ��������� ������� ", num, " ����� ���-�� ��������� � C.");
    }
    else if (sb > sa && sb > sc) {
        printf("%s %lg %s", "� ������� B ���-�� ��������� ������� ", num, " ����������.\n");
        if (sa == sc)printf("%s %g %s", "� ������� A ���-�� ��������� ������� ", num, " ����� ���-�� ��������� � C.");
    }
    else if (sc > sa && sc > sb) {
        printf("%s %lg %s", "� ������� C ���-�� ��������� ������� ", num, " ����������.\n");
        if (sa == sb)printf("%s %g %s", "� ������� B ���-�� ��������� ������� ", num, " ����� ���-�� ��������� � A.");
    }
    else if (sa == sb && sa > sc) {
        printf("%s %lg %s", "� �������� A � B ���-�� ��������� ������� ", num, " ���������� � ����� ����� �����.");
    }
    else if (sb == sc && sb > sa) {
        printf("%s %lg %s", "� �������� A � C ���-�� ��������� ������� ", num, " ���������� � ����� ����� �����.");
    }
    else if (sa == sc && sc > sb) {
        printf("%s %lg %s", "� �������� C � A ���-�� ��������� ������� ", num, " ���������� � ����� ����� �����.");
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
        printf("���������� ������� ���� '%s'\n", fname);
        return 0;
    }
    if (fscanf(file, "%d", n) < 1)
    {
        printf("������ ������ �� ����� '%s'\n", fname);
        fclose(file);
        return 0;
    }
    if (*n < 0 || *n > nmax)
    {
        printf("���-�� ��-��� ������� ������ ���� �� 1 �� %d! (���� '%s')\n", nmax, fname);
        return 0;
    }
    for (int i = 0; i < *n; i++)
        if (fscanf(file, "%lf", &x[i]) < 1)
        {
            printf("������ ������ �� ����� '%s'\n", fname);
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