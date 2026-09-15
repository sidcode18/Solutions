#include <iostream>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIndex;
        // A balance of 0 exists before the array starts.
        // This allows us to count valid subarrays starting at index 0.
        firstIndex[0] = -1;
        int balance = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            // Treat 0 as -1 and 1 as +1.
            // A subarray has equal 0s and 1s when its balance is 0.
            if (nums[i] == 0)
                balance--;
            else
                balance++;
            // If this balance appeared before, the elements
            // between the previous index and i have net balance 0.
            // Therefore, that subarray contains equal 0s and 1s.
            if (firstIndex.find(balance) != firstIndex.end()) {
                ans = max(ans, i - firstIndex[balance]);
            } else {
                // Store only the first occurrence because it gives
                // the longest possible subarray for this balance later.
                firstIndex[balance] = i;
            }
        }
        return ans;
    }
};