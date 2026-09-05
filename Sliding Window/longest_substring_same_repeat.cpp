#include <iostream>
using namespace std;

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times. Return the length of the longest substring containing the same letter you can get after performing the above operations.

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), low = 0, ans = 0, maxm = 0;
        vector <int> freq(26,0);
        // A vector of 26 spaces starting from index 0 is created. The vector is used to keep track of the frequency of each uppercase English letter in the current window of the string. The index of the vector corresponds to the letter's position in the alphabet (0 for 'A', 1 for 'B', ..., 25 for 'Z'). As we iterate through the string, we increment the count of the character at the high pointer in this frequency vector.
        for(int high = 0; high < n ; high++){
            freq[s[high]-'A']++;
            // The line `freq[s[high]-'A']++;` increments the count of the character at the `high` pointer in the frequency vector. `s[high]-'A' calculates the index corresponding to the character in the alphabet (e.g., 'A'-'A' = 0 -> +1 for 0th index, next 'B'-'A' = 1 -> +1 for 1st index and so on).
            maxm = max(maxm,freq[s[high]-'A']);
            int len = high - low + 1;
            if(len-maxm > k){
                freq[s[low]-'A']--;
                low++;
            }
            ans = max(ans,high - low + 1); // len is not used because when if conditon is satisfied, low increments but last registered len doesnt take that into account.
        }
        return ans;
    }
};