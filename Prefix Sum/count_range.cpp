#include <iostream>
using namespace std;
class Solution {
public:
    long long mergeSort(vector<long long>& prefix,
                        int left, int right,
                        int lower, int upper) {
        // One prefix sum cannot form a non-empty range by itself.
        if (right - left <= 1)
            return 0;
        int mid = left + (right - left) / 2;
        // Count valid ranges entirely in the left and right halves.
        long long count = mergeSort(prefix, left, mid, lower, upper)
                        + mergeSort(prefix, mid, right, lower, upper);
        int low = mid;
        int high = mid;
        for (int i = left; i < mid; i++) {
            // We need:
            // lower <= prefix[j] - prefix[i] <= upper
            // Therefore:
            // prefix[i] + lower <= prefix[j] <= prefix[i] + upper
            while (low < right && prefix[low] < prefix[i] + lower)
                low++;
            while (high < right && prefix[high] <= prefix[i] + upper)
                high++;
            // Every prefix sum in [low, high) forms a valid range.
            count += high - low;
        }
        // Merge both sorted halves so the parent call can use
        // the two-pointer counting technique.
        inplace_merge(prefix.begin() + left,
                      prefix.begin() + mid,
                      prefix.begin() + right);

        return count;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefix(nums.size() + 1, 0);

        // prefix[i] stores the sum of the first i elements.
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        return mergeSort(prefix, 0, prefix.size(), lower, upper);
    }
};
