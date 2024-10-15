// First of all we should build the heap
// We need to implement heapify() & buildHeap() before getting into the algorithm
#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *array, int rootIndex, int lastIndex)
{
    int largest = rootIndex;
    int leftIndex = 2 * rootIndex;
    int rightIndex = 2 * rootIndex + 1;

    if (leftIndex <= lastIndex && array[leftIndex] > array[largest])
    {
        largest = leftIndex;
    }
    if (rightIndex <= lastIndex && array[rightIndex] > array[largest])
    {
        largest = rightIndex;
    }
    if (largest != rootIndex)
    {
        swap(&array[rootIndex], &array[largest]);
        heapify(array, largest, lastIndex);
    }
}

void buildHeap(int *array, int lastIndex)
{
    for (int i = lastIndex / 2; i >= 0; i--)
    {
        heapify(array, i, lastIndex);
    }
}

void heapSort(int *array, int lastIndex)
{
    buildHeap(array, lastIndex);

    for (int i = lastIndex; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        heapify(array, 0, i - 1);
    }
}