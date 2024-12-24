/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    void helper(vector<string>& result, TreeNode* node, string path)
    {
        if (!node) return;
        path += to_string(node->val);
        if (node->left || node->right)
        {
            path += "->";
        }
        else {
            result.push_back(path); 
            return;
        }
        helper(result, node->left, path);
        helper(result, node->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return;
        string path = "";
        helper(result, root, string);
        return result;
    }
};
// @lc code=end

