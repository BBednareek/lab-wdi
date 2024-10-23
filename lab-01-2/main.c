#include <stdio.h>
#include <stdlib.h>

void chartest();
void floattest();
void scantest();

int main()
{
    //Zad 1. chartest();
    //Zad 2. floattest();
     scantest();
    return 0;
}





void chartest() {
    system("cls");
    char a = 'A';
    printf("Zmienna a = %c, kod ASCII = %d\n",a, a);
}

void floattest() {
    char a = 127;
    int b = 0;
    float x;

    x = (float)a/100;
    b = !a;

    system("cls");
    printf("Wynik dzielenia = %.2f, b = %d", x, b);
}

void scantest() {
    int a = 0;
    float b;


    system("cls");
    printf("\nPodaj liczbe calkowita i zmiennoprzecinkowa: \n");
    scanf("%d %f", &a, &b);

    printf("\n Int: %d, Float: %.1f", a, b);
}
