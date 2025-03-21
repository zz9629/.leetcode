/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    // bad solution, 两次递归，耗时
    int diameterOfBinaryTree(TreeNode* root) {
        int temp = maxDepth(root->left) + maxDepth(root->right);
        return max(temp, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }

    // diameter作为全局变量
    int helper(TreeNode* root, int& diameter)
    {
        if(!root) return 0;
        int l = helper(root->left, diameter);
        int r = helper(root->right, diameter);
        diameter = max(diameter, l + r);
        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }
};
// @lc code=end

