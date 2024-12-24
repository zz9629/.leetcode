/*
 * Class Solution contains 7 methods addressing 4 questions in assignment.
 * 
 * [I] Search Methods:
 *  - binarySearch(int[] a, int x)
 *      Performs a binary search on a sorted array 'a' to find 'x'.
 *      Returns the index of 'x' if found, otherwise returns -1. 
 *      Complexity: O(logN).

 *  - sortAndSearch(int[] a, int x)
 *      Sorts array 'a' using quicksort, then performs a binary search to find 'x'.
 *      Complexity: Sorting - O(NlogN), Searching - O(logN).
 *
 * [II] normalizeRMS()
 *    Applies Root Mean Square (RMS) normalization to an array of data.
 *    Complexity: O(N)
 *
 * [III] Convolution Methods
 *  - convolution(float[] a, float[] b)
 *      Performs the convolution of two arrays 'a' and 'b' with different lengths.
 *      Commonly used for discrete data in Linear Time Invariant systems. 
 *      Complexity: O(N^2).
 *
 *  - fftConvolution(float[] a, float[] b)
 *      Utilizes the Fast Fourier Transform (FFT) to perform convolution,
 *      significantly improving performance for large datasets. Requires FFTW library. 
 *      Complexity: O(NlogN).
 *    [Prerequisite]: Install and link the FFTW library.
 * 
 * [IV] smoothing(float[] data, int w):
 *  - smoothing(float[] data):
 *      Applies a basic smoothing algorithm to the 'data' array. Typically used to reduce noise and improve signal quality.
 *      Complexity: O(MN), where M is the window size
 *
 *  - improvedSmoothing(float[] data):
 *      Enhances the basic smoothing method by applying convolution method above.
 *      Complexity: O(NlogN)
 * 
 */

#include <algorithm>
#include <cmath>
#include <complex>
#include <cstddef>
#include <fftw3.h>
#include <iostream>
#include <ratio>
#include <vector>

#define tolerance 1e-10

using namespace std;

class Solution {

public:
    // binary search to find target value.
    int binarySearch(const vector<int>& nums, int target)
    {
        long int left = 0, right = nums.size() - 1;

        int first = -1;
        int last = -1;

        while (left <= right)
        {
            long int mid = left + (right - left) / 2;
            if (nums[mid] == target) 
            {
                first = last = mid;
                break;
            }
            // assuming this array is sorted ascendingly.
            else if (nums[mid] < target) 
            {
                left = mid + 1;
            }
            else 
            {
                right = mid - 1;
            }
        }
        if (first == -1) 
        {
            // target is not in this array 
        }
        
        // search first in range(left, mid);
        int new_right = first;
        while (left <= new_right)
        {
            long int mid = left + (new_right - left) / 2;
            if (nums[mid] == target) 
            {
                first = mid; // update here
            }
            else if (nums[mid] < target) left = mid + 1;
            else new_right = mid - 1;
        }

        return -1;
    }

    int sortAndSearch(vector<int>& nums, int target) {
        quickSort(nums, 0, nums.size() - 1);
        return binarySearch(nums, target);
    }

    // RMS-normalize array
    vector<float> normalizeRMS(const vector<float> & nums)
    {
        if (nums.empty())
        {
            return nums;
        }
        // Calculate the RMS and the constant value C
        long double sumOfSquares = 0.0;
        for (const float & num : nums)
        {
            // why pow, not num * num
            sumOfSquares += pow(num, 2);
        }
        // isZero(sumOfSquares, tolerance)
        // {
        //     if (abs(sumOfSquares - 0) < tolerance) return true;
        // }
        if (sumOfSquares == 0)
        {
            return nums;
        }
        float C = sqrt(nums.size() / sumOfSquares);
        // Normalize this array
        vector<float> result;
        for (const float & num : nums)
        {
            result.push_back(C * num);
        }
        return result;
    }

    // This method compute convolution directly, with complexity of O(N^2)
    // b is kernel
    vector<float> convolution(const vector<float>& a, const vector<float>& b)
    {
        if (a.empty() || b.empty()) return a;
        vector<float> result(a.size() + b.size() - 1, 0.0);
        for(long int i = 0; i < result.size(); i++)
        {
            long double sum = 0;
            for (long int j = 0; j < a.size(); j++)
            {
                // check boundries
                if (i - j >= 0 && i - j < a.size())
                {
                    sum += a[j] * b[i - j];
                } 
            }
            result[i] = sum;
        }
        return result;
    }

    // This method uses FFTW with complexity of O(NlogN)
    vector<float> fftConvolution(const vector<float>& A, const vector<float>& B)
    {
        size_t newSize = pow(2, ceil(log2(A.size() + B.size() - 1)));
        vector<float> result;

        // prepare FFTW plans
        fftw_plan plan_forward_A, plan_forward_B, plan_backward;
        vector<complex<double> > A_padded(newSize), B_padded(newSize), C(newSize);

        // initialize A_padded and B_padded with input data and zero padding
        copy(A.begin(), A.end(), A_padded.begin());
        copy(B.begin(), B.end(), B_padded.begin());

        // execute forward FFTs
        plan_forward_A = fftw_plan_dft_1d(newSize, 
                                    reinterpret_cast<fftw_complex*>(A_padded.data()), 
                                    reinterpret_cast<fftw_complex*>(A_padded.data()), 
                                    FFTW_FORWARD, 
                                    FFTW_ESTIMATE);
        fftw_execute(plan_forward_A);
        plan_forward_B = fftw_plan_dft_1d(newSize, 
                                    reinterpret_cast<fftw_complex*>(B_padded.data()), 
                                    reinterpret_cast<fftw_complex*>(B_padded.data()), 
                                    FFTW_FORWARD, 
                                    FFTW_ESTIMATE);
        fftw_execute(plan_forward_B);

        // get convlution array C via Element-wise multiplication 
        for (size_t i = 0; i < newSize; ++i) 
        {
            C[i] = A_padded[i] * B_padded[i];
        }

        // execute inverse FFT
        plan_backward = fftw_plan_dft_1d(newSize, 
                                reinterpret_cast<fftw_complex*>(C.data()), 
                                reinterpret_cast<fftw_complex*>(C.data()), 
                                FFTW_BACKWARD, 
                                FFTW_ESTIMATE);
        fftw_execute(plan_backward);

        // normalize the inverse FFT result
        for (auto& elem : C) 
        {
            elem /= newSize;
            if (abs(elem.real()) > tolerance) 
            {
                result.push_back(elem.real());
            }
        }

        // clean
        fftw_destroy_plan(plan_forward_A);
        fftw_destroy_plan(plan_forward_B);
        fftw_destroy_plan(plan_backward);

        return result;
    }

    vector<float> smoothing(const vector<float>& nums, int w)
    {
        // for invalid input
        if (nums.size() <= 1 || w < 1) 
        {
            return nums;
        }
        vector<float> result(nums.size(), 0.0);
        // 0 + 1, 0 + 1 + 2, 1 + 2 + 3, 2 + 3 + 4
        // 0   ,  1         , 2         , 3
        // f[i] = f[i-1]+nums[i+1]-nums[i-2];

        for (int i = 0; i < nums.size(); i++)
        {
            // for boundries
            int left = max(i - w, 0);
            int right = i + w < nums.size() ? i + w : nums.size() - 1;
            double sum = 0;
            for (int j = left; j <= right; j++)
            {
                sum += nums[j];
            }
            result[i] = sum / (right - left + 1);
        }
        return result;
    }

    vector<float> improvedSmoothing(const vector<float>& nums, int w)
    {
        // for invalid input
        if (nums.size() <= 1 || w < 1) 
        {
            return nums;
        }
        int window = 2 * w + 1;
        vector<float> kernel(window, float(1) / window);

        // use convolution to smooth
        // call convolution() is also ok, but make sure to input kernel as param B
        vector<float> result = fftConvolution(kernel, nums);

        // trim the padding elements
        result.erase(result.begin(), result.begin() + w);
        result.erase(result.end() - w, result.end());
        return result;
    }

    void print(const vector<float>& nums)
    {
        for (const auto & num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }

private:
    int partition(vector<int>& nums, int left, int right)
    {
        int i = left - 1;
        int pivot = nums[right];
        for (int j = left; j < right; j++)
        {
            if (nums[j] < pivot)
            {
                i++;
                swap(nums[j], nums[i]);
            }
        }
        i++;
        swap(nums[right], nums[i]);
        return i;
    }

    void quickSort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int random_index = rand() % (right - left + 1) + left;
        swap(nums[random_index], nums[right]);
        int mid = partition(nums, left, right);
        quickSort(nums, left, mid - 1);
        quickSort(nums, mid + 1, right);
    }
};

/*
    n^15
    1. naive method: 
        n * n * n ...* n: 14 times
    2. pow 
        math::pow
        n^15 = (n^7) * (n^7) * n
        n^7 = (n^3) * (n^3) * n
        n^3 = n * n * n
        6 multiplication

    res = 2, exp = 7, base = 2^2
    res = 2 * base = 2^3, exp = 3, (2^2)*(2^2) = 2^4
    res = 2^3 * 2^4, exp = 1, base = 2^8
    res = 2^7 * 2^8, exp = 0, break;

    15（decimal number) = 1111 (binary number)
    2^15 = 2^(8 + 4 + 2 + 1)
*/
int ipow(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

/* 
    g++ -std=c++11 assignment.cpp -I/usr/local/include -L/usr/local/lib -lfftw3 -lm -o test
    ./test
*/
int main(){
    /*  test code */
    // Solution s;
    // std::vector<float> a = {1, 3, 5, 7};
    // std::vector<float> b(3, float(1) / 3);

    // std::vector<int> array = {7, 5, 3, 1};
    // cout << "search (array, 5): " << s.sortAndSearch(array, 5) << endl; 
    // // 2

    // cout << "normalizeRMS(a): "; 
    // s.print(s.normalizeRMS(a));
    // // 0.218218 0.654654 1.09109 1.52753 

    // cout << "convolution(a, b): "; 
    // s.print(s.convolution(a, b));
    // // 0.333333 1.33333 3 5 4 2.33333 

    // cout << "fftConvolution(a, b): "; 
    // s.print(s.fftConvolution(a, b));
    // // 0.333333 1.33333 3 5 4 2.33333 

    // cout << "smoothing: ";
    // s.print(s.smoothing(a, 1));
    // // 2 3 5 6 
    
    // cout << "improvedSmoothing: ";
    // s.print(s.improvedSmoothing(a, 1));
    // 1.33333 3 5 4 

    ipow(2, 3);
}

