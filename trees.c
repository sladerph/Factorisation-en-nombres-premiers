#include <stdlib.h>
#include <stdio.h>
#include "trees.h"
#include "structures.h"

void expandTree(Tree *tree, int nbLeft, int nbRight)
{
    /**
    Adds two children trees to a tree.
    */
    Tree *left = createTree(nbLeft);
    Tree *right = createTree(nbRight);

    tree->leftTree = left;
    tree->rightTree = right;
}

void clearTree(Tree *tree)
{
    /**
    Frees memory of a tree.
    Recursive function.
    */
    if(tree == NULL)
        return;

    printf("\n*** Deleting tree with root value = %d ***\n", tree->infos.nb); /// DEBUGING HELP

    clearTree(tree->leftTree);
    clearTree(tree->rightTree);

    tree->leftTree = NULL;
    tree->rightTree = NULL;
    tree->parent = NULL;
    free(tree); // Freeing memory.
}

Tree* createTree(int number)
{
    /**
    Creates a tree and returns its address.
    */
    Tree *tr = (Tree*)malloc(sizeof(Tree));
    if(tr == NULL)
    {
        fprintf(stderr, "\n*** Error ! Unable to allocate memory ! ***\n");
        exit(EXIT_FAILURE);
    }

    printf("\n*** Creating tree with root value = %d ***\n", number); /// DEBUGING HELP.

    tr->leftTree = NULL;
    tr->rightTree = NULL;
    tr->parent = NULL;
    tr->infos.nb = number;
    tr->infos.prime = False;
    tr->infos.processed = False;

    return tr;
}
