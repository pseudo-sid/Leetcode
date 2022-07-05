/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
       int n = num.length();
       char ans[n-k+1];
       ans[n-k] = '\0';
       int j = n-k-1;
       stack<char> s;
       s.push(num[0]); 
       for(int i =1; i < n; i++){
            while(!s.empty() and k >0 and s.top() > num[i]){
                s.pop();
                k--;
            }
            s.push(num[i]);
       }
       while(k > 0){
        k--;
        s.pop();
       }
       while(!s.empty())
        {
            ans[j--] = s.top();
            s.pop();
        }
        int i = 0;
        if(string(ans) == "")
            return "0";
        while(ans[i] == '0' and i < n-k)
            i++;
        return string(ans + i) == ""? "0": string(ans + i);

    }
};
// @lc code=end

