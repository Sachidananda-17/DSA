#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    public:

    Node(int data1, Node* next1 )
    {
        data = data1;
        next = next1;

    }

    Node(int data1)
    {
        data = data1;
    }
};

Node* ll2arr(vector<int> &arr)
{
    if(arr.empty())
    {
        return nullptr;
    }

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++)
    {
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

};
void print(Node* head) {
    while (head != nullptr) { 
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* insert_at_k(Node* head, int k , int ele)
{
    if(head == NULL)
    {
        if(k==1)
        {
            return new Node(ele);
        }
        else{
            return head;
        }
    }
    if(k==1)
    {
        return new Node(ele, head);

    }
    int cnt =0;
    Node* temp = head;

    while(temp!=NULL)
    {
        cnt++;
        if(cnt == k-1)
        {
            Node* x = new Node(ele,temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;

    }
    return head;
}
    
int main()
{
    vector<int> arr = { 2,3,4,5,6};
    Node* head = ll2arr(arr);
    head = insert_at_k(head, 6,7);
    print(head);
}