#include <bits/stdc++.h>
using namespace std;

// Structure to represent node
struct StackNode {
    int data;
    StackNode *next;
    StackNode(int d) {
        data = d;
        next = NULL;
    }
};

// Structure to represent stack
struct MyStack {
    StackNode *top;
    int size;

    MyStack() {
        top = NULL;
        size = 0;
    }

    // Function to push an element onto the stack
    void stackPush(int x) {
        StackNode *element = new StackNode(x);
        element->next = top;
        top = element;
        cout << "Element pushed: " << x << "\n";
        size++;
    }

    // Function to pop an element from the stack
    int stackPop() {
        if (top == NULL) {
            cout << "Stack is empty, cannot pop.\n";
            return -1;
        }
        // Get data
        int topData = top->data;
        // Store top node temporarily
        StackNode *temp = top;
        // Update top to next node
        top = top->next;
        // Delete old top node
        delete temp;
        // Decrement size
        size--;
        // Return data
        return topData;
    }

    // Function to get the size of the stack
    int stackSize() {
        return size;
    }

    // Function to check if the stack is empty
    bool stackIsEmpty() {
        return top == NULL;
    }

    // Function to get the top element of the stack
    int stackPeek() {
        if (top == NULL) {
            cout << "Stack is empty, no top element.\n";
            return -1;
        }
        return top->data;
    }

    // Function to print the stack
    void printStack() {
        StackNode *current = top;
        if (current == NULL) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    // Create stack
    MyStack s;

    s.stackPush(10);
    cout << "Element popped: " << s.stackPop() << "\n";
    cout << "Stack size: " << s.stackSize() << "\n";
    cout << "Stack empty or not? " << (s.stackIsEmpty() ? "Yes" : "No") << "\n";
    cout << "Stack's top element: " << s.stackPeek() << "\n";

    // Test with multiple elements
    s.stackPush(20);
    s.stackPush(30);
    s.printStack();

    return 0;
}