#include <iostream>
using namespace std;

// Node of the Binary Heap
class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Max Heap implemented using a Linked Tree
class MaxHeap
{
private:
    Node* root;

    // Find a node by its level-order index
    Node* getNode(int index)
    {
        Node* current = root;

        int path[32];
        int length = 0;

        // Store the path from root to the node
        while (index > 1)
        {
            path[length++] = index % 2;
            index /= 2;
        }

        // Follow the path from root
        for (int i = length - 1; i >= 0; i--)
        {
            if (path[i] == 0)
                current = current->left;
            else
                current = current->right;
        }

        return current;
    }

    // Restore Max Heap property
    void heapifyUp(int index)
    {
        while (index > 1)
        {
            int parentIndex = index / 2;

            Node* child = getNode(index);
            Node* parent = getNode(parentIndex);

            if (child->data > parent->data)
            {
                // Swap data without built-in swap()
                int temp = child->data;
                child->data = parent->data;
                parent->data = temp;

                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    // Print nodes in level-order
    void printLevelOrder()
    {
        if (root == NULL)
            return;

        // Simple linked queue
        Node* queue[1000];
        int front = 0;
        int rear = 0;

        queue[rear++] = root;

        while (front < rear)
        {
            Node* current = queue[front++];

            cout << current->data << " ";

            if (current->left != NULL)
                queue[rear++] = current->left;

            if (current->right != NULL)
                queue[rear++] = current->right;
        }

        cout << endl;
    }

public:
    MaxHeap()
    {
        root = NULL;
    }

    // Insert a new node
    void insert(int value, int size)
    {
        Node* newNode = new Node(value);

        if (root == NULL)
        {
            root = newNode;
            return;
        }

        int parentIndex = size / 2;
        Node* parent = getNode(parentIndex);

        if (size % 2 == 0)
            parent->left = newNode;
        else
            parent->right = newNode;

        // Restore Max Heap property
        heapifyUp(size);
    }

    // Display the Heap
    void display()
    {
        printLevelOrder();
    }
};

int main()
{
    MaxHeap heap;

    // Create Heap by inserting elements one by one
    heap.insert(10, 1);
    heap.insert(5, 2);
    heap.insert(3, 3);
    heap.insert(2, 4);
    heap.insert(4, 5);
    heap.insert(15, 6);

    cout << "Max Heap: ";
    heap.display();

    // Insert another element
    heap.insert(20, 7);

    cout << "After inserting 20: ";
    heap.display();

    return 0;
}

/*
Heap after creating with 10, 5, 3, 2, 4, 15:

          15
         /  \
        4    10
       / \   /
      2   3 5

After inserting 20:

          20
         /  \
        4    15
       / \   / \
      2   3 5  10
*/

