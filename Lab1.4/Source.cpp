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

    delete[] a;
    delete[] b;
    delete[] c;

    a = 0;
    b = 0;
    c = 0;

    


}



