#include <stdio.h>

void inputData(int *n, int *k);
int validateData(int n, int k);
int countDividable(int n, int k);

int main() {
    int n, k;

    inputData(&n, &k);

    if (!validateData(n, k)) {
        printf("Bledne dane: n musi byc wieksze od k, a k > 0. Sprobuj ponownie.\n");
        return 1;
    }

    const int count = countDividable(n, k);
    printf("Ilosc liczb od 1 do %d podzielnych przez %d wynosi: %d\n", n, k, count);

    return 0;
}

void inputData(int *n, int *k) {
    printf("Podaj wartosc n (n > k): ");
    scanf("%d", n);

    printf("Podaj wartosc k (k > 0): ");
    scanf("%d", k);
}

int validateData(const int n, const int k) {
    return (n > k) && (k > 0);
}

int countDividable(const int n, const int k) {
    int count = 0;
    int i = 0;

    for (i = 1; i <= n; i++) {
        if (i % k == 0) {
            count++;
        }
    }
    return count;
}