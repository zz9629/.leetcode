/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
#include <cstdlib>
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    bool isBalanced_(TreeNode* root) {
        if (!root) return true;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        if (abs(leftDepth - rightDepth) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int helper(TreeNode* root)
    {
        if (!root) return 0;
        int leftDepth = helper(root->left); // 或者在这里判断leftDepth然后剪枝？
        int rightDepth = helper(root->right);
        if (leftDepth == -1 || rightDepth == -1) return -1; 
        if (abs(leftDepth - rightDepth) > 1) return -1;
        return 1 + max(leftDepth, rightDepth);
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return helper(root) != -1;
    }

};
// @lc code=end

