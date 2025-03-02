/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */
#include <numeric>
#include <string>
#include "vector"
#include "algorithm"
#include "stack"
#include "iostream"

using namespace std;

// @lc code=start
class Solution {
public:
    bool isDigit(char c)
    {
        return (c >= '0' && c <= '9');
    }

    // 用vec实现更简洁，不需要每次都把lastNumber出栈算完再放进去。
    // 返回的时候还可以直接调用accumulate
    int calculate_vec(string s) {
        s += '+';
        int result = 0;
        char sign = '+';
        long long currentNum = 0;
        vector<int> plate;
        for (int i = 0; i < s.length(); i++)
        {   
            if (s[i] == ' ') continue;
            if (isDigit(s[i])) currentNum = currentNum * 10 + s[i] - '0';
            else {
                if (sign == '+') plate.push_back(currentNum);
                else if (sign == '-') plate.push_back(-currentNum);
                else if (sign == '*') plate.back() = plate.back() * currentNum;
                else if (sign == '/') plate.back() = plate.back() / currentNum;
                sign = s[i];
                currentNum = 0;
            }
        }        
        return accumulate(plate.begin(), plate.end(), 0);
    }

    /*  
        s += "++"; // 确保所有数据都加上
        或者返回 result += lastNumber;

        对于"22-3*5+-"
        指针指向+时，lastNumber = 22, curNumber = 15; result += lastNumber = 22
        指针指向-时，result 才会加15
    */
    int calculate_nonStack(string s) {
        s += '+';
        char sign = '+';
        long long currentNumber = 0, lastNumber = 0, result = 0;
        for (int i = 0; i < s.length(); i++)
        {   
            if (s[i] == ' ') continue;
            if (isDigit(s[i])) currentNumber = currentNumber * 10 + s[i] - '0';
            // 这里有个else 
            else {
                if (sign == '+' || sign == '-') {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                } else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                // 这两行在else里面
                sign = s[i];
                currentNumber = 0;
            }
        }        
        return result += lastNumber;
    }

    void update(vector<int>& values, int num, char sign)
    {
        if (sign == '+') values.push_back(num);
        else if (sign == '-') values.push_back(-num);
        else if (sign == '*') values.back() *= num;
        else if (sign == '/') values.back() /= num;
    }
    
    int calculate(string s) {
        int result = 0;
        char sign = '+';
        long long currentNum = 0;
        vector<int> plate;
        for (int i = 0; i < s.length(); i++)
        {   
            if (s[i] == ' ') continue;
            if (isDigit(s[i])) currentNum = currentNum * 10 + s[i] - '0';
            else {
                update(plate, currentNum, sign);
                sign = s[i];
                currentNum = 0;
            }
        }        
        update(plate, currentNum, sign);
        return accumulate(plate.begin(), plate.end(), 0);
    }

};
// @lc code=end

int main()
{
    Solution s;
    cout << s.calculate("22-3*5+-") << endl;
 

    return 0;
    
}