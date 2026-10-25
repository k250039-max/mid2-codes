#include <iostream>
using namespace std;

// Node structure to represent each element in the priority queue
struct Node {
    int data;
    int priority;
    Node* next;
};

class PriorityQueue {
private:
    Node* head; // Head of the priority queue

public:
    PriorityQueue() {
        head = NULL;
    }

    // Function to push (insert) an element into the priority queue
    void push(int data, int priority) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->priority = priority;

        // If the queue is empty or the new element has higher priority
        if (head == NULL || newNode->priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;

            // Find the position to insert based on priority
            while (temp->next != NULL && temp->next->priority <= newNode->priority) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to pop (remove) the element with the highest priority from the queue
    void pop() {
        if (head == NULL) {
            cout << "Priority Queue is empty." << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to peek (get) the element with the highest priority without removing it
    int peek() {
        if (head == NULL) {
            cout << "Priority Queue is empty." << endl;
            return -1; // You can choose a different value to indicate an error.
        }
        return head->data;
    }
};

int main() {
    PriorityQueue priorityQueue;

    // Push elements with priorities
    priorityQueue.push(10, 2);
    priorityQueue.push(20, 1);
    priorityQueue.push(30, 3);

    // Peek and print the element with the highest priority
    cout << "Peek: " << priorityQueue.peek() << endl;

    // Pop and print the elements with the highest priority
    priorityQueue.pop();
    cout << "Popped an element." << endl;
    priorityQueue.pop();
    cout << "Popped an element." << endl;

    return 0;
}

