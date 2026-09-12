#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int a, b, x, y, ans = nums[0], best1 = nums[0], best2 = nums[0], max1 = nums[0], minm = nums[0], sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            // Find maximum subarray sum considering the array as linear
            a = nums[i];
            b = nums[i]+best1;
            best1 = max(a,b);
            max1 = max(max1,best1);
        }
        for(int i = 1; i < nums.size(); i++){
            // Find minimum subarray sum in linear array so that if end end start are connected we can get the maximum sum by taking entire sum of array and subtract the minimum subarray sum from it
            x = nums[i];
            y = nums[i]+best2;
            best2 = min(x,y);
            minm = min(minm,best2);
            sum = sum + nums[i];
        }
        // If the minimum subarray is the entire array,
        // sum - minm would give 0, which is not a valid
        // circular subarray.
        // Either:
        // 1. Maximum is a normal subarray
        // 2. Maximum wraps around the end
        if(sum==minm) return max(ans,max(max1,sum));
        else return max(ans,max(max1,sum-minm));
    }
};