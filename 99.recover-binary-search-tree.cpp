/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */
 #include <climits>
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

/*
    如果有一个inorder的树，打印出来是6, 3, 4, 5, 2
    那么6就是我们要找的firstEle，2是要找的secondEle
*/

class Solution {
public:
    TreeNode* prev = new TreeNode(INT_MIN);
    TreeNode* firstEle = nullptr;
    TreeNode* secondEle = nullptr;

    void traverse(TreeNode* root)
    {
        if (!root) return;

        traverse(root->left);

        // start
        if (root->val < prev->val)
        {
            // If first element has not been found, assign it to prevElement (refer to 6 in the example above)
            if (!firstEle) 
            {
                firstEle = prev;
            }
            // If first element is found, assign the second element to the root (refer to 2 in the example above)
            if (firstEle)
            {
                secondEle = root;
            }
        }
        prev = root; // 更新prev
        // end

        traverse(root->right);
    }

    void recoverTree(TreeNode* root) {
        traverse(root);
        int temp = firstEle->val;
        firstEle->val = secondEle->val;
        secondEle->val = temp;
    }
};
// @lc code=end

