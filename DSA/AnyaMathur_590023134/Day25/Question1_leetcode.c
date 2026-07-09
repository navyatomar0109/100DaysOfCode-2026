// Leetcode Problem 611 
// Valid Triangle Number

void mergeArrays(int nums[], int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int leftArray[leftSize], rightArray[rightSize];

    for(int leftIndex = 0; leftIndex < leftSize; leftIndex++)
        leftArray[leftIndex] = nums[start + leftIndex];

    for(int rightIndex = 0; rightIndex < rightSize; rightIndex++)
        rightArray[rightIndex] = nums[mid + 1 + rightIndex];

    int leftIndex = 0;
    int rightIndex = 0;
    int arrayIndex = start;

    while(leftIndex < leftSize && rightIndex < rightSize) {
        if(leftArray[leftIndex] <= rightArray[rightIndex])
            nums[arrayIndex++] = leftArray[leftIndex++];
        else
            nums[arrayIndex++] = rightArray[rightIndex++];
    }

    while(leftIndex < leftSize)
        nums[arrayIndex++] = leftArray[leftIndex++];

    while(rightIndex < rightSize)
        nums[arrayIndex++] = rightArray[rightIndex++];
}

void mergeSort(int nums[], int start, int end) {
    if(start < end) {
        int mid = start + (end - start) / 2;

        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);

        mergeArrays(nums, start, mid, end);
    }
}

int triangleNumber(int* nums, int numsSize) {
    mergeSort(nums, 0, numsSize - 1);
    int count = 0;
    for(int last = numsSize - 1; last >= 2; last--) {
        int left = 0;
        int right = last - 1;

        while(left < right) {
            if(nums[left] + nums[right] > nums[last]) {
                count += right - left;
                right--;
            }
            else {
                left++;
            }
        }
    }
    return count;
}