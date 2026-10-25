#include <iostream>
using namespace std;

// Restore Max Heap property from node i
void heapify(int arr[], int n, int i)
{
    int largest = i;          // Assume root is largest
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // Check if left child is greater than root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Check if right child is greater than largest
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If the largest element is not the root
    if (largest != i)
    {
        // Swap without using built-in swap()
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Restore heap property in affected subtree
        heapify(arr, n, largest);
    }
}

// Delete the root element from Max Heap
void deleteRoot(int arr[], int& n)
{
    // Check whether the Heap is empty
    if (n == 0)
    {
        cout << "Heap is empty. Nothing to delete." << endl;
        return;
    }

    // Replace root with the last element
    arr[0] = arr[n - 1];

    // Decrease the Heap size
    n--;

    // Restore Max Heap property from the root
    if (n > 0)
    {
        heapify(arr, n, 0);
    }
}

// Print the Heap array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    // Initial Max Heap
    int arr[] = {10, 5, 3, 2, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Max Heap before deletion: ";
    printArray(arr, n);

    // Delete the root (maximum element)
    deleteRoot(arr, n);

    cout << "Max Heap after deletion: ";
    printArray(arr, n);

    return 0;
}

/*
Initial Max Heap:

          10
         /  \
        5    3
       / \
      2   4

Delete root (10).
Move the last element (4) to the root.

          4
         / \
        5   3
       /
      2

After heapify, swap 4 and 5.

          5
         / \
        4   3
       /
      2

Final Heap Array:
5 4 3 2
*/

