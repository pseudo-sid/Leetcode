/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

    bool search_el(TreeNode*& root, TreeNode*& v, int id, vector<stack<TreeNode*>> &s){
        if(root == nullptr)
            return false;
        if(root == v){
            s[id].push(root);
            return true;
        }
        bool ans = search_el(root->left, v, id, s) or search_el(root->right, v, id, s);
        if(ans)
            s[id].push(root);
        return ans;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<stack<TreeNode*>> s(2);
        search_el(root, p, 0, s);
        search_el(root, q, 1, s);

        TreeNode* lowest;
        while(!s[0].empty() and !s[1].empty() and s[0].top() == s[1].top()){
            lowest = s[0].top();
            for(int i= 0; i < 2; i++)
                s[i].pop();
        }
        return lowest;
    }
};
// @lc code=end

