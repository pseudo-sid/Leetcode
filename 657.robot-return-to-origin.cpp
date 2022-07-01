/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontal = 0;
        int vertical = 0;

        for(int i = 0; i < moves.length(); i++)
            switch(moves[i]){
                case 'U': vertical++;
                break;
                case 'D': vertical--;
                break;
                case 'L': horizontal++;
                break;
                case 'R': horizontal--;
            }
        return !horizontal and !vertical;
    }
};
// @lc code=end

