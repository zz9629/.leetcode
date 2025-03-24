/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 */

#include <queue>
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
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        std::queue<TreeNode*> levels;
        vector<double> result;
        if (root)
        {
            levels.push(root);
        }
        while (!levels.empty())
        {
            int count = levels.size();
            double sum = 0;
            for (int i = 0; i < count; i++)
            {
                auto topRoot = levels.front();
                sum += topRoot->val;
                levels.pop();
                if (topRoot->left) levels.push(topRoot->left);
                if (topRoot->right) levels.push(topRoot->right);
            }
            result.push_back(sum / count);
        }
        return result;
    }
};
// @lc code=end

