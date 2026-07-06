/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
bool isPalindrome(struct ListNode* head) {
    struct ListNode* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    int arr[count];
    struct ListNode* temp1=head;
    for(int i=0;i<count;i++){
        arr[i]=temp1->val;
        temp1=temp1->next;
    }
    int arr2[count];
    struct ListNode* temp2=head;
    for(int i=0;i<count;i++){
        arr2[i]=temp2->val;
        temp2=temp2->next;
    }
    
    int left=0,right=count-1;
    while(left<right){
        int tempo=arr2[left];
        arr2[left]=arr2[right];
        arr2[right]=tempo;
        left++;
        right--;
    }
    for(int i=0;i<count;i++){
        if(arr[i]==arr2[i]) 
        continue;
        else
        return 0;
    }
    return 1;
}
