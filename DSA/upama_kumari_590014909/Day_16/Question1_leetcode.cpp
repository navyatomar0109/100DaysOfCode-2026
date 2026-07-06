#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;

    while (prev->next != NULL && prev->next->next != NULL) {
        ListNode* first = prev->next;
        ListNode* second = first->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }

    return dummy->next;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original List: ";
    printList(head);

    head = swapPairs(head);

    cout << "After Swapping: ";
    printList(head);

    return 0;
}