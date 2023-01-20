/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq_character(128, 0);
        for(int i = 0; i < magazine.length(); i++)
            freq_character[magazine[i]]++;
        
        for(int i = 0; i < ransomNote.length(); i++)
            if(not freq_character[ransomNote[i]]--)
                return false;
        
        return true;
    }
};
// @lc code=end

