class Solution {
public:
    Node* divide(Node* head) {

        if(head == nullptr || head->next == nullptr)
            return head;

        Node evenDummy(0);
        Node oddDummy(0);

        Node* evenTail = &evenDummy;
        Node* oddTail = &oddDummy;

        Node* curr = head;

        while(curr != nullptr)
        {
            if(curr->data % 2 == 0)
            {
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
            else
            {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }

            curr = curr->next;
        }
        evenTail->next = oddDummy.next;
        oddTail->next = nullptr;
        if(evenDummy.next == nullptr)
            return oddDummy.next;

        return evenDummy.next;
    }
};