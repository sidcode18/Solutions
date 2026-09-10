#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), a, b ;
        int best = nums[0], ans = nums[0] ; 
        for(int i = 1; i < n; i++){ 
            a = nums[i];
            b = nums[i]+best;
            best = min(a,b);
            ans = min(ans,best);
        }
        return ans;
    }
};