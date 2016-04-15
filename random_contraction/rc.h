#ifndef __RANDOM_CONTRACTION_H__
#define __RANDOM_CONTRACTION_H__

int **read_matrix(int n, const char *filename);
int random_contraction(int n, int **arr);
void random_sel(int *a, int *b, int n);
void group(int **arr, int a, int b, int n);
void remove_vertex(int **arr, int a, int n);
void free_matrix(int n, int **arr);

#endif
