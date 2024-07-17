#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

Node* convertArr2LL(const vector<int>& arr) {
    if (arr.empty()) {  
        return nullptr;
    }

    Node* head = new Node(arr[0]);  
    Node* mover = head;

    for (size_t i = 1; i < arr.size(); i++) {  
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;  
}

void print(Node* head) {
    while (head != nullptr) { 
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

Node* insertHead(Node* head, int val) {
    Node* temp = new Node(val, head);
    return temp;
}

Node* insertTail(Node* head, int val) {
    if (head == nullptr) {
        return new Node(val);
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 6};
    cout << "Initial vector: ";
    printVector(arr);  // Print initial vector

    Node* head = convertArr2LL(arr);
    cout << "Linked list before insertion: ";
    print(head);  // Print linked list before insertion

    head = insertTail(head, 69);
    cout << "Linked list after insertion: ";
    print(head);  // Print linked list after insertion

    return 0;
}
