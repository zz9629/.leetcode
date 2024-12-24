/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */
#include "vector"
#include <cstdlib>
using  namespace std;
// @lc code=start
class Solution {
public:
    void swap(int& a, int&b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // bubble sort
    void bubbleSort(vector<int>& nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = 0; j < nums.size() - i - 1; j++)
            {
                if (nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
            }
        }
    }

    // merge sort
    void mergeSort(int left, int right, vector<int>& nums, vector<int>& temp)
    {
        if (left >= right) return; 
        int mid = left + (right - left) / 2;
        mergeSort(left, mid, nums, temp);
        mergeSort(mid + 1, right, nums, temp);
        int l = left, r = mid + 1;
        int pos = left;
        while (l <= mid && r <= right)
        {
            if (nums[l] <= nums[r]) temp[pos++] = nums[l++];
            else temp[pos++] = nums[r++];
        }
        while (l <= mid) temp[pos++] = nums[l++];
        while (r <= right) temp[pos++] = nums[r++];
        for (int i = left; i <= right; i++) nums[i] = temp[i];
    }

    void quickSort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int pos = r_partition(nums, left, right);
        quickSort(nums, left, pos - 1);
        quickSort(nums, pos + 1, right);
    }
    
    void mergeSort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        vector<int> temp(right - left + 1, 0);
        int count = 0, i = left, j = mid + 1;
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j]) temp[count++] = nums[i++];
            else temp[count++] = nums[j++];
        }
        while (i <= mid) temp[count++] = nums[i++];
        while (j <= right) temp[count++] = nums[j++];
        for (int idx = 0; idx < temp.size(); idx++) nums[left + idx] = temp[idx];
    }


    int r_partition(vector<int>& nums, int left, int right)
    {
        int pos = rand() % (right - left + 1) + left;
        swap(nums[pos], nums[right]);
        // return partition(nums, left, right);
        int target = nums[right];
        int j = left - 1;
        for (int i = left; i < right; i++)
        {
            if (nums[i] < target) 
            {
                j++;
                swap(nums[j], nums[i]);
            }
        }
        j++; 
        swap(nums[j], nums[right]);
        return j;
    }

    void quickSort_(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int pos = r_partition(nums, left, right);
        quickSort_(nums, left, pos - 1);
        quickSort_(nums, pos + 1, right);
    }

    void maxHeap(vector<int>& nums, int node, int end)
    {
        if (node >= end) return;
        int child = node * 2 + 1;
        while (child <= end)
        {
            if (child + 1 <= end && nums[child] < nums[child + 1]) child++;
            if (nums[node] > nums[child]) return;
            else
            {
                swap(nums[node], nums[child]);
                node = child;
                child = node * 2 + 1;
            };
        }
    }

    void heapSort(vector<int>& nums)
    {
        int len = nums.size();
        for (int node = len / 2 - 1; node >= 0; node--) 
        {
            maxHeap(nums, node, len - 1);
        }

        for (int i = len - 1; i >= 0; i--)
        {
            swap(nums[0], nums[i]);
            maxHeap(nums, 0, i - 1);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        // bubbleSort(nums);
        // vector<int> temp(nums.size(), 0);
        // mergeSort(0, nums.size() - 1, nums, temp);
        // mergeSort(nums, 0, nums.size() - 1);
        // quickSort(nums, 0, nums.size() - 1);

        heapSort(nums);

        return nums;
    }
};
// @lc code=end

int main()
{
    vector<int> nums{5,1,1,2,0,0};
    Solution s;
    auto res = s.sortArray(nums);
}
