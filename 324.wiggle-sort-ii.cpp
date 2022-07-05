/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */

// @lc code=start
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> bucket(5001, 0);
        for(int num: nums)
            bucket[num]++;
        
        int mx = 5000;
        
        bool wiggle = true;
        for(int i = 1; i < nums.size(); i+=2){
          
            while(not bucket[mx])
                mx--;
            nums[i] = mx;
            bucket[mx]--;

            if(i+2 >= nums.size() and wiggle){
                wiggle = not wiggle;
                i = -2;
            }

        }
    }
};
// @lc code=end

