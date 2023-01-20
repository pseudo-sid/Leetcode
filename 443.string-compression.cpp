/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int i = 0;
        int k = 0;
        int ct = 1;
        while(i < chars.size()){
            if(i < chars.size()-1 and chars[i] == chars[i+1])
                ct += 1;
            else{
                chars[k++] = chars[i];
                if(ct != 1)
                {
                    string s = to_string(ct);
                    for(int j = 0; j < s.length(); j++)
                        chars[k++] = s[j];
                }
                ct = 1;
            }
            i++;
        }
        return k;
    }
};
// @lc code=end

