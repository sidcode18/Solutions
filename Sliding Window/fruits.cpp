#include <iostream>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int low = 0, ans = 0;
        // Use a hash map to store the frequency of each fruit type in the current window. The key is the fruit type and the value is its frequency.
        unordered_map<int, int> freq;
        for (int high = 0; high < n; high++) {
            freq[fruits[high]]++;
            while (freq.size() > 2) {
                freq[fruits[low]]--;
                if (freq[fruits[low]] == 0)
                    freq.erase(fruits[low]);
                low++;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};