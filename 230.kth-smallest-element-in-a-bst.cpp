/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int track;
    int inorder(TreeNode* root){
        if(root == nullptr)
            return -1;

        int left = inorder(root->left);
        if(left != -1)
            return left;
        if(track == 1)
            return root->val;
        track--;
        int right = inorder(root->right);
        if(right != -1)
            return right;
        return -1;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        track = k;
        return inorder(root);
    }
};
// @lc code=end

