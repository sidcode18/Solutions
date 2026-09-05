#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0, ans = 0;
        unordered_map<char, int> freq;
        for (int high = 0; high < s.size(); high++) {
            freq[s[high]]++;
            while (freq[s[high]] > 1) {
                // If the character at the high pointer is already present in the frequency map (i.e., its count is greater than 1), we need to shrink the window from the left by incrementing the low pointer and decrementing the count of the character at the low pointer in the frequency map. This continues until there are no repeating characters in the current window.  
                freq[s[low]]--;
                low++;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};