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
                freq[s[low]]--;
                low++;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};