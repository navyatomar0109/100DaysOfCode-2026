class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_set<int> st;
        
        for (int num : arr) {
            if (st.find(target - num) != st.end()) {
                return true;
            }
            st.insert(num);
        }
        
        return false;
    }
};