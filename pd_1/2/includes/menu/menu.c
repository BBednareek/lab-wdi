#include <stdio.h>
#include "menu.h"

void showTypeMenu() {
    printf("Wybierz typ danych:\n");

    printf("1. int\n");
    printf("2. float\n");
    printf("3. Wyjdz z programu\n");
}

void showOperationMenu(const int dataTypeChoice) {
    printf("Wybierz dzialanie:\n");

    printf("1. Dodawanie\n");
    printf("2. Odejmowanie\n");
    printf("3. Mnozenie\n");
    printf("4. Dzielenie\n");
    if(dataTypeChoice == 1) {
        printf("5. Modulo\n");
    }
}