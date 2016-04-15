#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../rc.h"

#define NO 6

int main(int argc, char **argv)
{
    int i, j;
    int data[NO][NO] = {  {0,0,0,0,0,0},
                        {1,0,0,0,0,0},
                        {0,2,0,0,0,0},
                        {0,0,1,0,0,0},
                        {0,2,0,0,0,0},
                        {0,1,0,0,1,0}};
    int **arr = (int **)malloc(sizeof(int *) * NO);
    for (i = 0; i < NO; i++) {
        arr[i] = (int *)malloc(sizeof(int) * NO);
        for (j = 0; j < NO; j++) {
            arr[i][j] = data[i][j];
        }
    }
    remove_vertex(arr, 3, NO);

    //expected array after remove 3 vertex
    int arr1[NO - 1][NO - 1] = {  {0,0,0,0,0},
                        {1,0,0,0,0},
                        {0,2,0,0,0},
                        {0,1,0,0,0},
                        {0,2,0,1,0}};

    for (i = 0; i < NO - 1; i++) {
        for (j = 0; j < NO - 1; j++) {
            assert(arr[i][j] ==  arr1[i][j]);
        }
    } 
}
