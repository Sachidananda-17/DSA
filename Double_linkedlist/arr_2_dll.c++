#include<iostream>
#include<vector>
using namespace std;
class Node {
    public:
    int data;
    Node * next;
    Node* prev;

    public:
    Node(int data1, Node* next1, Node* prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
    public: 
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* arr2dll(vector<int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++)
    {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;

    }
    return head;
}

void print(Node* head)
{
    while(head!= NULL)
    {
        cout<<head->data<< " ";
        head = head->next;
    }
}

int main()
{
    vector<int> arr = { 1,2,3,4,5};
    Node* head = arr2dll(arr);
    print(head);
    return 0;
}