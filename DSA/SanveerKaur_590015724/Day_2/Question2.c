#include <stdio.h>
int maxinteger(int* nums, int numsSize){
    int max= nums[0];
    for(int i=1; i<numsSize;i++){
        if (nums[i]>max){
            max=nums[i];

        }
    }
    return max;

}
int main(){
    int numsSize;
    int nums[100];
printf("Enter number of elements:");
scanf("%d", &numsSize);
printf("Enter %d elements:", numsSize);
for (int i=0;i<numsSize; i++){
    scanf("%d",&nums[i]);
}
int maximum= maxinteger(nums, numsSize);
printf("Maximum element = %d\n",maximum);
return 0;
}