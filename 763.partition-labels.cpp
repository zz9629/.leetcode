/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
#include "map"
#include <unordered_map>
#include <utility>
#include "string"
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int getFirst(std::string& s, char c)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == c) return i;
        }
        return -1;
    }

    int getLast(std::string& s, char c)
    {
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == c) return i;
        }
        return -1;
    }

    void getAppear(std::string& s, std::map<char, vector<int> >& appear)
    {
        for (const char& c : s)
        {
            int first = getFirst(s, c);
            int last = getLast(s, c);
            appear[c] = vector<int>{};
            appear[c].push_back(first);
            appear[c].push_back(last);
        }
    }

    vector<int> partitionLabels_(string s) {
        vector<int> result;
        int len = s.length();
        std::map<char, vector<int> > appear;
        getAppear(s, appear);
        int pos = 0;
        vector<char> tempStr;
        while (pos < len)
        {
            char startChar = s[pos];
            tempStr.push_back(startChar);
            int end = appear[startChar][1];
            for (int i = pos + 1; i <= end; i++)
            {
                char c = s[i];
                int last = appear[c][1];
                if (last > end){
                    end = last;
                }
                tempStr.push_back(c);
            }
            result.push_back(tempStr.size());
            tempStr.clear();
            pos = end + 1;
        }

        return result;
    }

    vector<int> partitionLabels__(string s) {
        vector<int> result;
        int len = s.length();
        map<char, int> lastIndex;
        for (int i = 0; i < len; i++)
        {
            lastIndex[s[i]] = i;
        }

        int end = 0;
        int start = -1;
        for (int i = 0; i < len; i++)
        {
            char c = s[i];
            end = max(end, lastIndex[c]);
            if (i == end)
            {
                result.push_back(end - start);
                start = end;
            }
   
        }

        return result;
    }

    vector<int> partitionLabel_s(string s) {
        vector<int> result;
        unordered_map<char, int> lastPos;
        for (int i = 0; i < s.size(); i++)
        {
            lastPos[s[i]] = i;
        }

        int end = 0, start = -1;
        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, lastPos[s[i]]);
            if (end == i) {
                result.push_back(end - start);
                start = end;
            }
        }
        return result;
    }

    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastPos;
        for (int i = 0; i < s.size(); i++)
        {
            lastPos[s[i]] = i;
        }

        vector<int> result;
        int start = -1, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, lastPos[s[i]]);
            if (i == end) {
                result.push_back(end - start);
                start = end;
            }
        }
        return result;
    }
};
// @lc code=end

int main(){
    Solution s;
    string str = "ababcbacadefegdehijhklij";
    auto result = s.partitionLabels(str);
    for (int idx = 0; idx < result.size() - 1; idx++ )
	{
		std::cout << result[idx] << " ";
	}    

    return 0;
}