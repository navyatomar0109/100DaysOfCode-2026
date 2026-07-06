#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Create Linked List
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Print Linked List
void printList(ListNode* head) {
    if (head == NULL) {
        cout << "[]";
        return;
    }

    while (head) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete nth node from end
        ListNode* delNode = slow->next;
        slow->next = delNode->next;
        delete delNode;

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cout << "Enter n (node to remove from end): ";
    cin >> k;

    ListNode* head = createList(arr);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.removeNthFromEnd(head, k);

    cout << "Updated List: ";
    printList(head);

    return 0;
}