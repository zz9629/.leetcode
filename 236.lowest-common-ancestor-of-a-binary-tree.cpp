/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

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
/*
Define a recursive function rec that takes three parameters: root (the current node), p (first node to find the lowest common ancestor for), and q (second node to find the lowest common ancestor for).

Check if the current node root is null or if it is either p or q. If any of these conditions is true, return the current node root as the lowest common ancestor.

Recursively call the rec function for the left subtree of the current node and assign the result to a variable l.

Recursively call the rec function for the right subtree of the current node and assign the result to a variable r.

Check if both l and r are not null. If so, it means that p and q are found on different subtrees of the current node, and the current node root is their lowest common ancestor. Return the current node root.

If l is null, it means that both p and q are on the right subtree (or not present in the tree). Return r.

If none of the above conditions are met, it means that both p and q are on the left subtree (or not present in the tree). Return l.

Define a function lowestCommonAncestor that takes three parameters: root (the root node of the tree), p (first node to find the lowest common ancestor for), and q (second node to find the lowest common ancestor for).

Return the result of calling the rec function with the parameters root, p, and q. This will find and return the lowest common ancestor of nodes p and q in the given binary tree.
    
*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) 
        {
            return root;
        }
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) return root; 
        //  代表左右子树都找到一个target

        return left ? left : right;
        // target都在左边/都在右边/不存在
    } 
};
// @lc code=end

