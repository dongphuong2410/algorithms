#include <stdio.h>
#include <stdlib.h>

#include "../rc.h"

int main(int argc, char **argv)
{
    srand(time(NULL));
    int a, b;
    int n;
    for (n = 10; n > 2; n--) {
        random_sel(&a, &b, n);
        printf("n = %d a = %d b = %d\n", n, a, b);
    }
    return 0;
}
