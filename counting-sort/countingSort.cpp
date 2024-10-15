
#include <iostream>

void simpleCountingSort(int *array, int size)
{
    int max = array[0];
    // gets the max element
    for (int i = 0; i < size; i++)
        if (max <= array[i])
            max = array[i];
    int *countArray = new int[max + 1]{0};
    for (int j = 0; j < size; j++)
        countArray[array[j]]++;
    int currentIndex = 0;
    for (int x = 0; x < max + 1; x++) //[0,1,2,3]
    {
        while (countArray[x] > 0)
        {
            array[currentIndex++] = x;
            countArray[x]--;
        }
    }
}
