#include <iostream>
#include <vector>
using namespace std;

// Definition of a linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Function to segregate even and odd nodes
ListNode* segregateEvenOdd(ListNode* head) {
    if (head == nullptr)
        return nullptr;

    ListNode *evenHead = nullptr, *evenTail = nullptr;
    ListNode *oddHead = nullptr, *oddTail = nullptr;

    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* nextNode = curr->next; // Save next node
        curr->next = nullptr;            // Detach current node

        if (curr->val % 2 == 0) {        // Even node
            if (evenHead == nullptr) {
                evenHead = evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else {                         // Odd node
            if (oddHead == nullptr) {
                oddHead = oddTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }

        curr = nextNode;
    }

    // If there are no even nodes
    if (evenHead == nullptr)
        return oddHead;

    // Connect even list with odd list
    evenTail->next = oddHead;

    return evenHead;
}

// Create linked list
ListNode* createList(vector<int> arr) {
    if (arr.empty())
        return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Delete linked list
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    vector<int> arr = {17, 15, 8, 9, 2, 4, 6};

    ListNode* head = createList(arr);

    cout << "Original List:\n";
    printList(head);

    head = segregateEvenOdd(head);

    cout << "\nAfter Segregating Even and Odd Nodes:\n";
    printList(head);

    deleteList(head);

    return 0;
}
