/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 */
 
/*

1. Two Sum 【了解 map[curSum - target] 的运用】
560. Subarray Sum Equals K 【了解数组的prefix sum】
再做437. Path Sum III【树的prefix sum】

图解：https://leetcode.com/problems/path-sum-iii/solutions/6517136/dfs-prefixsum-c 

*/

 #include "vector"
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
#include <unordered_map>
class Solution {
public:
    // 复杂度为n^2的递归
    // 用于计算连续加入节点的路径
    int helper(TreeNode* root, long long target)
    {
        if (!root) return 0;

        int count = root->val == target ? 1 : 0;
        count += helper(root->left, target - root->val);
        count += helper(root->right, target - root->val);
        return count;
    }

    int pathSum__(TreeNode* root, int targetSum) 
    {
        if (!root) return 0;
        return helper(root, targetSum) +  // 加入root节点
            pathSum__(root->left, targetSum) + // 不放root节点
            pathSum__(root->right, targetSum);
    }

    // 复杂度为n的prefix sum
    // 注意1. backtrace, 所以map是全局的用&，注意2.long long数据结构
    int helper_(TreeNode* root, long long curSum, int target, 
                std::unordered_map<long long, int>& map)
    {
        
        if (!root) return 0;
        // Update the current cumulative sum
        curSum += root->val;
        
        // Check if (currentSum - targetSum) exists in the prefix sum map
        int result = map[curSum - target];

        // Update the prefix sum map with the current cumulative sum
        map[curSum]++;
        
        // Recursively traverse the left and right subtrees
        result += helper_(root->left, curSum, target, map);
        result += helper_(root->right, curSum, target, map);
        
        // Backtrack: decrement the frequency of the current cumulative sum
        // 防止路径计算跨越不同的子树
        map[curSum]--;

        return result;
    }

    // prefix sum
    int pathSum_(TreeNode* root, int targetSum) 
    {
        std::unordered_map<long long, int> map;
        map[0] = 1;
        return helper_(root, 0, targetSum, map);
    }



    


    int pathSum(TreeNode* root, int targetSum) 
    {

    }

};
// @lc code=end

