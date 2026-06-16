package DSA.Sudhanshu_Ranjan_590018435.Day_2;
    class Solution {
        public int removeElement(int[] nums, int val) {
            int cnt = 0;
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] != val) {
                    nums[cnt] = nums[i];
                    cnt++;
                }
            }
            return cnt;
        }
    }
