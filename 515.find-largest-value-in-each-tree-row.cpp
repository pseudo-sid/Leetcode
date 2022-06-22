/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> ans;
        int curr_max = INT_MIN;

        while(q.size() > 1){
            TreeNode* t = q.front();
            q.pop();
            if(t == nullptr){
                ans.push_back(curr_max);
                q.push(nullptr);
                curr_max = INT_MIN;
            }
            else{
                curr_max = max(curr_max, t->val);
                if(t->left != nullptr)
                    q.push(t->left);
                if(t->right != nullptr)
                    q.push(t->right);
            }
        }
        ans.push_back(curr_max);
        return ans;
    }
};
// @lc code=end

