void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sortColors(int* nums, int numsSize){
    int left = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            swap(&nums[left], &nums[i]);
            left++;
        }
    }
    for (int i = left; i < numsSize; i++) {
        if (nums[i] == 1) {
            swap(&nums[left], &nums[i]);
            left++;
        }
    }
}