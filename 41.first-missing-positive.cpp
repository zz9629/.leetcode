/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */


/*
    nums.append(0)
    n = len(nums)
    for i in range(len(nums)): #delete those useless elements
        if nums[i]<0 or nums[i]>=n:
            nums[i]=0
    for i in range(len(nums)): #use the index as the hash to record the frequency of each number
        nums[nums[i]%n]+=n
    for i in range(1,len(nums)):
        if nums[i]/n==0:
            return i
    return n
*/
#include <vector>
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
    public:
        int firstMissingPositive_(vector<int> &nums) {
            nums.push_back(0);
            // to increase size by 1
            int n = nums.size();
            
            // remove unnecessary elements
            for (int i = 0; i < n; i++) {
                if (nums[i] < 0 or nums[i] >= n) {
                    nums[i] = 0;
                }
            }
    
            // store frequency of numbers in array
            // so, nums[0]=x; and x/n==freqency of 0
            // similarly, (nums[1])/n = freq of 1
            
            for (int i = 0; i < n; i++) {
                nums[nums[i] % n] += n;
                // 重置当前数字，保证后续计算不被干扰。
                if (nums[i] < n) {
                    nums[i] = 0;
                }
            }
    
            // if freqency of number is 0 means it is not present thus, print it. This will be our smallest missing number
            for (int i = 1; i < n; i++) {
                if (nums[i] == 0) {
                    return i;
                }
            }
            // else answer is n (same as nums.size()+1 as we added one 0 earlier in code)
            return n;
        }

        int firstMissingPositive(vector<int> &nums) {
            
            return 0;
        }

    };
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums = {7,8,9,11,12};
    // vector<int> nums = {1,2,0};
    // vector<int> nums = {3, 4, -1, 1};
    cout << s.firstMissingPositive(nums) << endl;
}