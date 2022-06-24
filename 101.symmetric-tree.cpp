/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
class Solution {
    bool Mirror(TreeNode* t1, TreeNode* t2){
        if(not t1 and not t2)
            return true;
        if(not t1 or not t2)
            return false;
        
        return (
            t1->val == t2->val and 
            Mirror(t1->left, t2->right) and 
            Mirror(t1->right, t2->left)
        );
    }
public:
    bool isSymmetric(TreeNode* root) {
        return Mirror(root, root);
    }
};
// @lc code=end

