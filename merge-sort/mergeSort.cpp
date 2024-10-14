// Idea: We start with an array of size n (referred to as arraySize in this context).
// We employ a divide-and-conquer recursive approach to sort the array by dividing it into halves.
// The recursion continues until we reach the smallest size (base case), which is an array of size one.
// To find the midpoint of the array, we calculate the index as: middleIndex = (left + right) / 2.
// We then divide the array into two halves: [left : middleIndex] and [middleIndex + 1 : right].
// Our base case occurs when left equals right, indicating that we have a single element to sort
//[should be left==right, however, common practice is left >=right to be the anchor].
// After completing the division, we begin the sorting and combining process.
// We utilize two indices to track the elements of the left and right subarrays, and a third index (k) for the original array.
// During the merging phase, we compare elements from the left and right subarrays, placing the smaller element into the original array.
// We also handle the case where one subarray runs out of elements before the other by simply filling the remaining elements from the second sorted subarray.

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

// Time Complexity:
// Does not depend on input values => (n * log n) for all cases

// Space Complexity:
// - In-place: No  // Merge sort requires additional space for temporary subarrays,
//   making it non-in-place with O(n) extra space.
// - Stable: Yes  // Merge sort preserves the relative order of equal elements,
//   maintaining stability during sorting.
