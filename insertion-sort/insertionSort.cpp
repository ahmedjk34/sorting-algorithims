// Idea: We should start from the second element (i = 1) and then start comparing the element with the ones to the left.
// This requires another index (called 'j' here), and we should continue comparing as long as:
// 1. The element to the left is bigger than the element we are trying to sort (already sorted).
// 2. We don't go beyond the first element [out of the array bounds] (j >= 0).
// With each comparison, if both conditions apply, we simply shift the element to the right.
// Eventually, when we either reach the start of the array (j would be -1) or we find a smaller element to the left,
// we simply insert the key.


void insertionSort(int* array, int size) {
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// Time Complexity:
// - Best case: O(n) - This occurs when the array is already sorted. Each element is compared only once.
// - Average case: O(n^2) - This happens with a random arrangement of elements, leading to approximately n/4 comparisons for each element.
// - Worst case: O(n^2) - This occurs when the array is sorted in reverse order, resulting in the maximum number of comparisons and shifts.

// Space Complexity:
// - In-place: Yes - The sorting is done within the original array, requiring only a constant amount of additional space (for variables `key` and `j`).
// - Stable: Yes - The relative order of equal elements remains unchanged since elements are only shifted to the right when necessary.
