/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
#define p pair<char, int>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char c: s)
            freq[c]++;
        int mx = max_element(freq.begin(), freq.end(), [](p a, p b){
            return a.second <= b.second;
        })->second;
        vector<vector<char>> charfreq(mx+1);

        for(p x: freq)
            charfreq[x.second].push_back(x.first);
        int j = 0;
        for(int i = mx; i >= 0; i--)
            for(char c: charfreq[i])
                for(int k = 0; k < i; k++)
                    s[j++] = c;
        
        return s;
    }
};
// @lc code=end

