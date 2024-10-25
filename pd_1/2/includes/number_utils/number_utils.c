#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "number_utils.h"


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

int convertInt(const char *input) { return atoi(input); }
float convertFloat(const char *input) { return atof(input); }