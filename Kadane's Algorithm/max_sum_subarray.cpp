#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), a, b ;
        int best = nums[0], ans = nums[0] ;  // initially at index 0, best and ans is the element at start itself.
        // from index 1, we have two options, either we can take the current element or we can take the current element and add it to the best sum we have found so far.
        for(int i = 1; i < n; i++){ // start from next index 
            a = nums[i];
            b = nums[i]+best;
            best = max(a,b);
            ans = max(ans,best);
        }
        return ans;
    }
};