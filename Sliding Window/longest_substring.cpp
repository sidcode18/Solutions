#include<iostream>
using namespace std;
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // incrementing low pointer either shrinks the window size (through erase) or keeps it the same size, while incrementing high pointer always increases the window size. The window is shrunk when the number of distinct characters in the current window exceeds k.
        // since longest is asked to find and if already the size of hashmap is less than k, then we can just increment the high pointer (instead of incrementing low again to reduce the size of window even more)  to increase the window size and check if the size of hashmap is equal to k. If greater than k, then we increment the low pointer to reduce the size of window and check again if the size of hashmap is equal to k.
        int low = 0, n = s.size(), ans = INT_MIN;
        unordered_map <char, int> freq;
        for (int high = 0 ; high < n ; high ++){
            freq[s[high]]++; // Increases count of character at high pointer in the frequency map.
            while (freq.size() > k){
                freq[s[low]]--;
                if (freq[s[low]]==0){
                    freq.erase(s[low]);
                }
                low++;
            }
            if(freq.size()==k){
                int len = high - low + 1;
                ans = max(len,ans);
            }
        }
        if(ans == INT_MIN){
            return -1;
        }
        else return ans;
    }
};