/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
 */
#include <stack>
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
    // 返回尾节点
   TreeNode* helper(TreeNode* root, TreeNode* & tail)
    {
        if (!root) return nullptr;
        
        // 左子树
        TreeNode* tailTemp = nullptr;
        auto l = helper(root->left, tailTemp);
        root->left = nullptr;
        if (l) tailTemp->right = root;

        // 没有右子树的话，tail是root
        tail = root;         
        root->right = helper(root->right, tail);
        return l ? l : root;    
    }

    TreeNode* increasingBST_(TreeNode* root) {
        TreeNode* tail = nullptr;
        return helper(root, tail);
    }


    /*
    递归展开
    进入 increasingBST(5, NULL)

    递归左子树：increasingBST(3, 5)

    进入 increasingBST(3, 5)

    递归左子树：increasingBST(2, 3)

    进入 increasingBST(2, 3)

    递归左子树：increasingBST(1, 2)

    进入 increasingBST(1, 2)

    递归左子树：increasingBST(NULL, 1)，返回 1

    断开 1->left

    递归右子树：increasingBST(NULL, 2)，返回 2

    1->right = 2，返回 1（新的根）

    回到 increasingBST(2, 3)

    断开 2->left

    递归右子树：increasingBST(NULL, 3)，返回 3

    2->right = 3，返回 1

    回到 increasingBST(3, 5)

    断开 3->left

    递归右子树：increasingBST(4, 5)

    进入 increasingBST(4, 5)

    递归左子树：increasingBST(NULL, 4)

    断开 4->left

    递归右子树：increasingBST(NULL, 5)

    4->right = 5

    返回 1
    
    */
    /*
    The most important thing to notice is that when we traverse left, the root is passed in, but when we traverse right, the tail is passed in.
    In other words, traversing left passes in the current node to the next iteration, while traversing right passes in the current node's parent.
    */
    TreeNode* increasingBST__(TreeNode* root, TreeNode* tail = NULL) {
        // if this null node was a left child, tail is its parent
        // if this null node was a right child, tail is its parent's parent
        if (!root) return tail;

        // // 递归处理左子树，找到最小节点（新树的根）
        // recursive call, traversing left while passing in the current node as tail
        TreeNode* res = increasingBST__(root->left, root);
        
        //we don't want the current node to have a left child, only a single right child
        root->left = NULL;

        // # we set the current node's right child to be tail
        // # what is tail? this part is important
        // # if the current node is a left child, tail will be its parent
        // # else if the current node is a right child, tail will be its parent's parent
        root->right = increasingBST__(root->right, tail);
        
        // # throughout the whole algorithm, res is the leaf of the leftmost path in the original tree
        // # its the smallest node and thus will be the root of the modified tree
        return res;
    }

    
   
    TreeNode* increasingBST(TreeNode* root) {
    }

};
// @lc code=end

