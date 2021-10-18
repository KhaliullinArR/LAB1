#include <cstdio>
#include <iostream>
#include <locale.h>
#pragma warning(disable : 4996)


const int nmax = 100;



int main(int argc, char* argv[])
{
    double a[nmax], b[nmax], c[nmax];
    double num;
    int na, nb, nc, sa=0, sb=0, sc=0;
    

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
        scanf("%lf", a+i);

    printf("%s", "������� ����� ��������� � ������� B: ");
    scanf("%d", &nb);
    if (nb < 0) {
        printf("%s", "���-�� ��������� ������� ������ ���� ������ ����.");
        return 1;
    }else if (nb > nmax) {
        printf("���-�� ��-��� ������� ������ ���� �� 1 �� %d!", nmax);
        return 1;
    }

    for (int i = 0; i < nb; i++)
        scanf("%lf", b + i);

    printf("%s", "������� ����� ��������� � ������� C: ");
    scanf("%d", &nc);
    if (nc < 0) { 
        printf("%s", "���-�� ��������� ������� ������ ���� ������ ����.");
        return 1; 
    }else if (nc > nmax) {
        printf("���-�� ��-��� ������� ������ ���� �� 1 �� %d!", nmax);
        return 1;
    }

    for (int i = 0; i < nc; i++)
        scanf("%lf", c + i);

    //������� ���-�� ��������� � ������ �������

    //1
    for (int i = 0; i < na; i ++)
        if (a[i] < num) sa++;
    //2
    for (int i = 0; i < nb; i++)
        if (b[i] < num) sb++;
    //3
    for (int i = 0; i < nc; i++)
        if (c[i] < num) sc++;

    FILE* file;
    const char* out = "output.txt";

    if ((file = fopen(out, "w")) == NULL)
    {
        printf("���������� ������� ���� ��� ������\n");
        return 1;
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
        fprintf(file, "%s %lg %s", "� ������� A ���-�� ��������� ������� ", num, " ����������.\n");
        if (sb == sc)fprintf(file, "%s %lg %s", "� ������� B ���-�� ��������� ������� ",num, " ����� ���-�� ��������� � C.");
    }
    else if (sb > sa && sb > sc) {
        fprintf(file, "%s %lg %s", "� ������� B ���-�� ��������� ������� ", num, " ����������.\n");
        if (sa == sc)fprintf(file, "%s %g %s", "� ������� A ���-�� ��������� ������� ", num, " ����� ���-�� ��������� � C.");
    }
    else if (sc > sa && sc > sb) {
        fprintf(file, "%s %lg %s", "� ������� C ���-�� ��������� ������� ", num, " ����������.\n");
        if (sa == sb)fprintf(file, "%s %g %s", "� ������� B ���-�� ��������� ������� ", num, " ����� ���-�� ��������� � A.");
    }
    else if (sa == sb && sa > sc) {
        fprintf(file, "%s %lg %s", "� �������� A � B ���-�� ��������� ������� ", num, " ���������� � ����� ����� �����.");
    }
    else if (sb == sc && sb > sa) {
        fprintf(file, "%s %lg %s", "� �������� A � C ���-�� ��������� ������� ", num, " ���������� � ����� ����� �����.");
    }
    else if (sa == sc && sc > sb) {
        fprintf(file, "%s %lg %s", "� �������� C � A ���-�� ��������� ������� ", num, " ���������� � ����� ����� �����.");
    }
  
}
