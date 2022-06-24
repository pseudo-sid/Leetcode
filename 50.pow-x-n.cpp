/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0)
        {
            x = 1/x;
            n = abs(n);
        }
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        double ans = 1;
        double v = myPow(x, n/2);
        if(n%2)
            ans *= x;
        return ans * v * v;
    }
};
// @lc code=end

