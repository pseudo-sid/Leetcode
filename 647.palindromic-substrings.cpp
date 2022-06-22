/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
    int expand(string& s, int l, int r){
        int ans = 0;
        while(l >= 0 and r < s.length() and s[l] == s[r]){
            l--;
            r++;
            ans++;
        }
        return ans;
    }
public:
    int countSubstrings(string s) {
        if(s.length() < 1 or s == "")
            return 0;
        
        int ans = 0;
        for(int i = 0; i < s.length(); i++)
            ans += expand(s, i, i) + expand(s, i, i+1);

        return ans;
    }

};
// @lc code=end

