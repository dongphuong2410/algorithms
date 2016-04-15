#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#include "../rc.h"

#define LOOP 1000 

int get_mincut(int n, const char *filename);
void test01(void);
void test02(void);
void test03(void);
void test04(void);
void test05(void);

int main(int argc, char **args)
{
    srand(time(NULL));
    test01();
    test02();
    test03();
    test04();
    test05();
}

int get_mincut(int n, const char *filename)
{
    int loop = LOOP;
    int min = INT_MAX;
    int **arr;
    while (loop--) {
        arr = read_matrix(n, filename);
        int val = random_contraction(n, arr);
        if (min > val) min = val; 
        free_matrix(n, arr);
    }
    return min;
}

void test01(void)
{
    printf("Test 01 ..\n");
    int mincut = get_mincut(4, "test1.txt");
    assert(mincut == 2);
}

void test02(void)
{
    printf("Test 02 ..\n");
    int mincut = get_mincut(5, "test2.txt");
    assert(mincut == 1);
}

void test03(void)
{
    printf("Test 03 ..\n");
    int mincut = get_mincut(7, "test3.txt");
    assert(mincut == 3);
}

void test04(void)
{
    printf("Test 04 ..\n");
    int mincut = get_mincut(11, "test4.txt");
    assert(mincut == 2);
}

void test05()
{
    printf("Test 05 ..\n");
    int mincut = get_mincut(200, "../kargerMinCut.txt");
    printf("mincut %d\n", mincut);
}
