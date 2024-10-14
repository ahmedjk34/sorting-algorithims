#include <iostream>
#include <cassert> // For assertions

void combine(int *array, int first, int last, int middle)
{
    int leftSize = middle - first + 1;
    int rightSize = last - middle;
    int *leftHalf = new int[leftSize];
    int *rightHalf = new int[rightSize];
    for (int i = 0; i < leftSize; i++)
        leftHalf[i] = array[first + i];
    for (int i = 0; i < rightSize; i++)
        rightHalf[i] = array[middle + 1 + i];
    int i = 0, j = 0, k = first;
    while (i < leftSize && j < rightSize)
    {
        if (leftHalf[i] <= rightHalf[j])
        {
            array[k++] = leftHalf[i++];
        }
        else
        {
            array[k++] = rightHalf[j++];
        }
    }
    while (i < leftSize)
    {
        array[k++] = leftHalf[i++];
    }

    while (j < rightSize)
    {
        array[k++] = rightHalf[j++];
    }
}
void mergeSort(int *array, int first, int last)
{
    if (first >= last)
        return;
    int middleIndex = (first + last) / 2;
    mergeSort(array, first, middleIndex);
    mergeSort(array, middleIndex + 1, last);
    combine(array, first, last, middleIndex);
}

// Function to compare two arrays
bool arraysEqual(int *arr1, int *arr2, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}

// Function to print an array
void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// Function to run tests
void runTests()
{
    // Test for already sorted array (Best Case)
    {
        int array[] = {1, 2, 3, 4, 5};
        int size = sizeof(array) / sizeof(array[0]);
        std::cout << "Test 1: Already Sorted Array" << std::endl;
        std::cout << "Before: ";
        printArray(array, size);
        mergeSort(array, 0, size - 1);
        std::cout << "After: ";
        printArray(array, size);
        int expected[] = {1, 2, 3, 4, 5};
        assert(arraysEqual(array, expected, size));
    }

    // Test for reverse sorted array (Worst Case)
    {
        int array[] = {5, 4, 3, 2, 1};
        int size = sizeof(array) / sizeof(array[0]);
        std::cout << "\nTest 2: Reverse Sorted Array" << std::endl;
        std::cout << "Before: ";
        printArray(array, size);
        mergeSort(array, 0, size - 1);
        std::cout << "After: ";
        printArray(array, size);
        int expected[] = {1, 2, 3, 4, 5};
        assert(arraysEqual(array, expected, size));
    }

    // Test for an array with duplicate elements
    {
        int array[] = {3, 1, 2, 1, 3};
        int size = sizeof(array) / sizeof(array[0]);
        std::cout << "\nTest 3: Array with Duplicates" << std::endl;
        std::cout << "Before: ";
        printArray(array, size);
        mergeSort(array, 0, size - 1);
        std::cout << "After: ";
        printArray(array, size);
        int expected[] = {1, 1, 2, 3, 3};
        assert(arraysEqual(array, expected, size));
    }

    // Test for an array with one element
    {
        int array[] = {42};
        int size = sizeof(array) / sizeof(array[0]);
        std::cout << "\nTest 4: Single Element Array" << std::endl;
        std::cout << "Before: ";
        printArray(array, size);
        mergeSort(array, 0, size - 1);
        std::cout << "After: ";
        printArray(array, size);
        int expected[] = {42};
        assert(arraysEqual(array, expected, size));
    }

    // Test for already sorted array with negative numbers
    {
        int array[] = {-5, -4, -3, -2, -1};
        int size = sizeof(array) / sizeof(array[0]);
        std::cout << "\nTest 5: Already Sorted Negative Array" << std::endl;
        std::cout << "Before: ";
        printArray(array, size);
        mergeSort(array, 0, size - 1);
        std::cout << "After: ";
        printArray(array, size);
        int expected[] = {-5, -4, -3, -2, -1};
        assert(arraysEqual(array, expected, size));
    }

    // Test for an array containing both positive and negative numbers
    {
        int array[] = {3, -1, 2, -5, 0};
        int size = sizeof(array) / sizeof(array[0]);
        std::cout << "\nTest 6: Mixed Numbers Array" << std::endl;
        std::cout << "Before: ";
        printArray(array, size);
        mergeSort(array, 0, size - 1);
        std::cout << "After: ";
        printArray(array, size);
        int expected[] = {-5, -1, 0, 2, 3};
        assert(arraysEqual(array, expected, size));
    }

    std::cout << "\nAll tests passed!" << std::endl;
}

int main()
{
    runTests();
    return 0;
}
