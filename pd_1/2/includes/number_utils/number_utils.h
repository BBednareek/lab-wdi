#ifndef NUMBER_UTILS_H
#define NUMBER_UTILS_H

typedef enum {
    INTEGER,
    FLOAT,
    INVALID
} NumberType;

NumberType checkType(const char *input);
int convertInt(const char *input);
float convertFloat(const char *input);

#endif //NUMBER_UTILS_H
