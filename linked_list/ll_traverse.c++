#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};

Node* convertArr2LL(int n)
{
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < n; i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int lengthOfLL(Node* head)
{
    int cnt =0;
    Node* temp = head;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

bool CheckIfPresent(Node* head, int val)
{
    Node* temp =head;
    while(temp)
    {
        if(temp->data == val) return true;
        temp = temp->next;
    }

    return false;
}

int main()
{
    int n,x;
    cout << "Enter the number of elements: ";
    cin >> n;

    Node* head = convertArr2LL(n);
    cout<<lengthOfLL(head);
    cout<<"enter the element to be checked"<<endl;
    cin>>x;
    cout<<CheckIfPresent(head, x);
    return 0;
}
