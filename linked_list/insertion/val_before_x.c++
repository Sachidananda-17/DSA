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

Node* insertBeforeValue(Node* head, int el, int val) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->data == val) {
        return new Node(el, head);
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != val) {
        current = current->next;
    }

    if (current->next != nullptr) {
        current->next = new Node(el, current->next);
    }

    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2LL(arr);

    cout << "Original Linked List: ";
    print(head);

    head = insertHead(head, 0);
    cout << "After inserting 0 at head: ";
    print(head);

    head = insertBeforeValue(head, 10, 3);
    cout << "After inserting 10 before 3: ";
    print(head);

    head = insertBeforeValue(head, 15, 0);
    cout << "After inserting 15 before 0: ";
    print(head);

    head = insertBeforeValue(head, 20, 6);
    cout << "After trying to insert 20 before non-existing 6: ";
    print(head);

    return 0;
}
