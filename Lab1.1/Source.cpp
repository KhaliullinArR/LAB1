#include <cstdio>
#include <iostream>
#include <locale.h>
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)


const int nmax = 100;



int main(int argc, char* argv[]) {
    double a[nmax], b[nmax], c[nmax];
    double num;
    int na, nb, nc, sa = 0, sb = 0, sc = 0;


    setlocale(LC_ALL, "rus");


    printf("%s", "������� �����: ");
    scanf("%lf", &num);

    printf("%s", "������� ����� ��������� � ������� A: ");
    scanf("%d", &na);

    if (na < 0) {
        printf("%s", "���-�� ��������� ������� ������ ���� ������ ����.");
        return 1;
    }
    else if (na > nmax) {
        printf("���-�� ��-��� ������� ������ ���� �� 1 �� %d!", nmax);
        return 1;
    }

    for (int i = 0; i < na; i++)
        scanf("%lf", &a[i]);

    printf("%s", "������� ����� ��������� � ������� B: ");
    scanf("%d", &nb);
    if (nb < 0) {
        printf("%s", "���-�� ��������� ������� ������ ���� ������ ����.");
        return 1;
    }
    else if (nb > nmax) {
        printf("���-�� ��-��� ������� ������ ���� �� 1 �� %d!", nmax);
        return 1;
    }

    for (int i = 0; i < nb; i++)
        scanf("%lf", &b[i]);

    printf("%s", "������� ����� ��������� � ������� C: ");
    scanf("%d", &nc);
    if (nc < 0) {
        printf("%s", "���-�� ��������� ������� ������ ���� ������ ����.");
        return 1;
    }
    else if (nc > nmax) {
        printf("���-�� ��-��� ������� ������ ���� �� 1 �� %d!", nmax);
        return 1;
    }

    for (int i = 0; i < nc; i++)
        scanf("%lf", &c[i]);

    //������� ���-�� ��������� � ������ �������

    //1
    for (int i = 0; i < na; i++)
        if (a[i] < num) sa++;
    //2
    for (int i = 0; i < nb; i++)
        if (b[i] < num) sb++;
    //3
    for (int i = 0; i < nc; i++)
        if (c[i] < num) sc++;


    printf("\n");

    printf("�������� ������:\n\n������ A:\n");

    for (int i = 0; i < na; i++) {
        printf("%-g ", a[i]);
    }

    printf("\n");
    printf("\n");

    printf("������ 'B':\n");

    for (int i = 0; i < nb; i++) {
        printf("%-g ", b[i]);
    }

    printf("\n");
    printf("\n");
    printf("������ �:\n");
    for (int i = 0; i < nc; i++) {
        printf("%-g ", c[i]);
    }

    printf("\n");
    printf("\n");


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

    printf("\n");
    printf("\n");
}
