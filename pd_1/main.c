#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "includes/types/types.h"
#include "includes/operations/operations.h"
#include "includes/menu/menu.h"

typedef enum {
    INTEGER,
    FLOAT,
    INVALID
} NumberType;

NumberType checkType(const char *input);
int convertInt(const char *input) {return atoi(input);}
float convertFloat(const char *input) {return atof(input);}

int main() {
    int dataTypeChoice = 0, operationChoice = 0;

    showTypeMenu();
    printf("Podaj swoj wybor: ");
    scanf("%d", &dataTypeChoice);

    if (dataTypeChoice < 0 || dataTypeChoice > 2) {
        printf("Niepoprawny wybor typu danych.\n");
    }

    if (dataTypeChoice == 1) {
        char input[100];
        IntPair intPair;

        intPair.a = 0;
        intPair.b = 0;

        system("cls");
        printf("Podaj dwie liczby calkowite: ");
        fgets(input, sizeof(input), stdin);

        const char *num1_str = strtok(input, " ");
        const char *num2_str = strtok(NULL, " ");

        if (num1_str == NULL || num2_str == NULL) {
            printf("\nNieprawidlowe dane wejsciowe, podaj dwie liczby calkowite oddzielone spacja.");
            return 1;
        }

        const NumberType result1 = checkType(num1_str);
        const NumberType result2 = checkType(num2_str);


        if (result1 != INTEGER && result2 != INTEGER) {
            printf("\nNieprawidlowe dane wejsciowe, podaj dwie liczby calkowite oddzielnone spacja.");
            return 1;
        }

        intPair.a = convertInt(num1_str);
        intPair.b = convertInt(num2_str);

        system("cls");
        showOperationMenu(dataTypeChoice);
        printf("Podaj swoj wybor: ");
        scanf("%d", &operationChoice);

        if (operationChoice < 0 || operationChoice > 5) {
            printf("Niepoprawny wybór operacji.\n");
        }

        system("cls");
        switch (operationChoice) {
            case 1:
                printf("Wynik dodawania: %d\n", addInt(intPair));
            break;
            case 2:
                printf("Wynik odejmowania: %d\n", subtractInt(intPair));
            break;
            case 3:
                printf("Wynik mnozenia: %d\n", multiplyInt(intPair));
            break;
            case 4:
                printf("Wynik dzielenia: %d\n", divideInt(intPair));
            break;
            case 5:
                printf("Wynik dzielenia z reszta: %d\n", moduloInt(intPair));
            break;
            default:
                printf("Niepoprawny wybor typu danych.\n");
            break;
        }
    }

    if (dataTypeChoice == 2) {
        char input[100];
        FloatPair floatPair;

        floatPair.a = 0;
        floatPair.b = 0;

        printf("Podaj dwie liczby zmiennoprzecinkowe: ");
        fgets(input, sizeof(input), stdin);

        const char *num1_str = strtok(input, " ");
        const char *num2_str = strtok(NULL, " ");

        if (num1_str == NULL || num2_str == NULL) {
            printf("\nNieprawidlowe dane wejsciowe, podaj dwie liczby zmiennoprzecinkowe oddzielone spacja.");
            return 1;
        }

        const NumberType result1 = checkType(num1_str);
        const NumberType result2 = checkType(num2_str);


        if (result1 != FLOAT && result2 != FLOAT) {
            printf("\nNieprawidlowe dane wejsciowe, podaj dwie liczby zmiennoprzecinkowe oddzielnone spacja.");
            return 1;
        }

        floatPair.a = convertFloat(num1_str);
        floatPair.b = convertFloat(num2_str);

        showOperationMenu(dataTypeChoice);
        printf("Podaj swoj wybor: ");
        scanf("%d", &operationChoice);

        if (operationChoice < 0 || operationChoice > 5) {
            printf("Niepoprawny wybor operacji.\n");
            return 1;
        }

        system("cls");
        switch (operationChoice) {
            case 1:
                printf("Wynik dodawania: %f\n", addFloat(floatPair));
                break;
            case 2:
                printf("Wynik odejmowania: %f\n", subtractFloat(floatPair));
                break;
            case 3:
                printf("Wynik mnozenia: %f\n", multiplyFloat(floatPair));
                break;
            case 4:
                printf("Wynik dzielenia: %f\n", divideFloat(floatPair));
                break;
            default:
                printf("Niepoprawny wybor operacji.\n");
            break;
        }
    }

        return 0;
}

NumberType checkType(const char *input) {
    if (strchr(input, '.')) {
        float value;
        if (sscanf(input, "%f", &value) == 1) {
            return FLOAT;
        }
    }

    int value;
    if (sscanf(input, "%d", &value) == 1) {
        return INTEGER;
    }

    return INVALID;
}


