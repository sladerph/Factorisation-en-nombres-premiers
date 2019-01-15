#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct Tree Tree;

typedef enum Bool
{
    False, True
} Bool;

typedef struct Information
{
    int nb;
    Bool prime;
    Bool processed;
} Information;

struct Tree
{
    int key;
    Information infos;
    Tree *leftTree;
    Tree *rightTree;
    Tree *parent;
};

#endif // STRUCTURES_H_INCLUDED
