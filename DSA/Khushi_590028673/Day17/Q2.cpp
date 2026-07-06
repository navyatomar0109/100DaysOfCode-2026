#include <iostream>
#include <vector>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<ListNode*> nodes;

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nodes.push_back(new ListNode(x));
    }

    // Connect nodes
    for (int i = 0; i < n - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    int pos;
    cout << "Enter position where last node connects (-1 for no cycle): ";
    cin >> pos;

    if (pos != -1) {
        nodes[n - 1]->next = nodes[pos];
    }

    ListNode* head = nodes[0];

    Solution obj;

    if (obj.hasCycle(head))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}