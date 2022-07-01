/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = INT_MIN;
        int ct = 0;

        for(int num: nums){
            if(not ct)
                candidate = num;
            ct += (candidate == num)? 1: -1;
        }

        return candidate;
    }
};
// @lc code=end

