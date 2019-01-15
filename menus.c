#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "menus.h"
#include "structures.h"

void mainMenu()
{
    /**
    Prints the main menu and lets the user choose what he wants to do.
    */
    Bool quit = False;
    char choice;
    int nb, max;
    FILE *file = fopen("output.txt", "w+");
    Tree *tree;

    if(file == NULL)
    {
        fprintf(stderr, "\nError !\nUnable to open the output file !\n");
        exit(EXIT_FAILURE);
    }

    while(!quit)
    {
        choice = '0';
        do
        {
               printf("\n\nChoose the action to provide !\n\
    - Factorize a number into a product of prime numbers (A)\n\
    - Process all numbers between two values             (B)\n\
    - Quit                                               (Q)\nEnter your choice : ");

            fflush(stdin);
            choice = getchar();
            fflush(stdin);
            strupr(&choice);
        } while((choice < 'A' || choice > 'B') && choice != 'Q');

        switch(choice)
        {
        case 'A':
            nb = readIntegerGreaterOrEqualToMin("\nEnter the number to factorize (> 1) : ", 2);
            if(numberIsPrime(nb))
                fprintf(file, "%d : NONE\n", nb);
            else
            {
                tree = createTree(nb);
                fprintf(file, "%d : ", nb);
                primeFactorizationOptimized(tree, file);
                fprintf(file, "\n");
            }
            break;
        case 'B':
            nb = readIntegerGreaterOrEqualToMin("\nEnter the number to start with (> 1) : ", 2);
            char str[50];
            sprintf(str, "\nEnter the maximum number (> %d) : ", nb);
            max = readIntegerGreaterOrEqualToMin(str, nb);
            while(nb <= max)
            {
                if(numberIsPrime(nb))
                    fprintf(file, "%d : NONE\n", nb);
                else
                {
                    tree = createTree(nb);
                    fprintf(file, "%d : ", nb);
                    primeFactorizationOptimized(tree, file);
                    fprintf(file, "\n");
                }
                nb++;
            }
            break;
        case 'Q':
            printf("\n*** Exiting project... ***\n");
            printf("\nSee you later !\n");
            quit = True;
            break;
        }
        fclose(file);
    }
}
