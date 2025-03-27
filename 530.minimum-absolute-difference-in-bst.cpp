/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 */
 #include <cstdlib>
using namespace std;
  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
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
#include <climits>
class Solution {
public:
    int result = INT_MAX;
    TreeNode* prev = new TreeNode(INT_MAX);

    void traverse(TreeNode* root)
    {
        if (!root) return;
        traverse(root->left);

        result = min(result, abs(root->val - prev->val));
        prev = root;

        traverse(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        if (!root) return result;
        traverse(root);
        return result;
    }
};
// @lc code=end

