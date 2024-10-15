// Radix sort uses counting sort in it's operation. so we must implement it first, check the counting sort folder for detailed explanation on it

#include <corecrt_math.h>
int getMaxDigits(int *array, int n);
void simpleCountingSort(int *array, int size);

void sortBasedOnDigit(int *array, int n, int exp)
{
    int *output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        int digit = (array[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (array[i] / exp) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
    {
        array[i] = output[i];
    }
}

void radixSort(int *array, int n)
{
    int maxDigits = getMaxDigits(array, n);
    for (int exp = 1; exp <= pow(10, maxDigits - 1); exp *= 10)
    {
        sortBasedOnDigit(array, n, exp);
    }
}

int getMaxDigits(int *array, int n)
{
    int maxDigits = 1;
    for (int i = 0; i < n; i++)
    {
        int currentDigits = 0;
        int currentNumber = array[i];
        if (array[i] == 0)
        {
            currentDigits = 1; // we can actually skip or delete this, but kept it for clarity
            continue;
        };
        while (currentNumber != 0)
        {
            currentNumber /= 10;
            currentDigits++;
        }
        if (currentDigits > maxDigits)
            maxDigits = currentDigits;
    }
    return maxDigits;
}
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