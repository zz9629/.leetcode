/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 */
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

    TreeNode* findMin_(TreeNode* root)
    {
        if (!root) return nullptr;
        auto cur = root;
        while (cur && cur->left)
        {
            cur = cur->left;
        }
        return cur;
    }

    TreeNode* deleteNode_(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (root->left && root->right)
        {
            auto temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, root->val);
        }
        else
        {
            auto temp = root;
            root = root->left ? root->left : root->right;
            delete temp;
        }

        return root;

    }


    TreeNode* deleteNode(TreeNode* root, int key) {
     
    }

};
// @lc code=end

