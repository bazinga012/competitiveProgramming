#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i - 1;
        for (; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

void unstableSelectionSort(int data[], int count)
{
    int tmp, minimum;
    for (int i = 0; i < count - 1; i++)
    {
        minimum = i;
        for (int j = i + 1; j < count; j++)
            if (data[minimum] > data[j])
                minimum = j;
        tmp = data[minimum];
        data[minimum] = data[i];
        data[i] = tmp;
    }
}

void stableSelectionSort(int data[], int count)
{
    int temp, minimum;
    for (int i = 0; i < count - 1; i++)
    {
        minimum = i;
        for (int j = i + 1; j < count; j++)
            if (data[j] < data[minimum])
                minimum = j;
        temp = data[minimum];
        for (int j = minimum; j > i; j--)
            data[j] = data[j - 1];
        data[i] = temp;
    }
}

void merge(int *arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2], i = 0, j = 0, k = l;
    while (i < n1)
    {
        L[i++] = arr[k++];
    }
    while (j < n2)
    {
        R[j++] = arr[k++];
    }
    i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void maxHeapify(int arr[], int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
void buildHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
