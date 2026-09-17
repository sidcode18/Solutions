#include<iostream>
using namespace std;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        // prefix[i] = sum of the first i elements.
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        deque<int> dq;
        int ans = n + 1;
        for (int i = 0; i <= n; i++) {
            // If prefix[i] - prefix[dq.front()] >= k,
            // the subarray between these two prefix sums
            // has sum at least k.
            // Remove it from the front because we found a valid
            // subarray, and any longer subarray ending at i
            // cannot be better than this shortest one.
            while (!dq.empty() &&
                   prefix[i] - prefix[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            // Remove larger or equal prefix sums from the back.
            // A larger prefix sum is never useful because it gives
            // a smaller subarray sum and is also farther back.
            while (!dq.empty() &&
                   prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }
            // Keep the current prefix index for future subarrays.
            dq.push_back(i);
        }
        return ans == n + 1 ? -1 : ans;
    }
};