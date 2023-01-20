/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
    vector<int> moves;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int idx){
        if(idx == word.length())
            return true;
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size())
            return false;
        if(board[i][j] != word[idx] or board[i][j] == '\0')
            return false;
        char temp = board[i][j];
        board[i][j] = '\0';    
        bool ret = false;
        for(int k = 0; k < moves.size()-1; k++)
            ret = ret or dfs(board, word, i + moves[k], j + moves[k+1], idx + 1);
        board[i][j] = temp;
        return ret;
    }
public:
    Solution(){
        moves = {1,0,-1,0,1};
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(dfs(board, word, i, j, 0))
                    return true;
        return false;
    }
};
// @lc code=end

