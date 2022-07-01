/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int isBoundary(vector<vector<int>>& grid, int i, int j){
        if(i < 0 or  j< 0 or i >= grid.size() or j >= grid[0].size())
            return 1;
        return not grid[i][j];
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> moves = {1,0,-1,0,1};
        int perimeter = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0 ; j < m; j++)
                if(grid[i][j])
                    for(int k = 0; k < 4; k++)
                        perimeter += isBoundary(grid, i + moves[k], j + moves[k+1]);
        return perimeter;
    }
};
// @lc code=end

