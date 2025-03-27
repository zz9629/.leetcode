/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 */
 #include <cstddef>
 #include <unordered_map>
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
    std::unordered_map<int, int> map;

    TreeNode* helper(vector<int>& preorder, int left, int right, int postStart, int postEnd)
    {
        if (left > right) return nullptr;
        int pivot = preorder[left];
        TreeNode* root = new TreeNode(pivot);

        if (left == right) return root;

        int childIndex = map[preorder[left + 1]];
        int childGap = childIndex - postStart;

        root->left = helper(preorder, left + 1, left + 1 + childGap, postStart, childIndex);
        if (childIndex == postEnd - 1) 
        {
            // only child
            return root;
        }
        root->right = helper(preorder, left + childGap + 2, right, childIndex + 1, postEnd - 1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++)
        {
            map[postorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
    }
};
// @lc code=end

