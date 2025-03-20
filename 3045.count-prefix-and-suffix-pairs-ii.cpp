/*
 * @lc app=leetcode id=3045 lang=cpp
 *
 * [3045] Count Prefix and Suffix Pairs II
 */
#include "vector"
#include "unordered_map"
#include <string> 
#include "memory"
#include "iostream"

using namespace std;
// @lc code=start

class TrieNode{     
public:
    ~TrieNode() = default;   
    unordered_map<int, unique_ptr<TrieNode>> child;
    int ctr = 0;    // 标记是否结束，等效于bool isEnd。单词可能重复，所以这里是计数。
};

class Node
{
public:
    unordered_map<int, unique_ptr<Node>> children;
    int count;
};

class Solution {
public:
    long long countPrefixSuffixPairs_(vector<string>& words) {
        unique_ptr<TrieNode> root = make_unique<TrieNode>();
        long res = 0;
        // 每一个词
        for(string& str: words){
            TrieNode* node = root.get(); // 注意get()取地址
            // word中的每一个字母
            for(int i = 0; i < str.size(); i++){
                // 双指针
                int key = (str[i]-'a') * 26 + (str[str.size()-1-i] - 'a');
                node = node->child.insert({key, make_unique<TrieNode>()}).first->second.get();
                /* Equals
                    if (cur->children.find(key) == cur->children.end())
                    {
                        cur->children[key] = new Node();
                    }
                    cur = cur->children[key];
                */
                res += node->ctr;   // 前面有相同prefix/suffix的词
            }
            node->ctr++; 
            // 不能是node->ctr = 1, 因为可能有重复的词，words =["b","a","b","a","b"]， Expected :4
        }
        return res;
    }

    long long countPrefixSuffixPairs(vector<string>& words) {
        long long result = 0;
        unique_ptr<Node> root = make_unique<Node>();

        for (auto & word: words)
        {
            auto cur = root.get();
            for (int i = 0; i < word.length(); i++)
            {
                int key = (word[i] - 'a') * 26 + word[word.length() - 1 - i] - 'a';
                if (cur->children.find(key) == cur->children.end())
                {
                    cur->children[key] = make_unique<Node>();
                }
                cur = cur->children[key].get();
                result += cur->count;
            }

            cur->count++;
        }

        return result;
    }
};
// @lc code=end

int main()
{
    vector<string> words = {"a","aba","ababa","aa", "a"};
    Solution s;
    cout << s.countPrefixSuffixPairs(words) << endl;
    return 0;
}