/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */
#include <stack>
#include <vector>
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
*     TreeNode *left;  AQAQsw   请问首尾4我
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    // https://www.youtube.com/watch?v=g_S5WuasWUE
    vector<int> inorderTraversal_(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> nodes;
        auto cur = root;
        while (cur || !nodes.empty())
        {
            while (cur)
            {
                nodes.push(cur);
                cur = cur->left;
            }
            cur = nodes.top();
            result.push_back(cur->val);
            nodes.pop();
            cur = cur->right;
        }

        return result;
    }


    vector<int> inorderTraversal(TreeNode* root) {
        // Iterative

    }
};
// @lc code=end

