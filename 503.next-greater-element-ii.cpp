/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res (n);
        stack<int> s;
        for(int i = 2 * n-1; i>= 0; i--){
            while(not s.empty() and nums[s.top()] <= nums[i%n])
                s.pop();
            res[i % n] = s.empty()?-1:nums[s.top()];
            s.push(i % n);
        }
        return res;
    }
};
// @lc code=end

