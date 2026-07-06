#include <bits/stdc++.h>
using namespace std;

Node *deleteTail(Node *head){
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *secondLast = head;
    while (secondLast->next->next != NULL)
    {
        secondLast = secondLast->next;
    }
    Node *tail = secondLast->next;
    tail->back = nullptr;
    secondLast->next = nullptr;
    delete tail;
    return head;

    /*
    The above can be done using traversing till the tail element:
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;

    */
}