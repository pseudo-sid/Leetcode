/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int ct = 0;
        int n = nums.size();
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] > nums[i]){
                if(ct)
                    return false;
                
                ct++;

                if(i < 2 or nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
            }
        }
        return true;
    }
};
// @lc code=end

