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

Node* removeKthElement(Node* head , int k)
{
    if(head == NULL)
    {
        return NULL;
    }

    int cnt =0;
    Node* Knode = head;
    while(Knode!= NULL)
    {
        cnt++;
        if(cnt==k) break;
        Knode = Knode->next;

    }

    Node* prev = Knode->prev;
    Node* front = Knode->next;

    if(prev ==NULL && front ==NULL)
    {
        return NULL;
    }

    else if (prev ==NULL)
    {
        return delete_head(head);
    }
    else if(front ==NULL)
    {
        return delete_tail(head);
    }

    prev->next = front;
    front->prev = prev;

    Knode->next = nullptr;
    Knode->prev = nullptr;

    delete Knode;

    return head;


}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6};
    Node* head = arr_2_ll(arr);
    head = removeKthElement(head, 1);
    print(head);
    return 0;
}
