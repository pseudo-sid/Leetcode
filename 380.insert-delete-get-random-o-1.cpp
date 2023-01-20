/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
    unordered_set<int> s;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val) != s.end())
            return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val) != s.end()){
            s.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int r = rand() % s.size();
        auto it = s.begin();
        advance(it, r);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

