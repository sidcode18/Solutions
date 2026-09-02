#include <iostream>
using namespace std;

// Have to find the minimum length of the subarray whose sum is greater than or equal to the target value. Since length is unknown, must use a dynamic sliding window approach.
// low and high both are 0 initially while using a dynamic sliding window approach.
// Sum is done till condition is satisfied atleast once and once it is achieved, the low pointer is moved to reduce the length of the subarray while still satisfying the condition. This is done until the condition is no longer satisfied and then the high pointer is moved again to increase the sum and satisfy the condition again. This process is repeated until the high pointer reaches the end of the array.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0, high = 0, ans = INT_MAX, sum = 0;
        int n = nums.size();
        while(high<n){
            sum = sum + nums[high];
            while(sum>=target){
                int len = high - low + 1;
                ans = min(len,ans);
                sum = sum - nums[low];
                low++;
            }
            high ++;
        }
        if(ans==INT_MAX){
            return 0;
        }
        else return ans;
    }
};