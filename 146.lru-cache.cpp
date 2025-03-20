/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <cstddef>
#include <deque>
#include <unordered_map>
class LRUCache {
public:
    struct Node
    {
        int key, value;
        Node* pre, *next;
        Node (int key, int value) : key(key), value(value), pre(nullptr), next(nullptr){
        }
    };

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        auto it = data.find(key);
        if (it == data.end()) return -1;

        // update list;
        Node* node = data[key];
        removeNode(node);
        addFirst(node);

        return node->value;
    }
    
    void put(int key, int value) {
        // in map, find it, re-arrange
        auto it = data.find(key);
        if (it == data.end()) 
        {
            if (data.size() >= this->capacity)
            {
                auto tailNode = this->tail->pre;
                removeNode(tailNode);
                data.erase(tailNode->key);
                delete tailNode; // 内存泄漏
            }
            Node* node = new Node(key, value);
            addFirst(node);
            data[key] = node; // 更新
        }
        else 
        {
            Node* node = data[key];
            node->value = value; // 更新
            removeNode(node);
            addFirst(node);
        }
    }

private:    
    // ！这里不要删除这个节点，只是更改链接关系 
    // 移除的可能是中间节点
    void removeNode(Node* & node)
    {
        auto pre = node->pre;
        auto next = node->next;

        pre->next = next;
        next->pre = pre;

        // tail->pre = tail->pre->pre;
        // tail->pre->pre->next = tail;
        // delete node; // do not delete
    }

    void addFirst(Node*& node)
    {
        // empty
        if (head->next == tail)
        {
            head->next = node;
            node->pre = head;
            
            node->next = tail;
            tail->pre = node;
        }
        else 
        {
            auto first = this->head->next;
            first->pre = node;
            node->next = first;
    
            head->next = node;
            node->pre = head;
        }
    }

    int capacity;
    std::unordered_map<int, Node*> data;
    Node* head, *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

