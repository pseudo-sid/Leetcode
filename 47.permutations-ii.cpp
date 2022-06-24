/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty())
            return {};
        
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        do{
            s.insert(nums);
        }
        while(next_permutation(nums.begin(), nums.end()));
        ans.assign(s.begin(), s.end());
        return ans;
    }
};
// @lc code=end

