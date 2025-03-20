/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// youtube视频 
// https://www.youtube.com/watch?v=oobqoCJlHA0
 
// @lc code=start
#include <unordered_map>
class Node
{
public:
    std::unordered_map<char, Node*> childern;
    bool isEnd;
};

class Trie {
public:
    Trie() {
        this->root = new Node();
    }
    
    void insert(string word) {
        auto cur = this->root;
        for (auto & ch: word)
        {
            if (cur->childern.find(ch) == cur->childern.end())
            {
                cur->childern[ch] = new Node();
            }
            cur = cur->childern[ch];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        auto cur = this->root;
        for (auto & ch: word)
        {
            if (cur->childern.find(ch) == cur->childern.end())
            {
                return false;
            }
            cur = cur->childern[ch];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        auto cur = this->root;
        for (auto & ch: prefix)
        {
            if (cur->childern.find(ch) == cur->childern.end())
            {
                return false;
            }
            cur = cur->childern[ch];
        }
        return true;
    }

    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

