#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

bool detectCycle(Node *head) {
    unordered_map<Node*, int> visitedNodes; // Map to keep track of visited nodes
    Node *temp = head;

    while (temp != NULL) {
        
        if (visitedNodes.find(temp) != visitedNodes.end()) {
            return true; // Cycle detected
        }

        // Mark the current node as visited
        visitedNodes[temp] = 1;
        
        // Move to the next node
        temp = temp->next;
    }

    // If we reached the end of the list, no cycle was detected
    return false;
}

int main() {
    // Create nodes
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    // Link nodes to form a looped linked list: 1 -> 2 -> 3 -> 4 -> 2
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creates a loop

    // Detect cycle
    if (detectCycle(node1)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    // Clean up the nodes to prevent memory leaks
    // (Note: This will not work correctly if there's a cycle, since some nodes will be part of the cycle and can't be deleted properly.)
    // This is just to demonstrate the concept, and manual deletion in practice requires handling cycles carefully.
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
