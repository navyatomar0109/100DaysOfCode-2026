#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node dummy(0);
        Node* temp = &dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->data <= list2->data) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1 != NULL)
            temp->next = list1;
        else
            temp->next = list2;

        return dummy.next;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
  
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(4);


    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    Solution obj;
    Node* result = obj.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(result);

    return 0;
}