/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;


class Solution {
    int isAlive(vector<vector<int>>& board, int i, int j){
        if(i < 0  or i >= board.size() or j < 0 or  j >= board[0].size())
            return 0;
        if(abs(board[i][j]) == 1)
            return 1;
        return 0;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> moves = {
            {0, 1}, {1, 0},
            {0, -1},{-1, 0},
            {1, 1}, {1, -1},
            {-1, -1},{-1, 1}
        };

        int n = board.size(), m = board[0].size();

        for(int i =0;i < n; i++)
            for(int j = 0; j < m; j++){
                int alive = 0;
                for(vector<int> move: moves)
                    alive += isAlive(board, i+move[0], j + move[1]);
                if(board[i][j]){
                    if(alive < 2 or alive > 3)
                        board[i][j] = -1;
                }
                else{
                    if(alive == 3)
                        board[i][j] = 2;
                }
            }
        
        for(int i =0; i < n; i++)
            for(int j = 0; j <m; j++)
                if(board[i][j] == -1)
                    board[i][j] = 0;
                else if(board[i][j] == 2)
                    board[i][j] = 1;
    }
};
// @lc code=end

