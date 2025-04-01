/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */
 #include <cstddef>
#include <unordered_map>
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
    unordered_map<int, int> map;

    // preorder的start 和end， 以及inorder的start
    // 和通过len找，没什么区别
    TreeNode* helper_(vector<int>& preorder, int preStart, int preEnd, int inStart) {
        if (preStart > preEnd) return nullptr;
        // if (len <= 0 || len > preorder.size()) return nullptr;
        if (preStart < 0 || preStart >= preorder.size() || inStart < 0 || inStart >= preorder.size()) 
        {
            return nullptr;
        }

        auto rootVal = preorder[preStart];
        auto rootNode = new TreeNode(rootVal);
        int rootIndex = map[rootVal];
        // 这里需要优化，每次都需要遍历很浪费时间
        // for (int i = inStart; i < inStart + len; i++)
        // {
        //     if (inorder[i] == rootVal)
        //     {
        //         rootIndex = i;
        //         break;
        //     }
        // }
        if (rootIndex != -1)
        {
            int lenLeft = rootIndex - inStart;
            // int lenRight = len - lenLeft - 1;
            // rootNode->left = helper_(preorder, preStart + 1, inStart, lenLeft);
            rootNode->left = helper_(preorder, preStart + 1, preStart + lenLeft, inStart);
            // rootNode->right = helper_(preorder, preStart + lenLeft + 1, rootIndex + 1, lenRight);
            rootNode->right = helper_(preorder, preStart + lenLeft + 1, preEnd, rootIndex + 1);
        }
        return rootNode;
    }

    TreeNode* buildTree_(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < preorder.size(); i++)
        {
            map[inorder[i]] = i;
        }

        int preStart = 0, inStart = 0;
        int len = preorder.size();
        return helper_(preorder, preStart, preorder.size() - 1, inStart);
    }



    TreeNode* helper(vector<int>& preorder, int startPre, int endPre, int startIn, int endIn)
    {
        if (startPre > endPre) return nullptr;
        int pivot = preorder[startPre];
        auto root = new TreeNode(pivot);
        auto index = map[pivot];
        int len = index - startIn;
        root->left = helper(preorder, startPre + 1, startPre + len, startIn, index - 1);
        root->right = helper(preorder, startPre + len + 1, endPre, index + 1, endIn);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    }
};
// @lc code=end

int main()
{
    vector<int> pre = {3,9,20,15,7};
    vector<int> in = {9,3,15,20,7};
    Solution s;
    auto root = s.buildTree(pre, in);

    return 0;
}
