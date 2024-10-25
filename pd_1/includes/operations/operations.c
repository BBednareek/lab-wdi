#include "operations.h"

int addInt(const IntPair pair) {return pair.a + pair.b;}
int subtractInt(const IntPair pair) {return pair.a - pair.b;}
int multiplyInt(const IntPair pair) {return pair.a * pair.b;}
int divideInt(const IntPair pair) {return (pair.b != 0) ? pair.a / pair.b : 0;}
int moduloInt(const IntPair pair) {return pair.a % pair.b;}

float addFloat(const FloatPair pair) {return pair.a + pair.b;}
float subtractFloat(const FloatPair pair) {return pair.a - pair.b;}
float multiplyFloat(const FloatPair pair) {return pair.a * pair.b;}
float divideFloat(const FloatPair pair) {return (pair.b != 0.0) ? pair.a / pair.b : 0;}