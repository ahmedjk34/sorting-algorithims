// Idea: We start with an array of size n
// We employ a divide-and-conquer recursive approach to sort the array by selecting a pivot element
// and partitioning the array around it. The recursion continues until we reach the smallest size (base case),
// which is when the sub-array has one or no elements to sort.

// To select the pivot, we generate a random index within the current bounds of the array.
// We then rearrange the elements in such a way that all elements less than the pivot are to its left
// and all elements greater are to its right. This partitioning is done in-place.

// The partitioning process involves two pointers:
// - One pointer starts from the beginning of the sub-array, and the other traverses to the end.
// As we iterate, we swap elements to ensure that they are correctly positioned relative to the pivot.

// After partitioning, we identify the final position of the pivot, which is now in its correct sorted place.
// We then recursively apply the same process to the two resulting sub-arrays: the left side (elements < pivot)
// and the right side (elements > pivot).

// Our base case occurs when the low index is greater than or equal to the high index [when n == 1 ; we used it like this to prevent errors],
// indicating that there is no need for further sorting in that sub-array.

#include <iostream>
#include <cstdlib>
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

// Time Complexity:
// Average and best case: n log n
// Worst case (when the smallest or largest element is always chosen as the pivot): O(n^2)
// NOTE THAT: we wrote the algorithm in a way to prevents the worse case from happening , so we can say quick sort is O(n log n)

// Space Complexity:
// - In-place: Yes  // Quicksort is an in-place sorting algorithm with O(log n) space complexity
//   due to the recursive call stack.
// - Stable: No  // Quicksort is not a stable sorting algorithm, as it may change the relative order of equal elements.