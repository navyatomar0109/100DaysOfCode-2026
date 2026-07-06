//Need to check if the linked list has a cycle

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

bool hasCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    // slow moves one step, fast moves two
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        // both pointers met, so there's a loop
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);

    // making a cycle by pointing last node to second node
    head->next->next->next->next = head->next;

    if (hasCycle(head))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}