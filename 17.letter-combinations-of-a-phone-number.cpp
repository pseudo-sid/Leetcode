/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
    vector<string> numpad;
    vector<string> ans;

    void generate(string &digits, char* curr, int idx)
    {
        if(idx == digits.length())
        {
            ans.push_back(string(curr));
            return;
        }
        int num = digits[idx] - '0';
        for(char c: numpad[num]){
            curr[idx] = c;
            generate(digits, curr, idx+1);
        }

    }
public:
    Solution(){
        numpad = {
                " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};
        
        char curr[digits.length()+1];
        curr[digits.length()] = '\0';
        generate(digits, curr, 0);
        return ans;
    }
};
// @lc code=end

