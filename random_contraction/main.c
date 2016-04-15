#include <stdio.h>
#include <stdlib.h>
#include "rc.h"

int main(int argc, char **args)
{
    if (argc < 3) {
        printf("Usage : main <graph size> <graph filename>\n");
        exit(1);
    }
    int n = atoi(args[1]);
    char *filename = args[2];
    int **arr;
    srand(time(NULL));
    
    arr = read_matrix(n, filename);
    int mincut = random_contraction(n, arr);
    printf("\n Min cut %d \n", mincut);
    free_matrix(n, arr);
    return 0;
}

