/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long x = 9, y = 1;
        long long digits = 0;
        long long num = 1;
        while(digits <= n and x * y <= n - digits){
            digits += x * y;
            num += x;
            x *= 10;
            y++;
        }
        num--;
        int ans;
        long long rem = n - digits;
        num += rem/y;
        string s;
        if(rem % y == 0){
            s = to_string(num);
            ans = s[s.length()-1]-'0';
        }
        else{
            s = to_string(num+1);
            ans = s[rem%y -1] - '0';
        }
        return ans;
    }
};
// @lc code=end

