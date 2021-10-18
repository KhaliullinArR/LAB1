#include <cstdio>
#include <iostream>
#pragma warning(disable : 4996)

double* ArrayInput(int* n, char* fname)
{
    FILE* file;
    double* x;

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
    if (*n < 0)
    {
        printf("���-�� ��-��� ������� ������ ���� ������ ��� ����� 1! (���� '%s')\n", fname);
        return 0;
    }

    try {
        x = new double[*n];
    }
    catch (std::bad_alloc) {
        printf("�� ���������� ������ ��� ��������� ������� � ����� %s.", fname);
        return 0;
    }

    for (int i = 0; i < *n; i++)
        if (fscanf(file, "%lf", x + i) < 1)
        {
            printf("������ ������ �� ����� '%s'\n", fname);
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
        printf("���������� ������� ���� ��� ������\n");
        return 0;
    }

    fprintf(file, "�������� ������:\n\n������ A:\n");

    for (int i = 0; i < na; i++) {
        fprintf(file, "%-g ", a[i]);
    }

    fprintf(file, "\n");
    fprintf(file, "\n");

    fprintf(file, "������ 'B':\n");

    for (int i = 0; i < nb; i++) {
        fprintf(file, "%-g ", b[i]);
    }

    fprintf(file, "\n");
    fprintf(file, "\n");
    fprintf(file, "������ �:\n");
    for (int i = 0; i < nc; i++) {
        fprintf(file, "%-g ", c[i]);
    }

    fprintf(file, "\n");
    fprintf(file, "\n");


    if (sa == sb && sa == sc) printf("%s", "� ���� �������� ���-�� ������� ��������� ���������");
    else if (sa > sb && sa > sc) {
        fprintf(file, "%s %lg %s", "� ������� A ���-�� ��������� ������� ", *num, " ����������.\n");
        if (sb == sc)fprintf(file, "%s %lg %s", "� ������� B ���-�� ��������� ������� ", *num, " ����� ���-�� ��������� � C.");
    }
    else if (sb > sa && sb > sc) {
        fprintf(file, "%s %lg %s", "� ������� B ���-�� ��������� ������� ", *num, " ����������.\n");
        if (sa == sc)fprintf(file, "%s %g %s", "� ������� A ���-�� ��������� ������� ", *num, " ����� ���-�� ��������� � C.");
    }
    else if (sc > sa && sc > sb) {
        fprintf(file, "%s %lg %s", "� ������� C ���-�� ��������� ������� ", *num, " ����������.\n");
        if (sa == sb)fprintf(file, "%s %g %s", "� ������� B ���-�� ��������� ������� ", *num, " ����� ���-�� ��������� � A.");
    }
    else if (sa == sb && sa > sc) {
        fprintf(file, "%s %lg %s", "� �������� A � B ���-�� ��������� ������� ", *num, " ���������� � ����� ����� �����.");
    }
    else if (sb == sc && sb > sa) {
        fprintf(file, "%s %lg %s", "� �������� A � C ���-�� ��������� ������� ", *num, " ���������� � ����� ����� �����.");
    }
    else if (sa == sc && sc > sb) {
        fprintf(file, "%s %lg %s", "� �������� C � A ���-�� ��������� ������� ", *num, " ���������� � ����� ����� �����.");
    }

    return 1;
}