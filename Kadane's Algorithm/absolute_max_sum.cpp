#include<iostream>
using namespace std;
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int a, b, c, maxsum = nums[0], minsum = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            a = nums[i];
            b = nums[i] + minsum;
            c = nums[i] + maxsum;
            minsum = min(a,min(b,c));
            maxsum = max(a,max(b,c));
            ans = max(abs(ans),max(abs(minsum),maxsum));
        }
        return abs(ans);
    }
};