#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1, Node* next1 , Node* prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;

    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* arr_2_ll(vector<int>&arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size();i++)
    {
        Node * temp = new Node(arr[i]);
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
      head =  head->next;
    }
    cout<<endl;
    
}

Node* removal_head(Node* head)
{
    if(head == NULL || head->next == NULL )
    {
        return NULL;
    }

    Node* prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}
Node* insert_before_head(Node* head, int val)
{
    Node* newNode = new Node(val, head, nullptr);
    head->prev = newNode;
    // newNode->prev = nullptr;
    return newNode;


}
int main()
{
    vector<int> arr = {2,3,4,5,6};
    Node* head = arr_2_ll(arr);
    head = insert_before_head(head,10);
    print(head);
}