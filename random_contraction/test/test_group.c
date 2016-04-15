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
                        {0,1,0,0,0,0},
                        {0,0,1,0,0,0},
                        {0,1,0,1,0,0},
                        {0,0,0,1,1,0}};
    int **arr = (int **)malloc(sizeof(int *) * NO);
    for (i = 0; i < NO; i++) {
        arr[i] = (int *)malloc(sizeof(int) * NO);
        for (j = 0; j < NO; j++) {
            arr[i][j] = data[i][j];
        }
    }
    group(arr, 1, 3, NO);

    //expected array after group 3 to 1
    int arr1[NO][NO] = {  {0,0,0,0,0,0},
                        {1,0,0,0,0,0},
                        {0,2,0,0,0,0},
                        {0,0,1,0,0,0},
                        {0,2,0,0,0,0},
                        {0,1,0,0,1,0}};
    for (i = 0; i < NO; i++) {
        for (j = 0; j < NO; j++) {
            if (i != 3 && j != 3) //vertex 3 has been group into 1
                assert(arr[i][j] ==  arr1[i][j]);
        }
    } 

}
