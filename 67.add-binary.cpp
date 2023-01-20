/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int x = a.length()-1, y = b.length()-1;
        if(x < y)
            return addBinary(b, a);
        int carry = false;
        while(x >= 0 and y >= 0 or carry){
            int c = x >= 0? a[x]- '0': 0;
            int d = y >= 0? a[y] - '0': 0;
            int res = c + d + carry;
            carry = res > 1;
            if(x < 0)
                a = to_string(res%2) + a;
            else
                a[x] = '0' + res%2;
            x--;
            y--;
        }
        return a;
    }
};
// @lc code=end

