#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "includes/types/types.h"
#include "includes/operations/operations.h"
#include "includes/menu/menu.h"
#include "includes/number_utils/number_utils.h"

int main() {
    int dataTypeChoice = 0, operationChoice = 0;

    while (1) {
        char input[100];
        showTypeMenu();
        printf("Podaj swoj wybor: ");
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "%d", &dataTypeChoice) != 1 || strlen(input) > 1) {
            printf("Niepoprawny wybor typu danych.\n");
            continue;
        }

        if (dataTypeChoice == 3) {
            printf("Program zakonczony. Do widzenia!");
            break;
        }

        if (dataTypeChoice != 1 && dataTypeChoice != 2) {
            printf("Niepoprawny wybor typu danych.\n");
            continue;
        }

        if (dataTypeChoice == 1) {
            IntPair intPair = {0, 0};

            printf("Podaj dwie liczby calkowite: ");
            fgets(input, sizeof(input), stdin);

            const char *num1_str = strtok(input, " ");
            const char *num2_str = strtok(NULL, " ");

            if (num1_str == NULL || num2_str == NULL) {
                printf("\nNieprawidlowe dane wejsciowe, podaj dwie liczby calkowite oddzielone spacja.\n");
                continue;
            }

            const NumberType result1 = checkType(num1_str);
            const NumberType result2 = checkType(num2_str);

            if (result1 != INTEGER || result2 != INTEGER) {
                printf("\nNieprawidlowe dane wejsciowe, podaj dwie liczby calkowite oddzielone spacja.\n");
                continue;
            }

            intPair.a = convertInt(num1_str);
            intPair.b = convertInt(num2_str);

            system("cls");
            showOperationMenu(dataTypeChoice);
            printf("Podaj swoj wybor: ");
            fgets(input, sizeof(input), stdin);

            if (sscanf(input, "%d", &operationChoice) != 1 || operationChoice < 0 || operationChoice > 5) {
                printf("Niepoprawny wybor operacji.\n");
                continue;
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
            FloatPair floatPair = {0, 0};

            printf("Podaj dwie liczby zmiennoprzecinkowe: ");
            fgets(input, sizeof(input), stdin);

            const char *num1_str = strtok(input, " ");
            const char *num2_str = strtok(NULL, " ");

            if (num1_str == NULL || num2_str == NULL) {
                printf("\nNieprawidlowe dane wejsciowe, podaj dwie liczby zmiennoprzecinkowe oddzielone spacja.\n");
                continue;
            }

            const NumberType result1 = checkType(num1_str);
            const NumberType result2 = checkType(num2_str);

            if (result1 != FLOAT || result2 != FLOAT) {
                printf("\nNieprawidlowe dane wejsciowe, podaj dwie liczby zmiennoprzecinkowe oddzielone spacja.\n");
                continue;
            }

            floatPair.a = convertFloat(num1_str);
            floatPair.b = convertFloat(num2_str);

            showOperationMenu(dataTypeChoice);
            printf("Podaj swoj wybor: ");
            fgets(input, sizeof(input), stdin);

            if (sscanf(input, "%d", &operationChoice) != 1 || operationChoice < 0 || operationChoice > 5) {
                printf("Niepoprawny wybor operacji.\n");
                continue;
            }

            system("cls");
            switch (operationChoice) {
                case 1:
                    printf("Wynik dodawania: %.2f\n", addFloat(floatPair));
                    break;
                case 2:
                    printf("Wynik odejmowania: %.2f\n", subtractFloat(floatPair));
                    break;
                case 3:
                    printf("Wynik mnozenia: %.2f\n", multiplyFloat(floatPair));
                    break;
                case 4:
                    printf("Wynik dzielenia: %.2f\n", divideFloat(floatPair));
                    break;
                default:
                    printf("Niepoprawny wybor operacji.\n");
                    break;
            }
        }
    }
    return 0;
}



