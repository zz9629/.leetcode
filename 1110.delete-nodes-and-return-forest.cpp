/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
 */
#include "vector"
#include <cstddef>
#include <unordered_set>

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
    // 返回值forest记得用引用&
    TreeNode* helper_(TreeNode* root, std::unordered_set<int> & dict, vector<TreeNode*>& forest)
    {
       if (!root) return nullptr;
       // 这里返回值要给root->left，否则不会删除节点
       // auto & left = root->left; 可以用一个引用类型，不用写那么多root->left了
       root->left = helper(root->left, dict, forest);
       root->right = helper(root->right, dict, forest);
       if (dict.count(root->val))
       {
            if (root->left) forest.push_back(root->left);
            if (root->right) forest.push_back(root->right);
            delete root;
            return nullptr;
       }
       return root;
    }

    vector<TreeNode*> delNodes_(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> dict(to_delete.begin(), to_delete.end());
        // 这里返回值必须给root，否则不会删除节点
        root = helper(root, dict, forest);
        if (root) 
        {
            forest.push_back(root);
        }
        return forest;
    }

    TreeNode* helper(TreeNode* root, unordered_set<int>& dict, vector<TreeNode*>& forest)
    {
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        
        return forest;
    }

};
// @lc code=end

