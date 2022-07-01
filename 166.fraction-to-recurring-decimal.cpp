/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        
        double frac = (double) numerator/ (double) denominator;
        string s = to_string(frac);
        int end = s.length()-1;
        while(end >= 0 and s[end] == '0')
            end--;

        string num = s.substr(0,s.find("."));
        string den = "";
    
        return num + "." + den;
    }
};
// @lc code=end

