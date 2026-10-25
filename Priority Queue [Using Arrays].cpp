
#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int data[100];
    int priority[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    // Insert an element according to its priority
    void push(int value, int p) {
        if (size == 100) {
            cout << "Priority Queue is full." << endl;
            return;
        }

        int i = size - 1;

        // Shift elements to maintain priority order
        while (i >= 0 && priority[i] > p) {
            data[i + 1] = data[i];
            priority[i + 1] = priority[i];
            i--;
        }

        data[i + 1] = value;
        priority[i + 1] = p;

        size++;
    }

    // Remove the element with the highest priority
    void pop() {
        if (size == 0) {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        // Shift remaining elements to the left
        for (int i = 0; i < size - 1; i++) {
            data[i] = data[i + 1];
            priority[i] = priority[i + 1];
        }

        size--;
    }

    // Return the element with the highest priority
    int peek() {
        if (size == 0) {
            cout << "Priority Queue is empty." << endl;
            return -1;
        }

        return data[0];
    }

    // Display all elements with their priorities
    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << "Data: " << data[i]
                 << ", Priority: " << priority[i] << endl;
        }
    }
};

int main() {
    PriorityQueue pq;

    pq.push(10, 2);
    pq.push(20, 1);
    pq.push(30, 3);

    cout << "Priority Queue:" << endl;
    pq.display();

    cout << "\nPeek: " << pq.peek() << endl;

    pq.pop();
    cout << "\nAfter pop:" << endl;
    pq.display();

    return 0;
}

