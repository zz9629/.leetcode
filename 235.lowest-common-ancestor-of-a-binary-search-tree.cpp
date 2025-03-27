/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // recursive
    TreeNode* lowestCommonAncestor_(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!p || !q || !root) return nullptr;
        if (p->val > q->val) return lowestCommonAncestor_(root, q, p);
        if (root == p || root == q) return root;  
        if (p->val < root->val && root->val < q->val) return root;
        if (root->val < p->val) return lowestCommonAncestor_(root->right, p, q);
        if (root->val > q->val) return lowestCommonAncestor_(root->left, p, q);
        return nullptr;
    }

    // iteratetive
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = min(p->val, q->val);
        int large = max(p->val, q->val);
        while (root)
        {
            if (root->val < small) root = root->right;
            else if (root->val > large) root = root->left;
            else return root; 
            // if (root->val == small || root->val == big) return root; 包括在else内了
        }
        return nullptr;
    }

};
// @lc code=end

