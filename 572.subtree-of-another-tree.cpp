/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */
 #include <queue>
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
    bool isSame(TreeNode* root, TreeNode* subRoot)
    {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        if (root->val != subRoot->val) return false;
        return isSame(root->left, subRoot->left) && 
               isSame(root->right, subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot) return false;
        if (isSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        // stack<TreeNode*> nodes;
        // nodes.push(root);
        // bool found = true;
        // while (!found && !nodes.empty())
        // {
        //     int count = nodes.size();
        //     while (count--)
        //     {
        //         auto topNode = nodes.top();
        //         nodes.pop();
        //         if (topNode->val == subRoot->val) 
        //         {
        //             found = isSame(topNode, subRoot);
        //         }
        //         if (found) return true;
        //         if (topNode->left) nodes.push(topNode->left);
        //         if (topNode->right) nodes.push(topNode->right);
        //     }
        // }
        // return false;
    }
};
// @lc code=end

