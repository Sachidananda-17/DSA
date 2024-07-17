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
    if (arr.empty()) {  
        return nullptr;
    }

    Node* head = new Node(arr[0]);  
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {  
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    mover = head;  
    while (mover != nullptr) {  
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;  

    return head;  
}

void print(Node* head) {
    while (head != nullptr) { 
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


Node* insertHead(Node* head, int val)
{
    Node* temp = new Node(val ,head);
    return temp;

}
int main() {
    vector<int> arr = {2, 3, 4, 5, 6};
    Node* head = convertArr2LL(arr);
    head = insertHead( head, 11);
    print(head);

    return 0;
}
