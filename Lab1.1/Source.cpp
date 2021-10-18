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


    printf("%s", "Введите число: ");
    scanf("%lf", &num);

    printf("%s", "Введите число элементов в массиве A: ");
    scanf("%d", &na);
  
    if (na < 0) {
        printf("%s", "Кол-во элементов массива должно быть больше нуля.");
        return 1;
    }
    else if (na > nmax) {
        printf("Кол-во эл-тов массива должно быть от 1 до %d!", nmax);
        return 1;
    }

    for (int i = 0; i < na; i++)
        scanf("%lf", a+i);

    printf("%s", "Введите число элементов в массиве B: ");
    scanf("%d", &nb);
    if (nb < 0) {
        printf("%s", "Кол-во элементов массива должно быть больше нуля.");
        return 1;
    }else if (nb > nmax) {
        printf("Кол-во эл-тов массива должно быть от 1 до %d!", nmax);
        return 1;
    }

    for (int i = 0; i < nb; i++)
        scanf("%lf", b + i);

    printf("%s", "Введите число элементов в массиве C: ");
    scanf("%d", &nc);
    if (nc < 0) { 
        printf("%s", "Кол-во элементов массива должно быть больше нуля.");
        return 1; 
    }else if (nc > nmax) {
        printf("Кол-во эл-тов массива должно быть от 1 до %d!", nmax);
        return 1;
    }

    for (int i = 0; i < nc; i++)
        scanf("%lf", c + i);

    //Считаем кол-во элементво в каждом массиве

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
        printf("Невозможно открыть файл для записи\n");
        return 1;
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
        fprintf(file, "%s %lg %s", "В массиве A кол-во элементов меньших ", num, " наибольшее.\n");
        if (sb == sc)fprintf(file, "%s %lg %s", "В массиве B кол-во элементов меньших ",num, " равно кол-ву элементов в C.");
    }
    else if (sb > sa && sb > sc) {
        fprintf(file, "%s %lg %s", "В массиве B кол-во элементов меньших ", num, " наибольшее.\n");
        if (sa == sc)fprintf(file, "%s %g %s", "В массиве A кол-во элементов меньших ", num, " равно кол-ву элементов в C.");
    }
    else if (sc > sa && sc > sb) {
        fprintf(file, "%s %lg %s", "В массиве C кол-во элементов меньших ", num, " наибольшее.\n");
        if (sa == sb)fprintf(file, "%s %g %s", "В массиве B кол-во элементов меньших ", num, " равно кол-ву элементов в A.");
    }
    else if (sa == sb && sa > sc) {
        fprintf(file, "%s %lg %s", "В массивах A и B кол-во элементов меньших ", num, " наибольшее и равны между собой.");
    }
    else if (sb == sc && sb > sa) {
        fprintf(file, "%s %lg %s", "В массивах A и C кол-во элементов меньших ", num, " наибольшее и равны между собой.");
    }
    else if (sa == sc && sc > sb) {
        fprintf(file, "%s %lg %s", "В массивах C и A кол-во элементов меньших ", num, " наибольшее и равны между собой.");
    }
  
}
