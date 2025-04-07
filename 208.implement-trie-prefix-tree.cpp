/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// youtube视频 
// https://www.youtube.com/watch?v=oobqoCJlHA0
 
#include <memory>
#include <unordered_map>
using namespace std;
// @lc code=start
class Node
{
public:
    std::unordered_map<char, unique_ptr<Node> > childern;
    bool isEnd;
};

class Trie {
public:
    Trie() {
        root = make_unique<Node>();
    }
    
    void insert(string word) {
        auto cur = root.get();
        for (auto & ch: word)
        {
            if (cur->childern.find(ch) == cur->childern.end())
            {
                cur->childern[ch] = make_unique<Node>();
            }
            cur = cur->childern[ch].get();
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        auto cur = this->root.get();
        for (auto & ch: word)
        {
            if (cur->childern.find(ch) == cur->childern.end())
            {
                return false;
            }
            cur = cur->childern[ch].get();
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        auto cur = this->root.get();
        for (auto & ch: prefix)
        {
            if (cur->childern.find(ch) == cur->childern.end())
            {
                return false;
            }
            cur = cur->childern[ch].get();
        }
        return true;
    }

    std::unique_ptr<Node> root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

