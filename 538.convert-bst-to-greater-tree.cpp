/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
    // 按照rightChild, root, left child的顺序遍历即从大到小
    // 每访问一个node，就把值加入到base中
    // base 代表当前访问过的node->val总和
    // 同时修改这个node的val
    void helper(TreeNode* root, int& base)
    {
        if (!root) return;
        helper(root->right, base);
        base += root->val;
        root->val = base;
        helper(root->left, base);
    }

    TreeNode* convertBST(TreeNode* root) {
        if (!root) return 0;
        int base = 0;
        helper(root, base);
        return root;
    }
};
// @lc code=end

