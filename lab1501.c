#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Ogólna budowa funkcji

    typ_zwracany nazwaFunkcji(typ1 argument1, typ2 argument2, ...){
        Instrukcje wykonywane przez funkcje

        return wartość_do_zwrócenia - nigdy dla void, on nic nie zwraca. Zakańcza działanie funkcji.
    }

*/

void parzyste(int a, int b);
int walidacja(int a, int b);
int suma(int a, int b);
double srednia(int a, int b);
int suma_tablica(const int tablica[], const int rozmiar);
double srednia_tablica(const int tablica[], const int rozmiar);
void wypisz(const int tablica[], const int rozmiar);
int unikalne(const int tablica[], int tab_unikalnych[], int rozmiar);
int nwd(int a, int b);
void wypisz_od_konca(const int tablica[], int rozmiar);


int main()
{
    srand(time(NULL));

    int a = 0;
    int b = 0;

    printf("Podaj a: ");
    scanf("%d", &a);

    printf("Podaj b: ");
    scanf("%d", &b);

    system("cls");

    // ZADANIE 1 - tą walidację sam dorobiłem - Wypisać wszystkie liczby parzyste z przedziału (a...b), a < b

    if (walidacja(a, b)) {
        printf("Wszystkie liczby parzyste z przedzialu <%d;%d>: ", a, b);
        parzyste(a, b);
    } else {
        printf("A musi byc mniejsze od b");
    }

    // Zadanie 2 - suma liczb całkowitych z przedziału <a...b>

    int sum_res = suma(a, b);

    printf("\nSuma liczb calkowitych z przedzialu <%d; %d> = %d", a ,b, sum_res);

    // Zadanie 3 - Średnia wszystkich liczb całkowitych <a...b>

    double srednia_res = srednia(a, b);
    printf("\nSrednia wszystkich liczb z przedzialu <%d, %d> = %.2lf", a, b, srednia_res);

    // Zadanie 4 - n-elementowa tablica całkowitych. Dwie funkcje - jedna suma elementow, druga srednia

    int n = 0;
    int i = 0;

    printf("\n\nPodaj n: ");
    scanf("%d", &n);

    int tab[n];
    for (; i < n; i++){
        tab[i] = rand() % (b-a+1);
    }
    printf("Wylosowane elementy tablicy: ");
    wypisz(tab, n);

    printf("\nSuma elementow w tablicy wynosi: %d\n", suma_tablica(tab, n));
    printf("Srednia elementow w tablicy wynosi: %.2lf, ", srednia_tablica(tab, n));

    // Zadanie 5 - wypisac unikalne elementy pierwszej tablicy do drugiej

    int tab_unikalnych[n];
    int rozmiar_unikalnych = unikalne(tab, tab_unikalnych, n);

    printf("\nUnikalne elementy tablicy: ");
    wypisz(tab_unikalnych, rozmiar_unikalnych);

    // Zadanie 6 - NWD w rekurencji

    int nwd_res = nwd(a, b);
    printf("\nNWD z %d i %d = %d", a, b, nwd_res);

    // Zadanie 7 - wypisac rekurencyjnie tablice od konca
    printf("\nTablica od konca: ");
    wypisz_od_konca(tab, n);

    printf("\n");
    return 0;
}

void parzyste(const int a, const int b){
    int i = a + 1;

    for(; i < b; i++) {
        if (i % 2 == 0){
            printf("%d ", i);
        }
    }
}

int walidacja(const int a, const int b){
    return a < b;
}

int suma(const int a, const int b){
    int res = 0;
    int i = b;

    for(; i >= a; i--){
        res += i;
    }

    return res;
}

double srednia(const int a, const int b){
    return (float)suma(a,b) / (b - a + 1);
}

int suma_tablica(const int tab[], const int rozmiar) {
    int suma_res = 0;
    int i = 0;

    for(; i < rozmiar; i++){
        suma_res+=tab[i];
    }

    return suma_res;
}

double srednia_tablica(const int tab[], const int rozmiar){
    return (double)suma_tablica(tab, rozmiar) / (double)rozmiar;
}

void wypisz(const int tablica[], int rozmiar){
    int i = 0;

    for(; i < rozmiar; i++){
        printf("%d ", tablica[i]);
    }
}

int unikalne(const int tablica[], int tab_unikalnych[], const int rozmiar){
    int i = 1;
    int j = 0;
    int flaga = 0;

    int ilosc_unikalnych = 1;
    tab_unikalnych[0] = tablica[0];

    for(; i < rozmiar; i++){
        flaga = 0;

        for(; j < ilosc_unikalnych; j++){
            if (tablica[i] == tab_unikalnych[j]){
                flaga = 1;
                break;
            }
        }

        if(!flaga) {
            tab_unikalnych[ilosc_unikalnych] = tablica[i];
            ilosc_unikalnych++;
        }

    }

    return ilosc_unikalnych;
}

int nwd(int a, int b){
    if (b!=0)
        return nwd(b, a%b);

    return a;
}

void wypisz_od_konca(const int tablica[], int rozmiar){
    if (rozmiar != 0){
        printf("%d ", tablica[rozmiar-1]);
        wypisz_od_konca(tablica, rozmiar-1);
    }
}
