/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int l = 0, r = 0;
         int n = s.length();
        vector<int> v(128, -1);
        int mx_length = 0;
         while(r < n){
            if(v[s[r]] != -1)
                while(v[s[r]] != -1)
                    v[s[l++]] = -1;
            
            v[s[r]] = r;
            mx_length = max(mx_length, r++ -l+1);
         }
         return mx_length;
    }
};
// @lc code=end

