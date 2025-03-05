#include <iostream>
#define SIZE 5  // Fixed size for stack and queue

// ================= STACK IMPLEMENTATION ================= //
class Stack {
    int arr[SIZE];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

    bool isEmpty() { return topIndex == -1; }
    bool isFull() { return topIndex == SIZE - 1; }

    void push(int x) {
        if (isFull()) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = x;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow\n";
            return;
        }
        --topIndex;
    }

    int top() {
        if (isEmpty()) return -1;
        return arr[topIndex];
    }
};

// ================= QUEUE IMPLEMENTATION ================= //
class Queue {
    int arr[SIZE];
    int frontIndex, rearIndex, count;

public:
    Queue() : frontIndex(0), rearIndex(-1), count(0) {}

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == SIZE; }

    void enqueue(int x) {
        if (isFull()) {
            std::cout << "Queue Overflow\n";
            return;
        }
        rearIndex = (rearIndex + 1) % SIZE;
        arr[rearIndex] = x;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow\n";
            return;
        }
        frontIndex = (frontIndex + 1) % SIZE;
        count--;
    }

    int front() {
        if (isEmpty()) return -1;
        return arr[frontIndex];
    }
};

// ================= SINGLY LINKED LIST IMPLEMENTATION ================= //
struct Node {
    int data;
    int next;  // Index of next node in the array
};

class SinglyLinkedList {
    Node nodes[SIZE];
    int head, freeIndex;  // Head pointer and free memory index

public:
    SinglyLinkedList() : head(-1), freeIndex(0) {
        for (int i = 0; i < SIZE - 1; i++)
            nodes[i].next = i + 1;  // Setup free list
        nodes[SIZE - 1].next = -1;
    }

    void insert(int x) {
        if (freeIndex == -1) {
            std::cout << "List Overflow\n";
            return;
        }
        int newNode = freeIndex;
        freeIndex = nodes[freeIndex].next;

        nodes[newNode].data = x;
        nodes[newNode].next = -1;

        if (head == -1) {
            head = newNode;
        } else {
            int temp = head;
            while (nodes[temp].next != -1)
                temp = nodes[temp].next;
            nodes[temp].next = newNode;
        }
    }

    void remove(int x) {
        int temp = head, prev = -1;
        while (temp != -1 && nodes[temp].data != x) {
            prev = temp;
            temp = nodes[temp].next;
        }
        if (temp == -1) return;  // Not found

        if (prev == -1)
            head = nodes[temp].next;
        else
            nodes[prev].next = nodes[temp].next;

        nodes[temp].next = freeIndex;
        freeIndex = temp;
    }

    void display() {
        int temp = head;
        while (temp != -1) {
            std::cout << nodes[temp].data << " -> ";
            temp = nodes[temp].next;
        }
        std::cout << "NULL\n";
    }
};

// ================= MAIN FUNCTION (TEST CASES) ================= //
int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Stack top: " << stack.top() << "\n";
    stack.pop();
    std::cout << "Stack top after pop: " << stack.top() << "\n";

    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "Queue front: " << queue.front() << "\n";
    queue.dequeue();
    std::cout << "Queue front after dequeue: " << queue.front() << "\n";

    SinglyLinkedList list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    std::cout << "Linked List: ";
    list.display();
    list.remove(10);
    std::cout << "After Removing 10: ";
    list.display();

    return 0;
}
