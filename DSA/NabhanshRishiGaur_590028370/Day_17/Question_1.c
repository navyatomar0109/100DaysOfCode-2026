bool isPalindrome(struct ListNode* head) {
    int arr[100000];
    int n = 0;

    while (head != NULL) {
        arr[n++] = head->val;
        head = head->next;
    }

    int i = 0, j = n - 1;

    while (i < j) {
        if (arr[i] != arr[j])
            return false;
        i++;
        j--;
    }

    return true;
}
