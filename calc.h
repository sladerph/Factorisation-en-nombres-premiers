#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

#include "structures.h"

void factorize(int nbToFactorize, int* r1, int* r2);
void primeFactorization(Tree *tree);
void primeFactorizationOptimized(Tree *tree, FILE *file);
void printPrimeFactorization(Tree *tree, FILE *file);
int readIntegerGreaterOrEqualToMin(char* display, int min);
Bool numberIsPrime(int nb);

#endif // CALC_H_INCLUDED
