#include <iostream>
using namespace std;

// Heapify a subtree rooted at index i
void heapify(int arr[], int N, int i)
{
    int largest = i;          // Assume root is largest
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // Check if left child is greater than root
    if (left < N && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Check if right child is greater than largest
    if (right < N && arr[right] > arr[largest])
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

        // Heapify the affected subtree
        heapify(arr, N, largest);
    }
}

// Build a Max Heap from the given array
void buildHeap(int arr[], int N)
{
    // Find the last non-leaf node
    int startIdx = (N / 2) - 1;

    // Heapify all non-leaf nodes in reverse order
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, N, i);
    }
}

// Print the array representation of the Heap
void printHeap(int arr[], int N)
{
    cout << "Array representation of Max Heap:\n";

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    // Initial array (not a Max Heap)
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

    // Calculate the number of elements
    int N = sizeof(arr) / sizeof(arr[0]);

    // Build the Max Heap
    buildHeap(arr, N);

    // Display the resulting Heap
    printHeap(arr, N);

    return 0;
}

/*
Final Max Heap Tree:

                 17
               /    \
             15      13
            /  \    /  \
           9    6  5   10
          / \  / \
         4   8 3   1

Final Array:
17 15 13 9 6 5 10 4 8 3 1
*/

