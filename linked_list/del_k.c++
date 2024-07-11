#include<iostream>
#include<vector>
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

Node* convertArr2LL(vector<int> &arr) {
    if (arr.empty()) { // Correct
        return nullptr;
    }

    Node* head = new Node(arr[0]); // Correct
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) { // Correct
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    mover = head; // Correct
    while (mover != nullptr) { // Correct
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl; // Correct, to ensure the output ends with a newline

    return head; // Correct
}

void print(Node* head) {
    while (head != nullptr) { // Corrected NULL to nullptr for consistency
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* removehead(Node* head) {
    if (head == nullptr) { // Corrected NULL to nullptr
        return head;
    }

    Node* temp = head;
    head = head->next;
    delete temp; // Corrected free to delete
    return head;
}

Node* deltail(Node* head) {
    if (head == nullptr || head->next == nullptr) { // Corrected NULL to nullptr
        return nullptr;
    }

    Node* temp = head;

    while (temp->next->next != nullptr) { // Corrected NULL to nullptr
        temp = temp->next;
    }
    delete temp->next; // Corrected free to delete
    temp->next = nullptr;

    return head;
}

Node* removek(Node* head, int k) {
    if (head == nullptr) { // Mistake: should be '==' instead of '='
        return head;
    }

    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp; // Corrected free to delete
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr) {
        cnt++;
        if (cnt == k) {
            prev->next = temp->next; // Fixed prev->next->next to temp->next
            delete temp; // Corrected free to delete
            break;
        }

        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 6};
    Node* head = convertArr2LL(arr);
    head = removek(head, 3);
    print(head);

    return 0;
}
