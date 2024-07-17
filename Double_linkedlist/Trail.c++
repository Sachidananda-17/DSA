#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* arr2ll(vector<int> &arr)
{

    if(arr.empty())
    {
        return nullptr;
    }
    Node* head = new Node(arr[0]);
    Node* mover= head;
    for(int i=1;i<arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }
    mover = head;
    while(mover!=nullptr)
    {
        cout<<mover->data<< " ";
        mover = mover->next;
    }
    cout<<endl;

    return head;



}

void print(Node* head)
{
    while(head!= nullptr)
    {
        cout<<head->data<< " ";
        head = head->next;
    }
    cout<<endl;
    
}

int main()
{
    vector<int> arr = {2,3,4,5,6};
    Node * head = arr2ll(arr);
    print(head);
}