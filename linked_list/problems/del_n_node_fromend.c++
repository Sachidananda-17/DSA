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

Node* createLinkedList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int countNodes(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

Node* del_n_from_end(Node* head, int k) {
    int totalNodes = countNodes(head);
    int deleteIndex = totalNodes - k;

    if (deleteIndex < 0) return head; // k is greater than the number of nodes

    if (deleteIndex == 0) {
        // Delete the head node
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    for (int i = 0; i < deleteIndex - 1; ++i) {
        current = current->next;
    }

    // Now current points to the node before the one we want to delete
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;

    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    Node* head = createLinkedList(arr);
    cout << "Original list: ";
    printLinkedList(head);

    head = del_n_from_end(head, k);
    cout << "Modified list: ";
    printLinkedList(head);

    return 0;
}




// optimised


// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* fast = head;
//         ListNode* slow = head;
//         for(int i=0;i<n;i++)
//         {
//             fast = fast->next;
//         }
//         if(fast==NULL)
//         {
//             return head->next;
//         }
//         while(fast->next!=NULL)
//         {
//             fast = fast->next;
//             slow= slow->next;
//         }
//         ListNode* delNode = slow->next;
//         slow->next = slow->next->next;
//         delete(delNode);
//         return head;
        
//     }
// };
