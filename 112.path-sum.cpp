/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
        bool helper(TreeNode* root, int curSum, int target, bool isRoot = false)
        {
            if (!root) return false;
    
            curSum += root->val;
    
            // If root is a leaf node (i.e., it has no left or right children)
            if (!root->left && !root->right) 
            {
                return curSum == target;
            }
    
            return helper(root->left, curSum, target) || 
                   helper(root->right, curSum, target);
        }
    
        bool hasPathSum(TreeNode* root, int targetSum) {
            if (!root) return false;
            return helper(root, 0, targetSum);
        }
    };
// @lc code=end

