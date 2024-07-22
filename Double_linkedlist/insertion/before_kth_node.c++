#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* arr_2_ll(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (size_t i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        temp->prev = prev;
        prev = temp;
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

Node* removal_head(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* newHead = head->next;
    newHead->prev = nullptr;
    delete head;
    return newHead;
}

Node* insert_before_head(Node* head, int val) {
    Node* newNode = new Node(val, head, nullptr);
    if (head != nullptr) {
        head->prev = newNode;
    }
    return newNode;
}

Node* insert_before_tail(Node* head, int val) {
    if (head == nullptr) {
        return new Node(val);
    }

    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    Node* newNode = new Node(val, tail, tail->prev);
    if (tail->prev != nullptr) {
        tail->prev->next = newNode;
    } else {
        head = newNode;  // If the list had only one element, update the head
    }
    tail->prev = newNode;
    return head;
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 6};
    Node* head = arr_2_ll(arr);
    head = insert_before_tail(head, 200);
    print(head);
    return 0;
}
