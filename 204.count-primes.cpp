/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */
#include "vector"
#include "iostream"
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPrime(int num)
    {   
        if (num < 2) return false;
        if (num == 2) return true;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0) return false;
        }
        return true;
    }

    // time limited exceeded: test case 5000000
    int countPrimes_(int n) {
        if (n <= 1) return 0;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            if (isPrime(i)) dp[i] += 1;
        }
        return dp[n - 1];
    }

    int countPrimes__(int n) {
        if (n <= 2) return 0; // 注意输入值处理
        vector<bool> prime(n, true);
        int count = n - 2;

        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                for (int j = 2 * i; j < n; j += i)
                {
                    if (prime[j])
                    {
                        prime[j] = false;
                        count--;
                    }
                }
            }
        }

        return count;
    }

    int countPrimes(int n) {

    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.countPrimes(10);
    return 0;
}