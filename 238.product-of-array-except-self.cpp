/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), left(n), right(n);

        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            left[i] = left[i-1] * nums[i];
            right[n-1-i] = right[n-i] * nums[n-1-i];
        }
        ans[0] = right[1];
        ans[n-1] = left[n-2];

        for(int i = 1; i < n-1; i++)
            ans[i] = left[i-1] * right[i+1];

        return ans;
    }
};
// @lc code=end

