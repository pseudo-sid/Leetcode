/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v(nums.begin(), nums.end());
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int x: nums)
        {
            auto it = lower_bound(v.begin(), v.end(), x);
            ans.push_back(it-v.begin());
        }
        return ans;
    }
};
// @lc code=end

