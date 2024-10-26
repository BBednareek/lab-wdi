#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "number_utils.h"

NumberType checkType(const char *input) {
    int dotCount = 0;
    int i = 0;

    if (input[0] == '-') {
        i = 1;
    }

    for (; input[i] != '\0'; i++) {
        if (input[i] == '.') {
            dotCount++;
        } else if (!isdigit(input[i])) {
            return INVALID;
        }
    }

    if (dotCount > 1) {
        return INVALID;
    }

    if (dotCount == 1) {
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


int convertInt(const char *input) { return atoi(input); }
float convertFloat(const char *input) { return atof(input); }