#include <stdbool.h>
bool hasPair(int* arr, int arrSize, int target) {
    int left = 0;
    int right = arrSize - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return true;
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    return false;
}