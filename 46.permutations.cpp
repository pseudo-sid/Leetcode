/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        do{
            ans.push_back(nums);
        }
        while(next_permutation(nums.begin(), nums.end()));

        return ans;
    }
};
// @lc code=end

