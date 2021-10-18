#include <cstdio>
#include <iostream>
#include <locale.h>
#pragma warning(disable : 4996)
123

const int nmax = 100;

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
        if (fscanf(file, "%lf", x + i) < 1)
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



int main(int argc, char* argv[])
{
    double a[nmax], b[nmax], c[nmax];
    double num;
    int na, nb, nc, sa = 0, sb = 0, sc = 0;

    setlocale(LC_ALL, "rus");                            // Меняем кодировку для консольного приложения

    printf("%s", "Введите число: ");
    scanf_s("%lf", &num);

    if (!ArrayInput(&na, a, argv[1]))
        return 1;
    if (!ArrayInput(&nb, b, argv[2]))
        return 1;
    if (!ArrayInput(&nc, c, argv[3]))
        return 1;
    
    //Считаем кол-во элементво в каждом массиве
    //1
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
    printf("\n");
    printf("\n");
    printf("\n");

    /* cout << "Введите число: ";
     cin >> num;
     if (cin.fail())
         cout << "Произошла ошибка при вводе\n";
     cout << "Введите кол-во элементов в массиве A: ";
     cin >> na;

     cout << "Введите кол-во элементов в массиве B: ";
     cin >> na;

     cout << "Введите кол-во элементов в массиве C: ";
     cin >> na;*/



     /* if (argc < 4)
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

      sa = Sum(a, na);
      sb = Sum(b, nb);
      sc = Sum(c, nc);

      max = sa;
      if (sb > max) max = sb;
      if (sc > max) max = sc;

      if (sa == max)
          printf("Массив А имеет максимальную сумму элементов: %9.3lf\n", max);
      if (sb == max)
          printf("Массив B имеет максимальную сумму элементов: %9.3lf\n", max);
      if (sc == max)
          printf("Массив C имеет максимальную сумму элементов: %9.3lf\n", max);*/
}


