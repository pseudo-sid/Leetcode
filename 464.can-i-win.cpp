/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 */

// @lc code=start
#include<unordered_map>
using namespace std;

class Solution {
    bool canPlayerWin(int x, int y, int chosenState, unordered_map<int, int>& dp){
        if(dp.find(chosenState) != dp.end())
            return dp[chosenState];
        
        for(int i = 0; i < x; i++){
            int curr = (1 << i);
            if( not (curr & chosenState)){
                int newChosenState = curr | chosenState;
                if (y <= i+1 or not canPlayerWin(x, y- i-1, newChosenState, dp))
                    return dp[chosenState] = true;
            }
        }
        return dp[chosenState] = false;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int x = maxChoosableInteger;
        int y = desiredTotal;
        
        //if maxChoosable is greater than equal to desired total, first player wins
        if(x >= y)
            return true;
        //max running total less than desired total
        if((x+1)*x/2 < y)
            return false;
        
        unordered_map<int, int> dp;
        return canPlayerWin(x, y, 0, dp);
    }
};
// @lc code=end

