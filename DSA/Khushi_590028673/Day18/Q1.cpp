#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        // Find length of list
        int len = 1;
        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            len++;
        }

        k %= len;
        if (k == 0)
            return head;

        // Make list circular
        tail->next = head;

        // Find new tail
        int steps = len - k;
        ListNode* newTail = head;

        for (int i = 1; i < steps; i++)
            newTail = newTail->next;

        // New head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};

// Create linked list
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;

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
    while (head) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cout << "Enter k: ";
    cin >> k;

    ListNode* head = createList(arr);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.rotateRight(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}