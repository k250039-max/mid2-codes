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

class MaxHeap
{
private:
    Node* root;

    // Count total nodes in the Heap
    int countNodes(Node* current)
    {
        if (current == NULL)
            return 0;

        return 1 + countNodes(current->left)
                 + countNodes(current->right);
    }

    // Find a node using its level-order index
    Node* getNode(int index)
    {
        Node* current = root;
        int path[32];
        int length = 0;

        while (index > 1)
        {
            path[length++] = index % 2;
            index /= 2;
        }

        for (int i = length - 1; i >= 0; i--)
        {
            if (path[i] == 0)
                current = current->left;
            else
                current = current->right;
        }

        return current;
    }

    // Restore Max Heap property downward
    void heapifyDown(Node* current)
    {
        if (current == NULL)
            return;

        Node* largest = current;

        if (current->left != NULL &&
            current->left->data > largest->data)
        {
            largest = current->left;
        }

        if (current->right != NULL &&
            current->right->data > largest->data)
        {
            largest = current->right;
        }

        if (largest != current)
        {
            // Swap data without built-in swap()
            int temp = current->data;
            current->data = largest->data;
            largest->data = temp;

            heapifyDown(largest);
        }
    }

public:
    MaxHeap()
    {
        root = NULL;
    }

    // Insert a node into the Max Heap
    void insert(int value)
    {
        Node* newNode = new Node(value);
        int size = countNodes(root) + 1;

        if (root == NULL)
        {
            root = newNode;
            return;
        }

        Node* parent = getNode(size / 2);

        if (size % 2 == 0)
            parent->left = newNode;
        else
            parent->right = newNode;

        // Restore Max Heap property upward
        int index = size;

        while (index > 1)
        {
            Node* child = getNode(index);
            Node* parentNode = getNode(index / 2);

            if (child->data > parentNode->data)
            {
                int temp = child->data;
                child->data = parentNode->data;
                parentNode->data = temp;

                index /= 2;
            }
            else
            {
                break;
            }
        }
    }

    // Delete the root of the Max Heap
    void deleteRoot()
    {
        if (root == NULL)
        {
            cout << "Heap is empty." << endl;
            return;
        }

        int size = countNodes(root);

        // If there is only one node
        if (size == 1)
        {
            delete root;
            root = NULL;
            return;
        }

        // Locate the last node and its parent
        Node* lastNode = getNode(size);
        Node* parent = getNode(size / 2);

        // Replace root data with last node data
        root->data = lastNode->data;

        // Remove the last node
        if (size % 2 == 0)
            parent->left = NULL;
        else
            parent->right = NULL;

        delete lastNode;

        // Restore Max Heap property
        heapifyDown(root);
    }

    // Display Heap in level-order
    void display()
    {
        int size = countNodes(root);

        for (int i = 1; i <= size; i++)
        {
            cout << getNode(i)->data << " ";
        }

        cout << endl;
    }
};

int main()
{
    MaxHeap heap;

    // Create a Max Heap
    heap.insert(10);
    heap.insert(5);
    heap.insert(3);
    heap.insert(2);
    heap.insert(4);

    cout << "Heap before deletion: ";
    heap.display();

    // Delete the root (maximum element)
    heap.deleteRoot();

    cout << "Heap after deletion: ";
    heap.display();

    return 0;
}

/*
Initial Max Heap:

          10
         /  \
        5    3
       / \
      2   4

After deleting root (10):

          5
         / \
        4   3
       /
      2

Final Heap:
5 4 3 2
*/

