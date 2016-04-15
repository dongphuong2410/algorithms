#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "rc.h"

//In the adjacent matrix, we just use the bottom half of the matrix (row value > col value)
#define VAL(arr, row, col) ((row >= col) ? arr[row][col] : arr[col][row])

static void print_matrix(int n, int **arr);

/**
 * Calculate min cut using random_contraction 
 * @input n Array size
 * @input arr Array
 * @return mincut
 */
int random_contraction(int n, int **arr)
{
    int cur = n;
    int a, b;
    while (cur > 2) {
        random_sel(&a, &b, cur);
        group(arr, a, b, cur);
        remove_vertex(arr, b, cur);
        cur--;
    }
    return arr[1][0];
}

/*
 * Read the grap from input file into the matrix
 */
int **read_matrix(int n, const char *filename)
{
    int **arr = NULL;
    int i, j;
    FILE *fp = fopen(filename, "r");
    if (!fp) return;

    arr = (int **)calloc(n, sizeof(int *));
    arr[0] = (int *)calloc(n * n, sizeof(int));
    for (i = 1; i < n; i++) {
        arr[i] = arr[0] + i * n;
    }

    char line[1024];
    char *ptr;
    char *end;
    char first;
    while (fgets(line, sizeof(line), fp) != NULL) {
        ptr = line;
        first = 1;
        while (*ptr) {
            end = ptr;
            while (*end != ' ' && *end != '\n' && *end != '\t') end++;
            if (first) {
                i = strtol(ptr, &end, 10);
                first = 0;
            }
            else {
                j = strtol(ptr, &end, 10);
                if (i >= j)
                    arr[i - 1][j - 1] = 1;
            }
            ptr = end;
            while (*ptr == ' ' || *ptr == '\n' || *ptr == '\t' || *ptr == '\r') ptr++;
        }
    }
    fclose(fp);
    return arr;
}

/*
 * Randomly select an edge (a,b) which a, b < n and a <> b
 */
void random_sel(int *a, int *b, int n)
{
    assert(n > 2);
    *a = *b = rand() % n;
    while (*a == *b) *b = rand() % n;
}

//Group vertex b into a 
void group(int **arr, int a, int b, int n)
{
    int i;
    for (i = 0; i < a; i++) {
        arr[a][i] = VAL(arr, a, i) + VAL(arr, b, i); 
        
    }
    for (i = a + 1; i < n; i++) {
        arr[i][a] = VAL(arr, a, i) + VAL(arr, b, i);
    }
}

//Remove vertex a by override it with the last vertex 
void remove_vertex(int **arr, int a, int n)
{
    int i;
    if (a == n - 1) return;
    for (i = 0; i < a; i++) {
        arr[a][i] = VAL(arr, n - 1, i);
    }
    for (i = a + 1; i < n; i++) {
        arr[i][a] = VAL(arr, n - 1, i);
    }
}

void free_matrix(int n, int **arr)
{
    int i;
    free(arr[0]);
    free(arr);
}

static void print_matrix(int n, int **arr)
{
    int i, j;
    for (i = 0; i < n; i++) {
        printf("line %-3d : ", i + 1);
        for (j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

