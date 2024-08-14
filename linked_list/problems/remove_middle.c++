#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    public:
    Node( int data1, Node* next1 )
    {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

};

Node* arr_2_ll(vector<int>&arr)
{
    Node* head = new Node(arr[0]);
     return head;
}

void print(Node* head)
{
    cout<<
}


int main()
{
    vector<int> arr = {1,2,3,4,5};

    Node* head = arr_2_ll(arr);
    cout<<head<<endl;

}