#include<iostream>
#include<vector>
using namespace std;

vector<int>endzeros(vector<int>&nums){
    int j = 0;
    for(int i = 0;i<nums.size();i++ ){
        if(nums[i]!=0){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
    return nums; 
};
int main(){
    vector<int>nums = {0,1,0,3,12};
    vector<int>ans = endzeros(nums);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}