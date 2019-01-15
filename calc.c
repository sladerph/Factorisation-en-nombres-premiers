#include <stdlib.h>
#include <stdio.h>
#include "calc.h"
#include "structures.h"
#include "trees.h"

void printPrimeFactorization(Tree *tree, FILE *file)
{
    /**
    Recursively prints the prime factorization of a number.
    */
    if(tree == NULL)
        return;
    if(tree->infos.prime)
        fprintf(file, "%d ", tree->infos.nb);
        //printf(" %d *", tree->infos.nb);
    else
    {
        printPrimeFactorization(tree->leftTree, file);
        printPrimeFactorization(tree->rightTree, file);
    }
}

void primeFactorizationOptimized(Tree *tree, FILE *file)
{
    /**
    Recursively makes the prime factorization of the number at tree.
    */
    if(numberIsPrime(tree->infos.nb))
    {
        tree->infos.prime = True;
        printPrimeFactorization(tree, file);
        return;
    }

    int nbLeft = 0, nbRight = 0;
    factorize(tree->infos.nb, &nbLeft, &nbRight);
    expandTree(tree, nbLeft, nbRight);

    primeFactorizationOptimized(tree->leftTree, file);
    clearTree(tree->leftTree);
    tree->leftTree = NULL;
    primeFactorizationOptimized(tree->rightTree, file);
    clearTree(tree);
}

void primeFactorization(Tree *tree)
{
    /**
    Recursively makes the prime factorization of the number at tree.
    */
    if(numberIsPrime(tree->infos.nb))
    {
        tree->infos.prime = True;
        return;
    }

    int nbLeft = 0, nbRight = 0;
    factorize(tree->infos.nb, &nbLeft, &nbRight);
    expandTree(tree, nbLeft, nbRight);

    primeFactorization(tree->leftTree);
    primeFactorization(tree->rightTree);
}

int readIntegerGreaterOrEqualToMin(char* display, int min)
{
    /**
    Reads and returns an integer greater or equal to min.
    */
    int nb;

    do
    {
        printf(display);
        fflush(stdin);
        scanf("%d", &nb);
        fflush(stdin);
    }while(nb < min);

    return nb;
}

void factorize(int nbToFactorize, int* r1, int* r2)
{
    /**
    Factorizes a number.
    */
    int i;

    for(i = 2 ; i < nbToFactorize ; i++)
    {
        if(nbToFactorize % i == 0)
        {
            *r1 = i;
            *r2 = nbToFactorize/i;
            break;
        }
    }
}

Bool numberIsPrime(int nb)
{
    /**
    Checks if a number is prime.
    */
    if(nb == 1)
        return False;

    int i;

    for(i = 1 ; i < nb ; i++)
        if(nb%i == 0) // If number can be divided by i.
            if(i != 1) // If i != 1, nb can't be prime.
                return False;
    return True;
}
