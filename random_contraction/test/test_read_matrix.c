#include <assert.h>
#include "../rc.h"

int main(int argc, char **argv)
{
    char *filename = "matrix.txt";
    int n = 6;
    int **arr = read_matrix(n, filename);
    assert(arr[0][0] == 0);
    assert(arr[1][0] == 1);
    assert(arr[1][1] == 0);
    assert(arr[2][0] == 0);
    assert(arr[2][1] == 0);
    assert(arr[2][2] == 0);
    assert(arr[3][0] == 0);
    assert(arr[3][1] == 1);
    assert(arr[3][2] == 1);
    assert(arr[3][3] == 0);
    assert(arr[4][0] == 0);
    assert(arr[4][1] == 0);
    assert(arr[4][2] == 0);
    assert(arr[4][3] == 0);
    assert(arr[4][4] == 0);
    assert(arr[5][0] == 0);
    assert(arr[5][1] == 1);
    assert(arr[5][2] == 0);
    assert(arr[5][3] == 1);
    assert(arr[5][4] == 1);
    assert(arr[5][5] == 0);
    free_matrix(n, arr);
    return 0;
}
