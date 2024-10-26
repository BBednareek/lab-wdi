#include <stdio.h>
#include <stdlib.h>

void inputData(int *n, int *k);

int main() {
    int n, k;

    inputData(&n, &k);
    const int count = n/k;

    printf("Ilosc liczb od 1 do %d podzielnych przez %d wynosi: %d\n", n, k, count);

    return 0;
}

void inputData(int *n, int *k) {
    char input[100];
    char *endptr;

    do {
        printf("Podaj wartosc n (n > 1): ");
        fgets(input, sizeof(input), stdin);

        *n = strtol(input, &endptr, 10);

        if (*endptr != '\n' || *n <= 1) {
            printf("Bledne dane. Wprowadz liczbe naturalna wieksza od 1.\n");
        }
    } while (*endptr != '\n' || *n <= 1);

    if (*n == 1) {
        printf("Wartosc n musi byc wieksza od 1.\n");
        return;
    }

    do {
        printf("Podaj wartosc k (0 < k < n): ");
        fgets(input, sizeof(input), stdin);

        *k = strtol(input, &endptr, 10);

        if (*endptr != '\n' || *k <= 0 || *k >= *n) {
            printf("Bledne dane. Wprowadz liczbe naturalna taka, ze 0 < k < n .\n");
        }
    } while (*endptr != '\n' || *k <= 0 || *k >= *n);
}
