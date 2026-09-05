#include<iostream>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), low = 0, ans = 0, zeroes = 0;
        for (int high = 0; high < n ; high++){
            if(nums[high]==0){
                zeroes++;
            }
            while(zeroes > k){
                if(nums[low]==0)
                    zeroes--;
                low++;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};