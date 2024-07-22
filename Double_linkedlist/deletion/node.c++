#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr)
        : data(data1), next(next1), prev(prev1) {}
};

Node* arr_2_ll(vector<int>& arr)
{
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        temp->prev = prev;
        prev = temp;
    }
    return head;
}

void print(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* delete_head(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node* new_head = head->next;
    new_head->prev = nullptr;
    delete head;
    return new_head;
}

Node* delete_tail(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node* tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    Node* new_tail = tail->prev;
    new_tail->next = nullptr;
    delete tail;
    return head;
}

Node* removeKthElement(Node* head, int k)
{
    if (head == nullptr) return nullptr;

    Node* Knode = head;
    for (int i = 1; i < k && Knode != nullptr; i++)
    {
        Knode = Knode->next;
    }

    if (Knode == nullptr) return head;

    if (Knode->prev == nullptr) 
    {
        return delete_head(head);
    }
    else if (Knode->next == nullptr) 
    {
        return delete_tail(head);
    }
    else
    {
        Node* prev = Knode->prev;
        Node* front = Knode->next;

        prev->next = front;
        front->prev = prev;

        delete Knode;
        return head;
    }
}

void deleteNode(Node* node)
{
    if (node == nullptr) return;

    if (node->prev != nullptr)
    {
        node->prev->next = node->next;
    }

    if (node->next != nullptr)
    {
        node->next->prev = node->prev;
    }

    delete node;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6};
    Node* head = arr_2_ll(arr);
    deleteNode(head->next->next);
    print(head);
    return 0;
}
