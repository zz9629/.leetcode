/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int partition(vector<int>& nums, int left, int right)
    {
        int pivot = nums[right];
        int i = left - 1;
        for (int j = left; j < right; j++)
        {
            if (nums[j] > pivot) swap(nums[++i], nums[j]);
        }
        swap(nums[i + 1], nums[right]);
        return i + 1;
    }

    int quickSort(vector<int>& nums, int left, int right)
    {
        int pos = rand() % (right - left + 1) + left;
        swap(nums[pos], nums[right]);
        return partition(nums, left, right);
    }

    void max_heap(vector<int>& nums, int start, int end)
    {
        if (start >= end) return;
        int node = start;
        int child = node * 2 + 1;
        while (child <= end)
        {
            if (child + 1 <= end && nums[child] < nums[child + 1]) child++;
            if (nums[node] <= nums[child]){
                swap(nums[node], nums[child]);
                node = child;
                child = child * 2 + 1;
            }
            else return;
        }
    }

    void max_heap_(vector<int>& nums, int node, int end)
    {
        if (node >= end) return;
        int child = node * 2 + 1;
        while (child <= end)
        {
            if (child <= end && nums[child + 1] > nums[child]) child++;
            if (nums[node] >= nums[child]) return;
            else
            {
                swap(nums[node], nums[child]);
                node = child;
                child = child * 2 + 1;
            }
        }
    }
    
    int findKthLargest_(vector<int>& nums, int k) {
        int start = 0, end = nums.size() - 1;
        for (int i = nums.size() / 2 - 1; i >= 0; i--) 
        {
            max_heap_(nums, i, end);
        }
        int i = end;
        int res = nums[0];
        while (k--)
        {
            res = nums[0];
            swap(nums[0], nums[i--]);
            max_heap_(nums, 0, i);
        }
        return res;
    }
    /* quick sort */
        // int left = 0, right = nums.size() - 1;
        // while (left < right)
        // {
        //     int mid = quickSort(nums, left, right);
        //     if (mid + 1 == k) return nums[mid];
        //     else if (mid + 1 < k) left = mid + 1;
        //     else right = mid - 1;
        // }
        // return nums[left];

    /* heap sort
        int start = 0, end = nums.size() - 1;
        for (int i = nums.size() / 2 - 1; i >= 0; i--)
        {
            max_heap(nums, i, end);
        }
        int i = nums.size() - 1;
        int res = nums[start];
        while (k--)
        {
            res = nums[0];
            swap(nums[0], nums[i--]);
            max_heap(nums, 0, i);
        }
        return res;
    */

    /* max heap using priority queue
    */
    // priority_queue<int> pq(nums.begin(), nums.end());
    // while (--k)
    // {
    //     pq.pop();
    // }
    // return pq.top();

    int findKthLargest(vector<int>& nums, int k) {
        
    }
};
// @lc code=end

