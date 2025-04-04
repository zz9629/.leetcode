/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
    TreeNode* trimBST_(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        if (root->val < low) 
        {
            // root->left = nullptr;
            return trimBST(root->right, low, high);
        }
        else if (root->val > high)
        {
            // root->right = nullptr;
            return trimBST(root->left, low, high);
        }  
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }



    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
    }

};
// @lc code=end

