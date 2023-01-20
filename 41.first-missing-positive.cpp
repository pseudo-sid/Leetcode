/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0 and nums[i] <= N and nums[i] != i+1 and nums[nums[i]-1] != nums[i]){
                swap(nums[i], nums[nums[i]-1]);
                i--;
                continue;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1)
                return i+1;
        }
        return N+1;
    }
};
// @lc code=end

