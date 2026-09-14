#include <iostream>
using namespace std; 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int, int> freq;
        // Empty prefix has sum 0
        freq[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            // Update prefix sum
            sum += nums[i];
            // Find how many previous prefix sums equal sum - k
            int count = freq[sum - k];
            // Add all valid subarrays ending at index i
            ans += count;
            // Store the current prefix sum so future subarrays can start after this index
            freq[sum]++;
        }
        return ans;
    }
};