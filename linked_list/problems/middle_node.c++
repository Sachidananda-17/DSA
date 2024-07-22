#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node* arr_2_ll(vector<int>& arr)
{
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        mover->next = new Node(arr[i]);
        mover = mover->next;
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

Node* middle_node(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = arr_2_ll(arr);
    Node* middle = middle_node(head);
    cout << "The middle node value is: " << middle->data << endl;
    return 0;
}
