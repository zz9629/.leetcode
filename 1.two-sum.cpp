/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <unordered_map>
#include <vector>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>

using namespace std;

#include <map>
template<typename K, typename V>
class interval_map {
	//friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{
        m_map.insert(m_map.begin(), std::make_pair(std::numeric_limits<K>::lowest(), val));
    }

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        if (!( keyBegin < keyEnd ))
        {
            return;
        }
        // 先找到keyBegin和keyEnd的位置
        std::pair<K,V> beginExtra;
        std::pair<K,V> endExtra;
        bool beginHasExtra = false;
        bool endHasExtra = false;

        typename std::map<K,V>::iterator itBegin;
        itBegin = m_map.lower_bound(keyBegin);
        if ( itBegin!=m_map.end() && keyBegin < itBegin->first ) {
            if (itBegin != m_map.begin()) {
                beginHasExtra = true;
                --itBegin;
                beginExtra = std::make_pair(itBegin->first, itBegin->second);
            }
            
        }

        typename std::map<K,V>::iterator itEnd;
        itEnd = m_map.lower_bound(keyEnd);
        if ( itEnd!=m_map.end() && keyEnd < itEnd->first ) {
            endHasExtra = true;
            typename std::map<K,V>::iterator extraIt = itEnd;
            --extraIt;
            endExtra = std::make_pair(keyEnd, extraIt->second);
        }
        
        itBegin = m_map.erase(itBegin, itEnd);
        if (beginHasExtra)
            itBegin = m_map.insert(itBegin, beginExtra);
        if (endHasExtra)
            m_map.insert(itBegin, endExtra);
        if (itBegin != itEnd) {
            m_map.erase(itBegin, itEnd);
        }
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}

    void print() {
		for (auto&&[key, val] : m_map)
			std::cout << "[" << key << ':' << val << "]";
		std::cout << '\n';
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;

        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             res.push_back(i);
        //             res.push_back(j);
        //             return res;
        //         }
        //     }
        // }
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(target - nums[i]) != map.end())
            {
                return {i, map[target - nums[i]]};
            }
            map[nums[i]] = i;
        }

        return res;
    }
};
// @lc code=end

int main(){
    interval_map<int,char> map('a');
	map.print(); // [-2147483648:a]

    map.assign(1, 6, 'A');
    map.print();

    map.assign(2, 4, 'B');
    map.print();

    return 0;
}

