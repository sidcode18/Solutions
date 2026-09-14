#include<iostream>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int, int> freq;
        // A prefix sum of 0 before the array starts allows us
        // to count subarrays beginning at index 0.
        freq[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;
            // prefix sum can produce a negative remainder. Adding k converts it to the equivalent remainder, in the range [0, k - 1].
            if (rem < 0) {
                rem += k;
            }
            // currentSum % k == previousSum % k then (currentSum - previousSum) % k == 0
            // If an earlier prefix sum had this same remainder, subtracting it from the current prefix sum gives a sum divisible by k. Each occurrence represents one different valid subarray ending at i.
            // freq[remainder] = number of previous prefix sums having that remainder
            ans += freq[rem];
            // Save this remainder because a later prefix sum with the same remainder can form a divisible subarray with the current prefix sum.
            freq[rem]++;
        }
        return ans;
    }
};