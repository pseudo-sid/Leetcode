/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void calculate(int n, int pos, vector<bool>& visited, int& ct){
        if(pos > n) ct++;
        for(int i = 1; i <=n; i++)
            if(not visited[i] and (pos % i == 0 or i % pos == 0)){
                visited[i] = true;
                calculate(n, pos + 1, visited, ct);
                visited[i] = false;
            }
    }
public:
    int countArrangement(int n) {
        vector<bool> visited(n+1, false);
        int ct = 0;
        calculate(n, 1, visited, ct);
        return ct;
    }
};
// @lc code=end

