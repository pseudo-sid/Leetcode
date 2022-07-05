/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
class Solution {
    vector<int> prefixSums;
public:
    Solution(vector<int>& w) {
        prefixSums.push_back(w[0]);
        for(int i = 1; i < w.size(); i++)
            prefixSums.push_back(prefixSums[i-1] + w[i]);
    }
    
    int pickIndex() {
        float randNum = (float) rand() / RAND_MAX;
        float target =  randNum * prefixSums.back();
        return upper_bound(begin(prefixSums), end(prefixSums), target) - begin(prefixSums);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

