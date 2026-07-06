/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *tail,*temp=head;
    int count=0;
    while(temp!=NULL) {
        temp=temp->next;
        count++;
    }
    int arr[count];
    for(int i=0;i<count;i++) {
        arr[i]=head->val;
        head=head->next;
    }
    int left=0,right=count-1;
    while(left<right) {
        if(arr[left]!=arr[right]) return 0;
        left++;
        right--;
    }
    return 1;
}
