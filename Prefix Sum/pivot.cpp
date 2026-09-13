#include<iostream>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, left = 0;
        for(int i = 0; i < nums.size(); i++){
            // finding sum because right is total sum - the current element - sum to the left of the current element
            sum += nums[i];
        }
        for(int j = 0; j < nums.size(); j++){
            // left is sum of elements to the left of index j
            // right is sum of elements to the right of index j
            int right = sum - left - nums[j];
            if (left == right) return j;
            left += nums[j];
        }
        return -1;
    }
};
// another way would be to create prefix and suffix arrays and compare each index till both are same.