/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        int sz = flowerbed.size();
        int pots = 0;
        while(i < sz){
            if(not flowerbed[i]){
                bool v1 = i <sz-1? not flowerbed[i+1]: true;
                bool v2 = i > 0 ? not flowerbed[i-1]: true;

                if(v1 and v2)
                {
                    i++;
                    pots++;
                }
            }
            i++;
        }
        return pots >= n;
    }
};
// @lc code=end

