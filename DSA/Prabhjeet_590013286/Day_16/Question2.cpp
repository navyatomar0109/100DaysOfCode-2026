//Need to delete the last node from a doubly linked list

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;

    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

Node* deleteLast(Node* head)
{
    // nothing to delete
    if (head == nullptr)
    {
        return nullptr;
    }

    // only one node was there
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node* temp = head;

    // reach the last node
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;

    return head;
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
    head->next->prev = head;

    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    head = deleteLast(head);

    print(head);

    return 0;
}