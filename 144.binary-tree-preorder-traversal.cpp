/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
*/
#include <vector>
#include <stack>
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
    void helper(TreeNode* root, vector<int>& result)
    {
        if (!root)
        {
            return;
        }
        result.push_back(root->val);
        if (root->left) 
        {
            helper(root->left, result);
        }
        if (root->right) 
        {
            helper(root->right, result);
        }
    }

    vector<int> preorderTraversal_recursive(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }


    vector<int> preorderTraversal_(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodes;
        if (root) nodes.push(root);
        while (!nodes.empty())
        {
            auto topNode = nodes.top();
            nodes.pop();
            result.push_back(topNode->val);
            if (topNode->right) nodes.push(topNode->right);
            if (topNode->left) nodes.push(topNode->left);
        }
        return result;
    }



    

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
       
        return res;
    }


};
// @lc code=end

