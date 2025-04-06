/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 */

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
#include <unordered_map>
class Solution {
public:
    std::unordered_map<long long, bool> map;
    
    // 递归调用所以很慢
    bool findTarget_recursive(TreeNode* root, int k) {
        if(!root) return false;
        if (map.count(k - root->val))
        {
            return true;
        }
        map[root->val] = true;
        return findTarget(root->left, k) || findTarget(root->right, k);
    }

    // 中序遍历 + 双指针法
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> nodes;
        auto cur = root;
        while (cur || !nodes.empty())
        {
            while (cur)
            {
                nodes.push(cur);
                cur = cur->left;
            }
            cur = nodes.top();
            result.push_back(cur->val);
            nodes.pop();
            cur = cur->right;
        }

        return result;
    }

    bool findTarget(TreeNode* root, int k) {
        auto vec = inorderTraversal(root);
        int left = 0, right = vec.size() - 1;
        while(left < right)
        {
            int sum = vec[left] + vec[right];
            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }
        return false;
     }
};
// @lc code=end

