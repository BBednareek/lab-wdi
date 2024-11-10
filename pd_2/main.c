#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void appendData(int **arr, int a, int b, int size);
void printArray(const int arr[], int size);
void duplicates(const int arr[], int size);
void shift(int arr[], int size);

int sum(const int arr[], int size);
int min(const int arr[], int size);
int max(const int arr[], int size);
int sorted(const int arr[], int size);
int subsequence(const int arr[], int size);

float avg(int size, int sum);

int main() {
    srand(time(NULL));

    int *arr = NULL;

    int n = 0;
    int a = 0;
    int b = 0;

    printf("Podaj rozmiar tablicy: ");
    scanf("%d", &n);
    system("cls");

    printf("Podaj dolna granice: ");
    scanf("%d", &a);
    system("cls");

    printf("Podaj gorna granice: ");
    scanf("%d", &b);
    system("cls");

    appendData(&arr, a, b, n);

    const int sumArray = sum(arr, n);

    printArray(arr, n);

    printf("\nsuma: %d", sumArray);
    printf("\nsrednia: %.2f", avg(n, sumArray));
    printf("\nmin: %d", min(arr, n));
    printf("\nmax: %d", max(arr, n));
    printf("\nDuplikaty: "); duplicates(arr, n);
    sorted(arr, n) ? printf("\nTablica uporzadkowana niemalejaco") : printf("\nTablica nieuporzadkowana niemalejaco");
    printf("\nNajdluszy rosnacy podciag: %d", subsequence(arr, n));
    printf("\nTablica po przesunieciu w prawo: "); shift(arr, n); printArray(arr, n);

    free(arr);
    return 0;
}

void appendData(int **arr, const int a, const int b, const int size) {
    *arr = (int *)malloc(size * sizeof(int));
    int i = 0;

    if (*arr == NULL) {
        printf("Blad alokacji");
        exit(1);
    }

    if (a < 1 ||  a > b) {
        printf("Pamietaj, ze b < a");
        exit(1);
    }

    for (; i < size; i++) {
        (*arr)[i] = rand() % (b - a + 1) + a;
    }
}

void printArray(const int arr[], const int size) {
    int i = 0;

    for (; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void shift(int arr[], const int size) {
    if (size <= 1) return;

    const int last = arr[size - 1];
    int i = size - 1;

    for (; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = last;
}

int sum(const int arr[], const int size) {
    int sum = 0;
    int i = 0;

    for (; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

int min(const int arr[], const int size) {
    int min = arr[0];
    int i = 0;

    for (; i < size; i++) {
        if (min > arr[i])
            min = arr[i];
    }

    return min;
}

int max(const int arr[], const int size) {
    int max = arr[0];
    int i = 0;

    for (; i < size; i++) {
        if (max < arr[i])
            max = arr[i];
    }

    return max;
}

void duplicates(const int arr[], const int size) {
    int *hash = calloc(size, sizeof(int));
    int *printed = calloc(size, sizeof(int));

    int duplicate = 0;
    int i = 0;

    for(; i < size; i++) {
        const int val = arr[i];
        if (hash[val] && !printed[val]) {
            printf("%d ", val);
            printed[val] = 1;
            duplicate = 1;
        } else {
            hash[val] = 1;
        }
    }

    if (!duplicate) {
        printf("Brak duplikatow");
    }

    free(hash);
    free(printed);
}

int sorted(const int arr[], const int size) {
    int i = 0;
    for (; i < size; i++) {
        if (arr[i] < arr[i-1])
            return 0;
    }

    return 1;
}

int subsequence(const int arr[], const int size) {
    if (size == 0) return 0;

    int longest = 1;
    int current = 1;
    int i = 0;

    for (; i < size; i++) {
        if (arr[i] > arr[i - 1])
            current += 1;
        else {
            if (current > longest)
                longest = current;
            current = 1;
        }
    }

    if (current > longest)
        longest = current;

    return longest;
}

float avg(const int size, const int sum) {
    return (float)sum / (float)size;
}
