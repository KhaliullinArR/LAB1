#include <iostream>
#include <locale.h>
#include "Array_h.h"
#pragma warning(disable : 4996)




int main(int argc, char* argv[])
{
    double *a = 0, *b = 0, *c = 0;
    double num;
    int na, nb, nc, sa = 0, sb = 0, sc = 0;


    setlocale(LC_ALL, "rus");


    printf("%s", "Введите число: ");
    scanf_s("%lf", &num);

    if (argc < 4)
    {
        printf("Недостаточно параметров!\n");
        return 1;
    }
    if (!(a=ArrayInput(&na, argv[1])))
        return 1;
    if (!(b=ArrayInput(&nb, argv[2])))
        return 1;
    if (!(c=ArrayInput(&nc, argv[3])))
        return 1;

    sa = AmountLessThan(a, na, num);
    sb = AmountLessThan(b, nb, num);
    sc = AmountLessThan(c, nc, num);

    if (!Output(a, b, c, na, nb, nc, &sa, &sb, &sc, &num))
        return 1;
    

    delete[] a;
    delete[] b;
    delete[] c;

    a = 0;
    b = 0;
    c = 0;

    


}



