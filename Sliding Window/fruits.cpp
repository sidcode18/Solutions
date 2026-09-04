#include <iostream>
using namespace std;
// The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
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