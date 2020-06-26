#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int compareMyType(const void *a, const void *b)
{
    /* change int to any custom type and write comparison logic */
    if (*(int *)a < *(int *)b)
        return -1;
    if (*(int *)a == *(int *)b)
        return 0;
    if (*(int *)a > *(int *)b)
        return 1;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    int arr[n];
    memset(arr, 0, sizeof(arr));

    int *arr1 = (int *)malloc(sizeof(int) * n);
    memset(arr1, 0, sizeof(int) * n);
    int r, c;
    cin >> r >> c;
    int **twoD = (int **)malloc(sizeof(int *) * r);
    for (int i = 0; i < r; i++)
    {
        twoD[i] = (int *)malloc(sizeof(int) * c);
    }
    memset(&twoD[0][0], 0, sizeof(int) * r * c);
    for (int i = 0; i <= n; i++)
    {
        free(twoD[i]);
    }
    free(twoD);

    //sorting
    qsort(arr1, n, sizeof(int), compareMyType);
    return 0;
}
