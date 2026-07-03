//Need to remove the nth node from the end of the linked list

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node* removeNth(Node* head, int n)
{
    Node dummy(0);
    dummy.next = head;

    Node* fast = &dummy;
    Node* slow = &dummy;

    // keep a gap of n nodes
    for (int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }

    // now move both together
    while (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node* temp = slow->next;
    slow->next = temp->next;
    delete temp;

    return dummy.next;
}

void print(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int n = 2;

    head = removeNth(head, n);

    print(head);

    return 0;
}