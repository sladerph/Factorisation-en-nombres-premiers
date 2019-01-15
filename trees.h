#ifndef TREES_H_INCLUDED
#define TREES_H_INCLUDED

#include "structures.h"

Tree* createTree(int number);
void expandTree(Tree *tree, int nbLeft, int nbRight);
void clearTree(Tree *tree);

#endif // TREES_H_INCLUDED
