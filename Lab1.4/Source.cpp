#include <iostream>
#include <locale.h>
#include "Array_h.h"
#pragma warning(disable : 4996)




int main(int argc, char* argv[])
{
    double *a = 0, *b = 0, *c = 0;
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

    ArrayInput(&na, argv[1], a);
    if (!a)
        return 1;

    ArrayInput(&nb, argv[2], b);
    if (!b)
        return 1;
    ArrayInput(&nc, argv[3], c);
    if (!c)
        return 1;


    sa = AmountLessThan(a, na, num);
    sb = AmountLessThan(b, nb, num);
    sc = AmountLessThan(c, nc, num);

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

    delete[] a;
    delete[] b;
    delete[] c;

    a = 0;
    b = 0;
    c = 0;

    


}



