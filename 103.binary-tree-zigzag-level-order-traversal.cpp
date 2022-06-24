/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        bool left = true;
        vector<int> level;
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        while(q.size() > 1){
            TreeNode* t = q.front();
            q.pop();
            if(t == nullptr){
                ans.push_back(level);
                level.clear();
                q.push(nullptr);
                left = not left;
                continue;
            }
            if(left)
                level.push_back(t->val);
            else
                level.insert(level.begin(), t->val);
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        ans.push_back(level);
        return ans;
    }
};
// @lc code=end

