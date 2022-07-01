/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool checkInRange(int a, int b, int c){
        return (a <= b and b <= c);
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty())
            return {newInterval};
        vector<vector<int>> ans;
        int start = newInterval[0], end = newInterval[1];
        bool flag = false;

        for(int i = 0; i < intervals.size(); i++){
            bool x = checkInRange(intervals[i][0], start, intervals[i][1]);
            bool y = checkInRange(intervals[i][0], end, intervals[i][1]);

            if(start == INT_MAX)
                x = y = false;
            if(x or y or (start < intervals[i][0] and end > intervals[i][1])){
                flag = true;
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
            else if (start < intervals[i][0] and end < intervals[i][1]){
                ans.push_back({start, end});
                start = INT_MAX;
                ans.push_back(intervals[i]);
            }
            else{
                if(flag and start != INT_MAX){
                    flag = false;
                    ans.push_back({start, end});
                    start = INT_MAX;
                }
                ans.push_back(intervals[i]);
            }
        }

        if(flag)
            ans.push_back(newInterval);
        else if(start != INT_MAX){
            if(start < intervals[0][0])
                ans.insert(ans.begin(), newInterval);
            else
                ans.push_back(newInterval);
        }
        return ans;
    }
};
// @lc code=end

