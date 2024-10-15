#include <iostream>
#include <cassert> // For assertions
#include <cstdlib> // For rand()
using namespace std;

int randomPivotIndex(int low, int high)
{

    return low + rand() % (high - low + 1);
}

void partition(int *array, int low, int high, int pivotIndex, int &leftEnd)
{
    int pivot = array[pivotIndex];
    std::swap(array[pivotIndex], array[low]);
    int i = low + 1;

    for (int j = low + 1; j <= high; j++)
    {
        if (array[j] < pivot)
        {
            swap(array[i], array[j]);
            i++;
        }
    }

    swap(array[low], array[i - 1]);
    leftEnd = i - 1;
}
void quickSort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = randomPivotIndex(low, high);
        int leftEnd;
        partition(array, low, high, pivotIndex, leftEnd);

        quickSort(array, low, leftEnd - 1);
        quickSort(array, leftEnd + 1, high);
    }
}

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
    // Test for already sorted array
    {
        int array[] = {1, 2, 3, 4, 5};
        int size = sizeof(array) / sizeof(array[0]);
        std::cout << "Test 1: Already Sorted Array" << std::endl;
        std::cout << "Before: ";
        printArray(array, size);
        quickSort(array, 0, size - 1);
        std::cout << "After: ";
        printArray(array, size);
        int expected[] = {1, 2, 3, 4, 5};
        assert(arraysEqual(array, expected, size));
    }

    // Test for reverse sorted array
    {
        int array[] = {5, 4, 3, 2, 1};
        int size = sizeof(array) / sizeof(array[0]);
        std::cout << "\nTest 2: Reverse Sorted Array" << std::endl;
        std::cout << "Before: ";
        printArray(array, size);
        quickSort(array, 0, size - 1);
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
        quickSort(array, 0, size - 1);
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
        quickSort(array, 0, size - 1);
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
        quickSort(array, 0, size - 1);
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
        quickSort(array, 0, size - 1);
        std::cout << "After: ";
        printArray(array, size);
        int expected[] = {-5, -1, 0, 2, 3};
        assert(arraysEqual(array, expected, size));
    }

    std::cout << "\nAll tests passed!" << std::endl;
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    runTests();
    return 0;
}
