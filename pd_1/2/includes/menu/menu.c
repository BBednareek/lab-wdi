#include <stdio.h>
#include "menu.h"

void showTypeMenu() {
    printf("Wybierz typ danych:\n");

    printf("1. int\n");
    printf("2. float\n");
}

void showOperationMenu(int dataTypeChoice) {
    printf("Wybierz dzialanie:\n");

    printf("1. Dodawanie\n");
    printf("2. Odejmowanie\n");
    printf("3. Mnożenie\n");
    printf("4. Dzielenie\n");
    if(dataTypeChoice == 1) {
        printf("5. Modulo\n");
    }
}