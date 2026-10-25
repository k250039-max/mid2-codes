#include <iostream>
using namespace std;

#define MAX 1000

// Heapify a node using the Bottom-Up approach
void heapify(int arr[], int n, int i)
{
    // Find the parent of the current node
    int parent = (i - 1) / 2;

    // Check whether the parent exists
    if (parent >= 0)
    {
        // Max Heap: Child must not be greater than parent
        if (arr[i] > arr[parent])
        {
            // Swap child and parent using a temporary variable
            int temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp;

            // Continue heapifying from the parent
            heapify(arr, n, parent);
        }
    }
}

// Insert a new element into the Max Heap
void insertNode(int arr[], int& n, int key)
{
    // Increase the heap size
    n++;

    // Insert the new element at the end
    arr[n - 1] = key;

    // Restore the Max Heap property
    heapify(arr, n, n - 1);
}

// Print the heap array
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
    int arr[MAX] = {10, 5, 3, 2, 4};
    int n = 5;

    // Element to insert
    int key = 15;

    cout << "Max Heap before insertion: ";
    printArray(arr, n);

    // Insert the new element
    insertNode(arr, n, key);

    cout << "Max Heap after insertion: ";
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


Insert 15 at the end:

          10
         /  \
        5    3
       / \  /
      2   4 15


After first swap (15 and 3):

          10
         /  \
        5    15
       / \  /
      2   4 3


After second swap (15 and 10):

          15
         /  \
        5    10
       / \   /
      2   4 3


Final Max Heap Array:
15 5 10 2 4 3
*/

